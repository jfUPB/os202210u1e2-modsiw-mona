#ifndef MAIL_H
  #define MAIL_H
  #include <stdio.h>
  #include <stdlib.h>
  #include "../../observer/observer.h"
  #include "../../observer/subject.h"

  typedef enum __mail_event
  {
    NOTICIANUEVA
  } MailEvent;  //triggerea un evento para notificar a la lista de observadores

  typedef struct __mail
  {
    char* titulo;
    void (*destruir)(struct __mail*);

    MailEvent event;
    MailEvent (*getEvento)(struct __mail*);

    void (*noticiaNueva)(struct __mail*);

    Subject * subject;
    int (*suscribirObservador)(struct __mail*, Observer*);
    int (*desuscribirObservador)(struct __mail *, Observer*);
  } Mail;

  Mail* CrearMail(char *);

#endif