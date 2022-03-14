#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int baju = 9;
    int *ptr;
    ptr = &baju;
    cout << "Alamat Dari Variable Baju :" << ptr << endl;
    cout << "Nilai dari Alamat ptr : " << *ptr << endl;
}