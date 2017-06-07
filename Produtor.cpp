#include "include/Produtor.h"

Produtor::Produtor( Buffer * b, char * ip, char * port){

    buffer = b;
    ip_ = ip;
    port_ = port;
    alive = true;

}

void Produtor::escreve(){


}

void Produtor::run(){
    while(alive){
    escreve();
    }
}