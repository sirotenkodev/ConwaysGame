#include "gamewindow.h"

//-----------------------------------------------------------------------------
GameWindow::GameWindow(const std::string &title, int windowWidth, int windowHeight)
{
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, 0);
    if (!window) {
        throw std::runtime_error("Error while window create: " + std::string(SDL_GetError()));
    }
}

//-----------------------------------------------------------------------------
GameWindow::~GameWindow()
{
    SDL_DestroyWindow(window);
}

//-----------------------------------------------------------------------------
SDL_Window *GameWindow::getWindow() const
{
    return window;
}
