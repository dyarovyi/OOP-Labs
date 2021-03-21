//
//  func.hpp
//  18_02_2021_1
//
//  Created by Daniil Yarovyi on 2/18/21.
//

#ifndef func_hpp
#define func_hpp

#include <iostream>

class Date
{
private:
    int day, month, year;
    
public:
    void set_date (int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    
    void print_date ()
    {
        std::cout << day << "." << month << "." << year << std::endl;
    }
};

#endif /* func_hpp */
