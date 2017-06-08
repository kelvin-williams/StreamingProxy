
#include "include/Consumidor.h"

Consumidor::Consumidor( Buffer * b, char * ip, char * port, bool hd){

    buffer = b;
    ip_ = ip;
    port_ = port;
    alive = true;
    HD = hd;
  //  buffer->readfront[0]->P();
  //  nc++;
  //  buffer->readfront[0]->V();
  //  id = nc;
    reading = buffer->front;

}

void Consumidor::connect(){

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    //if (sock < 0) error("Opening socket");

    length = sizeof(server);

    bzero(&server, length);
    server.sin_family = AF_INET;
    //server.sin_addr.s_addr = htons(atoi(ip_));
    inet_aton(ip_, &(server.sin_addr));
    // A funcao htons() converte o numero da porta para o padrao Little Endian.
    server.sin_port = htons(atoi(port_));

    // Associa um socket a um endereco
    bind(sock, (struct sockaddr *) &server, length);
       // error("binding");

}

void Consumidor::read(){

    
/////////////////Acesso ao Buffer////////////////////////////////////////////////////////
            buffer->full->P();

            std::copy(std::begin(buffer->buffer[reading]), std::end(buffer->buffer[reading]), std::begin(data));

            buffer->readfront[reading]->P();

            buffer->cont[reading]++;

            if(buffer->cont[reading] == nc){//Se o que ele leu é o front, e se ele é o ultimo a ler

                buffer->cont[reading] = 0;
                buffer->front = (int)((buffer->front + 1) % BUFFER_SIZE);
                buffer->empty->V();

                }else{
                    buffer->full->V();
                    } 

                buffer->readfront[reading]->V();
                reading =(int) ((reading + 1) % (BUFFER_SIZE)); 
////////////////////Fim do acesso ao buffer/////////////////////////////////////////////////////////////

}

void Consumidor::send(){

        sendto(sock, data, 1316, 0, (struct sockaddr *) &server, length);
}

void Consumidor::run(){

    if(HD){//Se é HD (escritor)
    
    buffer->readfront[0]->P();
    nc++;
    buffer->readfront[0]->V();
    id = nc;


            buffer->e->P();
            if(buffer->nr > 0 || buffer->nw > 0){
                buffer->dw++;
                buffer->e->V();
                buffer->w->P();
            }
            buffer->nw++;
            //SIGNAL
            buffer->e->V();
//////////////////////////////////////////////

    connect();

    while(alive){

        read();
        send();

    }
//////////////////////////////////////////////////

    buffer->e->P();
            buffer->nw--;
            //SIGNAL
            if(buffer->dw > 0){
                buffer->dw--;
                buffer->w->V();
            }else{
                if(buffer->dr > 0){
                    buffer->dr--;
                    buffer->r->V();
                }else buffer->e->V();
            }


        }else{//Se é só leitor

        buffer->readfront[0]->P();
        nc++;
        buffer->readfront[0]->V();
        id = nc;

            buffer->e->P();
            if(buffer->nw > 0 || buffer->dw > 0){
                buffer->dr++;
                buffer->e->V();
                buffer->r->P();
            }
            buffer->nr++;
            //SIGNAL
            if (buffer->dr > 0) { 
                buffer->dr--;
                 buffer->r->V();
                 }else{
                      buffer->e->V();
                      }
///////////////////////////////////////////////////////////
connect();

    while(alive){

        read();
        send();

    }
///////////////////////////////////////////////////////////
 buffer->e->P();
            buffer->nr--;
            //SIGNAL
            if(buffer->nr == 0 && buffer->dw > 0){
                buffer->dw--;
                buffer->w->V();
            }else{
                buffer->e->V();
            }
        }

}
