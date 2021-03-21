//
//  header.cpp
//  18_02_2021_3
//
//  Created by Daniil Yarovyi on 2/18/21.
//

#include "header.hpp"


void Queue::initialize ()
{
    size = 0;
    start = 0;
}

void Queue::add (int a)
{
    if (size >= 100)
    {
        cout << "Queue overflow!" << endl;
        exit (0);
    }
    array[size] = a;
    size++;
}

int Queue::get ()
{
    if (start == size)
    {
        cout << "Queue is empty!" << endl;
        exit (0);
    }
    ++start;
    return array[start-1];
}
