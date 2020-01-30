#include "note.h"
#include <stdio.h>
#include <stdlib.h>

Note *newListeNote() {
	Note *newNote = (Note *)malloc(sizeof(Note));
	newNote->nextNote = NULL;
	return newNote;
}

int ajouterNoteListe(Note *notes, long idEleve, float noteValue) {
	Note *newNote = newListeNote();
	if (newNote == NULL)
		return -1;
	newNote->idEleve = idEleve;
	newNote->valeurNote = noteValue;
	newNote->nextNote = notes->nextNote;
	notes->nextNote = newNote;
	return 0;
}

void afficheNoteid(const Note *notes, long idEleve) {
	while (notes != NULL) {
		if (notes->idEleve == idEleve) {
			printf("Note de l'élève n° %ld : %f\n", idEleve, notes->valeurNote);
			return;
		}
		notes = notes->nextNote;
	}
}