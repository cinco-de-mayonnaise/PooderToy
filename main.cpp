#include <SDL2/SDL.h>

SDL_Window *g_window;
SDL_Renderer *g_renderer;

bool init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return false;
    }
    g_window = SDL_CreateWindow("Pooder Toy",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          640, 480, 0);
    if (g_window == NULL)
    {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        return false;
    }
    
    g_renderer = SDL_CreateRenderer(g_window, -1, 0);
    if (g_renderer == NULL)
    {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

int main(void)
{
    if (!init())
        return -1;
  
    bool quit = false;

    SDL_Event event;

    while (!quit)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        }

        SDL_SetRenderDrawColor(g_renderer, 255, 0, 0, 255);
        SDL_RenderClear(g_renderer);
        SDL_RenderPresent(g_renderer);
    }
    
    SDL_DestroyWindow(g_window);
    SDL_Quit();


    return 0;
}