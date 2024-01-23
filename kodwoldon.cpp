#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int tab[12];
const int n = 12;

void wypelnijTab() { 
    srand( time( NULL ) );
    for(int i = 0; i < 12; i++){
        tab[i] = rand() % 100 + 1;
    }
}
void drukujTab() {
    for (int i = 0; i < 12; i++){
        cout << tab[i] << " ";
    }
}



void sortujBombelkowo() {
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





int main(){

    wypelnijTab();
    drukujTab();
    cout << "<-- nieposortowana tablica\n";

    sortujBombelkowo();

    drukujTab();
    cout <<  "<-- posortowana tablica";
    return 0;
}