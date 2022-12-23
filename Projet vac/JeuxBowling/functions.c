///////////// BY POLLET Quentin ///////////
//////////// Student at La Providence in Amiens (France)/////////
//////////// Last Release Date : 23/12/2022 - 21:59 /////////

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "functions.h"

int saisirNomJoueurs(Bowling ** Players)
{
	char nom[50];
	int nbChoose, nbPlayer = 0;

	printf("Bienvenue au pupitre !");

	do
	{
		printf("\n\nRentrez un nom pour le joueur %d : ", nbPlayer + 1);
		scanf("%s", nom);

		// ON VA VERIFER QUIL EXISTE OU PAS
		int playerPresent = 0;
		int indexPlayer = 0;

		for (int i = 0; i < nbPlayer; i++) // On parcour notre tableau de joueur
		{
			if (strcmp(nom, (*Players)[i].name) == 0)
			{
				playerPresent = 1;
				indexPlayer = i;
				break;
			}
		}

		while (playerPresent == 1) // Tant qu'il est déjà présent
		{
			printf("\n\nNom deja existant ! Veuillez en saisir un autre SVP ! : ");
			scanf("%s", nom);

			// ON VA VERIFER QUIL EXISTE OU PAS
			playerPresent = 0;
			indexPlayer = 0;

			for (int i = 0; i < nbPlayer; i++) // On parcour notre tableau de joueur
			{
				if (strcmp(nom, (*Players)[i].name) == 0)
				{
					playerPresent = 1;
					indexPlayer = i;
					break;
				}
			}
		}

		if (playerPresent == 0) // Si il est pas présent
		{
			nbPlayer++; // On va rajouter 1 au nombre de joueurs

			Bowling * oldMem = (*Players); // On fait une copie de l'ancien
			(*Players) = malloc(nbPlayer * sizeof(Bowling)); // On agrandi notre tableau de joueurs

			if (oldMem != NULL)
			{
				memcpy((*Players), oldMem, (nbPlayer - 1) * sizeof(Bowling)); // On copie l'ancien dans le nouveau
				free(oldMem); // on supprime l'ancien
			}

			strcpy((*Players)[nbPlayer - 1].name, nom); // On ajoute le nom du Joueur
			(*Players)[nbPlayer - 1].numJoueur = nbPlayer; // on met son numéro
			(*Players)[nbPlayer - 1].points = 0; // Et les points à 0

			printf("\nJoueur ajouter !\n");
		}

		if (nbPlayer != 6) // if nombre joueurs différent de  6
		{
			printf("Rajouter un joueur ? (Oui = 1 et Non = Entrer): "); // Si l'utilisateur souhaite rajouter un joueur
			nbChoose = getch();

			while (nbChoose != 49 && nbChoose != 13) // Si l'utilisateur rentre pas 1 ou 0
			{
				printf("\nRajouter un joueur [1 ou Entrer SVP !!!] ? (Oui = 1 et Non = Entrer): ");
				nbChoose = getch();
			}

			if (nbChoose == 13) // Si fin saisie 
			{
				if (nbPlayer == 1)
				{
					printf("\nBonne partie a toi !");
					break;
				}
				else
				{
					printf("\nBonne partie a vous tous !");
					break;
				}
			}
		}
		else // Sinon fin saisie
		{
			printf("Bonne partie a vous tous ! (nombre de joueur max atteint)");
			break;
		}
	
	} while (nbChoose != 0 || nbPlayer < 6); // Tant que pas 6 joueurs ou fin saisie

	return nbPlayer; // on retourne le nombres de joueurs
}

void initializeGame(Bowling ** Players, int nbPlayer)
{
	int nbCoups = 0, bonus = 0;

	do
	{
		nbCoups++; // On augmente le nombres de coups de 1

		// On fait jouer le joueur en affichant son nom
		for (int i = 0; i < nbPlayer; i++)
		{
			int tabScore[2]; // On va stocker
			bonus = 0;

			for (int k = 0; k < 2; k++) // On va jouer les deux lancer 
			{
				printf("\n\nTour %d en cours pour : %s\n", nbCoups, (*Players)[i].name); // On affiche le nom du joueur
				printf("Pour lancer la boule %d appuyer sur la touche *\n", k+1);

				while (_getch() != 42) // Tant qu'il a pas appuyer sur la touche *
				{
					printf("ERREUR : Veuillez appuyer sur la touche * pour lancer la boule %d SVP\n", k+1);
				}

				tabScore[k] = calculPoints(Players, i, nbCoups-1, k+1, &bonus); // On va renvoyer le tableau de lancers

				if (tabScore[0] == 10) // Si il fait un stike
				{
					(*Players)[i].points += tabScore[0];

					if (nbCoups == 10)
					{
						printf("\n2 Lancers bonus car vous avez fait un strike !\n");
						for (int j = 0; j < 2; j++)
						{
							printf("\n\nTour %d en cours pour : %s\n", nbCoups, (*Players)[i].name); // On affiche le nom du joueur
							printf("Pour lancer la boule bonus %d appuyer sur la touche *\n", j+1);

							while (_getch() != 42) // Tant qu'il a pas appuyer sur la touche *
							{
								printf("ERREUR : Veuillez appuyer sur la touche * pour lancer la boule %d bonus SVP\n", j+1);
							}

							if (j == 0) // Si c'est le premier lancer bonus
							{
								tabScore[1] = calculPoints(Players, i, nbCoups - 1, j+2, &bonus); // On va renvoyer le premier lancer bonus
							}
							else // Sinon si c'est le deuxième lancers bonus
							{
								(*Players)[i].coup3Bonus[0] = calculPoints(Players, i, nbCoups - 1, j+2, &bonus); // On va renvoyer le deuxiéme lancers bonus
							}
						}
						(*Players)[i].points += tabScore[1] + (*Players)[i].coup3Bonus[0]; // On met les points des lancers bonus
					}

					break; // On arrête
				}
				else if (k == 1 && tabScore[0] + tabScore[1] == 10) // Sinon si il fait un spare
				{
					if (nbCoups == 10)
					{
						printf("\n1 Lancer bonus car vous avez fait un spare !\n");

						printf("\n\nTour %d en cours pour : %s\n", nbCoups, (*Players)[i].name); // On affiche le nom du joueur
						printf("Pour lancer la boule bonus appuyer sur la touche *\n");

						while (_getch() != 42) // Tant qu'il a pas appuyer sur la touche *
						{
							printf("ERREUR : Veuillez appuyer sur la touche * pour lancer la boule bonus SVP\n");
						}

						(*Players)[i].coup3Bonus[0] = calculPoints(Players, i, nbCoups-1, k+2, &bonus); // On va renvoyer le premier lancer bonus
						(*Players)[i].points += tabScore[1] + (*Players)[i].coup3Bonus[0]; // On met les points du lancer bonus
					}
					break; // On arrête
				}
				else // Sinon si pas de spare ou de strike
				{
					(*Players)[i].points += tabScore[k];
				}
			}
			(*Players)[i].SavePoints[nbCoups - 1] = (*Players)[i].points; // On va sauvegarder les points du tour actuel
			affichageScore(*Players, nbPlayer, nbCoups);
		}

	} while (nbCoups < 10); // Tant que le nombre de coups est inférieur à 10
}

int calculPoints(Bowling ** Players, int numJoueur, int nbTours, int numCoups, int *bonus)
{
	int resultCoups[2], max = 0;
	srand(time(NULL));

	if (numCoups == 1) // Si c'est son premier coups
	{
		(*Players)[numJoueur].coup1[nbTours] = rand() % 11; // Tirer un nombre de quilles entre 0 et 10
		resultCoups[0] = (*Players)[numJoueur].coup1[nbTours]; // On met dans notre premier lancer le nombres de quilles (score)

		if (*bonus != 1 && nbTours > 0 && (*Players)[numJoueur].coup1[nbTours - 1] + (*Players)[numJoueur].coup2[nbTours - 1] == 10)// si le coup d'avant il fait un spare
		{
			if ((*Players)[numJoueur].coup1[nbTours - 1] != 10) // Si il à pas fait un strike
			{
				(*Players)[numJoueur].coup2[nbTours - 1] += resultCoups[0]; // On ajoute le premier coup du tour suivant
				(*Players)[numJoueur].points += (*Players)[numJoueur].coup2[nbTours - 1]; // On ajt le nb de points après le calcul et comme on fait pas le addpoint lignes 144
				*bonus = 1;
			}
		}
		
		if (*bonus != 1 && nbTours > 1 && (*Players)[numJoueur].coup1[nbTours - 2] == 10) // un strike deux tours avant
		{
			if ((*Players)[numJoueur].coup1[nbTours - 1] == 10) // un strike le tour avant
			{
				if (resultCoups[0] == 10) // Si il à fait un strike
				{
					(*Players)[numJoueur].coup1[nbTours - 2] += 10 + 10; // Turkey (3 strike d'affilet) = 30 points (deux coups suivant dans le strike)
					(*Players)[numJoueur].points += (*Players)[numJoueur].coup1[nbTours - 2] - 10; // On ajt le nb de points après le calcul
				}
				else // Sinon si il fait pas de strike
				{
					(*Players)[numJoueur].coup1[nbTours - 2] += 10 + resultCoups[0]; // 
					(*Players)[numJoueur].points += (*Players)[numJoueur].coup1[nbTours - 2] - 10; // On ajt le nb de points après le calcul
				}
			}
		}

		if (resultCoups[0] == 10 && nbTours != 9) // Si il fait un strike et que c'est pas le tour 10
		{
			(*Players)[numJoueur].coup2[nbTours] = NULL; // Deuxième lancer à 0
		}

		return resultCoups[0]; // On retourne notre lancer 1
	}
	else if (numCoups == 2) // sinon si c'est son deuxième coup
	{
		if (nbTours == 9 && (*Players)[numJoueur].coup1[nbTours] == 10) // Si c'est pas le tour 10 et qu'il à pas fait de strike
		{
			(*Players)[numJoueur].coup2[nbTours] = rand() % 11; // Tirer un nombre de quilles entre 0 et 10
			resultCoups[1] = (*Players)[numJoueur].coup2[nbTours]; // On met dans notre deuxième lancers le nombres de quilles (score)
		}
		else // Sinon si c'est le tour 10 et qu'il à fait un strike
		{
			max = 10 - (*Players)[numJoueur].coup1[nbTours]; // Pour savoir le nombres de quilles restantes

			(*Players)[numJoueur].coup2[nbTours] = rand() % ++max; // Tirer un nombres de quilles entre 0 et le nombres de quilles restantes
			resultCoups[1] = (*Players)[numJoueur].coup2[nbTours]; // On met dans notre second lancer le nombres de quilles (score)
		}

		if (*bonus != 1 && nbTours > 0 && (*Players)[numJoueur].coup1[nbTours - 1] == 10) // si le coup d'avant il à fait un strike
		{
			(*Players)[numJoueur].coup1[nbTours - 1] += (*Players)[numJoueur].coup1[nbTours] + resultCoups[1]; // Met les deux coups suivant dans le strike d'avant
			if (nbTours != 9)
			{
				(*Players)[numJoueur].points += (*Players)[numJoueur].coup1[nbTours - 1] - 10; // On ajoute les deux coups du strike
	
			}
			else
			{
				(*Players)[numJoueur].points += (*Players)[numJoueur].coup1[nbTours - 1] - 10 + resultCoups[1]; // On ajoute les deux coups du strike
			}
			*bonus = 1;
		}
		return resultCoups[1]; // On retourne notre lancer 2
	}
	else if (numCoups == 3) // Si coup bonus lors du tour 10
	{
		printf("numCoups = %d\n", numCoups);
		return rand() % 11; // Tirer un nombre de quilles entre 0 et 10
	}
}

void affichageScore(Bowling * Players, int nbJoueur, int nbTours)
{
	// Affichage des joueurs et de leurs scores
	printf("\nTableau des scores :\n\n");
	for (int i = 0; i < nbJoueur; i++) // Inférieur au nombres de joueurs
	{
		if (Players[i].coup1[nbTours-1] > -1 && Players[i].coup1[nbTours-1] <= 10) // Si il à jouer
		{
			printf("%s |", Players[i].name); // Affichage du joueur
			for (int j = 0; j < nbTours; j++)
			{
				if (Players[i].coup1[j] > -1 && Players[i].coup1[j] <= 30) // Si le joueur à jouer (que son premier coup1 est entre 0 et 10)
				{
					if (Players[i].coup1[j] >= 10) // Si le coup1 actuel est un strike
					{
						if (j == 9) // Si c'est le Tour 10
						{
							if (Players[i].coup2[j] == 10 && Players[i].coup3Bonus[0] == 10)
							{
								printf(" Tour %d: X X X (%d)", j + 1, Players[i].SavePoints[j]);
							}
							else if (Players[i].coup2[j] == 10 && Players[i].coup3Bonus[0] != 10)
							{
								printf(" Tour %d: X X %d (%d)", j + 1, Players[i].coup3Bonus[0], Players[i].SavePoints[j]);
							}
							else if (Players[i].coup2[j] != 10 && Players[i].coup3Bonus[0] == 10)
							{
								printf(" Tour %d: X %d X (%d)", j + 1, Players[i].coup2[j], Players[i].SavePoints[j]);
							}
							else
							{
								printf(" Tour %d: X %d %d (%d)", j + 1, Players[i].coup2[j], Players[i].coup3Bonus[0], Players[i].SavePoints[j]);
							}
						}
						else // Sinon si c'est pas le Tour 10
						{
							printf(" Tour %d: X ", j + 1);
						}
					}
					else if (Players[i].coup1[j] + Players[i].coup2[j] >= 10) // Sinon si le coup2 actuel est un spare
					{
						if (j == 9) // Si c'est le Tour 10
						{
							if (Players[i].coup3Bonus[0] == 10)
							{
								printf(" Tour %d: %d / X (%d)", j + 1, Players[i].coup1[j], Players[i].SavePoints[j]);
							}
							else
							{
								printf(" Tour %d: %d / %d (%d)", j + 1, Players[i].coup1[j], Players[i].coup3Bonus[0], Players[i].SavePoints[j]);
							}
						}
						else // Sinon si c'est pas le Tour 10
						{
							printf(" Tour %d: %d / ", j + 1, Players[i].coup1[j]);
						}
					}
					else // Sinon si aucun spare ou strike
					{
						printf(" Tour %d: %d %d (%d)", j+1, Players[i].coup1[j], Players[i].coup2[j], Players[i].SavePoints[j]);
					}
				}
			}
		}
		printf("\n");
	}
}

///////////// BY POLLET Quentin ///////////
//////////// Student at La Providence in Amiens (France)/////////
//////////// Last Release Date : 23/12/2022 - 21:59 /////////