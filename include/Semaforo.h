#ifndef SEMAFORO_H
#define SEMAFORO_H

#include <semaphore.h>
#include <sys/types.h>
#include <pthread.h>

class Semaforo{
	public:
  		Semaforo(int value);
  		~Semaforo();
  		void P();
  		void V();
  		
	private:
 		sem_t sem;
};

#endif
