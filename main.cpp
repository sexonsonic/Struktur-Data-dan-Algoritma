#include <iostream>
#include <conio.h>

using namespace std;

int main(){
    system("color 3") ;

    cout << "==========================" << endl ;
    cout << "\\ Nama  : M. Rafid M.F //" << endl ;
    cout << "\\ Kelas : 2B           //" << endl ;
    cout << "\\ NIM   : 2107757      //" << endl ;
    cout << "==========================" << endl << endl ;

    int n;
    cout <<" ~ INPUT DATA BARANG ~ " << endl << endl;
    cout <<"Masukkan Jumlah Data yang di Input: ";
    cin >> n;
    cout << endl;

    std::string *brg=new std::string[n];
    float *kd=new float;
    float *jmlh=new float;

    for(int i = 0; i <n; i++)
    {
        cout << "Masukkan Data ke- " << i <<endl;
        cout << "Masukkan Kode Barang: ";
        cin >>kd[i];
        cout << "Masukkan Nama Barang: ";
        cin >>brg[i];
        cout << "Masukkan Jumlah     : ";
        cin >>jmlh[i];
        cout << endl;
    }
    system("CLS");
    cout << "------------------------------------------------------------------" << endl;
    cout << "                     Menampilkan Data Keseluruhan                 " << endl;
    for(int i=0; i<n; i++){
        cout << "------------------------------------------------------------------" << endl;
        cout << " Data ke- " << i << endl;
        cout << " Kode Barang: " << kd [i] << endl;
        cout << " Nama Barang: " << brg[i] << endl;
        cout << " Jumlah     : " << jmlh[i] << endl;
        cout << "------------------------------------------------------------------" << endl;
        cout << endl;
    }

        cout<<endl;
    delete []brg;
    delete []jmlh;
    delete []kd;

    return 0;
}
