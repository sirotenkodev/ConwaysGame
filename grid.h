#ifndef GRID_H
#define GRID_H

#include <memory>
#include <vector>

#include "cell.h"
#include "gamerender.h"

class Grid
{
public:
    Grid(int wH, int wW, int gS, GameWindow &window);

public:
    void checkNeighbor(int x, int y);
    void drawGrid();
    void setCellOnGrid(int x, int y);
    void updateGrid();
    void updateGeneration();

private:
    int m_windowHeight;
    int m_windowWidht;
    int m_gridSize;
    int m_cellsize;
    std::unique_ptr<GameRender> m_renderer;
    std::vector<std::vector<Cell>> m_cells;
};

#endif // GRID_H
