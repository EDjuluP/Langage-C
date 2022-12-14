#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char ** argv)
{
	/////////////// EXO 1

	/*
	int tab1[40];
	int i, t, c, k, o, a, b;

	// Demande à l'user la taille du tableau
	printf("Saisir la taille du tableau (max 40 entier)\n");
	scanf("%d", &t);

	// Saisir les entiers dans le tableau
	printf("\n");
	for (i = 0; i < t; i++)
	{
		printf("Saisir un entier numero %d :\n", i+1);
		scanf("%d", &tab1[i]);

		if (tab1[i] == -1)
		{
			break;
			printf("La sasie est maintenant arreter");
		}
	}

	// Renvoyer ce que contient le tableau
	printf("\nLe tableau renvoie : ");
	for (c = 0; c < t; c++)
	{
		printf("%d ", tab1[c]);
	}

	printf("\ntris en cours ....\n");

	// Tris du tableau dans l'ordre croissant
	for (k = 0; k < t; k++)
	{
		for (a = k+1; a < t; a++)
		{
			if (tab1[k] > tab1[a])
			{
				b = tab1[k];
				tab1[k] = tab1[a];
				tab1[a] = b;
			}
		}
	}

	// Renvoyer ce que contient le tableau après le tris
	printf("\nLe tableau apres le tris renvoie : ");
	for (o = 0; o < t; o++)
	{
		printf("%d  ", tab1[o]);
	}

	printf("\n");
	*/

	/////////////// EXO 2

	/// Méthode choisie : tri par sélection

	// Définition du tableau + Variables
	int tab[20];
	int i, j, a, temp;

	srand(time(NULL)); // Définition séquence pseudo-aléatoire

	// Random des entiers dans le tableau
	for (i = 0; i < 20; i++)
	{
		a = rand();
		tab[i] = a;
	}

	// Tris des entiers random du tableau
	for (i = 0; i < 20; i++)
	{
		for (j = i+1; j < 20; j++)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
		}
	}

	// Affichage du tableau trier
	printf("Le tableau trier donne : ");
	for (i = 0; i < 20; i++)
	{
		printf("%d ", tab[i]);
	}

	///////////////////////////////////////////////
	/////////// A QUENTIN TOUCHE PAS //////////////
	///////////////////////////////////////////////
}