#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // for exit and random
#include <math.h>
#include <time.h>

using namespace std;

int main(int argc, char ** argv)
{
	/////////////// EXO 1

	
	int nb;
	printf("entrez un nombre compris entre 1 et 1000\n");
	scanf("%d", &nb);
	printf(" le caractere lu est : %d \n", nb);
	

	/////////////// EXO 2

	
	int x = 4, y;
	y = (x > 5) && (x < 8);
	printf("1er evaluation : \t x = %d y = %d\n", x, y); //x=4 y=0
	x = y + x + 2;
	y = (x > 5) && (x < 7);
	printf("2eme evaluation : \t x = %d y = %d\n", x, y); //x=6 y=1
	

	/////////////// EXO 3

	
	float x;
	printf("entrez votre nombre \n");
	scanf("%f", &x);
	if (!x) //x vaut 0
		printf("erreur de saisie");
	else
		printf("l inverse du nombre est : %f", 1 / x);
	

	/////////////// EXO 4

	
	int i = 1, entierN, sommeEntier = 0;

	printf("entrez un entier\n");
	scanf("%d", &entierN);

	while (entierN >= 1 && i <= entierN)
	{
		sommeEntier += i;
		printf("Somme Entier  de 1 a N = %d\n", sommeEntier);
		i++;
	}
	

	/////////////// EXO 5

	
	float amountArticle, amountFacture = 0, reduceFacture = 0;
	int nbArticles;

	printf("Saisir le montant de l article ainsi que le nombres d articles :\n");

	scanf("%f%d", &amountArticle, &nbArticles);
	amountFacture = nbArticles * amountArticle;

	if (amountFacture > 500)
	{
		reduceFacture = amountFacture * 10 / 100;
		amountFacture -= reduceFacture;

		printf("Le montant de la facure est  = %f euros apres une reduction de 10 pourcents qui est = %f euros", amountFacture, reduceFacture);
	}
	else
	{
		printf("Le montant de la facure est  = %f euros", amountFacture);
	}
	

	/////////////// EXO 6

	
	float notesSubject;
	int notesSup10 = 0, i = 0, nbEleves;

	printf("Veuillez saisir le nombres d eleves dans la classe !\n");
	scanf("%d", &nbEleves);

	while (i < nbEleves)
	{
		printf("\nVeuillez saisir la note de l eleve numero %d\n", i + 1);
		scanf("%f", &notesSubject);

		if (notesSubject > 20 || notesSubject < 0)
		{
			printf("Saisis de note stopper car la note que vous avez saisi est superieur a 20 ou inferieur a 0 !");
			break;
		}

		if (notesSubject > 10)
		{
			notesSup10 += 1;
		}

		i++;
	}

	printf("Le nombre de notes superieur a 10 est de = %d, pour un total de %d eleves !", notesSup10, nbEleves);
	

	/////////////// EXO 7

	
	float moyenneClasse = 0, notes;
	int compteurI = 1;

	srand(time(NULL));

	while (compteurI < 30)
	{
		notes = ((float)rand()/RAND_MAX*20);


		moyenneClasse += notes;
		compteurI++;
	}

	moyenneClasse = moyenneClasse / 30;
	printf("La moyenne de classe pour 30 eleves est de %f/20", moyenneClasse);

	//// link random 1 to 20 -> https://yard.onl/sitelycee/cours/c/NombresAlatoires.html

	
}