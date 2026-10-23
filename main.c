//add SDL3
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

//add standard things
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    //create window var
    SDL_Window *window;
    bool done = false;

    //activate SDL video system
    SDL_Init(SDL_INIT_VIDEO);

    //create window
    window = SDL_CreateWindow(
        "MVA Player",
        1280,
        720,
        SDL_WINDOW_MAXIMIZED
    );

    //check if window is created correct
    if (window == NULL)
    {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    //app loop
    while (!done)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                done = true;
            }
        }
    }

    //close and destroy the window
    SDL_DestroyWindow(window);

    //clean up
    SDL_Quit();
    return 0;
}