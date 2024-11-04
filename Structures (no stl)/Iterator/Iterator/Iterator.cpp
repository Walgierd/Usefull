// Iterator.cpp 

#include <iostream>
#include "Iter.h" 

int main() {
    Vector<double> v(9, 11.0); 

    std::cout << "Initial vector: " << v << std::endl;

    for (auto it = v.begin(); it != v.end(); ++it) {
        *it *= 2; 
    }

    std::cout << "Modified vector: " << v << std::endl;

    return 0;
}