#include <iostream>
#include "a.h"


int main()
{
    size_t max_elements = 10;
    A a(max_elements);

    a.PrintVector();
    a.PrintMap();

    a.DeleteElevents();

    a.Synchronize();



    return 0;
}
