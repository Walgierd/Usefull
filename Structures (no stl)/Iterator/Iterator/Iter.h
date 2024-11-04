//Iter.h

#pragma once
#include <ostream>
#include <string>
#include <exception>
#include <cstddef>



template <class T>
T DefValue() {
    throw std::exception();
}

template <>
int DefValue<int>() {
    return 6;
}

template <>
double DefValue<double>() {
    return 3.14;
}

template <>
std::string DefValue<std::string>() {
    return "napis";
}

template <class T>
class Vector {
public:
    class ConstIterator {
    protected:
        T* ptr;

    public:
        ConstIterator(T* ptr) : ptr(ptr) {}

        ConstIterator& operator++() noexcept {
            ++ptr;
            return *this;
        }

        ConstIterator operator++(int) noexcept {
            ConstIterator temp = *this;
            ++ptr;
            return temp;
        }

        const T& operator*() const noexcept {
            return *ptr;
        }

        const T* operator->() const noexcept {
            return ptr;
        }

        bool operator!=(const ConstIterator& it) const noexcept {
            return ptr != it.ptr;
        }
    };

    class Iterator : public ConstIterator {
    public:
        using ConstIterator::ConstIterator;

        T& operator*() noexcept {
            return *this->ptr;
        }

        T* operator->() noexcept {
            return this->ptr;
        }
    };

private:
    std::size_t size;
    T* data;

public:
    Vector(const std::size_t size, const T& defValue = DefValue<T>())
        : size(size), data(new T[size]) {
        for (std::size_t i = 0; i < size; ++i) {
            data[i] = defValue;
        }
    }

    ~Vector() noexcept {
        delete[] data;
    }

    std::size_t Size() const noexcept {
        return size;
    }

    const T& operator[](std::size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    T& operator[](std::size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    ConstIterator begin() const noexcept {
        return ConstIterator(data);
    }

    ConstIterator end() const noexcept {
        return ConstIterator(data + size);
    }

    Iterator begin() noexcept {
        return Iterator(data);
    }

    Iterator end() noexcept {
        return Iterator(data + size);
    }

    template <class U>
    friend std::ostream& operator<<(std::ostream& out, const Vector<U>& v) {
        out << "[";
        for (std::size_t i = 0; i < v.size; ++i) {
            out << v.data[i];
            if (i < v.size - 1) out << ", ";
        }
        out << "]";
        return out;
    }
};