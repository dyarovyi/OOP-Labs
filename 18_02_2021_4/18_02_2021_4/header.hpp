//
//  header.hpp
//  18_02_2021_4
//
//  Created by Daniil Yarovyi on 2/18/21.
//

#ifndef header_hpp
#define header_hpp

#include <iostream>

using namespace std;

class Sphere
{
private:
    int radius;
    const double PI = 3.1415962;
    
public:
    
    void set_radius (int R);
    int get_radius ();
    double area ();
    double circumference ();
    double volume ();
};

#endif /* header_hpp */
