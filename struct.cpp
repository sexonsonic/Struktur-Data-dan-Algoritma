#include <iostream>

using namespace std;

struct mahasiswa
{
    int nim;
    string nama;
    int umur;
    int nilaiSDA;
    int totalNilai;

};
mahasiswa mhs;


int main()
{
    int nilaiBonus = 30;
    mhs.totalNilai = mhs.nilaiSDA + nilaiBonus;
    cout << "NIM : ";
    cin >> mhs.nim;
    cout << "Nama : ";
    cin >> mhs.nama;
    cout << "Umur : ";
    cin >> mhs.umur;
    cout<<"Nilai SDA :";
    cin >> mhs.nilaiSDA;

    if (mhs.nilaiSDA>)
    {
        /* code */
    }
    
    cout << endl;

    cout<<"NIM : "<<mhs.nim<<endl;
    cout<<"Nama :"<<mhs.nama<<endl;
    cout << "Umur :" << mhs.umur << endl;
    cout << "Nilai SDA : " << mhs.nilaiSDA << endl;
    cout << "Total Nilai : " << mhs.totalNilai;

    if (mhs.totalNilai <= 80)
    {
        cout << "Keterangan : Remedial";
    }
    
}
