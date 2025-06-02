#include <iostream>
#include "grid.h"

//-----------------------------------------------------------------------------
Grid::Grid(int wH, int wW, int gS, GameWindow &window)
    : m_windowHeight{wH}
    , m_windowWidht{wW}
    , m_gridSize{gS}
    , m_cellsize{wW/gS}
    , m_cells{static_cast<size_t>(gS + 2), std::vector<Cell>(gS + 2)} // Добавляю по 1 клетке сверу и снизу, для более простого подсчета
{
    m_renderer = std::make_unique<GameRender>(window);
}

//-----------------------------------------------------------------------------
void Grid::drawGrid()
{
    SDL_SetRenderDrawColor(m_renderer->getRender(), 255, 255, 255, 255);
    SDL_RenderClear(m_renderer->getRender());

    for (int x = 0; x < m_gridSize; ++x) {
        for (int y = 0; y < m_gridSize; ++y) {

            SDL_FRect cellRect = {
                static_cast<float>(1.0f + x * m_cellsize),
                static_cast<float>(1.0f + y * m_cellsize),
                static_cast<float>(m_cellsize),
                static_cast<float>(m_cellsize)
            };

            if(m_cells[x + 1][y + 1].isAlive()) {
                SDL_SetRenderDrawColor(m_renderer->getRender(), 20, 20, 20, 255);
            } else {
                SDL_SetRenderDrawColor(m_renderer->getRender(), 200, 200, 200, 255);
            }

            SDL_RenderFillRectF(m_renderer->getRender(), &cellRect);
        }
    }

    SDL_SetRenderDrawColor(m_renderer->getRender(), 0, 0, 0, 255);

    for (int i = 1; i <= m_gridSize; ++i) {
        SDL_RenderDrawLine(m_renderer->getRender(), i * m_cellsize, 0, i * m_cellsize, m_windowHeight);
    }

    for (int i = 1; i <= m_gridSize; ++i) {
        SDL_RenderDrawLine(m_renderer->getRender(), 0, i * m_cellsize, m_windowWidht, i * m_cellsize);
    }

    SDL_RenderPresent(m_renderer->getRender());
}

//-----------------------------------------------------------------------------
void Grid::updateGrid()
{
    for (int x = 1; x < m_cells.size() - 1; ++x) {
        for (int y = 1; y < m_cells[x].size() - 1; ++y) {
            if(m_cells[x][y].isAlive()) {
                if(m_cells[x][y].getNeighbor() < 2 || m_cells[x][y].getNeighbor() > 3) {
                    m_cells[x][y].die();
                }
            } else {
                if(m_cells[x][y].getNeighbor() == 3) {
                    m_cells[x][y].born();
                }
            }
        }
    }
}

//-----------------------------------------------------------------------------
void Grid::updateGeneration()
{
    for (int x = 1; x < m_cells.size() - 1; ++x) {
        for (int y = 1; y < m_cells[x].size() - 1; ++y) {
            checkNeighbor(x, y);
        }
    }
}

//-----------------------------------------------------------------------------
void Grid::checkNeighbor(int x, int y)
{
    m_cells[x][y].clearNeighbor();
    if(m_cells[x - 1][y -1].isAlive()) {
        m_cells[x][y].addNeighbor();
    }
    if(m_cells[x - 1][y].isAlive()) {
        m_cells[x][y].addNeighbor();
    }
    if(m_cells[x - 1][y + 1].isAlive()) {
        m_cells[x][y].addNeighbor();
    }

    if(m_cells[x][y + 1].isAlive()) {
        m_cells[x][y].addNeighbor();
    }
    if(m_cells[x][y - 1].isAlive()) {
        m_cells[x][y].addNeighbor();
    }

    if(m_cells[x + 1][y - 1].isAlive()) {
        m_cells[x][y].addNeighbor();
    }
    if(m_cells[x + 1][y].isAlive()) {
        m_cells[x][y].addNeighbor();
    }
    if(m_cells[x + 1][y + 1].isAlive()) {
        m_cells[x][y].addNeighbor();
    }
}

//-----------------------------------------------------------------------------
void Grid::setCellOnGrid(int x, int y)
{
    int curX = x / m_cellsize;
    int curY = y / m_cellsize;

    if(!m_cells[curX + 1][curY + 1].isAlive()) {
        m_cells[curX + 1][curY + 1].born();
    } else {
        m_cells[curX + 1][curY + 1].die();
    }

}
