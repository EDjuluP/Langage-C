#define	_CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//////////// EXO 1

/*
int puissance(int x, int y)
{
	int r_puissance;

	r_puissance = pow(x, y);

	return r_puissance;
}

int puissance(int x, int y); // déclaration-prototype de la fonction puissance

*/

//////////// EXO 2

/*
void affiche(int *t) // on prend la valeur du tableau
{
	int i;

	for (i = 0; i < 10; i++) // lis les 9 cases du tableau
	{
		printf("Position %d = %d\n", i + 1, t[i]);
	}
}

void affiche(int *t); // déclaration-prototype de la fonction affiche

*/

////////// EXO 3

/*

/// MIN
float min(float *tab)
{
	int i;
	float min = tab[0];

	for (i = 0; i < 8; i++)
	{
		if (min > tab[i])
		{
			min = tab[i];
		}
	}

	return min;
}
float min(float *tab); // déclaration-prototype de la fonction affiche min

/// MAX
float max(float *tab)
{
	int i;
	float max = tab[0];

	for (i = 0; i < 8; i++)
	{
		if (max < tab[i])
		{
			max = tab[i];
		}
	}

	return max;
}
float max(float *tab); // déclaration-prototype de la fonction affiche max
*/

////////// EXO 4



int main(int argc, char ** argv)
{
	////////// EXO 1

	/*
	int x, y, xpuissy;

	printf("Rentrez la valeur de x :\n");
	scanf("%d", &x);
	printf("Rentrez la valeur de la puissance s appliquant a x :\n");
	scanf("%d", &y);

	xpuissy = puissance(x, y);

	printf("Ce que donne %d^%d = %d", x, y, xpuissy);
	*/

	////////// EXO 2

	/*
	int tab[100] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

	affiche(tab);
	*/

	////////// EXO 3

	/*
	float liste[8] = { 1.6, -6.9, 9.67, 5.90, 345, -23.6, 78, 34.6 };

	float a = min(liste);
	float b = max(liste);

	printf("Le minimum est %.2f et le maximum est %.2f", a, b);
	*/

	////////// EXO 4

	return 0;
}
