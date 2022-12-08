#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

using namespace std;

int main(int argc, char ** argv)
{
	/////////////// EXO 1

	/*
	char str[100], rev[100];
	int t = 0, j = 0, i;

	printf("Entrez votre chaine de caractere :\n");
	scanf("%s", &str);

	t = strlen(str);

	rev[t] = '\0';

	for (i = t - 1 ; i >= 0; i--)
	{
		rev[j++] = str[i];
	}

	printf("Le mot inverse de %s est : %s", str, rev);

			for (k = 0; k <= strlen(chaine1) - 1; k++)
		{
			if (chaine1[k] != c)
			{
				v = 1;
			}
		}
	*/

	/////////////// EXO 2

	
	char chaine1[100], c;
	int i, j = 0, k, v;

	printf("Rentrez votre chaine de caracteres :\n");
	gets_s(chaine1);

	printf("Rentrez le caractere que vous cherchez :\n");
	scanf("%c", &c);

	for (i = strlen(chaine1) - 1; i >= 0; i--) //  strlen(chaine1) - 1 car le dernier caractère vaut '\0'
	{

		for (k = 0; k <= strlen(chaine1) - 1; k++)
		{
			if (chaine1[k] != c)
			{
				v = 1;
			}
		
		}

		if (v == 1)
		{
			printf("Le caractere rechercher n est pas present dans la chaine !");
			break;
		}

		j++;

		if (chaine1[i] == c) // Si lettre = lettre occurence
		{
			printf("La premiere occurence de %c se trouve a la position %d a partir de la droite", c, j);
			break;
		}

	}
	

	/////////////// EXO3

	/*
	char chainCharacter[100] = "", tabC[52], cMin, cMaj;
	int i, j = 0, t = 0, a, b, e = 0;

	//printf("Les lettres de l alphabet en minuscule : ");

	for (cMin = 'a'; cMin <= 'z'; cMin++)
	{
		//printf("%c", cMin);
		tabC[t] = cMin;
		t++;
	}

	//printf("\n");

	//printf("Les lettres de l alphabet en majuscule : ");
	for (cMaj = 'A'; cMaj <= 'Z'; cMaj++)
	{
		//printf("%c", cMaj);
		tabC[t] = cMaj;
		t++;
	}

	//printf("\n");

	printf("Mon tableau de l alphabet est : ");
	for (a = 0; a < t; a++)
	{
		printf("%c", tabC[a]);
	}

	printf("\n\nSaisir une chaine de caracteres svp :\n");
	fgets(chainCharacter, 100, stdin);

	for (i = 0; chainCharacter[i] != '\0'; i++)
	{
		for (b = 0; b < t; b++)
		{
			if (chainCharacter[i] == tabC[b])
			{
				j++;
			}
		}

		if (chainCharacter[i] == ' ')
		{
			e++;
		}
	}

	printf("\nLe nombre de lettre de l alphabet est de %d et d espaces dans votre chaine est de %d\n", j, e);
	*/

	/////////////// EXO4

	/*
	char chaine1[100], tMaj[26], cMaj;
	int i, k, c = 0;

	for (cMaj = 'A'; cMaj <= 'Z'; cMaj++)
	{
		tMaj[c] = cMaj;
		c++;
	}

	printf("Rentrez votre chaine de caracteres de 100 caracteres max\n");
	fgets(chaine1, 100, stdin);

	for (i = 0; chaine1[i] != '\0'; i++)
	{
		for (k = 0; k < c; k++)
		{
			if (chaine1[i] == tMaj[k])
			{
				chaine1[i] = tolower(chaine1[i]);
			}
		}
	}

	printf("Votre chaine sans majuscules donne : %s", chaine1);
	*/

	/////////////// EXO5

	/*
	char chaine2[100], res[100];
	int i, j = 0;

	printf("Rentrez votre chaine de caracteres : ");
	fgets(chaine2, 100, stdin);

	for (i = 0; chaine2[i] !='\0'; i++) 
	{
		if (chaine2[i] != ' ')
		{
			res[j] = chaine2[i];
			j++;
		}
	}

	res[j] = '\0';

	printf("Votre chaine sans espaces donne : %s", res);
	*/

	return 0;

	///////////////////////////////////////////////
	/////////// A QUENTIN TOUCHE PAS //////////////
	///////////////////////////////////////////////

}