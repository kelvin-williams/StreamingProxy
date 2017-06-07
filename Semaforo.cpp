#include "include/Semaforo.h"

Semaforo::Semaforo(int value){
  sem_init(&sem, 0, value);
}

Semaforo::~Semaforo(){
  sem_destroy(&sem);
}

void Semaforo::P(){
  sem_wait(&sem);
}

void Semaforo::V(){
  sem_post(&sem);
}
