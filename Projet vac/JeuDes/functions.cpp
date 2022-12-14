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
		nbPlayer++;

		while (nbPlayer < 2) // SI IL Y A PAS DEUX JOUEURS
		{
			printf("Rentrez un nom :");
			scanf("%s", nom);

			// ON VA VERIFER QUIL EXISTE PAS

			// ENSUITE ON AJOUTE UN JOUEUR
			nbPlayer++;
		}
		
		printf("Rajouter un joueur ? (Oui = 1 et Non = 0) : ");
		scanf("%d", &nbChoose);

		if (nbChoose == 1)
		{
			if (nbPlayer == 6)
			{
				printf("ERREUR : Le nombre de joueurs maximum est 6 !");
				break;
			}
		}

		printf("\nJoueur : %d\n", nbPlayer);
	} while (nbPlayer < 6 || nbChoose != 0);
}