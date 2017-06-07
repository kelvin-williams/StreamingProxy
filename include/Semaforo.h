#ifndef SEMAFORO_H_
#define SEMAFORO_H_

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
