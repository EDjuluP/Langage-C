#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "functions.h"

//////// EXO 3 TD 1

/*
void saisie(int * val, int *nb)
{
	int i;

	for (i = 0; i < 20; i++)
	{
		printf("Veuillez saisir une valeur superieur a 0 ou bien 0 pour stopper cette saisi : ");
		scanf("%d", &val[i]);

		if (val[i] == 0)
		{
			break;
		}
	}

	if (i == 20)
	{
		val[i-1] = 0;
	}

	*nb = i;
}

void affiche(int * val, int nb)
{
	int i;

	printf("\n");

	if (nb == 20)
	{
		for (i = 0; i < nb; i++)
		{
			printf("%d ", val[i]);
		}
	}
	else
	{
		for (i = 0; i < nb + 1; i++)
		{
			printf("%d ", val[i]);
		}
	}

	printf("\nLe nombre de valeurs qui ont etaient saisi est de : %d", i);
}
*/

//////// EXO 4 TP 1

/*
void affiche(int *tab, int i, int j) // Affichage i = lignes et j = colonnes
{

}
*/

//////// EXO 5 TP 1

/*
void saisie(float *aa, float *bb, float *cc)
{
	printf("Saisir a : ");
	scanf("%f", &aa);

	printf("Saisir b : ");
	scanf("%f", &bb);

	printf("Saisir a : ");
	scanf("%f", &cc);
}

float *calcul(float aa, float bb, float cc)
{
	float delta = (bb*bb) - 4 * aa * cc;

	int nbSolutions = 0; // De base

	if (delta == 0) // Si delta = 0
	{
		nbSolutions = 1;
		float x = - bb / 2 * aa ;

	}
	else if (delta > 0) // Si delta est supérieur 0
	{
		nbSolutions = 2;

		float x1 = -bb - sqrt(delta) / 2 * aa;
		float x2 = -bb + sqrt(delta) / 2 * aa;
	}
}
*/

//////// EXO 1 SUPP

/*
int swap(int *a, int *b)
{
	int temp = *b;

	*b = *a;
	*a = temp;

	return 0;
}
*/

//////// EXO 2 SUPP

/*
int minmax(int *tab, int width, int *min, int *max)
{
	for (int i = 0; i < width; i++)
	{
		if (*min > tab[i])
		{
			*min = tab[i];
		}
		else if (*max < tab[i])
		{
			*max = tab[i];
		}
	}

	return 0;
}
*/

//////// EXO 3 SUPP

/*
int occurence(char *chaine, char charResearch)
{

	int nbOccurences = 0;

	for (int i = 0; chaine[i] != '\0'; i++)
	{
		if (chaine[i] == charResearch || chaine[i] == towlower(charResearch))
		{
			nbOccurences++;
		}
	}

	return nbOccurences;
}
*/

//////// EXO 4 SUPP

void copy(char * ch1, char ** ch2)
{
	*ch2 = (char*)malloc(strlen(ch1) * sizeof(char));

	strcpy(*ch2, ch1);
}