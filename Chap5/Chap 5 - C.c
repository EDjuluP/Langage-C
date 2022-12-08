#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

int main(int argc, char ** argv)
{
	FILE * fichier1 = NULL;
	fichier1 = fopen("source.txt", "a+");

	FILE * fichier2 = NULL;
	fichier2 = fopen("dest1.txt", "a+");

	FILE * fichier3 = NULL;
	fichier3 = fopen("dest2.txt", "a+");

	if (fichier1 != NULL)
	{
		// WRITE OR READ FILE

		/*
		fputc('A', fichier); // Écriture du caractère A - vaut 1 bytes
		_putw(70, fichier); // ASCII (F) - vaut 4 bytes

		fputs("\nSalut les développeurs du bled\nBienvenue !", fichier);
	
		char str[50];
		printf("Rentrez votre nom et prenom\n");
		gets_s(str, 50);

		int i = 0;
		// fseek(fichier, 2, SEEK_SET); // Back to begin of file

		fputc('A', fichier); // Écriture du caractère A
		fprintf(fichier," Je m'appelle %s numero : %d", str, i+1); // Write in file

		int longueur = ftell(fichier); // Longueur du fichier en octets
		printf("%d", longueur);

		char * ptr;
		unsigned size;
		int n;

		fread(ptr, size, n, fichier); // Lit le nombres n d'information lues avec une taille size 
		fwrite(ptr, size, n, fichier); // Lit le nombres n d'informations

		//remove("test.txt"); // Remove file

		//rename("test.txt", "test2.txt"); // Rename file

		// void rewind(FILE * fichier); // Back to begin of file

		*/

		////////// EXO 0 TP 1

		//fputs("Salut les développeurs du bled, Bienvenue !", fichier);

		////////// EXO 1 TP 1

		/*
		fichier =  fopen("test.txt", "a+");

		char c;

		do
		{ 
			c = getc(fichier);
			printf("%c", c);

		} while ( c != EOF);

		fclose(fichier);

		*/

		////////// EXO 2 TP 1

		/*
		FILE * fichier1 = NULL;
		fichier1 = fopen("source.txt", "r");

		FILE * fichier2 = NULL;
		fichier2 = fopen("dest1.txt", "w");

		char c;

		do
		{
			c = getc(fichier1);
			putc(c, fichier2);

			if (c != EOF)
			{
				putc(c, fichier2);
			}

		} while (c != EOF);

		fclose(fichier2);
		*/

		////////// EXO 3 TP 1

		/*
		char c;

		do
		{
			c = getc(fichier1);

			if (c != 'a' && c != EOF)
			{
				putc(c, fichier2);
			}

		} while (c != EOF);


		fclose(fichier2);

		*/

		////////// EXO 4 TP 1

		int tailleFile = 0;

		tailleFile = tailleFichier(fichier1);
		printf("Taille fichier 1 : %d octets\n", tailleFile);
		fclose(fichier1);


		tailleFile = tailleFichier(fichier2);
		printf("\nTaille fichier 2 : %d octets\n", tailleFile);
		fclose(fichier2);


		tailleFile = tailleFichier(fichier3);
		printf("Taille fichier 3 : %d octets\n", tailleFile);
		fclose(fichier3);
		

		////////// EXO 1 SUPP

		/*
		fichier1 = fopen("exosupp2.txt", "r");
		alphabet(fichier1);
		*/

		////////// EXO 2 SUPP
		
		/*
		fichier1 = fopen("exosupp2.txt", "r");
		afficherContenu(fichier1);
		*/

		////////// EXO 3 SUPP

		/*
		int tabEntier[100];

		int tailleTab = lireDonnees(fichier1, tabEntier);

		afficherTableau(tabEntier, tailleTab);
		triABulles(tabEntier, tailleTab);

		printf("\nTableau trier : ");
		for (int i = 0; i < tailleTab; i++)
		{
			printf("%d", tabEntier[i]);
		}

		enregistrerDonnees(fichier2, tabEntier, tailleTab);
		*/

	}
	else
	{
		// ERROR
		printf("Impossible d'ouvrir le fichier test.txt");
	}

	return 0;
}