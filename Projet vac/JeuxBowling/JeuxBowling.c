///////////// BY POLLET Quentin ///////////
//////////// Student at La Providence in Amiens (France)/////////
//////////// Last Release Date : 23/12/2022 - 21:59 /////////

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "functions.h"

int main(int argc, char ** argv)
{
	Bowling * Joueurs = NULL;

	printf("Bienvenue au bowling de biribi !\n\n");
	Sleep(3000);

	int nbSaisi; // Pour choisir de rejouer ou de quitter

	do
	{
		// On va faire notre choix
		int nbChoix;

		printf("1 - Lancer la partie de bowling\n");
		printf("2 - Voir les regles du bowling\n");

		printf("\nVotre choix : ");
		scanf("%d", &nbChoix);

		while (nbChoix != 1 && nbChoix != 2)
		{
			printf("\nVotre choix (1 ou 2 SVP !!) : ");
			scanf("%d", &nbChoix);
		}

		if (nbChoix == 1) // Si il décide de jouer
		{
			system("CLS");

			// Alors on va lancer la saisie des Joueurs
			int nbJoueur = saisirNomJoueurs(&Joueurs);

			// Ensuite on lancer la partie de bowling
			initializeGame(&Joueurs, nbJoueur);
		}
		else if (nbChoix == 2) // Infos par rapport au jeu du bowling
		{
			system("CLS");

			printf("Voici les differentes informations sur le bowling !\n\n");

			printf("Chaque partie comprend 10 jeux ou frames. Les participants jouent chacun leur tour. Le joueur lance\n");
			printf("au maximum 2 boules a chaque jeu et marque le nombre de points correspondant au nombre de\n");
			printf("quilles tombees.\n\n");

			printf("Si les 10 quilles tombent en deux lancers, le joueur a fait un spare; il marque 10 points plus les points\n");
			printf("du lancer suivant. Si les 10 quilles tombent au premier lancer, le joueur a fait un strike; Il marque 10\n");
			printf("points plus les points des 2 lances suivants. Au dixieme jeu, si le joueur realise un spare ou un strike, il\n");
			printf("beneficie de 1 ou 2 lancer(s) supplementaire(s).\n\n");

			printf("Compte tenu de ces bonifications, le maximum de points par partie est de 300.\n");

			Sleep(3000);
		}

		nbSaisi = 0;
		
		printf("\n\nVoulez vous revenir au pupitre ou partir ? (1 ou 0) : ");
		scanf("%d", &nbSaisi);

		while (nbSaisi != 0 && nbSaisi != 1)
		{
			printf("\nVoulez vous revenir au pupitre ou partir ? (0 ou 1 SVP !!) : ");
			scanf("%d", &nbSaisi);
		}

		if (nbSaisi == 1) // Si il décide de refaire une partie
		{
			Joueurs = NULL; // On va remettre la liste des joueurs à 0
			system("CLS");
		}
		else // Sinon si il quitte
		{
			free(Joueurs); // On supprimer notre liste de joueurs
		}
		
	} while(nbSaisi != 0);
}

///////////// BY POLLET Quentin ///////////
//////////// Student at La Providence in Amiens (France)/////////
//////////// Last Release Date : 23/12/2022 - 21:59 /////////