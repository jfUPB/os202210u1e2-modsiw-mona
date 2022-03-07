#ifndef OBSERVER_H
	#define OBSERVER_H
	#include "exit.h"

	typedef struct __observer { //implementa el garbage collector

		void (*destruir)(struct __observer *);
		
		void* impl;
		
		void (*notificar)(struct __observer*, int, void *);
	
		void (*notificarImpl)(void*, int, void*);
	} Observer;

	Observer * observerNew(void*, void (*)(void*, int, void*));

#endif