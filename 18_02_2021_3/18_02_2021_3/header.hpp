//
//  header.hpp
//  18_02_2021_3
//
//  Created by Daniil Yarovyi on 2/18/21.
//

#ifndef header_hpp
#define header_hpp

#include <iostream>

using namespace std;

class Queue
{
private:
    int size;
    int start;
    int array[100];
    
public:
    void initialize (void);
    void add (int);
    int get (void);
};

#endif /* header_hpp */
