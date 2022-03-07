#ifndef SUBJECT_H
	#define SUBJECT_H
	#include "observer.h"

	typedef struct __subject
	{
		int type;
		
		void (*destruir)(struct __subject *); //destruye el objeto 
	
		void * impl; //la implementacion de la clase mail 

		Observer * observers[MAX_OBSERVERS]; 
	
		int (*suscribirObservador)(struct __subject*, Observer*); //metodo que permite que se subscriban los observadores

		int (*desuscribirObservador)(struct __subject *, Observer*); //metodo para que se desubsriban los observadores

		void (*notificarObservador)(struct __subject*); //trigger al metodo notify a todos los observadores suscritos
	} Subject;


	Subject * subjectNew(void*, int); //constructor para el sujeto

#endif