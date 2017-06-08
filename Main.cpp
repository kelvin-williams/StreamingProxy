/* Projeto da Disciplina LP2 - Proxy de Vídeo

    Grupo:  Kelvin Williams
            Marcus Alves
            Valfredo Santos
*/

//#include <stdlib.h>
//#include <unistd.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

//#include "Thread.cpp"

//#include "Semaforo.cpp"
int nc = 0;

#include "Produtor.cpp"
#include "Consumidor.cpp"
#include "Semaforo.cpp"
#include "Thread.cpp"



int main(){
    buffer buf;
    initbuf(&buf);
    
    char ip1[20] = {"127.0.0.1"};
    char ip2[20] = {"127.0.0.1"};
    char po1[20] = {"4000"};
    char po2[20] = {"5000"};

    Produtor p(&buf, &ip1[0], &po1[0]);
    Consumidor c(&buf, &ip2[0], &po2[0], false);

    p.start();
    c.start();

    p.join();
    c.join();

    return 0;
}