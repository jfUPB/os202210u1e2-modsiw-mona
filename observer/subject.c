#include "subject.h"

static void _destroy(Subject* this)
{
	if (this != NULL) {
		free(this);
		this = NULL;
	}
}

static int _registerObserver(Subject* this, Observer* observer)
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

static int _unregisterObserver(Subject *this, Observer* observer)
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

static void _notifyObservers(Subject* this)
{
	for (int i=0; i < MAX_OBSERVERS; i++) {
		if (this->observers[i] != NULL) {
			this->observers[i]->notify(this->observers[i], this->type, this->impl);
		}
	}
}

Subject * subjectNew(void* impl, int type)
{
	Subject* this = (Subject *) malloc(sizeof(*this));

	this->destroy = _destroy;
	this->impl = impl;
	this->type = type;
	this->registerObserver = _registerObserver;
	this->unregisterObserver = _unregisterObserver;
	this->notifyObservers = _notifyObservers;

	return this;
}