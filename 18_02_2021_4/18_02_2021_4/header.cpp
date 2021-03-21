//
//  header.cpp
//  18_02_2021_4
//
//  Created by Daniil Yarovyi on 2/18/21.
//

#include "header.hpp"

void Sphere::set_radius (int R)
{
    radius = R;
}

int Sphere::get_radius ()
{
    return radius;
}

double Sphere::area ()
{
    return PI * radius * radius;
}

double Sphere::circumference ()
{
    return 2 * PI * radius;
}

double Sphere::volume ()
{
    return 4 / 3 * PI * radius * radius * radius;
}
