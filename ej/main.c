//utiliza la implementacion de observer
#include <stdio.h>
#include "mail.h"
#include "cliente.h"


int main(int argc, char const *argv[])
{

	Mail* elColombiano = CrearMail("El Colombiano");
	Cliente* sofia = Cliente_create("Sofia");

	sofia->sign_up(sofia, elColombiano);
	elColombiano->noticiaNueva(elColombiano);

	elColombiano->destruir(elColombiano);
	sofia->destruir(sofia);

	return 0;
}