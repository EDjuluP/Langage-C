#ifndef MINMAX_H
#define MINMAX_H

float mmin(int * gameState, int depth, int playerTurn);
float mmax(int * gameState, int depth, int playerTurn);
float evaluate(int * gameState);
void calculatePositionCaracteristics(int * gameState, int * p1Win, int * p2Win, int * winningCountP1, int * winningCountP2);
int * getPossibleActions(int * gameState, int * possibleActionsCount);
int getBestAction(int * gameState, int playerTurn);

#endif