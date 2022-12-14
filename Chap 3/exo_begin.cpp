#define	_CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

////////// EXO TIERS

/*
int euclide(int a, int b)
{
	int t = 0;

	while (b != 0)
	{
		t = b;
		b = a % b;
		a = t;

		return a;
	}
}

int euclide(int a, int b); // déclaration-prototype de la fonction euclide

*/

/*
int valeurAbsolue(int x)
{
	int valueAbsolute;

	if (x > 0)
	{
		valueAbsolute = x;
	}
	else if (x == 0)
	{
		valueAbsolute = 0;
	}
	else if (x < 0)
	{
		valueAbsolute = -x;
	}

	return valueAbsolute;
}

int valeurAbsolue(int x); // déclaration-prototype de la fonction valeurAbsolue

*/

/*
unsigned int factoriel(unsigned int a)
{
	if (a != 1)
	{
		a *= factoriel(a - 1);
	}

	return a;
}

unsigned int factoriel(unsigned int a) // déclaration-prototype de la fonction factoriel

*/

int main(int argc, char ** argv)
{
	////////// EXO TIERS

	/*
	int x;

	printf("Rentrez la valeur d'un entier\n");
	scanf("%d", &x);

	printf("La valeur absolue de %d est : |x| = %d.\n", x, valeurAbsolue(x));
	*/

	////////// CORRECTION ERREUR DS

	/*
	int a, b;

	printf("Rentrez la valeur de l'entier a \n");
	scanf("%d", &a);
	printf("Rentrez la valeur de l'entier b \n");
	scanf("%d", &b);

	printf("Le PGCD de %d et %d = %d", a, b, euclide(a, b));
	*/

	/*
	int i = 1, j = 0, taille_pyram;

	printf("Entrez la taille de votre pyramide en lignes svp\n");
	scanf("%d", &taille_pyram);

	/
	for (i = 1; i <= taille_pyram; i++)
	{
		for (j = 0; j < i; j++)
		{
			printf("*");
		}

		printf("\n");
	}
	
	
	while (i <= taille_pyram)
	{
		j = 0;

		while (j < i)
		{
			printf("*");
			j++;
		}

		printf("\n");
		i++;
	}
	*/

	////////////

	/*
	unsigned int f, x;

	printf("entrez une valeur entiere entre 1 et 8:");
	scanf("%d", &x);

	if (x > 8 || x < 1)
	{
		printf("erreur");
	}
	else
	{
		f = factoriel(x);
		printf("factoriel %u egal %u \n", x, f);
	}

	return 0;

	*/

	return 0;
}
