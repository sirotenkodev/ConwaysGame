#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include <vector>

#include <SDL.h>

#include "cell.h"
#include "gamewindow.h"
#include "grid.h"

class Application
{
public:
    Application(int wH, int wW, int gS);
    ~Application();

public:
    void init(int wH, int wW, int gS);
    int run();
    void stop();

private:
    void togglePause();

private:
    std::unique_ptr<GameWindow> m_window;
    std::unique_ptr<Grid> m_grid;

    bool m_isRunning; // Пишу в основном в Qt и тут принят стиль с m_
    bool m_onPause;
};

#endif // APPLICATION_H
