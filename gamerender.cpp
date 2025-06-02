#include "gamerender.h"

//-----------------------------------------------------------------------------
GameRender::GameRender(GameWindow &window)
{
    renderer = SDL_CreateRenderer(window.getWindow(), -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        throw std::runtime_error("Error while create renderer: " + std::string(SDL_GetError()));
    }
}

//-----------------------------------------------------------------------------
GameRender::~GameRender()
{
    SDL_DestroyRenderer(renderer);
}

//-----------------------------------------------------------------------------
SDL_Renderer *GameRender::getRender() const
{
    return renderer;
}
