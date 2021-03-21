//
//  main.cpp
//  18_02_2021_1
//
//  Created by Daniil Yarovyi on 2/18/21.
//

#include "func.hpp"

int main ()
{
    int day, month, year;
    std::cin >> day;
    std::cin >> month;
    std::cin >> year;
    
    Date object;
    object.set_date (day, month, year);
    object.print_date ();
    
    return 0;
}
