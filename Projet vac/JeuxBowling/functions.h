///////////// BY POLLET Quentin ///////////
//////////// Student at La Providence in Amiens (France)/////////
//////////// Last Release Date : 23/12/2022 - 21:59 /////////

#pragma once

typedef struct 
{
	char name[50];
	int numJoueur;

	int coup1[10];
	int coup2[10];
	int coup3Bonus[1];

	int points;
	int SavePoints[10];

} Bowling;

int saisirNomJoueurs(Bowling ** Players);
void initializeGame(Bowling ** Players, int nbPlayer);
int calculPoints(Bowling ** Players, int numJoueur, int nbTours, int numCoups, int *bonus);
void affichageScore(Bowling * Players, int nbJoueur, int nbTours);

///////////// BY POLLET Quentin ///////////
//////////// Student at La Providence in Amiens (France)/////////
//////////// Last Release Date : 23/12/2022 - 21:59 /////////