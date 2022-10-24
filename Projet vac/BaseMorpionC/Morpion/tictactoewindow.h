#ifndef TICTACTOEWINDOW_H
#define TICTACTOEWINDOW_H

#include <SDL.h>

typedef struct TicTacToeWindow
{
	SDL_Window * pWindow;
	SDL_Renderer * pRenderer;

	// Circle sprite :
	SDL_Surface * pCircleSprite;
	SDL_Texture * pCircleTexture;

	// Cross sprite :
	SDL_Surface * pCrossSprite;
	SDL_Texture * pCrossTexture;

} TicTacToeWindow;

TicTacToeWindow * initializeWindow();
int getPlayedCell(TicTacToeWindow * pData, int * playedX, int * playedY);
void drawGameState(TicTacToeWindow * pData, int * gameState);
void destroyWindow(TicTacToeWindow * pData);

#endif