#include "cell.h"

Cell::Cell()
    : Cell{false}
{}

Cell::Cell(bool isAlive)
    : m_isAlive{isAlive}
{}

void Cell::born()
{
    m_isAlive = true;
}

void Cell::die()
{
    m_isAlive = false;
}

void Cell::changeState()
{
    m_isAlive = !m_isAlive;
}
