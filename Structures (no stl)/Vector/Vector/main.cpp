//main.cpp for Vector project


#include <iostream>
#include <string>
#include "Vector.h"

int main() {
	Vector<int> v1(3);
	std::cout << v1 << std::endl;

	Vector<double> v2(6);
	std::cout << v2 << std::endl;

	Vector<std::string> v3(9);
	std::cout << v3 << std::endl;


}