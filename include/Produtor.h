
#ifndef PRODUTOR_H
#define PRODUTOR_H


#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include "Thread.h"
#include <stdio.h>
#include <stdlib.h>
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

    void error(const char *msg);


private:

    

};

#endif