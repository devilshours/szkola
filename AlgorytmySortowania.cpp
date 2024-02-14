#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int tab[12];
const int n = 12;

void wypelnijTab() { 
    srand(time(NULL));
    for(int i = 0; i < 12; i++){
        tab[i] = rand() % 100 + 1;
    }
}
void drukujTab() {
    for (int i = 0; i < 12; i++){
        cout << tab[i] << " ";
    }
}


void SortujBombelkowo(int tab[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (tab[j] > tab[j+1]) {
                int temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
    }
}


void SortujKoktajlowo(int tab[], int rozmiar) {
    bool zamienione = true;
    int poczatek = 0;
    int koniec = rozmiar - 1;    
    while (zamienione) {
        zamienione = false;        
        // Sortowanie od lewej do prawej
        for (int i = poczatek; i < koniec; ++i) {
            if (tab[i] > tab[i + 1]) {
                swap(tab[i], tab[i + 1]);
                zamienione = true;
            }
        }       
        if (!zamienione)
            break;       
        zamienione = false;
        --koniec;        
        // Sortowanie od prawej do lewej
        for (int i = koniec - 1; i >= poczatek; --i) {
            if (tab[i] > tab[i + 1]) {
                swap(tab[i], tab[i + 1]);
                zamienione = true;
            }
        }        
        ++poczatek;
    }
}


void Scal(int tab[], int lewy, int srodek, int prawy) {
    int n1 = srodek - lewy + 1;
    int n2 = prawy - srodek;    
    int lewa[n1], prawa[n2];   
    for (int i = 0; i < n1; ++i) {
        lewa[i] = tab[lewy + i];
    }
    for (int j = 0; j < n2; ++j) {
        prawa[j] = tab[srodek + 1 + j];
    }    
    int i = 0, j = 0, k = lewy;   
    while (i < n1 && j < n2) {
        if (lewa[i] <= prawa[j]) {
            tab[k] = lewa[i];
            ++i;
        } else {
            tab[k] = prawa[j];
            ++j;
        }
        ++k;
    }    
    while (i < n1) {
        tab[k] = lewa[i];
        ++i;
        ++k;
    }    
    while (j < n2) {
        tab[k] = prawa[j];
        ++j;
        ++k;
    }
}
int* SortujScalaniem(int arr[], int l, int r) {
    if (l < r) {
        int m = l+(r-l)/2;
        SortujScalaniem(arr, l, m);
        SortujScalaniem(arr, m+1, r);
        Scal(arr, l, m, r);
    }
    return arr;
}


int podzial(int tablica[], int dolny, int gorny) {
    int os = tablica[gorny];
    int i = dolny - 1;    
    for (int j = dolny; j < gorny; ++j) {
        if (tablica[j] < os) {
            ++i;
            swap(tablica[i], tablica[j]);
        }
    }
    
    swap(tablica[i + 1], tablica[gorny]);
    return i + 1;
}

int* SortujSzybko(int arr[], int dolny, int gorny) {
    if (dolny < gorny) {
        int pi = podzial(arr, dolny, gorny);
        SortujSzybko(arr, dolny, pi - 1);
        SortujSzybko(arr, pi + 1, gorny);
    }
    return arr;
}

int* SortujPrzezWstawianie(int tab[], int n) {
    for (int i = 1; i < n; i++) {
        int key = tab[i];
        int j = i - 1;
        while (j >= 0 && tab[j] > key) {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = key;
    }
    return tab;
}



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
