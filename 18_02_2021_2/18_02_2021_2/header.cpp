//
//  header.cpp
//  18_02_2021_2
//
//  Created by Daniil Yarovyi on 2/18/21.
//

#include "header.hpp"

void Country::set_name (string name)
{
    this->name = name;
}

void Country::set_area (double area)
{
    this->area = area;
}

void Country::set_population (int population)
{
    this->population = population;
}


string Country::get_name ()
{
    return this->name;
}

double Country::get_area ()
{
    return this->area;
}

int Country::get_population ()
{
    return this->population;
}


double Country::density ()
{
    return this->population / this->area;
}
