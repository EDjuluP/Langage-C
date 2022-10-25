#define _CRT_SECURE_NO_WARNINGS

#include "tictactoewindow.h"
#include "tictactoehelper.h"

#include <stdio.h>

int main(int argc, char ** argv)
{
	int grille[9];
	int again, nbStart, positionX, positionY;

	printf("Bienvenu au jeu du morpion - OXO (Version console)\n\n");

	do
	{
		printf("Choissisez une des options suivantes :\n");
		printf("1 - Jouer contre un ami ?\n2 - Jouer contre une IA ?\n3 - En savoir plus sur le morpion ?\n\n");

		scanf("%d", &nbStart); // Wait user tap number

		int index, win = 0, null = 0;

		if (nbStart == 1) // Equivalent number 1
		{
			printf("Vous avez choisi 1 !\n\n");

			initializeGameState(grille); // Initialize grid

			char player1 = 'X', player2 = 'O'; // Symbol player 1 and 2
			printf("Le Joueur 1 aura le symbole X et le joueur 2 le symbole O\n\n");

			do
			{
				int nbPlayer = 1; // Player 1

				// Show grid before turn Player 1
				for (int i = 0; i < 9; i++)
				{
					if (grille[i] == 0)
					{
						printf("- ");
					}
					else if (grille[i] == 1)
					{
						printf("X ");
					}
					else if (grille[i] == -1)
					{
						printf("O ");
					}

					if (i == 2 || i == 5 || i == 8)
					{
						printf("\n");
					}
				}

				printf("\nTour actuel : Joueur 1\n\nRAPPEL : X = la colonne (donc 0 a 2 (3 colonnes)) et Y = la ligne (donc 0 a 2 (3 lignes)), exemple 11 = milieu\nRentrer la position de votre symbole (x y) : ");
				scanf("%d %d", &positionX, &positionY);

				index = (positionY * 3) + positionX; // Formule tab 2 dimensions to 1 dimension

				while (positionX > 2 || positionX < 0 || positionY > 2 || positionY < 0 || grille[index] != 0)
				{
					printf("Veuillez rentrer une valeur de X ou Y inferieur a 3 ou bien superieur ou egal a 0 et une case non jouee : ");
					scanf("%d %d", &positionX, &positionY);

					index = (positionY * 3) + positionX; // Formule tab 2 dimensions to 1 dimension
				}

				grille[index] = nbPlayer; // Stock

				if (testGameEnd(grille) == 1)
				{
					printf("\nJoueur 1 Gagnant ! GG\n\n");
					win = 1;
					break;
				}
				else if (testGameEnd(grille) == -2)
				{
					printf("\nMatch nul ! Bien jouez a vous !\n\n");
					null = 1;
					break;
				}


				nbPlayer *= -1; // Player 2

				// Show grid before turn Player 2
				for (int i = 0; i < 9; i++)
				{
					if (grille[i] == 0)
					{
						printf("- ");
					}
					else if (grille[i] == 1)
					{
						printf("X ");
					}
					else if (grille[i] == -1)
					{
						printf("O ");
					}

					if (i == 2 || i == 5 || i == 8)
					{
							printf("\n");
					}
				}

				printf("\nTour actuel : Joueur 2\n\nRAPPEL : X = la colonne (donc 0 a 2 (3 colonnes)) et Y = la ligne (donc 0 a 2 (3 lignes)), exemple 11 = milieu\nRentrer la position de votre symbole (xy) : ");
				scanf("%d %d", &positionX, &positionY);

				index = (positionY * 3) + positionX; // Formule tab 2 dimensions to 1 dimension

				while (positionX > 2 || positionX < 0 || positionY > 2 || positionY < 0 || grille[index] != 0)
				{
					printf("Veuillez rentrer une valeur de X ou Y inferieur a 3 ou bien superieur ou egal a 0 et une case non jouee : ");
					scanf("%d %d", &positionX, &positionY);

					index = (positionY * 3) + positionX; // Formule tab 2 dimensions to 1 dimension
				}

				grille[index] = nbPlayer; // Stock

				if (testGameEnd(grille) == -1)
				{
					printf("\nJoueur 2 Gagnant ! GG\n\n");
					win = 1;
					break;
				}
				else if (testGameEnd(grille) == -2)
				{
					printf("\nMatch nul ! Bien jouez a vous !\n\n");
					null = 1;
					break;
				}

			} while (win != 1 || null != 1); // !Win or !null


			// Show grid after win player or match null
			for (int i = 0; i < 9; i++)
			{
				if (grille[i] == 0)
				{
					printf("- ");
				}
				else if (grille[i] == 1)
				{
					printf("X ");
				}
				else if (grille[i] == -1)
				{
					printf("O ");
				}

				if (i == 2 || i == 5 || i == 8)
				{
					printf("\n");
				}
			}

		}
		else if (nbStart == 2) // Equivalent number 2
		{
			printf("Vous avez choisi 2 !\n\n");
			printf("Bonne chance contre l'IA !\n\n");

			initializeGameState(grille);
		}
		else if (nbStart == 3) // Equivalent number 3
		{
			printf("Vous avez choisi 3 !\n\n");

			printf("But du jeu : Le but du jeu est d aligner avant son adversaire 3 symboles identiques horizontalement, verticalement ou en diagonale. Chaque joueur a donc son propre symbole, generalement une croix pour l un et un rond pour l autre.\n\n");
			printf("Le truc en + : Attention, le joueur qui debute est toujours avantager pour gagner !\n\n");
			printf("En fin de partie : Le premier joueur a aligner 3 symboles identiques gagne la partie. Si la grille est completee sans vainqueur, la partie est finie et il y a match nul.\n\n");
		}


		printf("\nVoulez-vous revenir en arriere ? (y/n)\n\n");
		again = getch();

	} while (again == 121 || again == 89);

	printf("Bonne continuation et merci d avoir jouer !\n");

	return 0;
}