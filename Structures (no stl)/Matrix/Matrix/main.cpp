//main.cpp for Matrix project

#include <iostream>
#include <string>
#include "Matrix.h"

int main() {
	Matrix<int> mat1(3, 4, 4);
	std::cout << mat1 << std::endl;

	Matrix<double> mat2(3, 4, 4);
	std::cout << mat2 << std::endl;

	Matrix<std::string> mat3(4, 4, "ok");
	std::cout << mat3 << std::endl;


}