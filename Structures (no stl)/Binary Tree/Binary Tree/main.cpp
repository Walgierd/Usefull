//main.cpp

#include "Tree.h"
#include <iostream>

int main() {
    Tree<int> tree; 
    char input[100];

    while (true) {
        std::cout << "Enter a number to insert or /number to delete (or 'exit' to quit): ";
        std::cin.getline(input, 100);

        if (strcmp(input, "exit") == 0) {
            break; 
        }

        if (input[0] == '/') {
            int valueToDelete = 0;
            bool validInput = false;

            for (int i = 1; input[i] != '\0'; ++i) {
                if (isdigit(input[i])) {
                    valueToDelete = valueToDelete * 10 + (input[i] - '0');
                    validInput = true;
                }
                else {
                    std::cout << "Invalid input for deletion." << std::endl;
                    validInput = false;
                    break;
                }
            }

            if (validInput) {
                tree.deleteNode(valueToDelete);
                std::cout << "Deleted: " << valueToDelete << std::endl;
            }
        }
        else {
        
            int valueToInsert = 0;
            bool validInput = true;


            for (int i = 0; input[i] != '\0'; ++i) {
                if (isdigit(input[i])) {
                    valueToInsert = valueToInsert * 10 + (input[i] - '0');
                }
                else {
                    std::cout << "Invalid input for insertion." << std::endl;
                    validInput = false;
                    break;
                }
            }

            if (validInput) {
                tree.insert(valueToInsert);
                std::cout << "Inserted: " << valueToInsert << std::endl;
            }
        }


        std::cout << "Current tree structure:" << std::endl;
        tree.printTree(); 
    }

    return 0;
}