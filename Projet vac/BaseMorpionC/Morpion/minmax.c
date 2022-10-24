#include "minmax.h"
#include "tictactoehelper.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

float mmin(int * gameState, int depth, int playerTurn)
{
	float minVal = 10000, curEval;
	int possibleActionsCount, i;
	int * curPos, * possibleActions;

	if(depth == 0 || testGameEnd(gameState) != 0)
		return evaluate(gameState);

	curPos = copyGameState(gameState);
	possibleActions = getPossibleActions(gameState, &possibleActionsCount);

	for(i = 0; i < possibleActionsCount; i++)
	{
		curPos[possibleActions[i]] = playerTurn;
		curEval = mmax(curPos, depth - 1, playerTurn * -1);

		if(curEval < minVal)
			minVal = curEval;

		destroyGameState(curPos);
		curPos = copyGameState(gameState);
	}

	return minVal;
}

float mmax(int * gameState, int depth, int playerTurn)
{
	float maxVal = -10000, curEval;
	int possibleActionsCount, i;
	int * curPos, * possibleActions;

	if(depth == 0 || testGameEnd(gameState))
		return evaluate(gameState);

	curPos = copyGameState(gameState);
	possibleActions = getPossibleActions(gameState, &possibleActionsCount);

	for(i = 0; i < possibleActionsCount; i++)
	{
		curPos[possibleActions[i]] = playerTurn;
		curEval = mmin(curPos, depth - 1, playerTurn * -1);

		if(curEval > maxVal)
			maxVal = curEval;

		destroyGameState(curPos);
		curPos = copyGameState(gameState);
	}

	return maxVal;
}

float evaluate(int * gameState)
{
	float eval = 0; 
	int p1Win, p2Win;
	int w1, w2;

	calculatePositionCaracteristics(gameState, &p1Win, &p2Win, &w1, &w2);

	if(p1Win == 1)
		eval = -1000;
	else if(p2Win == 1)
		eval = 1000;
	else if(testGameEnd(gameState) == -2)
		eval = 0;
	else
		eval = w2 - w1;

	return eval;
}

void calculatePositionCaracteristics(int * gameState, int * p1Win, int * p2Win, int * winningCountP1, int * winningCountP2)
{	
	int p1AlignCount[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	int p2AlignCount[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	int index = 0;
	int i;
	int j;

	*p1Win = *p2Win = 0;
	*winningCountP1 = *winningCountP2 = 0;

	// check lines :
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(gameState[(i * 3) + j] == 1)
			{
				p1AlignCount[index]++;
			}
			else if(gameState[(i * 3) + j] == -1)
			{
				p2AlignCount[index]++;
			}
		}

		index++;
	}

	// check columns :
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(gameState[(j * 3) + i] == 1)
			{
				p1AlignCount[index]++;
			}
			else if(gameState[(j * 3) + i] == -1)
			{
				p2AlignCount[index]++;
			}
		}

		index++;
	}

	// check diagos :
	for(i = 0; i < 9; i = i + 4)
	{
		if(gameState[i] == 1)
		{
			p1AlignCount[index]++;
		}
		else if(gameState[i] == -1)
		{
			p2AlignCount[index]++;
		}
	}

	index++;

	for(i = 2; i < 7; i = i + 2)
	{
		if(gameState[i] == 1)
		{
			p1AlignCount[index]++;
		}
		else if(gameState[i] == -1)
		{
			p2AlignCount[index]++;
		}
	}

	for(i = 0; i < 8; i++)
	{
		if(p1AlignCount[i] == 3)
			*p1Win = 1;
		else if(p2AlignCount[i] == 3)
			*p2Win = 1;

		if(p1AlignCount[i] >= 2 && p2AlignCount[i] == 0)
			(*winningCountP1)++;

		if (p2AlignCount[i] >= 2 && p1AlignCount[i] == 0)
			(*winningCountP2)++;
	}
}

int * getPossibleActions(int * gameState, int * possibleActionsCount)
{
	int * possibleActions;
	int i;
	
	if(possibleActionsCount == NULL)
		return NULL;
	
	possibleActions = (int *) malloc(9 * sizeof(int));
	*possibleActionsCount = 0;

	for(i = 0; i < 9; i++)
	{
		if(gameState[i] == 0)
		{
			possibleActions[*possibleActionsCount] = i;
			(*possibleActionsCount)++;
		}
	}

	return possibleActions;
}

static int randIsInitialized = 0;

int getBestAction(int * gameState, int playerTurn)
{
	int bestAction = -2;
	float bestEval = -10000, curEval;
	int * curPos, * possibleActions, possibleActionsCount, i;
	float evals[9];
	int randomAction[9], randomActionCount = 0;

	curPos = copyGameState(gameState);
	possibleActions = getPossibleActions(curPos, &possibleActionsCount);

	for(i = 0; i < possibleActionsCount; i++)
	{
		curPos[possibleActions[i]] = playerTurn;
		curEval = mmin(curPos, 9, playerTurn * -1);
		evals[i] = curEval;
		if(curEval > bestEval)
		{
			bestEval = curEval;
			bestAction = possibleActions[i];
		}

		destroyGameState(curPos);
		curPos = copyGameState(gameState);
	}

	for(i = 0; i < possibleActionsCount; i++)
	{
		if(evals[i] == bestEval)
		{
			randomAction[randomActionCount] = possibleActions[i];
			randomActionCount++;
		}
	}

	printf("There is %d equal possibilities\n", randomActionCount);
	if(randomActionCount > 1)
	{
		if(randIsInitialized == 0)
		{
			srand(time(NULL));
			randIsInitialized = 1;
		}

		bestAction = randomAction[rand() % randomActionCount];
	}

	return bestAction;
}