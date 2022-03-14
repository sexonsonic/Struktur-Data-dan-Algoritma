#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int ukuran = 5;
    int *buku = new int[5];
        for (int i = 0; i < ukuran; i++)
    {
        cout << "masukan nilai (" << (i + 1) << ") : ";
        cin >> buku[i];
    }
    cout << endl;
    cout << "nilai yang dimasukan :" << endl;
    for (int i = 0; i < ukuran; i++)
    {
        cout << buku[i] << endl;
    }
    delete[] buku;
}