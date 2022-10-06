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
float min(float *tab); // déclaration-prototype de la fonction min

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
float max(float *tab); // déclaration-prototype de la fonction max
*/

////////// EXO 4

/*
int euclide(int a, int b)
{
	int t;

	while (b != 0)
	{
		t = b;
		b = a % b;
		a = t;
	}

	return a;
}
int euclide(int a, int b); // déclaration-prototype de la fonction euclide
*/

////////// EXO 5

/*
 unsigned int factoriel(unsigned int n)
{
	 if (n!=1)
	 {
		 n *= factoriel(n - 1);
	 }

	 return n;
}
 unsigned int factoriel(unsigned int n); // déclaration-prototype de la fonction factoriel
 */

 ////////// EXO 6

/*
void inverse(char *ch)
{
	int i;

	printf("L inverse de votre texte est : ");
	for (i = strlen(ch) - 1; i >= 0; i--)
	{
		printf("%c", ch[i]);
	}
}
void inverse(char *ch); // déclaration-prototype de la fonction void inverse
*/

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

	/*
	int a, b, c;

	printf("Rentrer la valeur de a\n");
	scanf("%d", &a);

	printf("Rentrer la valeur de b\n");
	scanf("%d", &b);

	c = euclide(a, b);

	printf("Le PGCD de (a) %d et (b) %d = %d", a, b, c);
	*/

	////////// EXO 5

	/*
	unsigned int n, f;

	printf("Rentrer la valeur de la factorielle que vous souhaitez\n");
	scanf("%u", &n);

	if (n < 0)
	{
		printf("erreur");
	}
	else if (n == 0)
	{
		printf("factoriel de 0 != 1", n);
	}
	else
	{
		f = factoriel(n);
		printf("factoriel de %u != %u", n, f);
	}
	*/

	////////// EXO 6

	/*
	char str[100];

	printf("Rentrer votre chaine texte\n");
	gets_s(str);

	inverse(str);
	*/

	return 0;
}
