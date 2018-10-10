#include "structures.h"

Cell::Cell()
{
    state = EMPTY;
}


void Cell::SetCondition(enum CONDITION state)
{
    this->state = state;
}


enum Cell::CONDITION Cell::GetCondition()
{
    return state;
};


Field::Field()
{
    WIDTH = 20;
    HEIGHT = 20;
    MainField = new Cell*[WIDTH];
    for (int i = 0; i < WIDTH; i++)
    {
        MainField[i] = new Cell[HEIGHT];
    }
}


Field::Field(int WIDTH, int HEIGHT)
{
    if (WIDTH > 0)                                  //All the IFs are input check
    {
        if (HEIGHT > 0)
        {
            this->WIDTH = WIDTH;
            this->HEIGHT = HEIGHT;
            MainField = new Cell*[WIDTH];
            for (int i = 0; i < WIDTH; i++)
            {
                MainField[i] = new Cell[HEIGHT];
            }
        }
        else
        {
            this->WIDTH = WIDTH;
            this->HEIGHT = WIDTH;
            MainField = new Cell*[WIDTH];
            for (int i = 0; i < WIDTH; i++)
            {
                MainField[i] = new Cell[WIDTH];
            }
        }
    }
    else
    {
        WIDTH = 20;
        HEIGHT = 20;
        MainField = new Cell*[WIDTH];
        for (int i = 0; i < WIDTH; i++)
        {
            MainField[i] = new Cell[HEIGHT];
        }
    }

}


Field::~Field()
{
    for (int i = 0; i < WIDTH; i++)
    {
        delete(MainField[i]);
    }
    delete(MainField);
}
