///////////// BY POLLET Quentin ///////////
//////////// Student at La Providence in Amiens (France)/////////
//////////// Last Release Date : 17/12/2022 - 12:22 AM /////////

#pragma once

typedef struct
{
	char name[50];
	int numJoueur;
	int points;

} Players;

int saisieNomsJoueurs(Players ** Joueur);
void Jeu(Players ** Joueu, int nbJoueur);
int calculPoints(Players ** Joueur, int * tab);
void affichageScore(Players * Joueur, int nbJoueur, int winner);


///////////// BY POLLET Quentin ///////////
//////////// Student at La Providence in Amiens (France)/////////
//////////// Last Release Date : 17/12/2022 - 12:22 AM /////////