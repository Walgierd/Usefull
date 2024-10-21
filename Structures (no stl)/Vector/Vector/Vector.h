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
	Vector(const size_t size, const T& defValue = DefValue<T>()) : size(size), data(new T[size]) { //Parametryczny
		for (size_t i = 0; i < size; ++i) {
			data[i] = defValue;
		}
	}

	Vector(const Vector& another) : size(another.size), data(new T[another.size]) { //Kopiuj¹cy
		for (size_t i = 0; i < size; ++i) {
			data[i] = another.data[i];
		}	
	}

	Vector(Vector&& another) noexcept : size(another.size), data(another.data) { //Przenosz¹cy
		another.size = 0;
		another.data = nullptr;  
	}
	
	~Vector() noexcept {
		delete[] data;
	}
	
	Vector<T>& operator=(const Vector<T>& another) { //Operator przypisania
		if (this != &another) {
			delete[] data;
			size = another.size;
			data = new T[size];
			for (size_t i = 0; i < size; ++i) {
				data[i] = another.data[i];
			}
		}
		return *this;
	}

	
	Vector<T>& operator=(Vector<T>&& another) noexcept { //Operator przeniesienia
		if (this != &another) {
			delete[] data;
			size = another.size;
			data = another.data;
			another.size = 0;
			another.data = nullptr;
		}
		return *this;
	}

	size_t Size() const noexcept {
		return size;
	}

	const T& operator[](const size_t index) const { //Operator []
		if (index >= size) throw std::exception();
		return data[index];
	}

	T& operator[](const size_t index) { //Operator []
		if (index >= size) throw std::exception();
		return data[index];
	}

	bool operator==(const Vector<T>& another) const { //Operator ==
		if (size != another.size) return false;
		for (size_t i = 0; i < size; ++i) {
			if (data[i] != another.data[i]) return false;
		}
		return true;
	}

	bool operator!=(const Vector<T>& another) const { //Operator !=
		return !(*this == another);
	}

	void PushBack(const T& value) { //PushBack
		T* newData = new T[size + 1];
		for (size_t i = 0; i < size; ++i) {
			newData[i] = data[i];
		}
		newData[size] = value;
		delete[] data;
		data = newData;
		++size;
	}
};

template<class T> std::ostream& operator<<(std::ostream& out, const Vector<T>& v) {
	for (size_t i = 0; i < v.Size(); ++i) {
		out << v[i] << std::endl;
	}
	return out;
}