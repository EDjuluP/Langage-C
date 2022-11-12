#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

	*nb = i;

}

void affiche(int * val, int nb)
{
	int i;

	printf("\n");

	for (i = 0; i < nb; i++)
	{
		printf("%d ", val[i]);
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

int main(int argc, char ** argv)
{
	//////// EXO 3 TD 1

	/*
	int tab[20], nb = 0;

	saisie(tab, &nb);
	affiche(tab, nb);
	*/

	//////// EXO 1 TP 1

	/*
	double *adr1, *adr2;

	adr1 = (double*)malloc(sizeof(double)); // alloue case mémoire
	adr2 = (double*)malloc(sizeof(double));

	*adr1 = -45.78; // Pointe sur un réel
	*adr2 = 678.89;

	printf("%p, %p, %f, %f", &adr1, &adr2, *adr1, *adr2);

	free(adr1); // libére case mémoire
	free(adr2);
	*/

	//////// EXO 2 TP 1

	/*
	int *adr_deb, nb = 6, temp;

	adr_deb = (int*)malloc(nb * sizeof(int));

	for (int i = 0; i < 6; i++)
	{
		printf("Saisir un entier : ");
		scanf("%d", &adr_deb[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		if (adr_deb[i+1] < adr_deb[i])
		{
			temp = adr_deb[i];
			adr_deb[i] = adr_deb[i+1];
			adr_deb[i+1] = temp;

		}
	}

	printf("Le Tableau de %d entiers trier donne : ", nb);
	for (int i = 0; i < 6; i++)
	{
		printf("%d", adr_deb[i]);
	}
	printf("\nLe plus grand entier est %d a l indice %d avec comme adresse %p", adr_deb[5], 5, &adr_deb[5]);

	free(adr_deb);
	*/

	//////// EXO 3 TP 1

	/*
	char *ptr = (char*)malloc(1000 * sizeof(char)); // Emplacer mémoire chaine

	printf("Saisir une chaine de caractere : ");
	gets_s(ptr, 1000); // Saisir la chaîne

	for (int i = 0; ptr[i] != '\0'; i++) // Tant que pas dernier caractere
	{
		printf("%c : %p\n", ptr[i], &ptr[i]);
	}

	free(ptr);
	*/

	//////// EXO 4 TP 1

	/*
	int tab1[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };
	int tab2[] = { -19,18,-17,16,-15,14,-13,12,-11,10,-9,8,-7,6,-5,4,-3,2,-1,0 };
	*/

	//////// EXO 5 TP 1

	/*
	float aa, bb, cc;

	saisie(&aa, &bb, &cc);
	calcul(aa, bb, cc);
	*/

	//////////// EXO 1 REVISION SN2

	/*
	int *ptr;
	ptr = 5;
	printf("%d \n", ptr);

	// Adresse
	printf("%d", &ptr);
	*/

	//////////// EXO 2 REVISION SN2

	/*
	float varfloat = 1.7;
	float *stockVar;
	printf("%d", &varfloat);

	stockVar = (float*)malloc(sizeof(float)); // On reserve la place d'un reel
	stockVar = &varfloat; // Affiche l'adresse de A
	printf("\n%d", stockVar);

	*stockVar = varfloat; // Affiche le contenu de A
	printf("\n%.1f", *stockVar);
	*/

	//////////// EXO 3 REVISION SN2

	/*
	int tabint[15] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
	int *tabptr = tabint; // Pointeur sur le tableau
	int i;

	for (i = 0; i < 15; i++)
	{
		if (i % 2 == 0)
		{
			printf("%d ", *(tabptr + i));
		}
	}	
	*/

	///////// SECONDD PROG
	
	/*
	int tabint[15] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
	int *tabptr = tabint;
	int i;

	for (i = 0; i < 15; i++)
	{
		if (i % 2 == 0)
		{
			printf("%d ", *(tabptr));
		}

		tabptr++;
	}
	*/
	
	return 0;
}