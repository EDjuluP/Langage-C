#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "functions.h"

void saisieNomsJoueurs(Players ** Joueur)
{
	char nom[50];
	int nbPlayer = 0, nbChoose;

	do
	{

		if (nbPlayer < 2) // SI IL Y A PAS DEUX JOUEURS
		{
			while (nbPlayer < 2)
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

				if (playerPresent == 1) // Si present alors on re-saisi
				{
					printf("\nCe nom de joueur est deja present ! Merci de choisir un autre SVP !\n");
				}
				else
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
					(*Joueur)[nbPlayer - 1].numJoueur = nbPlayer; // Definis le numéro du joueur
					(*Joueur)[nbPlayer - 1].points = 0; // On lui met sont nombres de point a zero
				}
			}
		}
		else
		{
				printf("TEST 1234");
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

				while (playerPresent == 1)
				{
					printf("\nCe nom de joueur est deja present ! Merci de choisir un autre SVP !\n");

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

				}

				if
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
					(*Joueur)[nbPlayer - 1].numJoueur = nbPlayer; // Definis le numéro du joueur
					(*Joueur)[nbPlayer - 1].points = 0; // On lui met sont nombres de point a zero
				}
			}
		}

		printf("Rajouter un joueur ? (Oui = 1 et Non = 0) : ");
		scanf("%d", &nbChoose);

		if (nbChoose == 1)
		{
			if (nbPlayer == 6)
			{
				printf("\nERREUR : Le nombre de joueurs maximum est 6 !");
				break;
			}
		}

	} while (nbPlayer < 6 || nbChoose != 0);
}