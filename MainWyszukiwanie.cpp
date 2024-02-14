#include <iostream>
#include <cmath>
#include "AlgorytmyWyszukiwania.hpp"

int main() {
    int tab[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(tab) / sizeof(tab[0]);
    int key = 9;

    cout << "Wyszukiwanie liniowe: " << liniowe(tab, size, key) << endl;
    cout << "Wyszukiwanie liniowe z wartownikiem: " << liniowezWartownikiem(tab, size, key) << endl;
    cout << "Wyszukiwanie skokowe: " << skokowe(tab, size, key) << endl;
    cout << "Wyszukiwanie binarne: " << binarne(tab, size, key) << endl;

    return 0;
}
