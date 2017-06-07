
#ifndef CONSUMIDOR_H
#define CONSUMIDOR_H

#include "Thread.h"
//#include "buffer.h"


class Consumidor : public Thread {

public:

    Consumidor(Buffer * b, char * ip, char * port, bool hd);

    bool alive;

    bool HD;

    char * ip_;
    char * port_;

    int sock, length, n;

    struct sockaddr_in server;

    void connect();

    void read();

    void send();

    void run();

    Buffer * buffer;

private:

    

};

#endif