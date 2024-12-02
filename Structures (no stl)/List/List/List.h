//List.h

#pragma once

#include <iostream>
#include <functional>
#include <cassert>

template<typename T>
struct Part {
    T data;
    Part* next;

    Part(const T& value) : data(value), next(nullptr) {}
};

template<typename T>
class List {
private:
    Part<T>* head;
    size_t list_size;

public:
    // Deklaracja iteratora przed metodami
    class iterator;

    List() : head(nullptr), list_size(0) {}

    List(size_t n, const std::function<T(size_t)>& lambda) : head(nullptr), list_size(0) {
        for (size_t i = 0; i < n; ++i) {
            pushBack(lambda(i));
        }
    }

    ~List() { clear(); }

    void pushBack(const T& value) {
        Part<T>* newPart = new Part<T>(value);
        if (head == nullptr) {
            head = newPart;
        }
        else {
            Part<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newPart;
        }
        ++list_size;
    }

    void insert(iterator it, const T& value) {
        Part<T>* newPart = new Part<T>(value);
        if (it == begin()) {
            newPart->next = head;
            head = newPart;
        }
        else {
            Part<T>* prev = nullptr;
            Part<T>* current = head;
            while (current != nullptr && current != it.part) {
                prev = current;
                current = current->next;
            }
            if (prev != nullptr) {
                prev->next = newPart;
                newPart->next = current;
            }
        }
        ++list_size;
    }

    void erase(iterator it) {
        if (it == begin()) {
            Part<T>* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            Part<T>* prev = nullptr;
            Part<T>* current = head;
            while (current != nullptr && current != it.part) {
                prev = current;
                current = current->next;
            }

            if (current != nullptr) {
                if (prev != nullptr) {
                    prev->next = current->next;
                    delete current;
                }
            }
            else {

                std::cerr << "Error: Iterator is pointing to nullptr!" << std::endl;
            }
        }
        --list_size;
    }

    size_t size() const {
        return list_size;
    }

    void clear() {
        Part<T>* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
        list_size = 0;
    }

    // Klasa iterator
    class iterator {
    public:
        iterator(Part<T>* part, Part<T>* head) : part(part), head(head) {}

        bool operator==(const iterator& other) const {
            return part == other.part;
        }

        T& operator*() {
            return part->data;
        }

        T* operator->() {
            return &part->data;
        }

        iterator& operator++() {
            part = part->next;
            return *this;
        }

        iterator operator++(int) {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        iterator& operator--() {
            if (part == head) {
                part = nullptr;
            }
            else {
                Part<T>* current = head;
                Part<T>* prev = nullptr;
                while (current != nullptr && current->next != part) {
                    prev = current;
                    current = current->next;
                }
                part = prev;
            }
            return *this;
        }

        iterator operator--(int) {
            iterator tmp = *this;
            --(*this);
            return tmp;
        }

        bool operator!=(const iterator& other) const {
            return part != other.part;
        }

        friend class List<T>;

    private:
        Part<T>* part;
        Part<T>* head;
    };

    // Klasa const_iterator
    class const_iterator {
    public:
        const_iterator(Part<T>* part) : part(part) {}

        const T& operator*() const {
            return part->data;
        }

        const T* operator->() const {
            return &part->data;
        }

        const_iterator& operator++() {
            part = part->next;
            return *this;
        }

        const_iterator operator++(int) {
            const_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator!=(const const_iterator& other) const {
            return part != other.part;
        }

        friend class List<T>;

    private:
        Part<T>* part;
    };

    iterator begin() {
        return iterator(head, head);
    }

    const_iterator begin() const {
        return const_iterator(head);
    }

    iterator end() {
        return iterator(nullptr, head);
    }

    const_iterator end() const {
        return const_iterator(nullptr);
    }
};
