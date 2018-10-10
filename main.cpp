#include "structures.h"

int main()
{
    Field MyField(24);
    MyField.FillFieldWithProbability(20);
    MyField.StartLife(1000);

    return 0;
}
