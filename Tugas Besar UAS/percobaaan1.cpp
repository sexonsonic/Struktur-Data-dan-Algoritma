// library yang dibutuhkan
#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdlib>
#include <iomanip>
#include <windows.h>

#define INF 99

using namespace std;

// variable global
int jmlbuk, a, c, e, f, g, h, jmlpin, hs, lp, kodepin, kodebuku, hstotal;
int pilihan;
int b = -1;
int d = -1;
char yn, ch, temp;
string user = "";
string pass = "";

struct buku
{
    int kodeB, sewa, stock;
    char judul[20];
    int b;
} buku[100];

struct pinjam
{
    int kodepinjam, d, kB, tglpin, tglbalik, dipinjem;
    char namap[40];
    char alamat[40];
    char status;
} pinjembuku[100];

void headerMenu()
{
    system("CLS");
    cout << endl;
    cout << "                           ========================" << endl;
    cout << "                 ===========================================" << endl;
    cout << "        ==============================================================" << endl;
    cout << "============================ GRAMEDIA DURIAN RUNTUH =========================== " << endl;
    cout << "              Jl. Indah Pada Waktunya No.2 Telp.(088)88899999" << endl;
    cout << "                Antapani, Karawang Barat, Jawa Barat 11530" << endl;
    cout << "===============================================================================" << endl;
    cout << "===============================================================================" << endl;
    cout << endl;
}

// fungsi menu pilihan
void menu()
{
    headerMenu();
    cout << "                    ====================================" << endl;
    cout << "                                 DAFTAR MENU            " << endl;
    cout << "                    ====================================" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "|1.|   Daftar Buku                                                       |" << endl;
    cout << "|2.|   Peminjaman Buku                                                   |" << endl;
    cout << "|3.|   Pengembalian Buku                                                 |" << endl;
    cout << "|4.|   Tampil data Peminjaman & Pengembalian Buku      [admin]           |" << endl;
    cout << "|5.|   Petunjuk / Panduan Rute                                           |" << endl;
    cout << "|6.|   Exit                                                              |" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
}

// menu login khusus admin
void menuAdmin()
{
    system("cls");
login:
    cout << "Username : ";
    cin >> user;
    cout << "Password : ";
    ch = _getch();

    while (ch != 13)
    {
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }

    cout << endl;
    if (user == "admin" && pass == "admin")
    {
        cout << "\n\n Anda berhasil login. \n"
             << endl;
        system("pause");
        system("cls");
        menu();
    }
    else
    {
        cout << " Password Anda Salah \n";
        system("pause");
        system("cls");
        goto login;
    }
}

// fungsi untuk list seluruh buku di gramedia durian runtuh
void listBuku()
{
    system("cls");
    headerMenu();
    cout << endl;
    cout << "=========================================================================" << endl;
    cout << "               List Buku Gramedia Durian Runtuh" << endl;
    cout << "=========================================================================" << endl;
    cout << "                      Judul Buku          |    Kode    |   Harga Sewa   |" << endl; // kode buku
    cout << "-------------------------------------------------------------------------" << endl; // harga sewa buku /hari
    cout << "|1.  Konspirasi Alam Semesta              |     101    |       75K      |" << endl;
    cout << "|2.  Kau tak Pernah Berjalan Sendiri      |     102    |       35K      |" << endl;
    cout << "|3.  Pulang Pergi - Tere Liye             |     103    |       90K      |" << endl;
    cout << "|4.  Seni Untuk Bersikap Bodo Amat        |     104    |       85K      |" << endl;
    cout << "|5.  Berani Tidak Disukai                 |     105    |       98K      |" << endl;
    cout << "|6.  Larutan Senja Ratih                  |     106    |       45K      |" << endl;
    cout << "|7.  Pokok-Pokok Filsafat Hukum           |     107    |       55K      |" << endl;
    cout << "|8.  Lebih Senyap Dari Bisikan            |     108    |       72K      |" << endl;
    cout << "|9.  Ayahku Pembohong                     |     109    |       60K      |" << endl;
    cout << "|10. Komunikasi itu Ada Seninya           |     110    |       82K      |" << endl;
    cout << "=========================================================================" << endl;
}

// fungsi menampilkan rute yang dapat ditempuh untuk menuju gramedia durian runtuh
void headerMap()
{
    system("cls");

    headerMenu();
    cout << endl;
    cout << "===============================================================================" << endl;
    cout << "                                    Peta Panduan" << endl;
    cout << "             Mencari Rute Tercepat Menuju Perpustakaan Duriah Runtuh" << endl;
    cout << "===============================================================================" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "|1. Antapni" << endl;
    cout << "|2. Trans Studi Mall" << endl;
    cout << "|3. Bandung Indah Plaza" << endl;
    cout << "|4. Paskal" << endl;
    cout << "|5. Dago" << endl;
    cout << "|6. Margahayu" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
}

// fungsi peminjaman / penyewaan buku
void sewaBuku()
{

    listBuku();
    int hargasewa;
    d++;
    cout << "\n"
         << endl;
    cout << "\t\tTRANSAKSI PEMINJAMAN\t\t" << endl;
    cout << endl;

    cout << "Masukan data Pinjaman Ke \t: " << d + 1 << endl;
    cout << "Kode Pinjaman \t\t\t: "; // ex 01
    cin >> pinjembuku[d].kodepinjam, temp;

    cout << "Kode Buku \t\t\t: ";
    cin >> pinjembuku[d].kB, temp;

    if (pinjembuku[d].kB == 101)
    {
        hargasewa = 75000;
    }
    else if (pinjembuku[d].kB == 102)
    {
        hargasewa = 35000;
    }

    else if (pinjembuku[d].kB == 103)
    {
        hargasewa = 90000;
    }
    else if (pinjembuku[d].kB == 104)
    {
        hargasewa = 85000;
    }
    else if (pinjembuku[d].kB == 105)
    {
        hargasewa = 98000;
    }
    else if (pinjembuku[d].kB == 106)
    {
        hargasewa = 45000;
    }
    else if (pinjembuku[d].kB == 107)
    {
        hargasewa = 55000;
    }
    else if (pinjembuku[d].kB == 108)
    {
        hargasewa = 72000;
    }
    else if (pinjembuku[d].kB == 109)
    {
        hargasewa = 60000;
    }
    else if (pinjembuku[d].kB == 110)
    {
        hargasewa = 82000;
    }
    else
    {
        cout << "Masukkan kode buku dengan benar! " << endl;
        return;
    }

    cout << "Nama Penyewa Buku \t\t: ";
    gets(pinjembuku[d].namap);
    gets(pinjembuku[d].namap);

    cout << "Alamat Penyewa \t\t\t: ";
    gets(pinjembuku[d].alamat);

    cout << "Tanggal Pinjam (DDMMYYYY) \t: ";
    cin >> pinjembuku[d].tglpin, temp;

    cout << "Tanggal Balik (DDMMYYYY) \t\t: ";
    cin >> pinjembuku[d].tglbalik, temp;

    lp = (pinjembuku[d].tglbalik - pinjembuku[d].tglpin) / 1000000;
    cout << "Lama Pinjam \t\t\t: " << lp << " Hari" << endl;

    cout << "banyak Buku yang dipinjam \t: ";
    cin >> pinjembuku[d].dipinjem, temp;

    hs = pinjembuku[d].dipinjem * hargasewa;
    hstotal = hs * lp;

    if (lp > 1)
    {
        cout << "Harga total : " << hstotal << " Selama " << lp << " Hari" << endl;
    }

    cout << "status dipinjam (y) \t\t: ";
    cin >> pinjembuku[d].status;
    cout << endl;
}

// fungsi pengembalian penyewaan buku
void pengembalian()
{
    system("cls");
    string keterangan;

    headerMenu();
    cout << endl;
    cout << "Masukan Kode Buku yang disewa : ";
    cin >> pinjembuku[d].kodepinjam;

    if (pinjembuku[d].kodepinjam == 01)
    {
        keterangan = "Konspirasi Alam Semesta";
    }
    else if (pinjembuku[d].kodepinjam == 02)
    {
        keterangan = "Kau tak Pernah Berjalan Sendiri";
    }
    else if (pinjembuku[d].kodepinjam == 03)
    {
        keterangan = "Pulang Pergi - Tere Liye";
    }
    else if (pinjembuku[d].kodepinjam == 04)
    {
        keterangan = "Seni Untuk Bersikap Bodo Amat";
    }
    else if (pinjembuku[d].kodepinjam == 05)
    {
        keterangan = "Berani Tidak Disukai ";
    }
    else if (pinjembuku[d].kodepinjam == 06)
    {
        keterangan = "Larutan Senja Ratih ";
    }
    else if (pinjembuku[d].kodepinjam == 07)
    {
        keterangan = "Pokok-Pokok Filsafat Hukum ";
    }
    else if (pinjembuku[d].kodepinjam == 08)
    {
        keterangan = "Lebih Senyap Dari Bisikan ";
    }
    else if (pinjembuku[d].kodepinjam == 09)
    {
        keterangan = "Aayahku Pembohong";
    }
    else if (pinjembuku[d].kodepinjam == 10)
    {
        keterangan = "Komunikasi itu Ada Seninya";
    }
    cout << "__________";
    cout << endl;

    for (f = 0; f <= d; f++)
    {
        if (pinjembuku[f].kodepinjam == kodepin)
        {
            cout << "Nama Penyewa Buku \t\t: " << pinjembuku[f].namap;
            cout << endl;
            cout << "Alamat Penyewa \t\t\t: " << pinjembuku[f].alamat;
            cout << endl;
            cout << "Judul Buku \t\t\t: " << keterangan << endl;

            cout << "Tanggal pinjam (DDMMYY) \t: " << pinjembuku[f].tglpin;
            cout << endl;
            cout << "Tanggal Balik (DDMMYY) \t\t: " << pinjembuku[f].tglbalik;
            cout << endl;

            lp = (pinjembuku[f].tglbalik - pinjembuku[f].tglpin) / 1000000;
            cout << "Lama Pinjaman \t\t\t: " << lp << " Hari" << endl;
            cout << endl;
            cout << "Banyak buku yang dipinjam \t: " << pinjembuku[f].dipinjem;
            cout << endl;

            cout << "Status \t\t\t: " << pinjembuku[f].status;

            if ((pinjembuku[f].status == 'y') || (pinjembuku[f].status == 'Y'))
            {
                cout << "dipinjam" << endl;
            }
            else
            {
                cout << "dikembalikan" << endl;
            }

            cout << endl;
            cout << "Sudah dikembalikan ? [y/n] : ";
            cin >> yn;

            if ((yn == 'y') || (yn == 'Y'))
            {
                cout << "ganti status (input n) : ";
                cin >> pinjembuku[f].status;

                cout << "Data berhasil disimpan" << endl;
                system("pause");
                system("cls");
                menu();
            }
            else
            {
                cout << "\nData Berhasil Disimpan " << endl;
                system("pause");
                system("cls");
                menu();
            }
        }
        else
        {
            cout << "Data tidak ditemukan!" << endl;

            cout << "Apakah ingin mencoba lagi ? (y/n) : ";
            cin >> yn;

            if (yn == 'Y' || yn == 'y')
            {
                system("cls");
                pengembalian();
            }
            else
            {
                system("cls");
                menu();
            }
        }
    }
}

// fungsi untuk melihat laporan penyewaan dan pengembalian buku
void laporan()
{
    system("cls");

    menuAdmin();
    cout << "\n"
         << endl;
    cout << "\t\t\t laporan Perpustakaan\n";
    cout << "\t\t\t________\n"
         << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------\n";
    cout << " No  Kode Peminjam  Judul Buku  Nama Peminjam    Alamat           Tanggal Pinjam  Tanggal Balik   Status   Buku Keluar \n";
    cout << "-----------------------------------------------------------------------------------------------------------------------\n";
    for (g = 0; g <= b; g++)
    {
        if (pinjembuku[g].kB == buku[g].kodeB)
        {
            cout << setw(2) << g + 1 << setw(10) << pinjembuku[g].kodepinjam << setw(13) << buku[g].judul << setw(12) << pinjembuku[g].namap
                 << setw(14) << pinjembuku[g].alamat << setw(20) << pinjembuku[g].tglpin << setw(10) << pinjembuku[g].tglbalik
                 << setw(12) << pinjembuku[g].status;
            if ((pinjembuku[g].status == 'y') || (pinjembuku[g].status == 'Y'))
            {
                cout << " (di Pinjam) " << endl;
            }
            else
            {
                cout << " (di kembalikan) " << endl;
            }
            cout << setw(12) << pinjembuku[g].dipinjem;
            cout << endl;
        }
    }
    system("pause");
    system("cls");
    menu();
}

// fungsi penghitungan untuk jarak minimun yang dapat ditempuh
int jarakMinimum(int jarak[], bool set[])
{
    int kecil = INF;
    int index;

    for (int i = 0; i < 7; i++)
    {
        if (set[i] == false && jarak[i] <= kecil)
        {
            kecil = jarak[i];
            index = i;
        }
    }
    return index;
}

// mencetak rute yang ditemukan
void cetakRute(int simpan[], int j, int awal)
{
    string keteranganDaerah;
    if (j == 1)
    {
        keteranganDaerah = "Antapani";
    }
    else if (j == 2)
    {
        keteranganDaerah = "Trans Studi Mall";
    }
    else if (j == 3)
    {
        keteranganDaerah = "Bandung Indah Plaza";
    }
    else if (j == 4)
    {
        keteranganDaerah = "Paskal";
    }
    else if (j == 5)
    {
        keteranganDaerah = "Dago";
    }
    else if (j == 6)
    {
        keteranganDaerah = "Margahayu";
    }

    if (simpan[j] == -1)
    {
        return;
    }
    else
    {
        cetakRute(simpan, simpan[j], awal);
        if (j == 0)
        {
            cout << "Kemudian lanjutkan menuju Cibiru" << endl;
            cout << "Lalu lanjutkan perjalanan hingga sampai di Perpustakaan Durian Runtuh" << endl;
        }
        else
        {
            cout << "Lanjutkan Perjalanan menuju " << keteranganDaerah << endl;
        }
    }
}

// menampilkan rute-rute yang ditemukan
int tampilkanRute(int jarak[], int n, int simpan[], int awal)
{
    string keterangan;
    for (int i = 0; i < 7; i++)
    {
        if (i == 0)
        {
            cout << endl;
            if (awal == 1)
            {
                keterangan = "Antapani";
            }
            else if (awal == 2)
            {
                keterangan = "Trans Studi Mall";
            }
            else if (awal == 3)
            {
                keterangan = "Bandung Indah Plaza";
            }
            else if (awal == 4)
            {
                keterangan = "Paskal";
            }
            else if (awal == 5)
            {
                keterangan = "Dago";
            }
            else if (awal == 6)
            {
                keterangan = "Margahayu";
            }

            cout << "Mulai Dari " << keterangan << endl;
            cetakRute(simpan, i, awal);
            cout << endl;
            cout << "\"Stay Safe, Stay healty and Stay With Me\" " << endl;
            cout << endl;

            cout << "---------------------------------" << endl;
            cout << "Total Jarak yang ditempuh : " << jarak[i] << "km" << endl;
            cout << "---------------------------------" << endl;
            cout << endl;
        }
    }
}

// algoritma dijkstra untuk mencari nilai minimum
int dijkstra(int graf[7][7], int awal)
{
    int jarak[7];
    bool set[7];
    int simpan[7];

    for (int i = 0; i < 7; i++)
    {
        jarak[i] = INF;
        set[i] = false;
        simpan[i] = -1;
    }

    jarak[awal] = 0;

    for (int i = 0; i < 7; i++)
    {
        int m = jarakMinimum(jarak, set);
        set[m] = true;

        for (int i = 0; i < 7; i++)
        {
            if (!set[i] && graf[m][i] && jarak[m] + graf[m][i] < jarak[i])
            {
                simpan[i] = m;
                jarak[i] = jarak[m] + graf[m][i];
            }
        }
    }
    tampilkanRute(jarak, 7, simpan, awal);
}

int main()
{
    system("cls");

    char backTomenu;

    int graf[7][7] = {
        // matriks G = [v,e]
        {0, 4, 0, 5, 0, 0, 0}, // Perpustakaan Durian Runtuh
        {4, 0, 1, 0, 4, 5, 0}, // Antapani
        {0, 1, 0, 2, 6, 0, 0}, // Trans Studi Mall
        {5, 0, 2, 0, 5, 0, 8}, // Bandung indah Plaza
        {0, 4, 6, 5, 0, 2, 7}, // Paskal
        {0, 5, 0, 0, 2, 0, 0}, // Dago
        {0, 0, 0, 8, 7, 0, 0}, // Margahayu

    };
    int asalDaerah;

    do
    {
        system("cls");
        menu();
        cout << "> Input Pilihan [1-10] : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            system("cls");
            listBuku();
            break;

        case 2:
            system("cls");
            sewaBuku();
            break;
        case 3:
            system("cls");
            pengembalian();
            break;
        case 4:
            system("cls");
            laporan();
            break;
        case 5:
            system("cls");
            headerMap();
            cout << "Tentukan titik Awal (1-6): ";
            cin >> asalDaerah;
            while (asalDaerah > 6)
            {
                cout << endl;
                cout << "Maaf, daerah tidak tersedia!" << endl;
                cout << "Tentukan titik awal anda berada!  (1-6): ";
                cin >> asalDaerah;
            }
            cout << endl;
            cout << "Loading..." << endl;
            cout << "Mencari Rute tercepat" << endl;
            Sleep(3000);
            system("cls");

            cout << "Rute tercepat Ditemukan : ";
            cout << endl;
            dijkstra(graf, asalDaerah);
            break;

        default:
            break;
        }

        cout << "\nKembali Ke Menu Utama? (Y/N) : ";
        cin >> backTomenu;
    } while (backTomenu == 'y' || backTomenu == 'Y');
}