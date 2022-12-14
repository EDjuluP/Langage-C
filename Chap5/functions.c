#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

////////// EXO 4 TP 1


int tailleFichier(FILE * fichier) 
{
	int taille = 0;

	fseek(fichier, 0L, SEEK_END);
	taille = ftell(fichier); // Longueur du fichier en octets

	return taille;
}


////////// EXO 1 SUPP

/*
void alphabet(FILE * fichier)
{
	char c;

	fputs("Minuscule : ", fichier);
	for (c = 'a'; c <= 'z'; c++)
	{
		putc(c, fichier);
	}

	fputs("\nMajuscule : ", fichier);
	for (c = 'A'; c <= 'Z'; c++)
	{
		putc(c, fichier);
	}
}
*/

////////// EXO 2 SUPP

/*
void afficherContenu(FILE * file)
{
	char c;

	do
	{
		c = getc(file);
		printf("%c", c);

	} while (c != EOF);

}
*/

////////// EXO 3 SUPP

int lireDonnees(FILE * file, int *tab)
{
	int nbentiers = 0;

	//int myInt;
	char c;

	do
	{
		c = getc(file);

		int n = c - 48; // Conveti char en int

		if (n >= 0 && n <= 9)
		{
			tab[nbentiers] = n;
			nbentiers++; // Ajoute 1 au nb entiers
		}

	} while (c != EOF);

	return nbentiers;
}

void afficherTableau(int * tab, int tailleTab)
{

	
	printf("Tableau non trier : ");
	for (int i = 0; i < tailleTab; i++)
	{
		printf("%d", tab[i]);
	}
	

}

void triABulles(int * tab, int tailleTab)
{
	int temp;

	for (int i = 0; i < tailleTab; i++)
	{
		for (int j = i + 1; j < tailleTab; j++)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
		}
	}

	return tab;
}

void enregistrerDonnees(FILE * file, int * tab, int nb)
{

	fprintf(file, "Le tableau trier : ");
	for (int i = 0; i < nb; i++) 
	{
		fprintf(file, "%d", tab[i]);
	}
}