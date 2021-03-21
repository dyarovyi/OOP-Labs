//
//  main.cpp
//  18_02_2021_2
//
//  Created by Daniil Yarovyi on 2/18/21.
//

#include "header.hpp"

int main ()
{
    Country Ukraine;
    Ukraine.set_name ("Ukraine");
    Ukraine.set_area (603.0);
    Ukraine.set_population (40000000);
    
    cout << Ukraine.get_name () << "\t" << Ukraine.get_area () << "\t" << Ukraine.get_population () << endl;
    return 0;
}
