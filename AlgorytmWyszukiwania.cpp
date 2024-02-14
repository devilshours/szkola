#include <iostream>
#include <cmath>

using namespace std;

// Wyszukiwanie liniowe
int liniowe(int tab[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (tab[i] == key) {
            return i;
        }
    }
    return -1; // klucz nie został znaleziony
}

// Wyszukiwanie liniowe z wartownikiem
int liniowezWartownikiem(int tab[], int size, int key) {
    int last = tab[size - 1];
    tab[size - 1] = key;
    int i = 0;
    while (tab[i] != key) {
        ++i;
    }
    tab[size - 1] = last;
    if (i < size - 1 || tab[size - 1] == key) {
        return i;
    }
    return -1; // klucz nie został znaleziony
}

// Wyszukiwanie skokowe (jump search)
int skokowe(int tab[], int size, int key) {
    int przod = sqrt(size);
    int tyl = 0;
    while (tab[min(przod, size) - 1] < key) {
        tyl = przod;
        przod += sqrt(size);
        if (tyl >= size) {
            return -1; // klucz nie został znaleziony
        }
    }
    while (tab[tyl] < key) {
        tyl++;
        if (tyl == min(przod, size)) {
            return -1; // klucz nie został znaleziony
        }
    }
    if (tab[tyl] == key) {
        return tyl;
    }
    return -1; // klucz nie został znaleziony
}

// Wyszukiwanie binarne
int binarne(int tab[], int size, int key) {
    int lewy = 0;
    int prawy = size - 1;
    while (lewy <= prawy) {
        int srodek = lewy + (prawy - lewy / 2);
        if (tab[srodek] == key) {
            return srodek;
        }
        if (tab[srodek] < key) {
            lewy = srodek + 1;
        } else {
            prawy = srodek - 1;
        }
    }
    return -1; // klucz nie został znaleziony
}

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