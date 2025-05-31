#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <memory>
#include <string>

#include <SDL.h>

class GameWindow
{
public:
    GameWindow(const std::string& title);
    ~GameWindow();

    SDL_Window* getWindow() const;

private:
    SDL_Window* window;
};

#endif // GAMEWINDOW_H
