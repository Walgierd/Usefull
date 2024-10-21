//main.cpp for Vector project


#include <iostream>
#include <string>
#include <utility>
#include "Vector.h"

int main() {
    std::cout << "PushBack:" << std::endl;
    Vector<int> v1(3);
    std::cout << v1 << std::endl;
    v1.PushBack(10);
    v1.PushBack(20);
    std::cout << v1 << std::endl;

    std::cout << "Porownanie:" << std::endl;
    Vector<int> v2 = v1;
    v2[0] = 99;
    std::cout << v2 << std::endl;
    std::cout << v1 << std::endl;
    std::cout << (v1 == v2) << std::endl;

    std::cout << "PushBack doubla:" << std::endl;
    Vector<double> v3(3, 3.14);
    v3.PushBack(2.71);
    std::cout << v3 << std::endl;

    std::cout << "Zamiana stringow:" << std::endl;
    Vector<std::string> v4(2, "Hello");
    v4.PushBack("World");
    Vector<std::string> v5 = v4;
    v5[1] = "Everyone";
    std::cout << v4 << std::endl;
    std::cout << v5 << std::endl;
    std::cout << (v4 != v5) << std::endl;

    return 0;
}