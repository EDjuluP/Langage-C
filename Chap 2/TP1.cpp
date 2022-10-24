#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

using namespace std;

int main(int argc, char ** argv)
{
	/////////////// EXO 1
 
	
	int tab1[10]; // Table with 1 dimension (10 lines)
	int entier, iValue, i, grand, petit; // Variable int

	for (iValue = 0; iValue < 10; iValue++)
	{
		printf("Rentrez un entier \n");
		scanf("%d", &entier);

		tab1[iValue] = entier;
	}

	printf("\nrenvoie des valeurs du tableau : \n\n");

	for (i = 0;  i < 10; i++)
	{
		printf("%d\n", tab1[i]);

		grand = tab1[0];

		if (grand < tab1[i])
		{
			grand = tab1[i];
		}
		
		petit = tab1[0];

		if (petit > tab1[i])
		{
			petit = tab1[i];
		}

	}
	printf("\nLe plus grand nombres entier est : %d et le plus petit est : %d", grand, petit);
	

	/////////////// EXO 2

	
	int t2[10];
	float t3[10];
	int i, count, j = 0, nbTable, nombreTb, stockValue;

	printf("Rentrez le nombre d elements de votre tableau inferieur a 10 et superieur a 0\n");
	scanf("%d", &nbTable);

	while (nbTable < 0 && nbTable > 10)
	{
		printf("Rentrez le nombre d elements de votre tableau inferieur a 10 et superieur a 0\n");
		scanf("%d", &nbTable);
	}

	for (i = 0; i < nbTable; i++)
	{
		printf("Rentrez un nombre\n");
		scanf("%d", &nombreTb);

		t2[i] = nombreTb;

		if (t2[i] > 0)
		{
			t3[j] = t2[i];
			j++;
		}
	}

	printf("\n");

	for (count = 0; count < nbTable; count++)
	{
		printf("%.f | ", t3[count]);
	}
	

	/////////////// EXO 3
	
	float t[10];
	float sommeElements = 0, nombre = 0;
	int i, count, nbTable;

	printf("Rentrez le nombre d elements de votre tableau\n");
	scanf("%d", &nbTable);

	for (i = 0; i < nbTable; i++) 
	{
		printf("Rentrez une valeur\n");
		scanf("%f", &nombre);

		t[i] = nombre;
	}

	for (count = 0; count < nbTable; count++)
	{
		sommeElements += t[count];
	}
	printf("La somme des elements du tableau est = %.1f", sommeElements);
	
}