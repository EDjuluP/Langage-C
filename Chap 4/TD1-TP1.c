#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

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

	stockVar = &varfloat; // Affiche l'adresse de A
	printf("\n%d", stockVar);

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
	
	///////// EXO1 SUPP
	
	/*
	int a, b;

	printf("Fonction qui swap des valeurs entre deux variable entieres grace a des pointeurs !\n");

	printf("Rentrez la valeur de a : ");
	scanf("%d", &a);

	printf("Rentrez la valeur de b : ");
	scanf("%d", &b);

	printf("\na = %d et b = %d\n", a, b);

	swap(&a, &b);

	printf("Maintenant a = %d et b = %d", a, b);

	*/

	///////// EXO2 SUPP

	/*
	int tab[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int min = 0, max = 0;

	minmax(tab, 10, &min, &max);

	printf("Maximum = %d et Minimum = %d", max, min);
	*/

	///////// EXO3 SUPP

	/*
	char str[50], charResearch = 'A';
	int nbOccurences;

	printf("Saisir une chaine de caractere svp ;)\n");
	fgets(str, 50, stdin);

	nbOccurences = occurence(str, charResearch);
	printf("\nLe nombre d'occurence de A ou a est de %d", nbOccurences);

	*/
	
	//////// EXO 4 SUPP

	char str2[50], *copychar; 

	printf("Saisir une chaine de caracteres svp ;)\n");
	fgets(str2, 50, stdin);

	copy(str2, &copychar);

	printf("%s", copychar);
 
	return 0;
}