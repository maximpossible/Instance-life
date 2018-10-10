#include <iostream>
#include <random>
#include <time.h>
#include <unistd.h>
#include "structures.h"

void Field::FillFieldWithProbability(short int chance)
{
    srand(time(0));
    short int RealChance = chance;
    if (chance >= 100)                                      //If chance was incorrect, then it
    {                                                           //reduced to the desired form
        RealChance = chance % 99;
    }
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            short int exodus = rand() % 99;                 //If number more then chance, then fill empty
            if (exodus <= RealChance)                           //else fill "active"
            {
                MainField[i][j].SetCondition(Cell::ACTIVE);
            }
            else
            {
                MainField[i][j].SetCondition(Cell::EMPTY);
            }
        }
    }
}


void Field::Show()
{
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            if (MainField[i][j].GetCondition() == 0)        //Show nothing, if cell is incorrect
            {
                std::cout << ' ';
            }
            else if (MainField[i][j].GetCondition() == 1)
            {
                std::cout << 'O';
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


int Field::GetSomeNearCells(int x, int y)
{
    short int CounterOfActiveCells = 0;                     //Check all the near cells on "active" or "empty"
    if (x - 1 > -1)                                     //Check output from array
    {
        if (MainField[x - 1][y].GetCondition() == 1)
        {
            CounterOfActiveCells++;
        }
    }
    if ( (x - 1 > -1) && (y + 1 < HEIGHT) )
    {
        if (MainField[x - 1][y + 1].GetCondition() == 1)
        {
            CounterOfActiveCells++;
        }
    }
    if (y + 1 < HEIGHT)
    {
        if (MainField[x][y + 1].GetCondition() == 1)
        {
            CounterOfActiveCells++;
        }
    }
    if ( (x + 1 < HEIGHT) && (y + 1 < HEIGHT) )
    {
        if (MainField[x + 1][y + 1].GetCondition() == 1)
        {
            CounterOfActiveCells++;
        }
    }
    if (x + 1 < HEIGHT)
    {
        if (MainField[x + 1][y].GetCondition() == 1)
        {
            CounterOfActiveCells++;
        }
    }
    if ( (x + 1 < HEIGHT) && (y - 1 > -1) )
    {
        if (MainField[x + 1][y - 1].GetCondition() == 1)
        {
            CounterOfActiveCells++;
        }
    }
    if (y  - 1 > -1)
    {
        if (MainField[x][y - 1].GetCondition() == 1)
        {
            CounterOfActiveCells++;
        }
    }
    if ( (x - 1 > -1) && (y - 1 > -1) )
    {
        if (MainField[x - 1][y - 1].GetCondition() == 1)
        {
            CounterOfActiveCells++;
        }
    }

    return CounterOfActiveCells;
}


void Field::PrepareField()
{
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            if (MainField[i][j].GetCondition() == 0 && GetSomeNearCells(i, j) == 3) //If cell is "empty" and near there are 3 "active" cells,
            {                                                                           //then this cell will be activated in the next time
                MainField[i][j].SetCondition(Cell::PREPARED_TO_BE_ACTIVATED);
            }
            else if (MainField[i][j].GetCondition() == 1 && ( GetSomeNearCells(i, j) < 2 || GetSomeNearCells(i, j) > 3) )   //If cell is "active" and there are less
            {                                                                                                                   //then 2 or more then 3 "active" cells
                MainField[i][j].SetCondition(Cell::PREPARED_TO_BE_DELETED);                                                     //near, then this cell will be died
            }                                                                                                                   //in the next time
        }
    }
}


void Field::UpdateField()                                   //Updates the field by setting prepared status of cells to "active" or "empty"
{
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            if (MainField[i][j].GetCondition() == 2)
            {
                MainField[i][j].SetCondition(Cell::ACTIVE);
            }
            else if (MainField[i][j].GetCondition() == 3)
            {
                MainField[i][j].SetCondition(Cell::EMPTY);
            }
        }
    }
}


void Field::StartLife(int count_of_iteratings)
{
    for (int i = 0; i < count_of_iteratings; i++)
    {
        PrepareField();                                 //Field prepares, Updates, is being showed. Then delay and clearing of the screen
        UpdateField();
        Show();
        usleep(50000);
        system("clear");
    }
}
