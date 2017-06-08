
#include "include/Consumidor.h"

Consumidor::Consumidor( Buffer * b, char * ip, char * port, bool hd){

    buffer = b;
    ip_ = ip;
    port_ = port;
    alive = true;
    HD = hd;
    buffer->readfront->P();
    nc++;
    buffer->readfront->V();

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

            buffer->full->P();
            std::copy(std::begin(buffer->buffer[reading]), std::end(buffer->buffer[reading]), std::begin(data));
          //  data = buffer->buffer[buffer->front];
        //    buffer->front = (buffer->front + 1) % BUFFER_SIZE;
          //  buffer->empty->V();

            buffer->readfront->P();
            buffer->cont[reading]++;

            if(reading == buffer->front && buffer->cont[reading] == nc){//Se o que ele leu é o front, e se ele é o ultimo a ler
                buffer->cont[reading] = 0;
                buffer->front = (buffer->front + 1) % BUFFER_SIZE;
                buffer->empty->V();
                }
                
                buffer->readfront->V();

                reading = (reading + 1) % BUFFER_SIZE;
            

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
