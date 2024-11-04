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
	

	//Zadanie domowe:
	std::cout << "Zadanie 1:" << std::endl;

	auto powers2 = CreateVector<int>(10, [](const size_t i) {return 1 << i; }); //Zadanie 1
	std::cout << "Powers of 2:\n" << powers2 << std::endl;

	std::cout << "Zadanie 2:" << std::endl;

	auto fibo = CreateVector<int>(10, [a = 0, b = 1](const size_t i) mutable { //Zadanie 2
		if (i == 0) return a;
		if (i == 1) return b;
		int fib = a + b;
		a = b;
		b = fib;
		return fib;
		});
	std::cout << "Fibonacci:\n" << fibo << std::endl;

	std::cout << "Zadanie 3:" << std::endl;

	auto vminmax = CreateVector<int>(10, [](const size_t i) {return i * 2 - 5; }); //Zadanie 3
	std::cout << "Original vector:\n" << vminmax << std::endl;
	vminmax.erase(std::remove(vminmax.begin(), vminmax.end(), *std::min_element(vminmax.begin(), vminmax.end())), vminmax.end());
	vminmax.erase(std::remove(vminmax.begin(), vminmax.end(), *std::max_element(vminmax.begin(), vminmax.end())), vminmax.end());
	std::cout << "Vector after erasing:\n" << vminmax << std::endl;

	std::cout << "Zadanie 4:" << std::endl;

	auto count_even = [](const std::vector <int>& v) { //Zadanie 4
		return std::count_if(v.begin(), v.end(), [](int n) {return n % 2 == 0; });
		};
	std::cout << "Number of even elements: " << count_even(fibo) << std::endl;

	std::cout << "Zadanie 5:" << std::endl;

	auto remove_multiples = [](std::vector<int>& v) {
		std::sort(v.begin(), v.end()); 
		v.erase(std::unique(v.begin(), v.end()), v.end()); 

		v.erase(std::remove_if(v.begin(), v.end(), [&](int n) {
			for (int m : v) {
				if (m != n && m != 0 && n % m == 0) {
					return true; 
				}
			}
			return false;
			}), v.end());
		};
	remove_multiples(fibo);
	std::cout << "After removing multiples: \n " << fibo << std::endl;

	std::cout << "Zadanie 6:" << std::endl;

	auto remove_negatives = [](std::vector<int>& v) {
		v.erase(std::remove_if(v.begin(), v.end(), [](int n) { return n < 0; }), v.end());
		};
	remove_negatives(vminmax);
	std::cout << "After removing negatives: " << vminmax << std::endl;

	std::cout << "Zadanie 7:" << std::endl;

	auto remove_evens = [](std::vector<int>& v) {
		v.erase(std::remove_if(v.begin(), v.end(), [](int n) { return n % 2 == 0; }), v.end());
		};
	remove_evens(v3);
	std::cout << "After removing evens: " << v3 << std::endl;


	std::cout << "Zadanie 8:" << std::endl;


	auto override_elements = [](std::vector<int>& v, int upper, int lower) {
		std::for_each(v.begin(), v.end(), [upper, lower](int& n) {
			if (n > upper) n = upper;
			if (n < lower) n = lower;
			});
		};
	override_elements(v2, 5, -3);
	std::cout << "After overriding elements: " << v2 << std::endl;
}

