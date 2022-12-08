#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

////////// EXO 1

/*
int multipleDeux(int a)
{
	int b;

	b = a % 2;

	return b;
}
int multipleDeux(int a); // Déclaration prototype de la fonction multipleDeux

int multipleTrois(int a)
{	
	int b;
	
	if (a % 3 == 0 && a % 6 == 0)
	{
		b = 1;
	}
	else if (a % 3 == 0)
	{
		b = 2;
	}
	else if (a % 6 == 0)
	{
		b = 3;
	}
	else
	{
		b = NULL;
	}

	return b;
}
int multipleTrois(int a); // Déclaration prototype de la fonction multipleTrois
*/

////////// EXO 2

/*
void psswrd(char *pwd, int width)
{
	int i;

	printf("Rentrer votre mdp : ");
	for (i = 0; i < width; i++) {

		pwd[i] = _getch(); // Recupere la saisie dans notre chaine

		if (pwd[i] == 13) // Si entrée
		{
			break;
		}

		printf("*");
	}

	pwd[i] = '\0'; // Définis la case actuelle comme la dernière de notre chaine
}
void psswrd(char *password, int width); // Déclaration prototype de la fonction psswrd
*/

////////// EXO 3

/*
void transform(char *str)
{
	int i, k = 0;
	char minuscule[26], c;

	for (c = 'a'; c <= 'z'; c++)
	{
		minuscule[k] = c;
		k++;
	}


	for (i = 0; str[i] != '\0'; i++)
	{
		for (k = 0; minuscule[k] != '\0'; k++)
		{
			if (str[i] == minuscule[k])
			{
				str[i] = toupper(str[i]);
			}
		}
	}

}
void transform(char *str); // Déclaration prototype de la fonction transform
*/

////////// EXO 4

void lire(int *tab, int width)
{
	int i;

	for (i = 0; i < width; i++)
	{
		printf("Valeur de la case %d : ", i + 1);
		scanf("%d", &tab[i]);
	}
}
void lire(int *tab, int width);

int indice_min(int *tab, int width)
{
	int i;
	int min = tab[0];

	for (i = 0; i < width; i++)
	{
		if (min > tab[i])
		{
			min = tab[i];
		}
	}

	return min;
}
int indice_min(int *tab, int width);

void trier(int *tab, int width, int indice_min)
{
	int i, j, temp;
	indice_min = tab[0];

	for (i = 0; i < width; i++)
	{
		for (j = i + 1; j < width; j++)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
		}
	}
}
void trier(int *tab, int width, int indice_min);

void affiche(int *tab, int width)
{
	int i;

	for (i = 0; i < width; i++)
	{
		printf("%d ", tab[i]);
	}
}
void affiche(int *tab, int width);

int main(int argc, char ** argv)
{
	////////// EXO 1

	/*
	int nbEntier;

	printf("Veuillez rentrer un nombre entier\n");
	scanf("%d", &nbEntier);


	if (multipleDeux(nbEntier) == 0)
	{
		printf("Le nombre %d est pair", nbEntier);
	}

	printf("\n");

	if (multipleTrois(nbEntier) == 1)
	{
		printf("Le nombre %d est multiple de 3 et de 6", nbEntier);
	}
	else if (multipleTrois(nbEntier) == 2)
	{
		printf("Le nombre %d est multiple de 3", nbEntier);
	}
	else if (multipleTrois(nbEntier) == 3)
	{
		printf("Le nombre %d est multiple de 6", nbEntier);
	}
	else
	{
		printf("Le nombre %d n'est ni multiple de 3 et 6", nbEntier);
	}
	*/

	////////// EXO 2
	
	/*
	char pwd[30];
	int i, width;

	printf("Rentrer le nombre de caracteres de votre mot de passe : ");
	scanf("%d", &width); // Taille du pwd

	psswrd(pwd, width);

	printf("\nVotre mot de passe est : ");
	for (i = 0; pwd[i] != '\0'; i++)
	{
		printf("%c", pwd[i]); // Renvoie le mdp
	}
	*/

	////////// EXO 3

	/*
	char str[100];

	printf("Rentrer la chaine que vous souhaitez\n");
	gets_s(str);

	transform(str);

	printf("La chaine modifier donne : %s", str);
	*/

	////////// EXO 4

	int tab[20], width, min;

	printf("Rentrer le nombres d elements du tableau (max 20 et entier)\n");
	scanf("%d", &width);

	while (width > 20)
	{
		printf("ERREUR : Nombres d elements du tableau (max 20 et entier)\n");
		scanf("%d", &width);
	}

	lire(tab, width);
	printf("\nLes valeurs du tableau on etait saisis !\n");

	min = indice_min(tab, width);
	printf("La valeur minimum du tableau est : %d\n", min);

	trier(tab, width, min);

	printf("Le tableau trier donne : ");
	affiche(tab, width);

	return 0;
}