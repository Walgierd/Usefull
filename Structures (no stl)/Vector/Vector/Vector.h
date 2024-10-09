//Vector.h

#pragma once

#include <ostream>

template <typename T> T DefValue() {
	throw std::exception();
}

template <> int DefValue() { return 6; }
template <> double DefValue() { return 23; }
template <> std::string DefValue() { return "Super :D"; }

template<typename T> class Vector {
	size_t size;
	T* data;
public:
	Vector(const size_t size, const T& defValue = DefValue<T>()) : size(size), data(new T[size]) {
		for (size_t i = 0; i < size; ++i) {
			data[i] = defValue;
		}
	}
	~Vector() noexcept {
		delete[] data;
	}

	size_t Size() const noexcept {
		return size;
	}

	const T& operator[](const size_t index) const {
		if (index >= size) throw std::exception();
		return data[index];
	}

	T& operator[](const size_t index) {
		if (index >= size) throw std::exception();
		return data[index];
	}
};

template<class T> std::ostream& operator<<(std::ostream& out, const Vector<T>& v) {
	for (size_t i = 0; i < v.Size(); ++i) {
		out << v[i] << std::endl;
	}
	return out;
}