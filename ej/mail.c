#include "mail.h"

/**
 * Cuando hay una noticia nueva, los clientes la reciben. mail es el sujeto
 */

static void _noticiaNueva(Mail* this)
{
  printf("%s", "Noticia de ultima hora de:");
  printf("%s\n", this->titulo);

	this->event = NOTICIANUEVA;
	this->subject->notificarObservador(this->subject);
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

static int _suscribirObservador(Mail* this, Observer* observer) {
  return this->subject->suscribirObservador(this->subject, observer);
}

static int _desuscribirObservador(Mail * this, Observer* observer) {
  return this->subject-> desuscribirObservador(this->subject, observer);
}

Mail* CrearMail(char * titulo)
{
	Mail* this = (Mail *) malloc(sizeof(*this));
	this->titulo = titulo;
	this->destruir = _destruir;
	this->getEvento = _getEvento;
	this->noticiaNueva = _noticiaNueva;

	this->subject = subjectNew(this, 1);
	this->suscribirObservador = _suscribirObservador;
	this->desuscribirObservador = _desuscribirObservador;

	return this;
}