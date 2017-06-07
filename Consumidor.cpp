#include "include/Consumidor.h"

Consumidor::Consumidor( Buffer * b, char * ip, char * port, bool hd){

    buffer = b;
    ip_ = ip;
    port_ = port;
    alive = true;
    HD = hd;

}

void Consumidor::read(){


}

void Consumidor::send(){


}

void Consumidor::run(){

    while(alive){

        if(HD){//Se é HD (escritor)



        }else{//Se é só leitor



        }
    }

}