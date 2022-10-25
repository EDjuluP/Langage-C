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

	// For player 1 (Inline, Column, Diagonal)
	if ((gameState[0] == 1 && gameState[1] == 1 && gameState[2] == 1 )|| (gameState[3] == 1 && gameState[4] == 1 && gameState[5] == 1) || (gameState[6] == 1 && gameState[7] == 1 && gameState[8] == 1))
	{ 
		nbEvaluate = 1;
	}
	else if ((gameState[0] == 1 && gameState[3] == 1 && gameState[6] == 1) || (gameState[1] == 1 && gameState[4] == 1 && gameState[7] == 1) || (gameState[2] == 1 && gameState[5] == 1 && gameState[8] == 1))
	{
		nbEvaluate = 1;
	}
	else if ((gameState[0] == 1 && gameState[4] == 1 && gameState[8] == 1) || (gameState[2] == 1 && gameState[4] == 1 && gameState[6] == 1))
	{
		nbEvaluate = 1;
	}



	// For player 2 (Inline, Column, Diagonal)
	if ((gameState[0] == -1 && gameState[1] == -1 && gameState[2] == -1) || (gameState[3] == -1 && gameState[4] == -1 && gameState[5] == -1) || (gameState[6] == -1 && gameState[7] == -1 && gameState[8] == -1))
	{
		nbEvaluate = -1;
	}
	else if ((gameState[0] == -1 && gameState[3] == -1 && gameState[6] == -1) || (gameState[1] == -1 && gameState[4] == -1 && gameState[7] == -1) || (gameState[2] == -1 && gameState[5] == -1 && gameState[8] == -1))
	{
		nbEvaluate = -1;
	}
	else if ((gameState[0] == -1 && gameState[4] == -1 && gameState[8] == -1) || (gameState[2] == -1 && gameState[4] == -1 && gameState[6] == -1))
	{
		nbEvaluate = -1;
	}



	// For match null
	int count = 0;

	for (int i = 0; i < 9; i++)
	{
		if (gameState[i] != 0)
		{
			count++;
		}
	}

	if (count == 9)
	{
		nbEvaluate = -2;
	}

	return nbEvaluate;
}

int * copyGameState(int * gameState)
{
	// We take space of a table with 9 integer
	int *newGameState = malloc(sizeof(int[9]));

	// Put grid in new space
	for (int i = 0; i < 9; i++)
	{
		newGameState[i] = gameState[i];
	}

	// We return copy of grid
	return newGameState;
}

// Destroy grid
void destroyGameState(int * gameState)
{
  	free(gameState);
}