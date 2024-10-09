//Node.h

#pragma once

template <typename T> class Node {

public:
    T data;
    bool isRed;  //T - Red, F - Black
    Node* left;
    Node* right;
    Node* parent;

    Node(T value) : data(value), isRed(true), left(nullptr), right(nullptr), parent(nullptr) {}
};