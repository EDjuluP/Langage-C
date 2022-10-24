#include "drawhelper.h"
#include "tictactoewindowparams.h"

void drawVerticalLine(SDL_Renderer * pRenderer, int verticalLinePosition)
{
	SDL_Rect verticalLine;

	// Set render color to parametrized color ( lines will be rendered in this color )
	SDL_SetRenderDrawColor( pRenderer, LINE_R, LINE_G, LINE_B, 255 );

	verticalLine.x = verticalLinePosition - (LINE_W / 2);
    verticalLine.y = 0;
	verticalLine.w = LINE_W;
	verticalLine.h = WINDOW_H;

	// Render rect
	SDL_RenderFillRect( pRenderer, &verticalLine );
}

void drawHorizontalLine(SDL_Renderer * pRenderer, int horizontalLinePosition)
{
	SDL_Rect horizontalLine;
	
	// Set render color to parametrized color ( lines will be rendered in this color )
	SDL_SetRenderDrawColor( pRenderer, LINE_R, LINE_G, LINE_B, 255 );

	horizontalLine.x = 0;
    horizontalLine.y = horizontalLinePosition - (LINE_W / 2);
	horizontalLine.w = WINDOW_W;
	horizontalLine.h = LINE_W;

	// Render rect
	SDL_RenderFillRect( pRenderer, &horizontalLine );
}