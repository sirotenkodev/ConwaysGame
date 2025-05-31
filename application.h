#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include <vector>

#include <SDL.h>

#include "cell.h"
#include "grid.h"
#include "gamerender.h"
#include "gamewindow.h"

class Application
{
public:
    Application();
    ~Application();

public:
    void init();
    int run();
    void stop();

private:
    void createCell(int x, int y);

private:
    std::unique_ptr<GameWindow> m_window;
    std::unique_ptr<GameRender> m_renderer;
    std::unique_ptr<Grid> m_grid;
    std::vector<std::vector<Cell>> m_cells;
    bool m_isRunning; // Пишу в основном в Qt и тут принят стиль с m_
};

#endif // APPLICATION_H
