#pragma once
#include <iostream>

class Cell
{
public:
    enum CONDITION {EMPTY, ACTIVE, PREPARED_TO_BE_ACTIVATED, PREPARED_TO_BE_DELETED};
    Cell();
    void SetCondition(enum CONDITION);
    enum CONDITION GetCondition();
private:
    CONDITION state;
};


class Field
{
private:
    int WIDTH;
    int HEIGHT;
    Cell** MainField;
public:
    Field();
    Field(int, int = 0);
    ~Field();
    void FillFieldWithProbability(short int = 30);
    void Show();
    int GetSomeNearCells(int, int);
    void PrepareField();
    void UpdateField();
    void StartLife(int = 500);
};
