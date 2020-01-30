#include "evenement.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printEvenement(const Evenement *toPrint);

Evenement *newListeEvenement() {
	Evenement *newEvent = (Evenement *)malloc(sizeof(Evenement));
	newEvent->previous = NULL;
	newEvent->next = NULL;
	return newEvent;
}

int ajouterEvenementListe(Evenement *evts, time_t eventDate,
						  const char *eventValue) {
	Evenement *newEvent = newListeEvenement();
	newEvent->dateEvenement = eventDate;
	strcpy(newEvent->valeurEvenement, eventValue);

	Evenement *whereToAdd = evts;
	while (eventDate < whereToAdd->next->dateEvenement)
		whereToAdd = whereToAdd->next;

	newEvent->previous = whereToAdd;
	newEvent->next = whereToAdd->next;
	whereToAdd->next = newEvent;
}

void afficheListeEvenement(const Evenement *evts) {
	while (evts->next != NULL) {
		Evenement *toPrint = evts->next;

		evts = evts->next;
	}
}

void afficheEvenement(const Evenement *evts, time_t dateEvenement) {
	afficheEvenementAutour(evts, dateEvenement, 0);
}

void afficheEvenementAutour(const Evenement *evts, time_t dateEvenement,
							int beforeAfter) {
	int nbToPrint = beforeAfter * 2 + 1;

	Evenement *toPrint = NULL;
	while (evts->next != NULL) {
		toPrint = evts->next;
		if (toPrint->dateEvenement) {
			printEvenement(toPrint);
			return;
		}
		evts = evts->next;
	}
	if (toPrint != NULL) {
		int i;
		for (i = 0; i < beforeAfter && evts->previous != NULL; i++)
			evts = evts->previous;
		while (evts != toPrint) {
            printEvenement(evts);
            evts = evts->next;
		}
        printEvenement(evts);
        for (int j = 0; j < i; j++)
            printEvenement(evts);
	}
}

void printEvenement(const Evenement *toPrint) {
	printf("[%ld] : %s", toPrint->dateEvenement, toPrint->valeurEvenement);
}