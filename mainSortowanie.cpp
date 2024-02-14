#include <iostream>
#include "AlgorytmySortowania.hpp"

using namespace std;

int main(){



    wypelnijTab();
    drukujTab();
    cout << "<-- nieposortowana tablica\n";
    SortujBombelkowo(tab, n);
    drukujTab();
    cout <<  "<-- posortowana tablica\n";

    wypelnijTab();
    drukujTab();
    cout << "<-- nieposortowana tablica\n";
    SortujKoktajlowo(tab, n);
    drukujTab();
    cout <<  "<-- posortowana tablica\n";

    wypelnijTab();
    drukujTab();
    cout << "<-- nieposortowana tablica\n";
    SortujScalaniem(tab, 0, n - 1);
    drukujTab();
    cout <<  "<-- posortowana tablica\n";

    wypelnijTab();
    drukujTab();
    cout << "<-- nieposortowana tablica\n";
    SortujSzybko(tab, 0, n - 1);
    drukujTab();
    cout <<  "<-- posortowana tablica\n";

    wypelnijTab();
    drukujTab();
    cout << "<-- nieposortowana tablica\n";
    SortujPrzezWstawianie(tab, n);
    drukujTab();
    cout <<  "<-- posortowana tablica\n";

    return 0;
}
