#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#include "functions.h"

int saisieNomsJoueurs(Players ** Joueur)
{
	char nom[50];
	int nbPlayer = 0, nbChoose;

	do
	{
		if (nbPlayer < 2) // SI IL Y A PAS DEUX JOUEURS
		{
			while (nbPlayer < 2) // Tant que y'a pas deux joueurs
			{
				printf("Rentrez un nom (Vous serez le joueur numero %d) : ", nbPlayer + 1);
				scanf("%s", nom);

				// ON VA VERIFER QUIL EXISTE OU PAS
				int playerPresent = 0;
				int indexPlayer = 0;

				for (int i = 0; i < nbPlayer; i++) // On parcour notre tableau de joueur
				{
					if (strcmp(nom, (*Joueur)[i].name) == 0)
					{
						playerPresent = 1;
						indexPlayer = i;
						break;
					}
				}

				// Si il existe
				if (playerPresent == 1) // Si present alors on re-saisi
				{
					printf("\nCe nom de joueur est deja present ! Merci de choisir un autre SVP !\n");
				}
				else // Si il existe pas
				{
					nbPlayer++; // on ajoute 1 au nombre de joueurs

					Players * oldMem = (*Joueur); // On fait une copie de l'ancier
					(*Joueur) = malloc(nbPlayer * sizeof(Players)); // On agrandi le tableau

					if (oldMem != NULL)
					{
						memcpy((*Joueur), oldMem, (nbPlayer - 1) * sizeof(Players)); // On copie l'ancien dans le nouveau
						free(oldMem); // on supprime l'ancien
					}

					strcpy((*Joueur)[nbPlayer - 1].name, nom); // On ajoute le nom du Joueur
					(*Joueur)[nbPlayer - 1].numJoueur = nbPlayer; // Definis le num�ro du joueur
					(*Joueur)[nbPlayer - 1].points = 0; // On lui met sont nombres de point a zero

					printf("\nJoueur ajouter !\n");
				}
			}
		}
		else
		{
			printf("Rentrez un nom (Vous serez le joueur numero %d) : ", nbPlayer + 1);
			scanf("%s", nom);

			// ON VA VERIFER QUIL EXISTE OU PAS
			int playerPresent = 0;
			int indexPlayer = 0;

			for (int i = 0; i < nbPlayer; i++) // On parcour notre tableau de joueur
			{
				if (strcmp(nom, (*Joueur)[i].name) == 0)
				{
					playerPresent = 1;
					indexPlayer = i;
					break;
				}
			}

			// Si il existe
			while (playerPresent == 1)
			{
				printf("\nCe nom de joueur est deja present ! Merci de choisir un autre SVP !\n");

				printf("Rentrez un nom (Vous serez le joueur numero %d) : ", nbPlayer + 1);
				scanf("%s", nom);

				// ON VA VERIFER QUIL EXISTE OU PAS
				playerPresent = 0;
				indexPlayer = 0;

				for (int i = 0; i < nbPlayer; i++) // On parcour notre tableau de joueur
				{
					if (strcmp(nom, (*Joueur)[i].name) == 0)
					{
						playerPresent = 1;
						indexPlayer = i;
						break;
					}
				}
			}

			// Si il existe pas
			if (playerPresent == 0)
			{
				nbPlayer++; // on ajoute 1 au nombre de joueurs

				Players * oldMem = (*Joueur); // On fait une copie de l'ancier
				(*Joueur) = malloc(nbPlayer * sizeof(Players)); // On agrandi le tableau

				if (oldMem != NULL)
				{
					memcpy((*Joueur), oldMem, (nbPlayer - 1) * sizeof(Players)); // On copie l'ancien dans le nouveau
					free(oldMem); // on supprime l'ancien
				}

				strcpy((*Joueur)[nbPlayer - 1].name, nom); // On ajoute le nom du Joueur
				(*Joueur)[nbPlayer - 1].numJoueur = nbPlayer; // Definis le num�ro du joueur
				(*Joueur)[nbPlayer - 1].points = 0; // On lui met sont nombres de point a zero

				printf("\nJoueur ajouter !\n");
			}
		}

		printf("Rajouter un joueur ? (Oui = 1 et Non = 0): "); // Si l'utilisateur souhaite rajouter un joueur
		scanf("%d", &nbChoose);

		while (nbChoose != 1 && nbChoose != 0) // Si l'utilisateur rentre pas 1 ou 0
		{
			printf("Rajouter un joueur [1 ou 0 SVP !!!] ? (Oui = 1 et Non = 0): ");
			scanf("%d", &nbChoose);
		}

		if (nbChoose == 1)
		{
			if (nbPlayer == 6) // Si le nombre de joueurs est déjà au max
			{
				printf("\nERREUR : Le nombre de joueurs maximum est 6 !");
				break;
			}
		}
		else if (nbChoose == 0) // Sinon on arrête la saisie de joueurs
		{
			break;
		}

	} while (nbPlayer < 6 || nbChoose != 0); // Tant que le nombre Joueur est pas au max et que

	return nbPlayer;
}


void Jeu(Players ** Joueur, int nbJoueur)
{
	int winner = 0;
	srand(time(NULL));

	do
	{
		// On fait jouer le joueur en affichant nom
		for (int i = 0; i < nbJoueur; i++)
		{
			printf("\nTour en en cours : %s\n", (*Joueur)[i].name); // On affiche le nom du joueur
			printf("Pour lancer les des appuyer sur la touche *\n");

			while (_getch() != 42) // Tant qu'il a pas appuyer sur la touche *
			{
				printf("ERREUR : Veuillez appuyer sur la touche * SVP\n");
			}

			int des[6]; // On fait un tableau pour stocker les valeurs des 6 dés 

			printf("\nVotre tirage donne : ");
			for (int j = 0; j < 6; j++) // On tire les valeurs des 6 dés
			{
				des[j] = rand() % 6 + 1;  // Entre 1 et 6

				printf("%d ", des[j]);
			}

			// On calcul alors les points du joueur en question
			int score = calculPoints(Joueur, des);

			if (score == 1) // Si un joueur à gagner
			{
				winner = 1;
				break;
			}
			else
			{
				printf("Vous avez un score : %d points", score);
			}

			// Affichage du score après le calcul des points
			// affichageScore(&Joueur);

			printf("\nVotre score est donc de : %d", score);
		}

		// Affichage des scores à la fin du tour
		// affichageScore(&Joueur);

	} while (winner != 1);
}

int calculPoints(Players ** Joueur, int * tab)
{
	// On va faire chaque combinaison de points une par une
	// et la comparer avec chaque valeur obtenue
	// afin de calculer le score du joueur.

	int scoreJoueur = 0;

	// On va faire un tableau de 6 cases (num 1 à 6 du dé)
	// Quand un chiffre est trouvé il va être additionné pour les combinaisons
	int numDes[6] = { 0,0,0,0,0,0 };

	for (int i = 0; i < 6; i++) // On va partir les valeurs et comparer
	{
		// On va faire dans les cas ou on à 1 chiffres afin de stocker et faire avec le score
		if (tab[i] == 1)
		{
			numDes[0] += 1; // On ajoute 1 au tableau colonne 1
			scoreJoueur += 100;
		}
		else if (tab[i] == 2)
		{
			numDes[1] += 2; // On ajoute 2 au tableau colonne 2
		}
		else if (tab[i] == 3)
		{
			numDes[2] += 3; // On ajoute 3 au tableau colonne 3
		}
		else if (tab[i] == 4)
		{
			numDes[3] += 4; // On ajoute 4 au tableau colonne 4
		}
		else if (tab[i] == 5) // Si dé = 5
		{
			numDes[4] += 5; // On ajoute 5 au tableau colonne 5
			scoreJoueur += 50;
		}
		else if (tab[i] == 6)
		{
			numDes[5] += 6; // On ajoute 6 au tableau colonne 6
		}
	}

	/// Pour Les combinaisons identiques 6 fois
	if (numDes[0] == 6) // Si 6 dés sont égales à 1 (1+1+1+1+1+1)
	{
		scoreJoueur = 1; // Win
	}
	else if (numDes[1] == 12 || numDes[2] == 18 || numDes[3] == 24 || numDes[4] == 30 || numDes[5] == 36) // Si 6 dés sont égales identiques (n+n+n+n+n+n)
	{
		scoreJoueur += 1000 * tab[0]; // 1000 fois la valeur du dé
	}

	for (int i = 0; i < 6; i++) // on re parcour le tableau des valeurs du dés après Les combinaisons identiques 6 fois
	{
		/// Pour Les combinaisons identiques 3 fois
		if (tab[i] == 1 && numDes[0] == 3 || numDes[0] == 4 || numDes[0] == 5) // Si 3 ou plus de dés sont égales à 1 (1+1+1+1+1 max)
		{
			scoreJoueur += 1000; // 1000 points
			numDes[0] = 0; // On met à 0 pour par qui retombe dessus
		}
		else // Si 3 dés identiques (n+n+n+n+n max)
		{
			if (tab[i] == 2 && numDes[1] == 6 || numDes[1] == 8 || numDes[1] == 10) // Si ma valeur de dés est x et qu'on l'a déjà eu trois fois ou plus
			{
				scoreJoueur += 100 * tab[i]; // 100 fois la valeur du dé
				numDes[1] = 0; // On met à 0 pour par qui retombe dessus
			}
			else if (tab[i] == 3 && numDes[2] == 9 || numDes[2] == 12 || numDes[2] == 15)
			{
				scoreJoueur += 100 * tab[i]; 
				numDes[2] = 0;
			}
			else if (tab[i] == 4 && numDes[3] == 12 || numDes[3] == 16 || numDes[3] == 20)
			{
				scoreJoueur += 100 * tab[i];
				numDes[3] = 0;
			}
			else if (tab[i] == 5 && numDes[4] == 15 || numDes[4] == 20 || numDes[4] == 25)
			{
				scoreJoueur += 100 * tab[i];
				numDes[4] = 0;
			}
			else if (tab[i] == 6 && numDes[5] == 18 || numDes[5] == 24 || numDes[5] == 30)
			{
				scoreJoueur += 100 * tab[i];
				numDes[5] = 0;
			}
		}
	}

	return scoreJoueur; // Retourner le score du joueur
}