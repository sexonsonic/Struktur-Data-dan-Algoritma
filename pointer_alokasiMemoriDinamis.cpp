#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int *bil = new int;
    *bil = 20;
    cout << "Nilai bil :" << *bil << " pada lokasi memori :" << bil << endl;
    cout << "Dengan Ukuran Data : " << sizeof(bil) << "Byte" << endl;
}