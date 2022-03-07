#ifndef CLIENTE_H
	#define CLIENTE_H
 	#include <stdio.h>
	#include <stdlib.h>
	#include "../observer/observer.h"
	#include "mail.h"

	typedef struct __cliente
	{
		char* name;
		void (*destruir)(struct __cliente*); //cliente.destroy
		void (*sign_up)(struct __cliente*, Mail*); //paso previo para que el mail subscriba al cliente

		Observer* observer;
	} Cliente;

	Cliente* Cliente_create(char *); //crea un cliente 

#endif