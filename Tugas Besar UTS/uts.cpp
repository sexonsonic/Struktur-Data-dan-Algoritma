#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

using namespace std;

int nmr, total, input[10]; // variable umum

struct node // struct linked-list
{
    int nomorpem;
    int hargatotal;
    int hrgaaks;
    int hrgamdl;
    int hrgamrk;
    string merk;
    string model;
    string warna;
    string ukuran;
    string nama;
    string aksesoris;
    string alamat;
    struct node *next;

} *front = NULL, *rear, *temp;

void gotoxy(int x, int y) // fungsi go to x,y
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    cout.flush();
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

void insert() // fungsi inputan
{
    system("cls");
    temp = new node;
    string mrk;
    string mdl;
    string wrn;
    string ukr;
    string nm;
    string aks;
    string alamat;

    // untuk membuat tampilan table agar lebih rapih
    gotoxy(1, 1);
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n";
    gotoxy(65, 2);
    cout << "HELM CIGARATES\n";
    gotoxy(50, 3);
    cout << "Jl.Istiqomah 1,Cinunuk,kab.Bandung,Jawa Barat 40624\n";
    gotoxy(1, 4);
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
    gotoxy(29, 6);
    cout << "                                      | PEMBELIAN HELM |";
    gotoxy(25, 8);
    cout << "        > Masukkan kode Pembelian\n";
    gotoxy(25, 9);
    cout << "        > Contoh : 01\n";
    gotoxy(20, 11);
    cout << "============================================================================================================================================================\n";
    gotoxy(20, 12);
    cout << "|Kode | Merk Helm         || Harga Merk       ||  Model Helm      ||   Harga Model   || Warna        || Ukuran     || Aksesoris Helm    || Harga Aksesoris |\n";
    gotoxy(20, 13);
    cout << "============================================================================================================================================================\n";
    gotoxy(20, 14);
    cout << "|  1  | KYT               || Rp.100.000,00    || FULL FACE        || RP. 50.000,00   || Merah        || S          || Visor             || Rp.300.000,00   |\n";
    gotoxy(20, 15);
    cout << "|  2  | TRX               || Rp.150.000,00    || OPEN FACE        || RP. 40.000,00   || Hijau        || M          || Balaclava         || Rp.60.000,00    |\n";
    gotoxy(20, 16);
    cout << "|  3  | SHARK             || Rp.170.000,00    || HALF FACE        || RP. 45.000,00   || Kuning       || L          || Spoiler           || Rp.50.000,00    |\n";
    gotoxy(20, 17);
    cout << "|  4  | INK               || Rp.155.000,00    || FLIP UP          || RP. 70.000,00   || Biru         || XL         || Intercom          || Rp.500.000,00   |\n";
    gotoxy(20, 18);
    cout << "|  5  | SHOEI             || Rp.200.000,00    || OFFROAD          || RP. 65.000,00   || Hitam        ||            || Go Pro            || Rp.3.000.000,00 |\n";
    gotoxy(20, 19);
    cout << "|  6  | NOLAN             || Rp.200.000,00    || DUAL SPORT       || RP. 55.000,00   || Abu-Abu      ||            || Antifog           || Rp.100.000,00   |\n";
    gotoxy(20, 20);
    cout << "|  7  | CARGLOSS          || Rp.135.000,00    ||                  ||                 ||              ||            || Tear Off          || Rp.55.000,00    |\n";
    gotoxy(20, 21);
    cout << "|  8  | KBC               || Rp.120.000,00    ||                  ||                 ||              ||            || Stiker            || Rp.10.000,00    |\n";
    gotoxy(20, 22);
    cout << "|  9  | ARAI              || Rp.500.000,00    ||                  ||                 ||              ||            ||                                      |\n";
    gotoxy(20, 23);
    cout << "============================================================================================================================================================\n";
    gotoxy(1, 24);
    cout << endl;

    // Inputan pembelian User
    cout << "== INPUT PEMBELIAN ==\n\n";
    cout << "Input No. Pesanan\t: "; // ex. 01
    cin >> nmr;
    cin.ignore(1, '\n');
    cout << "Input Merk\t\t: ";
    getline(cin, mrk);
    cout << "Input Model\t\t: ";
    getline(cin, mdl);
    cout << "Input Warna\t\t: ";
    getline(cin, wrn);
    cout << "Input Ukuran\t\t: ";
    getline(cin, ukr);
    cout << "Input Nama\t\t: ";
    getline(cin, nm);
    cout << "Input Alamat\t\t: ";
    getline(cin, alamat);
    cout << "Input Aksesoris\t\t: ";
    getline(cin, aks);

    // alokasi memori
    temp->nomorpem = nmr;
    temp->merk = mrk;
    temp->model = mdl;
    temp->warna = wrn;
    temp->ukuran = ukr;
    temp->nama = nm;
    temp->aksesoris = aks;

    temp->next = NULL;

    if (front == NULL)
        front = rear = temp;

    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void del() // fungsi untuk menghapus data
{
    if (front == NULL)
    {
        cout << "Belum ada Pesanan!\n";
        getch();
    }
    else
    {
        temp = front;
        front = front->next;
        cout << "Pembelian atas nama" << temp->nama << " Telah DIhapus beserta Datanya\n";
        delete (temp);
        getch();
    }
}

void display() // fungsi untuk menampilkan data yang sudah di inputkan sebelumnya
{
    system("cls");
    int total, hrgaaks, hrgamdl, hrgamrk;
    if (front == NULL)
    {
        cout << "Belum ada data Pembelian!\n";
        getch;
    }

    else
    {
        temp = front;
        while (temp != NULL)
        {
            cout << "\t\t DATA PEMBELIAN \t\t" << endl;
            cout << endl;
            cout << "No. Pembelian\t: " << temp->nomorpem << endl;
            cout << "Nama\t\t: " << temp->nama << endl;
            cout << "Merk Helm\t: " << temp->merk << endl;

            // kondisi untuk menentukan harga pada merk helm
            if ((temp->merk == "KYT") || (temp->merk == "kyt"))
            {

                hrgamrk = 100000;
            }
            else if ((temp->merk == "TRX") || (temp->merk == "trx"))
            {

                hrgamrk = 150000;
            }
            else if ((temp->merk == "SHARK") || (temp->merk == "shark"))
            {

                hrgamrk = 170000;
            }
            else if ((temp->merk == "INK") || (temp->merk == "ink"))
            {

                hrgamrk = 155000;
            }
            else if ((temp->merk == "SHOEI") || (temp->merk == "shoei"))
            {

                hrgamrk = 200000;
            }
            else if ((temp->merk == "NOLAN") || (temp->merk == "nolan"))
            {

                hrgamrk = 200000;
            }
            else if ((temp->merk == "CARGLOSS") || (temp->merk == "cargloss"))
            {

                hrgamrk = 135000;
            }
            else if ((temp->merk == "KBC") || (temp->merk == "kbc"))
            {

                hrgamrk = 120000;
            }
            else if ((temp->merk == "ARAI") || (temp->merk == "arai"))
            {

                hrgamrk = 500000;
            }

            cout << "Model Helm\t: " << temp->model << endl;

            // kondisi untuk menentukan harga model helm
            if ((temp->model == "FULL FACE") || (temp->model == "full face"))
            {
                hrgamdl = 50000;
            }
            else if ((temp->model == "OPEN FACE") || (temp->model == "open face"))
            {
                hrgamdl = 40000;
            }
            else if ((temp->model == "HALF FACE") || (temp->model == "half face"))
            {
                hrgamdl = 45000;
            }
            else if ((temp->model == "FLIP UP") || (temp->model == "flip up"))
            {
                hrgamdl = 70000;
            }
            else if ((temp->model == "OFFROAD") || (temp->model == "offroad"))
            {
                hrgamdl = 65000;
            }
            else if ((temp->model == "DUAL SPORT") || (temp->model == "dual sport"))
            {
                hrgamdl = 55000;
            }

            cout << "Warna Helm\t: " << temp->warna << endl;
            cout << "Ukuran Helm\t: " << temp->ukuran << endl;
            cout << "Aksesoris\t: " << temp->aksesoris << endl;
            // kondisi untuk menentukan harga aksesoris helm
            if ((temp->aksesoris == "VISOR") || (temp->aksesoris == "visor"))
            {
                hrgaaks = 300000;
            }
            else if ((temp->aksesoris == "BALACLAVA") || (temp->aksesoris == "balaclava"))
            {
                hrgaaks = 60000;
            }
            else if ((temp->aksesoris == "SPOILER") || (temp->aksesoris == "spoiler"))
            {
                hrgaaks = 50000;
            }
            else if ((temp->aksesoris == "INTERCOM") || (temp->aksesoris == "intercom"))
            {
                hrgaaks = 500000;
            }
            else if ((temp->aksesoris == "GO PRO") || (temp->aksesoris == "go pro"))
            {
                hrgaaks = 3000000;
            }
            else if ((temp->aksesoris == "ANTIFOG") || (temp->aksesoris == "antifog"))
            {
                hrgaaks = 100000;
            }
            else if ((temp->aksesoris == "TEAR OFF") || (temp->aksesoris == "tear off"))
            {
                hrgaaks = 55000;
            }
            else if ((temp->aksesoris == "STIKER") || (temp->aksesoris == "sticker"))
            {
                hrgaaks = 10000;
            }
            else if ((temp->aksesoris == "NULL") || (temp->aksesoris == "-"))
            {
                hrgaaks = 0;
            }

            cout << "------------------------------------------" << endl;

            total = hrgamrk + hrgamdl + hrgaaks; // deklasri fungsi untuk menghitung total harga dari model, merk dan aksesoris

            temp->hargatotal = total;

            cout << "Total Harga : Rp. " << total << endl;

            temp = temp->next;
        }
        getch();
    }
}

void transaksi() // fungsi transaksi
{
    system("cls");
    int bayar, kembalian;
    if (front == NULL)
    {
        cout << "Belum ada data Pembelian!\n";
        getch;
    }

    else
    {
    BAYAR:
        temp = front;
        while (temp != NULL)
        {
            cout << endl;
            cout << "\t\t TRANSAKSI PEMBAYARAN \t\t" << endl
                 << endl;
            cout << "No. Pembelian\t: " << temp->nomorpem << endl;
            cout << "Nama\t\t: " << temp->nama << endl;
            cout << "------------------------------------------" << endl;
            cout << "Harga Total\t: Rp. " << temp->hargatotal << endl;
            cout << "Pembayaran\t: Rp. ";
            cin >> bayar;
            cout << "------------------------------------------" << endl;
            kembalian = bayar - temp->hargatotal;
            if (bayar < temp->hargatotal)
            {
                cout << "Silahkan Masukan Nominal Pembayaran Sesuai dengan Total Harga" << endl;
                cout << "Pembayaran kurang : Rp. " << temp->hargatotal - bayar << endl;
                getch();
                system("cls");
                goto BAYAR;
            }
            else if (kembalian != 0)
            {
                cout << "Kembalian      : Rp. " << kembalian;
            }
            else if (kembalian == 0)
            {
                cout << "Kembalian      : Rp. 0";
            }

            temp = temp->next;
        }
        getch();
    }
}

void search() // fungsi untuk mencari data
{
    system("cls");
    node *temp;
    temp = front;
    int cari;
    int ketemu = 0;
    if (front != NULL)
    {
        cout << "\n Input No. Pembelian yang dicari\t: ";
        cin >> cari;

        while (temp != NULL)
        {
            temp->nomorpem;
            if (cari == temp->nomorpem)
            {
                cout << "\n\n == Data Ditemukan ==\n\n";
                cout << "Merk Helm\t: " << temp->merk << endl;
                cout << "Model Helm\t: " << temp->model << endl;
                cout << "Warna Helm\t: " << temp->warna << endl;
                cout << "Ukuran Helm\t: " << temp->ukuran << endl;
                cout << "Aksesoris\t: " << temp->aksesoris << endl;
                cout << "Nama\t\t: " << temp->nama << endl;
                cout << "-------------------------------------" << endl;
                cout << "\n\n";
                ketemu = 1;
            }
            temp = temp->next;
        }

        if (ketemu == 0)
        {
            cout << "Data tidak Ditemukan";
        }
    }
    else
        cout << "Belum ada Pesanan!";
    getch();
}

int main() // fungsi utama
{
    int nmr, input;
    while (1)
    {
        system("cls");
        cout << "\n\n=================================================";
        cout << "\n               Pembelian HELM & Aksesoris             ";
        cout << "\n___";
        cout << "\n                       Menu                    ";
        cout << "\n=================================================";
        cout << "\n 1.Input Data Pembelian ";
        cout << "\n 2.Hapus Data Pembelian";
        cout << "\n 3.Tampilkan Daftar Pembelian";
        cout << "\n 4.Transaksi";
        cout << "\n 5.Cari Data Pembelian";
        cout << "\n 6.Keluar";
        cout << "\n\n Masukkan Pilihan (1-6): ";
        cin >> input;
        cout << "\n=================================================";
        cout << "\n";

        switch (input)
        {
        case 1:
            insert();
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            transaksi();
            break;
        case 5:
            search();
            break;
        case 6:
            system("cls");
            return 0;
            break;
        default:
            cout << "Input salah, silahkan input ulang!(press any key)";
            getch();
        }
    }
    return 0;
}