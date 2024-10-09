//Tree.h

#pragma once

#include "Node.h"
#include <iostream>
#include <iomanip>

template <typename T> class Tree {

private:
	
    Node<T>* root;
    Node<T>* TNULL;  
    
    Node<T>* minimum(Node<T>* node) {
        while (node->left != TNULL) {
            node = node->left;
        }
        return node;
    }

    Node<T>* searchTreeHelper(Node<T>* node, T key) {
        if (node == TNULL || key == node->data) {
            return node;
        }
        if (key < node->data) {
            return searchTreeHelper(node->left, key);
        }
        return searchTreeHelper(node->right, key);
    }

    void preOrderHelper(Node<T>* node) {
        if (node != TNULL) {
            std::cout << node->data << " ";
            preOrderHelper(node->left);
            preOrderHelper(node->right);
        }
    }
    void fixDelete(Node<T>* x) {
        while (x != root && !x->isRed) {
            if (x == x->parent->left) {
                Node<T>* w = x->parent->right;
                if (w->isRed) {
                    w->isRed = false;
                    x->parent->isRed = true;
                    leftRotate(x->parent);
                    w = x->parent->right;
                }
                if (!w->left->isRed && !w->right->isRed) {
                    w->isRed = true;
                    x = x->parent;
                }
                else {
                    if (!w->right->isRed) {
                        w->left->isRed = false;
                        w->isRed = true;
                        rightRotate(w);
                        w = x->parent->right;
                    }
                    w->isRed = x->parent->isRed;
                    x->parent->isRed = false;
                    w->right->isRed = false;
                    leftRotate(x->parent);
                    x = root;
                }
            }
            else {
                Node<T>* w = x->parent->left;
                if (w->isRed) {
                    w->isRed = false;
                    x->parent->isRed = true;
                    rightRotate(x->parent);
                    w = x->parent->left;
                }
                if (!w->right->isRed && !w->left->isRed) {
                    w->isRed = true;
                    x = x->parent;
                }
                else {
                    if (!w->left->isRed) {
                        w->right->isRed = false;
                        w->isRed = true;
                        leftRotate(w);
                        w = x->parent->left;
                    }
                    w->isRed = x->parent->isRed;
                    x->parent->isRed = false;
                    w->left->isRed = false;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->isRed = false;
    }

    void fixInsert(Node<T>* k) {
        Node<T>* u;
        while (k->parent && k->parent->isRed) { 
            if (k->parent == k->parent->parent->left) {
                u = k->parent->parent->right;  
                if (u && u->isRed) {
                    
                    k->parent->isRed = false;
                    u->isRed = false;
                    k->parent->parent->isRed = true;
                    k = k->parent->parent;
                }
                else {
                    if (k == k->parent->right) {
                        
                        k = k->parent;
                        leftRotate(k);
                    }
                    
                    k->parent->isRed = false;
                    k->parent->parent->isRed = true;
                    rightRotate(k->parent->parent);
                }
            }
            else {
                u = k->parent->parent->left;  
                if (u && u->isRed) {
                   
                    k->parent->isRed = false;
                    u->isRed = false;
                    k->parent->parent->isRed = true;
                    k = k->parent->parent;
                }
                else {
                    if (k == k->parent->left) {
                       
                        k = k->parent;
                        rightRotate(k);
                    }
                   
                    k->parent->isRed = false;
                    k->parent->parent->isRed = true;
                    leftRotate(k->parent->parent);
                }
            }
            if (k->parent == nullptr) {
                break; 
            }
        }
        root->isRed = false; 
    }

    void leftRotate(Node<T>* x) {
        Node<T>* y = x->right;
        x->right = y->left;
        if (y->left != TNULL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node<T>* x) {
        Node<T>* y = x->left;
        x->left = y->right;
        if (y->right != TNULL) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        }
        else if (x == x->parent->right) {
            x->parent->right = y;
        }
        else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    void printHelper(Node<T>* root, std::string indent, bool last) {
        if (root != TNULL) {
            std::cout << indent;
            if (last) {
                std::cout << "R---- ";
                indent += "   ";
            }
            else {
                std::cout << "L---- ";
                indent += "|  ";
            }

            std::cout << (root->isRed ? "\033[31m" : "\033[37m") << root->data << "\033[0m" << std::endl; // Red if red, White if black
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
    }

public:

    Tree() {
        TNULL = new Node<T>(0); 
        TNULL->isRed = false;
        root = TNULL;
    }

    void printTree() {
        printHelper(this->root, "", true);
    }

    void preOrder() {
        preOrderHelper(this->root);
    }
    
    void rbTransplant(Node<T>* u, Node<T>* v) {
        if (u->parent == nullptr) {
            root = v;
        }
        else if (u == u->parent->left) {
            u->parent->left = v;
        }
        else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    void deleteNode(T data) {
        Node<T>* nodeToDelete = searchTreeHelper(this->root, data);
        Node<T>* y = nodeToDelete;
        Node<T>* x;
        bool yOriginalColor = y->isRed;

        if (nodeToDelete->left == TNULL) {
            x = nodeToDelete->right;
            rbTransplant(nodeToDelete, nodeToDelete->right);
        }
        else if (nodeToDelete->right == TNULL) {
            x = nodeToDelete->left;
            rbTransplant(nodeToDelete, nodeToDelete->left);
        }
        else {
            y = minimum(nodeToDelete->right);
            yOriginalColor = y->isRed;
            x = y->right;
            if (y->parent == nodeToDelete) {
                x->parent = y;
            }
            else {
                rbTransplant(y, y->right);
                y->right = nodeToDelete->right;
                y->right->parent = y;
            }

            rbTransplant(nodeToDelete, y);
            y->left = nodeToDelete->left;
            y->left->parent = y;
            y->isRed = nodeToDelete->isRed;
        }
        delete nodeToDelete;

        if (!yOriginalColor) {
            fixDelete(x);
        }
    }

    void insert(T key) {
        Node<T>* node = new Node<T>(key);
        node->parent = nullptr;
        node->data = key;
        node->left = TNULL;
        node->right = TNULL;

        Node<T>* y = nullptr;
        Node<T>* x = this->root;

        while (x != TNULL) {
            y = x;
            if (node->data < x->data) {
                x = x->left;
            }
            else {
                x = x->right;
            }
        }

        node->parent = y;
        if (y == nullptr) {
            root = node;
        }
        else if (node->data < y->data) {
            y->left = node;
        }
        else {
            y->right = node;
        }

       
        fixInsert(node);  
    }
};
