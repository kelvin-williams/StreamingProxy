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
    char po3[20] = {"6000"};
    char po4[20] = {"7000"};
    char po5[20] = {"8000"};

    Produtor p(&buf, &ip1[0], &po1[0]);
    Consumidor c(&buf, &ip2[0], &po2[0], false);
    Consumidor c2(&buf, &ip2[0], &po3[0], false);
    Consumidor c3(&buf, &ip2[0], &po4[0], false);
    Consumidor c4(&buf, &ip2[0], &po5[0], true);

    p.start();
    c.start();
    c2.start();
    c3.start();
    c4.start();

    p.join();
    c.join();
    c2.join();
    c3.join();
    c4.join();

    return 0;
}