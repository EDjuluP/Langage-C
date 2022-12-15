#pragma once

typedef struct
{
	char name[50];
	int numJoueur;
	int points;

} Players;

void saisieNomsJoueurs(Players ** Joueur);

void jeu(Players ** Joueur)
{

}