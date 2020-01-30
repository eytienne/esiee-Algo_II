
#ifndef NOTE_H
#define NOTE_H

typedef struct Note {
	long idEleve;
	float valeurNote;
	struct Note *nextNote;
} Note;

Note *newListeNote();

int ajouterNoteListe(Note *notes, long idEleve, float newNote);

void afficheNoteid(const Note *notes, long idEleve);

#endif