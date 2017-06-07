
#ifndef PRODUTOR_H_
#define PRODUTOR_H_


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <cstdlib>
#include "Thread.h"
#include "buffer.h"


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