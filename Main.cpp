/* Projeto da Disciplina LP2 - Proxy de Vídeo

    Grupo:  Kelvin Williams
            Marcus Alves
            Valfredo Santos
*/
#include <stdlib.h>
#include <unistd.h>

#include "Produtor.cpp"
#include "Consumidor.cpp"

#include "Thread.cpp"

Semaforo empty, full;

int main(){
    buffer buf;
    empty = new Semaforo(20);
    full = new Semaforo(0);
    Produtor p(&buf, "127.0.0.1", "4000");
    Consumidor c(&buf, "127.0.0.1", "5000", false); 

    p.start();
    c.start();

    return 0;
}