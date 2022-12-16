#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "functions.h"

int main(int argc, char ** argv)
{
	Players * joueursDes = NULL; // Tableau de joueurs

	printf("------- Bienvenue au jeu des 10000 ! -------\n\n");
	Sleep(3000);

	int nbAgain;

	do
	{
		system("CLS");

		// On fait notre choix
		int nbSaisi;
		printf("Choissisez votre choix en entrant un des chiffres suivant :\n\n");

		printf("1 - Lancer le jeu des 10000\n");
		printf("2 - Voir les regles du jeu des 10000\n");

		printf("\nVotre choix : ");
		scanf("%d", &nbSaisi);

		// Selon notre choix on fait
		if (nbSaisi == 1)
		{
			system("CLS");

			// Saisi Joueur et r�cup�ration du nombre de joueurs
			int nbJoueur = saisieNomsJoueurs(&joueursDes);

			// On va lancer le jeu et jouer
			Jeu(&joueursDes, nbJoueur);

			// On supprime le tableau joueurs
			free(joueursDes);
		}
		else if (nbSaisi == 2) // Affichage des r�gles et but du jeu
		{
			system("CLS");

			printf("Voici les regles du jeu des 10000 !\n\n");
		}

		nbAgain = 0;
		printf("\nVoulez-vous revenir au menu ou bien quitter ?  (Oui = 1 et Non = 0) : ");
		scanf("%d", &nbAgain);

		printf("\n\n");

	} while (nbAgain != 0);
}