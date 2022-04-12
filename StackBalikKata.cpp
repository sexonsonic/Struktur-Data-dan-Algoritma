#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
using namespace std;

#define MaxChar 200

struct tumpukan
{
    char isi[MaxChar];
    int awal;
} tumpuk;

void Push(char karakter)
{
    if (tumpuk.awal == MaxChar)
    {
        cout << "Tumpukkan sudah Penuh !";
        getch();
    } else {
        tumpuk.awal = tumpuk.awal + 1;
        tumpuk.isi[tumpuk.awal] = karakter;
    }
}

char Pop()
{
    char hasil;
    if (tumpuk.awal == 0)
    {
        cout << "Tumpukkan sudah kososng";
    } else {
        hasil = tumpuk.isi[tumpuk.awal];
        tumpuk.awal = tumpuk.awal - 1;
    }
    return hasil;
}

int main()
{
    int i;
    char kalimat[MaxChar];
    system("CLS");
    tumpuk.awal = 0;
    cout << "APLIKASI STACK MEMBALIK KALIMAT\n";
    cout << "===============================\n";

    cout << "Masukkan Nama : ";
    gets(kalimat);
    system("CLS");
    cout << "Nama Asli : " << kalimat;

    for (i = 0; i < strlen(kalimat); i++)
    {
        Push(kalimat[i]);
    }
    cout << "\nNama Setelah dibalik : ";

    for ( i = 0; i < strlen(kalimat); i++)
    {
        cout << "" << Pop();
    }
    getch();
}