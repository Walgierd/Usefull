//Matrix.h

#pragma once

#include <ostream>

template <class T> T DefValue() {
	throw std::exception();
}

template <class T> class Matrix {
	size_t m;
	size_t n;
	T* data;

public:
	Matrix(const size_t m, const size_t n, const T& defValue = DefValue<T>()) : m(m), n(n), data(new T[m, n]) {
		for (size_t i = 0; i < m; ++i) {
			for (size_t j = 0; j < n; ++j) {
				data[i, j] = defValue;
			}
		}
			
	}

	~Matrix() noexcept {
		delete[] data;
	}

	size_t Size_m() const noexcept {
		return m;
	}

	size_t Size_n() const noexcept {
		return n;
	}

	const T& operator[](const size_t index) const {
		if (index >= m && index >= n) throw std::exception();
		return data[index];
	}

	T& operator[](const size_t index) {
		if (index >= m && index >= n) throw std::exception();
		return data[index];
	}
};

template<class T> std::ostream& operator<<(std::ostream& out, const Matrix<T>& mat) {
	for (size_t i = 0; i < mat.Size_m(); ++i) {
		for (size_t j = 0; j < mat.Size_n(); ++j) {
			out << mat[i, j] << " ";
		}
		std::cout << std::endl;
		
	}
	return out;
}