#pragma once

//Vector2.0.h

#pragma once

#include <vector>
#include<functional>
#include<ostream>

template <class T> std::vector<T> CreateVector(const size_t size, const std::function<T(const size_t)>& f) {
	std::vector<T> result(size);
	for (size_t i = 0; i < size; ++i) {
		result[i] = f(i);

	}
	return result;
}
template<class T> std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
	for (const auto& el : v) {
		out << el << std::endl;
	}
	return out;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
	for (const auto& el : v) {
		out << el << " ";
	}
	out << std::endl;
	return out;
}