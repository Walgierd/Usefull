//Vector 2.0.cpp

#include <iostream>
#include <algorithm>
#include <numeric>
#include "Vector2.h"

int main()
{
	auto v1 = CreateVector<int>(7, [](const size_t i) { return i; });
	std::cout << v1 << std::endl;

	auto sum = std::accumulate(v1.begin(), v1.end(), 0);
	auto avg = (double)sum / v1.size();

	std::sort(v1.begin(), v1.end(), [](const auto& l, const auto& r) {return r < l; });
	std::cout << v1 << std::endl;

	std::sort(v1.begin(), v1.end(), [avg](const auto& l, const auto& r) {return abs(r-avg) > abs(l - avg); });
	std::cout << v1 << std::endl;

	auto v2 = CreateVector<int>(10, [](const size_t i) { return i / 3; });
	std::cout << v2 << std::endl;

	v2.erase(std::unique(v2.begin(), v2.end()), v2.end());
	std::cout << v2 << std::endl;

	auto v3 = CreateVector<int>(10, [](const size_t i) { return i % 3; });
	std::cout << v3 << std::endl;
	
	std::sort(v3.begin(), v3.end());
	v3.erase(std::unique(v3.begin(), v3.end()), v3.end());
	std::cout << v3 << std::endl;
	
	

	auto v4 = CreateVector<int>(10, [x = -1](const size_t i) mutable {x *= -1; return x * (i + 1); });
	std::cout << v4 << std::endl;

	v4.erase(std::remove_if(v4.begin(), v4.end(), [](const auto& el) {return el <= 0; }), v4.end());
	std::cout << v4 << std::endl;
	
}

