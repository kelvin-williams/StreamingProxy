#include "include/Consumidor.h"

Consumidor::Consumidor( Buffer * b, char * ip, char * port, bool hd){

    buffer = b;
    ip_ = ip;
    port_ = port;
    alive = true;
    HD = hd;

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

void Consumidor::read(){

    if(HD){//Se é HD (escritor)

            


        }else{//Se é só leitor



        }

}

void Consumidor::send(){


}

void Consumidor::run(){

    while(alive){

        
    }

}