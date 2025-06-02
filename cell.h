#ifndef CELL_H
#define CELL_H

class Cell
{
public:
    Cell();

public:
    void addNeighbor();
    void born();
    void clearNeighbor();
    void die();
    int getNeighbor();
    bool isAlive();

private:
    bool m_isAlive;
    int m_neighbor;
};

#endif // CELL_H

