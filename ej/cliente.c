/**
 * por cada cliente presente, subsribimos los correos presentes
 * 
 */

#include "cliente.h"

static void _destruir(Cliente* this)
{
	this->observer->destruir(this->observer);

	if (this != NULL){
		free(this);
		this = NULL;
	}
}

static void _sign_up(Cliente * this, Mail* mail)
{
	mail->suscribirObservador(mail, this->observer);
	printf("%s Just smelled %s\n", this->name, mail->titulo);
}

static void _handleMailEvent(Cliente* this, Mail* mail)
{
	printf("%s\n just received %s", this->name, mail->titulo);
}

static void _notificar(Cliente* this, int numero, void* subject) {
	_handleMailEvent(this, (Mail*) subject);
}

Cliente* Cliente_create(char* clientesName)
{
	Cliente* this = (Cliente*) malloc(sizeof(*this));

	this->name = clientesName;
	this->sign_up = _sign_up;
	this->destruir = _destruir;
	this->observer = observerNew(this, (void (*)(void*, int, void*))_notificar);

	return this;
}