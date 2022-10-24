#define _CRT_SECURE_NO_WARNINGS

typedef char string[1024];

#include <stdio.h>
#include <string.h>

using namespace std;

int main(int argc, char ** argv)
{
	/////////////// EXO 1

	
	float a, b, produit = 0;
	int i;

	printf("Veuillez rentrez deux nombres, afin d'avoir le produits d'eux m�me\n");
	scanf("%f%f", &a, &b);

	for (i = 1; i <= a; i++)
	{
		produit += b;
	}

	printf("Le produit des deux nombres que vous avez saisi est : %f", produit);
	

	/////////////// EXO 2
	
	
	int a, b, c;

	printf("Veuillez entrer 3 nombres entiers svp \n");
	scanf("%d%d%d", &a, &b, &c);

	// For a is the minimum
	if (a < b && a < c && b < c)
	{
		printf("%d < %d < %d", a, b, c);
	}
	else if (a < b && a < c && c < b)
	{
		printf("%d < %d < %d", a, c, b);
	}

	// For b is the minimum
	if (b < a && b < c && a < c)
	{
		printf("%d < %d < %d", b, a, c);
	}
	else if (b < a && b < c && c < a)
	{
		printf("%d < %d < %d", b, c, a);
	}

	// For c is the minimum
	if (c < a && c < b && a < b)
	{
		printf("%d < %d < %d", c, a, b);
	}
	else if (c < a && c < b && b < a)
	{
		printf("%d < %d < %d", c, b, a);
	}
	

	/////////////// EXO 3

	
	float price = 0;
	int weight;

	printf("Veuillez entrer le poids de votre lettre afin de savoir le tarif\n");
	scanf("%d", &weight);

	if (weight < 20)
	{
		price = 3.00;
	}
	else if (weight >= 20 && weight < 50)
	{
		price = 3.95;
	}
	else if (weight >= 50)
	{
		price = 5.90;
	}

	printf("Le tarif que vous aurez a paye sera de %.2f francs-suisse.", price);
	

	/////////////// EXO 4

	
	string x, sexe, fastFood, sport, sportName;
	int age, nbCine, nbFastFood;

	printf("Voulez vous faire le questionnaire ?\n");
	scanf("%s", &x);

	while (strcmp(x, "oui") == 0 || strcmp(x, "Oui") == 0)
	{
		printf("\nVotre age\n");
		scanf("%d", &age);

		printf("\nVotre sexe\n");
		scanf("%s", &sexe);

		printf("\nLe nombre de fois ou vous allez au cinema par mois\n");
		scanf("%d", &nbCine);

		printf("\nVous preferez quick ou macdo ?\n");
		scanf("%s", &fastFood);

		if (strcmp(fastFood, "quick") == 0 || strcmp(fastFood, "Quick") == 0)
		{
			printf("\nLe nombre de fois ou vous y allez par mois ?\n");
			scanf("%d", &nbFastFood);
		}
		else if (strcmp(fastFood, "macdo") == 0 || strcmp(fastFood, "Macdo") == 0)
		{
			printf("\nLe nombre de fois ou vous y allez par mois ?\n");
			scanf("%d", &nbFastFood);
		}

		printf("\nPratiquez vous un sport ?\n");
		scanf("%s", &sport);

		if (strcmp(sport, "oui") == 0 || strcmp(sport, "Oui") == 0)
		{
			printf("\nUn sport parmi : foot, tennis, basket, judo, natation ?\n");
			scanf("%s", &sportName);

		}
		else if (strcmp(sport, "non") == 0 || strcmp(sport, "non") == 0)
		{
			 string sportName = "non";
		}

		printf("\nVotre age : %d\nVotre sexe : %s\nLe nombre de fois que vous allez au cine par mois : %d\nVotre fast food preferez : %s\nLe nombre de fois que vous y allez par mois : %d\nPratique de sport : %s, parmi (foot, tennis, basket, judo, natation) : %s\n", age, sexe, nbCine, fastFood, nbFastFood, sport, sportName);

		printf("Voulez vous refaire le questionnaire ?\n");
		scanf("%s", &x);
	}
	

	/////////////// EXO 5

	int x, i, j, again = 1, resultat;

	while (again == 1) 
	{
		printf("Rentrez une valeur de x comprise entre 2 et 10\n");
		scanf("%d", &x);

		while (x < 2 || x > 30) 
		{
			printf("Rentrez une valeur de x comprise entre 2 et 10\n");
			scanf("%d", &x);
		}

		printf("\t|");

		for (i = 1; i <= x; i++) 
		{
			printf("%3d ", i);
		}

		printf("\n-------------------------------------------------------\n");

		for (i = 1; i <= x; i++) {
			printf("%d	|", i);

			for (j = 1; j <= x; j++) {
				resultat = i * j;
				printf("%3d ", resultat);
			}
			
			printf("\n");
		}
		
		printf("\nVous vous recommencez ? (1 = oui et 0 = non)\n");
		scanf("%d", &again);
	}
}