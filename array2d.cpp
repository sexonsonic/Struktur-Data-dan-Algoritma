#include <iostream>
using namespace std;

int main()
{

    int penjumlahan[3][2];
    int matriks1[3][2] = {
        {2, -5},
        {5, 2},
        {4, 3},
    };

    int matriks2[3][2] = {
        {9, -2},
        {5, 4},
        {-6, 5},
    };

    cout << "Matriks Pertama" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << matriks1[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\n";

    cout << "Matriks Kedua" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << matriks2[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "Penjumlahan Matriks = " << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            penjumlahan[i][j] = matriks1[i][j] + matriks2[i][j];

            cout << penjumlahan[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}