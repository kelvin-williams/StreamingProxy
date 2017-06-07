
#ifndef PRODUTOR_H
#define PRODUTOR_H

#include "Thread.h"
//#include "buffer.h"


class Produtor : public Thread {

public:

    Produtor(Buffer * b, char * ip, char * port);

    bool alive;

    char * ip_;
    char * port_;

    void escreve();

    void run();

    Buffer * buffer;

private:

    

};

#endif