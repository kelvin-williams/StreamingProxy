
#ifndef PRODUTOR_H
#define PRODUTOR_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Thread.h"
//#include "buffer.h"


class Produtor : public Thread {

public:

    Produtor(Buffer * b, char * ip, char * port);

    bool alive;

    char * ip_;
    char * port_;

    int sock, length, n;

    struct sockaddr_in server;


    void escreve();

    void connect();

    void run();

    Buffer * buffer;


private:

    

};

#endif