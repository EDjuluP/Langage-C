#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

////////// EXO 1

int multipleDeux(int a)
{
	int b;

	b = a % 2;

	return b;
}
int multipleDeux(int a); // D�claration prototype de la fonction multipleDeux

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
int multipleTrois(int a); // D�claration prototype de la fonction multipleTrois

////////// EXO 2

void psswrd(char *pwd, int width)
{
	int i;

	printf("Rentrer votre mdp : ");
	for (i = 0; i < width; i++) {

		pwd[i] = _getch(); // Recupere la saisie dans notre chaine

		if (pwd[i] == 13) // Si entr�e
		{
			break;
		}

		printf("*");
	}

	pwd[i] = '\0'; // D�finis la case actuelle comme la derni�re de notre chaine
}
void psswrd(char *password, int width); // D�claration prototype de la fonction psswrd

////////// EXO 3

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
void transform(char *str); // D�claration prototype de la fonction transform

////////// EXO 4

void lire(int *tab, int taille)
{

}
void lire(int *tab, int taille);

void affiche(int *tab, int taille)
{

}
void affiche(int *tab, int taille);

int indice_min(int *tab, int taille) 
{

}
int indice_min(int *tab, int taille);

void trier(int *tab, int taille)
{

}
void trier(int *tab, int taille);

void affiche(int *tab, int taille)
{

}
void affiche(int *tab, int taille);

int main(int argc, char ** argv)
{
	////////// EXO 1

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

	////////// EXO 2
	
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

	////////// EXO 3

	char str[100];

	printf("Rentrer la chaine que vous souhaitez\n");
	gets_s(str);

	transform(str);

	printf("La chaine modifier donne : %s", str);

	////////// EXO 4

	return 0;
}