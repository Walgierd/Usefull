//List.cpp

#include <iostream>
#include "List.h"

int main()
{
    // Testowanie funkcjonalności listy
    List<double> lista(4, [](const size_t i) { return 1.0 + i; });

    std::cout << "Lista: \n";
    // Wyświetlanie zawartości listy
    for (const auto& el : lista) std::cout << el << std::endl;

    // Modyfikacja elementów listy
    for (auto& el : lista) el *= 2.0;

    std::cout << "Lista po modyfikacji: \n";
    // Wyświetlanie po modyfikacji
    for (auto it = lista.begin(); it != lista.end(); ++it) std::cout << *it << std::endl;

    std::cout << "Lista bez pierwszego elementu: \n";
    // Usuwanie pierwszego elementu
    lista.erase(lista.begin());
    for (const auto& el : lista) std::cout << el << std::endl;

    std::cout << "Lista bez ostatniego elementu: \n";
    // Usuwanie ostatniego elementu
    lista.erase(--lista.end());
    for (const auto& el : lista) std::cout << el << std::endl;

    std::cout << "Lista z nowym na koncu: \n";
    // Dodawanie elementu na końcu
    lista.pushBack(13.3);
    for (const auto& el : lista) std::cout << el << std::endl;

    std::cout << "Lista z nowym w srodku: \n";
    // Wstawianie elementu w środek
    lista.insert(++lista.begin(), 16.6);
    for (const auto& el : lista) std::cout << el << std::endl;

    return 0;
}

