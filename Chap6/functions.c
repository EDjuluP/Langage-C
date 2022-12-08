#define _CRT_SECURE_NO_WARNINGS

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//////// EXO 1 TP 1

/*
void afficheStruct(Fiche1 * f1)
{

	printf("Nom : %s\n", f1->nom);
	printf("Prenom : %s\n", f1->prenom);
	printf("Age : %d ans\n", f1->age);
	printf("Note : %.1f de moyenne\n", f1->note);
}
*/

//////// EXO 2-3 TP 1

/*s
void saisieStruct2(point * f1)
{
	for (int i = 0; i < 15; i++)
	{
		printf("X :");
		scanf("%f", &f1[i].x);

		printf("Y :");
		scanf("%f", &f1[i].y);
	}
}

void afficheStruct2(point * f1)
{
	for (int i = 0; i < 15; i++)
	{
		printf("X : %.1f\n", f1[i].x);
		printf("Y : %.1f\n", f1[i].y);
	}
}
*/

//////// EXO 4 TP 1

int getNote(float * note)
{
	printf("Entrez une note : ");
	scanf("%f", note);

	return *note >= 0 && *note <= 20;
}

void saisir(notesSubject ** students, int * nbEleves)
{

	int nbSaisi;
	float note;
	char nom[100];
	char prenom[100];

	printf("\n\nDebut de la saisie des notes !\n\n");

	do
	{
		printf("Entrez un nom : ");
		scanf("%s", nom);

		printf("Entrez un prenom : ");
		scanf("%s", prenom);

		int elevepresent = 0;
		int indexEleve = -1;

		for (int i = 0; i < (*nbEleves); i++)
		{
			if (strcmp(nom, (*students)[i].nom) == 0 && strcmp(prenom, (*students)[i].prenom) == 0)
			{
				elevepresent = 1;
				indexEleve = i;
				break;
			}
		}

		if (elevepresent == 1)
		{
			if (getNote(&note) == 1)
			{
				(*students)[indexEleve].note[(*students)[indexEleve].nbNotes] = note;
				(*students)[indexEleve].nbNotes++; // On ajoute 1 au nb de notes

				(*students)[indexEleve].moyenne += note;
			}
		}
		else
		{
			notesSubject * oldMem = (*students);

			(*nbEleves)++;

			(*students) = malloc(*nbEleves * sizeof(notesSubject));
			if (oldMem != NULL)
			{
				memcpy((*students), oldMem, (*nbEleves - 1) * sizeof(notesSubject));
				free(oldMem);
			}

			strcpy((*students)[(*nbEleves) - 1].nom, nom);
			strcpy((*students)[(*nbEleves) - 1].prenom, prenom);
			(*students)[(*nbEleves) - 1].nbNotes = 0;

			if (getNote(&note) == 1)
			{
				(*students)[(*nbEleves) - 1].note[(*students)[(*nbEleves) - 1].nbNotes] = note;
				(*students)[(*nbEleves) - 1].nbNotes++; // On ajoute 1 au nb de notes

				(*students)[(*nbEleves) - 1].moyenne = note;
			}
		}

		printf("Voulez-vous continuer ? (Oui = 1, Non = 0) : ");
		scanf("%d",	&nbSaisi);
		system("CLS");

	} while (nbSaisi != 0);

}

void afficher(notesSubject * students, int nbEleves)
{
	float moyenne = 0;

	for (int i = 0; i < nbEleves; i++)
	{
		printf("Nom : %s\n", students[i].nom);
		printf("Prenom : %s\n", students[i].prenom);

		// Le but savoir le taille du tableau du nombres de notes
		// Donc la récupérer

		printf("Note : ");
		for (int j = 0; j < students[i].nbNotes; j++)
		{
			printf("%.2f ", students[i].note[j]);
		}
		moyenne = students[i].moyenne / students[i].nbNotes;

		printf("\nMoyenne : %.2f\n\n", moyenne);

		moyenne = 0;
	}
}
