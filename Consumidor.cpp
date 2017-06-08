
#include "include/Consumidor.h"

Consumidor::Consumidor( Buffer * b, char * ip, char * port, bool hd){

    buffer = b;
    ip_ = ip;
    port_ = port;
    alive = true;
    HD = hd;
    buffer->readfront[0]->P();
    nc++;
    buffer->readfront[0]->V();
    id = nc;
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

    if(HD){//Se é HD (escritor)

            


        }else{//Se é só leitor

            //printf("\n Thread :%d pegando dados", id);
            buffer->full->P();


            std::copy(std::begin(buffer->buffer[reading]), std::end(buffer->buffer[reading]), std::begin(data));
        //    buffer->front = (buffer->front + 1) % BUFFER_SIZE;
          //  buffer->empty->V();
       //     printf("\n Thread :%d deu P no readfront[%d]", id, reading);
            buffer->readfront[reading]->P();
            
      //      printf("\n Thread :%d, Lendo: %d, Front: %d", id, reading, buffer->front);
            buffer->cont[reading]++;


            if(buffer->cont[reading] == nc){//Se o que ele leu é o front, e se ele é o ultimo a ler
         //       printf("\n Thread: %d, Vai avançar o front para: %d, Front: %d", id, (int) ((buffer->front + 1) % BUFFER_SIZE));
                buffer->cont[reading] = 0;
                buffer->front = (int)((buffer->front + 1) % BUFFER_SIZE);
                buffer->empty->V();
                }else{
                    buffer->full->V();
                } 

           //     printf("\n Thread :%d deu V no readfront[%d]\n", id, reading);
                buffer->readfront[reading]->V();
                reading =(int) ((reading + 1) % (BUFFER_SIZE));  

        }

}

void Consumidor::send(){

        sendto(sock, data, 1316, 0, (struct sockaddr *) &server, length);
}

void Consumidor::run(){

    connect();

    while(alive){

        read();
        send();

    }

}
