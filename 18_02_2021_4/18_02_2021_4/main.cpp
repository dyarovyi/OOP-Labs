//
//  main.cpp
//  18_02_2021_4
//
//  Created by Daniil Yarovyi on 2/18/21.
//

#include "header.cpp"

int main ()
{
    Sphere S1;
    int R;
    cin >> R;
    
    S1.set_radius (R);
    double area = S1.area();
    double circumference = S1.circumference();
    double volume = S1.volume();
    
    cout << area << "\t" << circumference << "\t" << volume << endl;
    
    return 0;
}
