#include "note.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	Note *notes = newListeNote();
	assert(notes != NULL);
	assert(notes->nextNote == NULL);

	ajouterNoteListe(notes, 1, 13);
	assert(notes->nextNote->idEleve == 1);
	assert(notes->nextNote->valeurNote == 13);

	ajouterNoteListe(notes, 2, 20);
	assert(notes->nextNote->idEleve == 2);
	assert(notes->nextNote->valeurNote == 20);

    afficheNoteid(notes, 1);

	return 0;
}
