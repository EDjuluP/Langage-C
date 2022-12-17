///////////// BY POLLET Quentin ///////////
//////////// Student at La Providence in Amiens (France)/////////
//////////// Last Release Date : 17/12/2022 - 12:22 AM /////////

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

		// Si le choix est différent de 1 et 2
		while (nbSaisi != 1 && nbSaisi != 2)
		{
			printf("\nVotre choix (1 ou 2 SVP) : ");
			scanf("%d", &nbSaisi);
		}

		// Selon notre choix on
		if (nbSaisi == 1) // Lance la partie
		{
			system("CLS");

			// Saisi Joueur et recuperation du nombre de joueurs
			int nbJoueur = saisieNomsJoueurs(&joueursDes);

			// On va lancer le jeu et jouer
			Jeu(&joueursDes, nbJoueur);
		}
		else if (nbSaisi == 2) // Affichage les infos concernant le jeu
		{
			system("CLS");
			printf("Voici les regles du jeu des 10000 !\n\n");

			// Nombre de joueurs min - max
			printf("Nombre de des : 6\n\n");

			// Nombre de joueurs min - max
			printf("Nombre de joueurs : de 2 a 6 \n\n");

			// Regle du jeu et le but
			printf("Regle du jeu :\n\n");
			printf("Lorsque un joueur atteint ou depasse 10 000 points, il est considere comme\n");
			printf("temporairement gagnant mais on fini le tour pour permettre a un autre joueur de\n");
			printf("surpasser ce score.\n\n");

			printf("On lance les des d un coup. On additionne les points de chaque lancer.\n\n");

			printf("Si on ne fait aucun point lors d un lancer des des, on ne marque aucun point, on\n");
			printf("perd meme 1000 points a 6 des.Cependant, on ne peut devenir negatif et on\n");
			printf("descend a 0.\n\n");

			// Baréme (Combinaison ou valeur de dé en points)
			printf("Bareme :\n\n");

			printf("   Combinaison   |  Nombre de points\n");
			printf("ou valeur de de  |\n");
			printf("	1	 |	100\n");
			printf("	5	 |	50\n");
			printf("      3 des	 |  100 * la valeur du de\n");
			printf("    identiques	 |\n");
			printf("      1+1+1	 |  1000\n");
			printf("      6 des	 |  1000 * la valeur du de\n");
			printf("    identiques	 |\n");
			printf("   1+1+1+1+1+1	 |  Partie gagnee\n");

			Sleep(3000);
		}

		nbAgain = 0;
		printf("\nVoulez-vous revenir au menu ou bien quitter ?  (Oui = 1 et Non = 0) : ");
		scanf("%d", &nbAgain);

		// Si c'est différent de 1 et de 0
		while (nbAgain != 0 && nbAgain != 1)
		{
			printf("\nVoulez-vous revenir au menu ou bien quitter (1-0 SVP) ? (Oui = 1 et Non = 0) : ");
			scanf("%d", &nbAgain);
		}

		if (nbAgain == 1) // Si il veut revenir en arrière
		{
			joueursDes = NULL; // On remet notre tableau vierge
		}
		else // Sinon on arrête le programme
		{
			// On supprime le tableau joueurs
			free(joueursDes);
		}

		printf("\n\n");

	} while (nbAgain != 0); // Tant que le joueur veux rester dans l'espace du jeu
}

///////////// BY POLLET Quentin ///////////
//////////// Student at La Providence in Amiens (France)/////////
//////////// Last Release Date : 17/12/2022 - 12:22 AM /////////