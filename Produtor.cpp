#include "include/Produtor.h"
#include <sys/socket.h>
#include <netinet/in.h>

Produtor::Produtor( Buffer * b, char * ip, char * port){

    buffer = b;
    ip_ = ip;
    port_ = port;
    alive = true;

}

void Produtor::escreve(){
    buf[buf.rear] = data;
    buf.rear = (buf.rear + 1) % 20;
}

void Produtor::run(){
    while(alive){
    empty->P();
    escreve();
    full->V();
    }
}