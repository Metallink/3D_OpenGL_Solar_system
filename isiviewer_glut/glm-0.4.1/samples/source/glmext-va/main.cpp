#include "sample.h"
#include <SDL/SDL.h>

SDL_Surface* g_Surface = 0;

void DeleteWindow()
{
	if(g_Surface)
    {
		SDL_FreeSurface(g_Surface);
        g_Surface = 0;
    }

    SDL_Quit();
}

void CreateWindow(const char* Title, int Width, int Height, bool Fullscren)
{
    if(g_Surface)
        DeleteWindow();

	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) < 0)
		return;

	unsigned int Flags = SDL_OPENGL | SDL_DOUBLEBUF;

	if(Fullscren)
		Flags |= SDL_FULLSCREEN;

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 0);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 0);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE, 0);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE, 0);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE, 0);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE, 0);

	if((g_Surface = SDL_SetVideoMode(Width, Height, 32, Flags)) == 0)
		return;

	SDL_WM_SetCaption(Title, Title);
}

int main(int argc, char* argv[])
{
    CreateWindow("GLM core and GLM extensions for intermediate mode", 640, 480, false);

	Begin(640, 480);

	bool Exit = false;
    while(!Exit)
    {
		SDL_Event Event;

		while(SDL_PollEvent(&Event))
		{
			switch(Event.type)
			{
			case SDL_QUIT:
			case SDL_KEYDOWN:
				Exit = true;
				break;
			}
		}

		static float Time = 0.0f;
		Time += 0.1f;

		Render(Time);

		SDL_GL_SwapBuffers();
	}

	End();

    DeleteWindow();

    return 0;
}
