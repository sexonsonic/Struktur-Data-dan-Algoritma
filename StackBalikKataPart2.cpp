#include <iostream>
#include <string.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

int main()

{
    char word[100];
    int maxStack, i;

    cout <<"Masukkan Kalimat : ";
    gets(word);
    maxStack = strlen(word);

    system("cls");

    cout <<"Kalimat : "<< word;
    cout <<"\nMenjadi :";
    for (i = maxStack; i >= 0; i--)
    {
        char stack = word[i];
        cout << stack;
    }
}
