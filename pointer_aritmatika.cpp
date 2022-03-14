#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int a[5], *p;
    a[0] = 100;
    a[1] = 200;
    a[2] = 300;
    a[3] = 400;
    a[4] = 500;
    p = &a[0];
    cout << "Nilai " << *p << " ada di alamat memori " << p;
    cout << "\nNilai " << *(p + 1) << " ada di alamat memori " << p + 1;
    cout << "\nNilai " << *(p + 2) << " ada di alamat memori " << p + 2;
    cout << "\nNilai " << *(p + 3) << " ada di alamat memori " << p + 3;
    cout << "\nNilai " << *(p + 4) << " ada di alamat memori " << p + 4;
    getch();
}