#include <iostream>
using namespace std;

int main()
{
    int nilai[5] = {80, 90, 100, 20, 50};
    int total=0, ratarata, totalkali=1;
    int jmlharray = sizeof(nilai) / sizeof(nilai[0]);

    for (int i = 0; i < 5; i++)
    {
        cout << nilai[i] << endl;
        total += nilai[i];
        totalkali *= nilai[i];
    }

    ratarata = total / jmlharray;
    cout << "Total nilai = " << total <<endl;
    cout << "rata rata nilai adalah = " << ratarata << endl;
    cout << "total kali = " << totalkali;
}