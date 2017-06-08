#ifndef BUFFER_H_
#define BUFFER_H_

//#include "Thread.h"
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <netdb.h>
#include "Semaforo.h"

#define BUFFER_SIZE 60

typedef struct buffer{
    //Buffer(int size, int socksize);

    char buffer[BUFFER_SIZE][1316];

    int rear;
    int front;
    int cont[BUFFER_SIZE];

    Semaforo * empty;
    Semaforo * full;

    Semaforo * readfront[BUFFER_SIZE];

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

}

#endif