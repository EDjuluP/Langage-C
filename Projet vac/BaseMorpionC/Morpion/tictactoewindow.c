
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "tictactoewindow.h"
#include "tictactoewindowparams.h"
#include "drawhelper.h"

// Create a window and load needed textures.
// Return :
//    - a TicTacToeWindow pointer if the window can be created.
//    - NULL if there was something wrong.
TicTacToeWindow * initializeWindow()
{
	TicTacToeWindow * pTicTacToeWindow = NULL;
	SDL_Window * pWindow = NULL;
	SDL_Renderer * pRenderer = NULL;
	SDL_Surface * pSprite = NULL;
	SDL_Texture * pTexture = NULL;

	/* Initialization */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Echec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return NULL;
    }

    {
        /* Créate the window */
        pWindow = NULL;
        pWindow = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
																  WINDOW_W,
																  WINDOW_H,
                                                                  SDL_WINDOW_SHOWN);

        if( pWindow != NULL )
        {
			pRenderer =  SDL_CreateRenderer( pWindow, -1, SDL_RENDERER_ACCELERATED);

			pTicTacToeWindow = (TicTacToeWindow *) malloc (sizeof(TicTacToeWindow));
			pTicTacToeWindow->pWindow = pWindow;
			pTicTacToeWindow->pRenderer = pRenderer;

			// Load player textures :
			pSprite = SDL_LoadBMP(PLAYER1_IMG);
			if ( pSprite != NULL)
			{
				pTicTacToeWindow->pCircleSprite = pSprite;
				pTexture = SDL_CreateTextureFromSurface(pRenderer,pSprite); // Prepare the sprite

				if ( pTexture != NULL )
				{
					pTicTacToeWindow->pCircleTexture = pTexture;
				}
				else
				{
					fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
				}
			}
			else
			{
				fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
			}

			pSprite = SDL_LoadBMP(PLAYER2_IMG);
			if ( pSprite != NULL)
			{
				pTicTacToeWindow->pCrossSprite = pSprite;
				pTexture = SDL_CreateTextureFromSurface(pRenderer,pSprite); // Prepare the sprite

				if ( pTexture != NULL )
				{
					pTicTacToeWindow->pCrossTexture = pTexture;
				}
				else
				{
					fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
				}
			}
			else
			{
				fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
			}
        }
        else
        {
            fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
			SDL_Quit();
			return NULL;
        }
    }

	return pTicTacToeWindow;
}

// Return :
//  1 : if quit
//  0 : if the player clicked on a cell
//      The coordinates of the clicked cell are set in
//      playerX and playerY parameters.
int getPlayedCell(TicTacToeWindow * pData, int * playedX, int * playedY)
{
	int hasClicked = 0;
	SDL_Event sdl_event;

	if(playedX != NULL)
		*playedX = -1;
	if(playedY != NULL)
		*playedY = -1;

	while(hasClicked != 1)
	{	
		if(SDL_WaitEvent(&sdl_event) == 1)
		{
			if(sdl_event.type == SDL_MOUSEBUTTONUP)
			{
				if(sdl_event.button.windowID == SDL_GetWindowID(pData->pWindow))
				{
					switch(sdl_event.button.button)
					{
					case SDL_BUTTON_LEFT:
						if(playedX != NULL)
							*playedX = sdl_event.button.x / CELL_W;
						if(playedY != NULL)
							*playedY = sdl_event.button.y / CELL_H;

						hasClicked = 1;
						break;
					}
				}
			}
			else if(sdl_event.type == SDL_QUIT)
			{
				return 1;
			}
		}
	}

	return 0;
}

void drawGameState(TicTacToeWindow * pData, int * gameState)
{
	int i, j;
	SDL_Rect drawPos;
	SDL_Texture * pTexture;
	int value;

	// Set render color to parametrized color ( background will be rendered in this color )
	SDL_SetRenderDrawColor( pData->pRenderer, BG_COLOR_R, BG_COLOR_G, BG_COLOR_B, 255 );

	// Clear window
	SDL_RenderClear( pData->pRenderer );

	// Draw circle and cross :
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			pTexture = NULL;
			value = gameState[(j * 3) + i];

			drawPos.x = i * CELL_W;
			drawPos.y = j * CELL_H;
			drawPos.w = CELL_W;
			drawPos.h = CELL_H;

			if(value > 0)		// Player 1
				pTexture = pData->pCircleTexture;
			else if(value < 0)	// Player 2
				pTexture = pData->pCrossTexture;

			if(pTexture != NULL)
				SDL_RenderCopy(pData->pRenderer, pTexture, NULL, &drawPos);
		}
	}

	// draw the lines :
	drawVerticalLine(pData->pRenderer, WINDOW_W / 3);
	drawVerticalLine(pData->pRenderer, 2 * (WINDOW_W / 3));
	drawHorizontalLine(pData->pRenderer, WINDOW_H / 3);
	drawHorizontalLine(pData->pRenderer, 2 * (WINDOW_H / 3));

	// Render to the screen
    SDL_RenderPresent(pData->pRenderer);
}

void destroyWindow(TicTacToeWindow * pData)
{
	if(pData != NULL)
	{
		// Free circle :
		if(pData->pCircleTexture != NULL)
			SDL_DestroyTexture(pData->pCircleTexture);
		if(pData->pCircleSprite != NULL)
			SDL_FreeSurface(pData->pCircleSprite);

		// Free cross :
		if(pData->pCrossTexture != NULL)
			SDL_DestroyTexture(pData->pCrossTexture);
		if(pData->pCrossSprite != NULL)
			SDL_FreeSurface(pData->pCrossSprite);


		if(pData->pWindow != NULL)
			SDL_DestroyWindow(pData->pWindow);

		free(pData);
		SDL_Quit();
	}
}