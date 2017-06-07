#include "include/Produtor.h"


Produtor::Produtor( Buffer * b, char * ip, char * port){

    buffer = b;
    ip_ = ip;
    port_ = port;
    alive = true;

}

void Produtor::connect(){

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock < 0) error("Opening socket");

    length = sizeof(server);

    bzero(&server, length);
    server.sin_family = AF_INET;
    //server.sin_addr.s_addr = htons(atoi(ip_));
    inet_aton(ip_, &(server.sin_addr));
    // A funcao htons() converte o numero da porta para o padrao Little Endian.
    server.sin_port = htons(atoi(port_));

    // Associa um socket a um endereco
    if (bind(sock, (struct sockaddr *) &server, length) < 0)
        error("binding");

}

void Produtor::escreve(){
    
    n = recvfrom(sock, buffer->buffer[buffer->rear], 1316, 0, NULL, NULL);
    if (n < 0) printf("\nrecvfrom");

    buffer->rear = (buffer->rear + 1) % BUFFER_SIZE;

}


void Produtor::run(){
    while(alive){
    empty->P();
    escreve();
    full->V();
    }
}

void error(const char *msg) {
    perror(msg);
    exit(0);
}