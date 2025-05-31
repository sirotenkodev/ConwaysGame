#include "gamewindow.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

GameWindow::GameWindow(const std::string &title)
{
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (!window) {
        throw std::runtime_error("Error while window create: " + std::string(SDL_GetError()));
    }
}

GameWindow::~GameWindow()
{
    SDL_DestroyWindow(window);
}

SDL_Window *GameWindow::getWindow() const
{
    return window;
}
