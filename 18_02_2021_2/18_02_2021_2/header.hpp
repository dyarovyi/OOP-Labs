//
//  header.hpp
//  18_02_2021_2
//
//  Created by Daniil Yarovyi on 2/18/21.
//

#ifndef header_hpp
#define header_hpp

#include <iostream>
#include <string>

using namespace std;

class Country
{
private:
    string name;
    double area;
    int population;
    
public:
    void set_name (string);
    void set_area (double);
    void set_population (int);
    
    string get_name (void);
    double get_area (void);
    int get_population (void);
    
    double density (void);
};

#endif /* header_hpp */
