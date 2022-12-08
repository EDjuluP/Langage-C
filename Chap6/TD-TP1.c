#define _CRT_SECURE_NO_WARNINGS

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char ** argv)
{
	//////// EXO 1 TP 1

	/*
	Fiche1 f1;

	strcpy(f1.nom, "DUPONT");
	strcpy(f1.prenom, "JEAN");
	f1.age = 20;
	f1.note = 11.5;

	afficheStruct(&f1);
	*/

	//////// EXO 2-3 TP 1

	/*
	point coordonnees1[15];

	saisieStruct2(coordonnees1);
	afficheStruct2(coordonnees1);
	*/

	//////// EXO 4 TP 1

	notesSubject * carnetNotes = NULL; //Tableau de notes
	int nbEnter, nbEleves = 0;
	char caract;

	printf("Bievenue sur votre carnet de notes M.GREMONT !\n\n");
	printf("Appuyez sur 1 pour commencer la saisie des notes :) : ");
	scanf("%c", &caract);

	if (caract=='1')
	{	
		system("CLS");
		saisir(&carnetNotes, &nbEleves);
		afficher(carnetNotes, nbEleves);
	}

	return 0;
}