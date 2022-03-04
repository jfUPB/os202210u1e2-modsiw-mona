#include "mail.h"

/**
 * Cuando hay una noticia nueva, los clientes la reciben. mail es el sujeto
 */

static void _noticiaNueva(Mail* this)
{
  printf("%s\n", "Noticia de ultima hora");
  printf("%s\n", this->name);

	this->event = NOTICIANUEVA;
	this->subject->notifyObservers(this->subject);
}

static void _destruir(Mail* this)
{
	this->subject->destruir(this->subject);

  if (NULL != this) {
    free(this);
    this = NULL;
  }
}

static MailEvent _getEvento(Mail* this)
{
	return this->event;
}

static int _subscribirObservador(Mail* this, Observer* observer) {
  return this->subject->subscribirObservador(this->subject, observer);
}

static int _desubscribirObservador(Mail * this, Observer* observer) {
  return this->subject-> desubscribirObservador(this->subject, observer);
}

Mail* CrearMail(char * titulo)
{
	Mail* this = (Mail *) malloc(sizeof(*this));
	this->titulo = titulo;
	this->destruir = _destruir;
	this->getEvento = _getEvento;
	this->noticiaNueva = _noticiaNueva;

	this->subject = subjectNew(this, 1);
	this->subscribirObservador = _subscribirObservador;
	this->desubscribirObservador = _desubscribirObservador;

	return this;
}