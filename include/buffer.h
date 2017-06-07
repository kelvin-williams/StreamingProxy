
//#include "Thread.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 60

typedef struct buffer{
    //Buffer(int size, int socksize);

    char buffer[BUFFER_SIZE][1316];

    int rear;
    int front;

}Buffer;

void initbuf(Buffer *buf){

    buf->rear = 0;
    buf->front = 0;

}