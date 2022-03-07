#include "subject.h"

static void _destruir(Subject* this)
{
	if (this != NULL) {
		free(this);
		this = NULL;
	}
}

static int _subscribirObservador(Subject* this, Observer* observer)
{
	for (int i =0; i < MAX_OBSERVERS; i++) {
		if (this->observers[i] == NULL) {
			this->observers[i] = observer;

			return OK;
		}
	}

	printf("[INF] [SUBJECT] we have rush the max number of observers\n");
	return KO;
}

static int _desubscribirObservador(Subject *this, Observer* observer)
{
	for (int i = 0; i < MAX_OBSERVERS; i++) {
		void* pObserver = this->observers[i];

		if (observer == pObserver) {
			pObserver = NULL;
			return OK;
		}
	}

	return KO;
}

static void _notificarObservador(Subject* this)
{
	for (int i=0; i < MAX_OBSERVERS; i++) {
		if (this->observers[i] != NULL) {
			this->observers[i]->notificar(this->observers[i], this->type, this->impl);
		}
	}
}

Subject * subjectNew(void* impl, int type)
{
	Subject* this = (Subject *) malloc(sizeof(*this));

	this->destruir = _destruir;
	this->impl = impl;
	this->type = type;
	this->suscribirObservador = _subscribirObservador;
	this->desuscribirObservador = _desubscribirObservador;
	this->notificarObservador = _notificarObservador;

	return this;
}