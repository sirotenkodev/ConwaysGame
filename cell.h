#ifndef CELL_H
#define CELL_H


class Cell
{
public:
    Cell();
    Cell(bool isAlive);

public:
    void born();
    void die();
    void changeState();

private:
    bool m_isAlive;
    int m_neighbours;
};

#endif // CELL_H



// https://habr.com/ru/articles/532732/ читал как делать

/*  Правила клеток
 *
 * 1) Живые клетки умирают, если у них меньше двух (недостаточное количество) или больше трёх (избыточное количество) живых соседей.
 * 2) Живые клетки остаются живыми, если у них есть два или три живых соседа.
 * 3) Мёртвые клетки с ровно тремя живыми соседями становятся живыми (воспроизводятся).
 *
 * */

