#pragma once

typedef struct
{
	char name[50];
	int numJoueur;
	int points;

} Players;

int saisieNomsJoueurs(Players ** Joueur);
void Jeu(Players ** Joueur, int nbJoueur);
int calculPoints(Players ** Joueur, int * tab);
//void affichageScore(Players * Joueur);