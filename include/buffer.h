
//#include "Thread.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

typedef struct buffer{

public:

    //Buffer(int size, int socksize);

    char buffer[20][1316];

    int rear = 0;
    int front = 0;

}Buffer;