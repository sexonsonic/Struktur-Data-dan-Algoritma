#include <iostream>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

using namespace std;

void algo()
{
    
    char word[100];
    int maxStack, i;

    cout << "\nMasukkan Kalimat : ";
    gets(word);
    maxStack = strlen(word);

    cout << "\nHasil Pembalikan" << endl;
    cout << "\nKalimat : " << word;
    cout << "\nMenjadi : ";
    for (i = maxStack; i >= 0; i--)
    {
        char stack = word[i];
        cout << stack;
    }
    getch();
}

int main()
{
    system("color a");
    int pilihan;

    cout << endl;
    cout <<"M.Rafid M.F-2107757\n";

    algo();
}