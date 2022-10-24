#include "tictactoehelper.h"
#include <stdlib.h>

// Morpion
void initializeGameState(int * gameState)
{
	// Inialize the grid at 0
	for (int index = 0; index < 9; index++)
	{
		gameState[index] = 0;
	}

}

// If a player win or match null
int testGameEnd(int * gameState)
{
	int nbEvaluate = 0;

	return nbEvaluate;
}


int * copyGameState(int * gameState)
{
	// We take space of a table with 9 integer
	 int newGameState = (int*)malloc(9 * sizeof(int));

	 newGameState = gameState;

	// We return copy of grid

	return newGameState;
}

// Destroy grid
void destroyGameState(int * gameState)
{
	// Supp space of grid
	free(gameState);
}