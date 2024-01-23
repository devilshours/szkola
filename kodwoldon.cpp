#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int a[12];
const int n = 12;

void wypelnijTab() { 
    srand( time( NULL ) );
    for(int i = 0; i < 12; i++){
        a[i] = rand() % 100 + 1;
    }
}
void drukujTab() {
    for (int i = 0; i < 12; i++){
        cout << a[i] << " ";
    }
}



void sortujBombelkowo(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}




int main(){

    wypelnijTab();
    
    cout << "Tablica przed sortowaniem bombelkowym:\n";
    drukujTab();

    sortujBombelkowo(a, n);

    cout << "\n\nTablica po sortowaniu bombelkowym:\n";
    drukujTab();

    return 0;
}