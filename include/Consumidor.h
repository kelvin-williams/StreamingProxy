
#ifndef CONSUMIDOR_H_
#define CONSUMIDOR_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include <iterator>
#include "Thread.h"
#include "buffer.h" 


class Consumidor : public Thread {

public:

    Consumidor(Buffer * b, char * ip, char * port, bool hd);

    bool alive;

    bool HD;

    char * ip_;
    char * port_;

    int sock, length, n;

    struct sockaddr_in server;

    char data[1316];

    int reading;

    int id;

    void connect();

    void read();

    void send();

    void run();

    Buffer * buffer;


private:

    

};

#endif