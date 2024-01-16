#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void wypelnijTab(int a[], int size) { 
    srand( time( NULL ) );
    for(int i = 0; i < size; i++)
    {
        a[i] = rand() % 100 + 1;
    }
}

void sortujBombelkowo(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // zamiana miejscami
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void drukujTab(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main(){
    const int rozmiar = 12;
    int a[rozmiar];
    
    wypelnijTab(a, rozmiar);
    
    cout << "Tablica przed sortowaniem bombelkowym:\n";
    drukujTab(a, rozmiar);

    sortujBombelkowo(a, rozmiar);

    cout << "\n\nTablica po sortowaniu bombelkowym:\n";
    drukujTab(a, rozmiar);

    return 0;
}