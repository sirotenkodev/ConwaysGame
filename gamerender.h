#ifndef GAMERENDER_H
#define GAMERENDER_H

#include <memory>
#include <string>

#include <SDL.h>

#include "gamewindow.h"

class GameRender
{
public:
    GameRender(GameWindow& window);
    ~GameRender();

    SDL_Renderer* getRender() const;

private:
    SDL_Renderer* renderer;
};

#endif // GAMERENDER_H
