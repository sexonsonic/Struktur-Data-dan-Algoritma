#include <iostream>
#include <conio.h>
using namespace std;

struct Barang
{
    string *nama_barang = new string[20];
    float *kode_barang = new float;
    float *jml_barang = new float;
};

Barang brg;

int main()
{
    cout << "============================" << endl;
    cout << "|| Nama  : Farrel Fadilah ||" << endl;
    cout << "|| Kelas : 2B             ||" << endl;
    cout << "|| NIM   : 2104671        ||" << endl;
    cout << "============================" << endl;
    cout << endl;

    int jml_input;
    cout << "Input banyaknya data : ";
    cin >> jml_input;
    cout << endl;

   

    for (int i = 0; i < jml_input; i++)
    {
        cout << "Masukkan Data ke-" << i + 1 << endl;
        cout << "Masukkan Kode Barang               : ";
        cin >> brg.kode_barang[i];
        cout << "Masukkan Nama Barang               : ";
        cin >> brg.nama_barang[i];
        cout << "Masukkan Jumlah/Banyaknya Barang   : ";
        cin >> brg.jml_barang[i];
        cout << endl;
    }

    system("CLS");
    cout << "                     Menampilkan Data Keseluruhan                 " << endl;
    for (int i = 0; i < jml_input; i++)
    {
        cout << "Data Ke-" << i + 1 << endl;
        cout << "Kode Barang      : " << brg.kode_barang[i] << endl;
        cout << "Nama Barang      : " << brg.nama_barang[i] << endl;
        cout << "Jumlah Barang    : " << brg.jml_barang[i] << endl;
        cout << endl;
    }
    delete[] brg.nama_barang;
    delete[] brg.jml_barang;
    delete[] brg.kode_barang;
}