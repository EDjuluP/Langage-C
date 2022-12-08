#pragma once

//////// EXO 1 TP 1

/*
typedef struct Fiche1
{
	char nom[10];
	char prenom[10];
	int age;
	float note;
} Fiche1;

//void afficheStruct(Fiche1 * f1);
*/

//////// EXO 2-3 TP 1

/*
typedef struct point
{
	float x, y;
} point;

void saisieStruct2(point * f1);
void afficheStruct2(point * f1);
*/

//////// EXO 4 TP 1

typedef struct /* On définit un type struct */
{
	char nom[100];
	char prenom[100];
	int nbNotes; //permet de stocker le nombre de notes saisies
	float note[50];
	float moyenne;
}
notesSubject;

int getNote(float * note);

void saisir(notesSubject ** students, int * nbEleves);
void afficher(notesSubject * students, int nbEleves);
