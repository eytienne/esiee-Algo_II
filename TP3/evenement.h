#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <time.h>

typedef struct Evenement {
	time_t dateEvenement;
	char *valeurEvenement;
	struct Evenement *previous;
	struct Evenement *next;
} Evenement;

Evenement *newListeEvenement();

int ajouterEvenementListe(Evenement *evts, time_t eventDate, const char *eventValue);

void afficheListeEvenement(const Evenement *evts);

void afficheEvenement(const Evenement *evts, time_t dateEvenement);

void afficheEvenementAutour(const Evenement *evts, time_t dateEvenement, int beforeAfter);

#endif