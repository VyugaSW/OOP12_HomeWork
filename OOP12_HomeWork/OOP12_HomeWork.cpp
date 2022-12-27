

#include <iostream>
#include "Array.h"

int main()
{
    Array <char/*int*/> a(5);
    a.fill();
    a.print();
    a + 5;
    a.print();
    
}

