#ifndef BUFFER_H_
#define BUFFER_H_

//#include "Thread.h"
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <netdb.h>
#include "Semaforo.h"

#define BUFFER_SIZE 2000

typedef struct buffer{
    //Buffer(int size, int socksize);

    char buffer[BUFFER_SIZE][1316];

    int rear;
    int front;
    int cont[BUFFER_SIZE];

    Semaforo * empty;
    Semaforo * full;

    Semaforo * readfront[BUFFER_SIZE];

    //Passagem de bastão
    int nr, nw, dr, dw;
    Semaforo * e;
    Semaforo * r;
    Semaforo * w;

}Buffer;

void initbuf(Buffer *buf){

    buf->rear = 0;
    buf->front = 0;
    int i;
    for(i = 0; i < BUFFER_SIZE; i++){
        buf->cont[i] = 0;
    }

    buf->empty = new Semaforo(BUFFER_SIZE);
    buf->full = new Semaforo(0);
    int k;
    for(k = 0; k < BUFFER_SIZE; k++){
    buf->readfront[k] = new Semaforo(1);
    }

    buf->nr = 0;
    buf->nw = 0;
    buf->dr = 0;
    buf->dw = 0;

    buf->e = new Semaforo(1);
    buf->r = new Semaforo(0);
    buf->w = new Semaforo(0);

}

#endif