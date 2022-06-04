// library yang dibutuhkan
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <windows.h>

#define INF 99

using namespace std;

// variable global
int jmlbuk, a, c, e, f, g, h, jmlpin, hs, lp, kodepin, stok;
int pilihan;
int b = -1;
int d = -1;
char yn, ch, temp;

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

struct pemesanan
{
    int idAntrian;
    string namaPembeli,
        alamatPembeli;
    int telpPembeli;
    int idBuku,
        hargaBuku;
    pemesanan *next;
    string statusPembayaran = "Belum dibayar";
    string statusAntrian = "Tidak ada di antrian";
    string kesamaanAntrian;
    int validasiPembayaran = 0;
    int validasiAntrian = 0;
};

pemesanan *head = NULL;
pemesanan *front = NULL;
pemesanan *rear = NULL;

void gotoxy(int x, int y)
{
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

bool cekKosong()
{
    if (head == NULL)
        return true;
    return false;
}

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

void headerMenu2()
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
    cout << "                           Peta Panduan Kota Bandung" << endl;
    cout << "                Mencari Rute Tercepat Menuju Lokasi Barbershop" << endl;
    cout << "===============================================================================" << endl;
    cout << endl;
    cout << endl;
}

void menu()
{

    headerMenu();
    cout << "                    ====================================" << endl;
    cout << "                                 DAFTAR MENU            " << endl;
    cout << "                    ====================================" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "|1.|   Daftar Buku                                                       |" << endl;
    cout << "|2.|   Pemesanan Buku                                                    |" << endl;
    cout << "|3.|   Pembayaran                                                        |" << endl;
    cout << "|4.|   Tampil data Pemesanan                                             |" << endl;
    cout << "|5.|   Struk Pembayaran                                                  |" << endl;
    cout << "|2.|   Peminjaman Buku                                                   |" << endl;
    cout << "|2.|   Pengembalian Buku                                                 |" << endl;
    cout << "|2.|   Laporan Peminjaman & Pengembalian                                 |" << endl;
    cout << "|6.|   Simpan Data Pembayaran [admin]                                    |" << endl;
    cout << "|7.|   Tampil Data Pembelian [admin]                                     |" << endl;
    cout << "|8.|   Petunjuk / Panduan                                                |" << endl;
    cout << "|9.|   Exit                                                              |" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
}

/*void keywordAdmin()
{
    string key;

    headerMenu();
    cout << "Perhatian!\n Menu ini Khusus untuk Admin.\n Silahkan masukan kata kunci : ";
    cin >> key;

    while (key != "admin")
    {
        headerMenu();
        cout << endl;
        cout << "Kata kunci yang anda masukan salah!" << endl;
        cout << "Silahkan masukan kata kunci : ";
        cin >> key;
    }

    headerMenu();
    cout << endl;
    cout << "Selamat anda dapat mengakses menu ini!\n Tekan enter untuk melanjutkan" << endl;
    getch();
}*/

/*void headerPemesanan()
{

    cout << endl;
    cout << "======================================================================================" << endl;
    cout << "                          Pemesanan Gramedia Durian Runtuh" << endl;
    cout << "======================================================================================" << endl;
    gotoxy(0, 11);
    cout << "| ID Pemesanan ";
    gotoxy(5, 11);
    cout << "| Nama Pemesan ";
    gotoxy(20, 11);
    cout << "| Alamat Pemesan ";
    gotoxy(37, 11);
    cout << "| Nomor Telp Pemesan ";
    gotoxy(58, 11);
    cout << "|";
}*/

// fungsi untuk list seluruh buku di gramedia durian runtuh
void listBuku()
{
    system("cls");
    headerMenu();
    cout << endl;
    cout << "====================================================================" << endl;
    cout << "               List Buku Gramedia Durian Runtuh" << endl;
    cout << "====================================================================" << endl;
    cout << "                      Judul Buku          |    Kode    |   Harga   |" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "|1.  Konspirasi Alam Semesta              |     001    |    75K    |" << endl;
    cout << "|2.  Kau tak Pernah Berjalan Sendiri      |     002    |    35K    |" << endl;
    cout << "|3.  Pulang Pergi - Tere Liye             |     003    |    90K    |" << endl;
    cout << "|4.  Seni Untuk Bersikap Bodo Amat        |     004    |    85K    |" << endl;
    cout << "|5.  Berani Tidak Disukai                 |     005    |    98K    |" << endl;
    cout << "|6.  Larutan Senja Ratih                  |     006    |    45K    |" << endl;
    cout << "|7.  Pokok-Pokok Filsafat Hukum           |     007    |    55K    |" << endl;
    cout << "|8.  Lebih Senyap Dari Bisikan            |     008    |    72K    |" << endl;
    cout << "|9.  Ayahku Pembohong                     |     009    |    60K    |" << endl;
    cout << "|10. Komunikasi itu Ada Seninya           |     010    |    82K    |" << endl;
    cout << "====================================================================" << endl;
}

// fungsi pengembalian penyewaan buku
void pengembalian()
{
    system("cls");
    headerMenu();
    cout << endl;
    cout << "Masukan kode peminjaman : ";
    cin >> kodepin;
    cout << "____________________________";
    cout << endl;

    for (f = 0; f <= d; f++)
    {
        if (pinjembuku[f].kodepinjam == kodepin)
        {
            cout << "Nama Penyewa Buku \t: " << pinjembuku[f].namap;
            cout << endl;
            cout << "Alamat Penyewa \t\t : " << pinjembuku[f].alamat;
            cout << endl;

            if (buku[f].kodeB == pinjembuku[f].kB)
            {
                cout << "Judul Buku \t\t : " << buku[f].judul << endl;
            }

            cout << "Tanggal pinjam (DDMMYY) \t: " << pinjembuku[f].tglpin;
            cout << endl;
            cout << "Tanggal Balik (DDMMYY) \t: " << pinjembuku[f].tglbalik;
            cout << endl;

            lp = (pinjembuku[f].tglbalik - pinjembuku[f].tglpin) / 1000000;
            cout << "Lama Pinjaman \t\t\t: " << lp << " Hari" << endl;
            cout << endl;
            cout << "Banya buku yang dipinjam \t: " << pinjembuku[f].dipinjem;
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
    headermenu();
    cout << "\n"
         << endl;
    cout << "\t\t\t laporan Perpustakaan\n";
    cout << "\t\t\t____________________\n"
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

/*void pembayaran(pemesanan *head)
{
    headerMenu();
    int nominal,
        sisa,
        selisih,
        i = 0;
    pemesanan *tmp;
    tmp = head;
    int cari;

    cout << "===============================================================================" << endl;
    cout << "                               Payment Page" << endl;
    cout << "===============================================================================" << endl;
    cout << "Masukkan Nomor Id Pesanan yang ingin dicari : ";
    cin >> cari;

    tmp = head;

    while (tmp != NULL)
    {
        if (cari == tmp->idAntrian)
        {
            tmp->kesamaanAntrian == "cocok";
            break;
        }
        else
        {
            tmp = tmp->next;
        }
    }
    if (tmp == NULL)
    {
        cout << "Maaf, tidak terdapat data yang tersedia" << endl;
    }
    else if (tmp->validasiPembayaran == 1)
    {
        cout << "Maaf, data pesanan atas nama " << tmp->namaPembeli << " telah terbayar" << endl;
    }

    while (tmp != NULL && tmp->validasiPembayaran == 0)
    {
    bayar:
        cout << "=================================================" << endl;
        cout << " Pesanan atas nama : " << tmp->namaPembeli << endl;
        cout << " Pilihan Buku      : Buku " << tmp->idBuku << endl;
        cout << " Total harga       : Rp." << tmp->hargaBuku << endl;
        cout << "=================================================" << endl;
        cout << " Masukkan Jumlah Pembayaran : ";
        cin >> nominal;
        selisih = tmp->hargaBuku - nominal;
        while (selisih > 0)
        {
            cout << "Pembayaran anda tidak memenuhi total harga. Pembayaran anda kurang senilai Rp. " << selisih << endl;
            cout << "Silahkan masukan sisa pembayarannya : ";
            cin >> sisa;
            nominal += sisa;
            selisih = tmp->hargaBuku - nominal;
        }

        if (nominal == tmp->hargaBuku)
        {
            tmp->statusPembayaran = "Terbayar";
            tmp->statusAntrian = "Masuk kedalam Antrian";
            tmp->validasiPembayaran = 1;
            cout << "Terima kasih! Pembayaran Anda sebesar Rp. " << nominal << " telah kami terima!" << endl;
        }
        else
        {
            cout << "Maaf, terdapat kelebihan dalam pembayaran, diharapkan melakukan pembayaran dengan memasukan nominal yang pas dengan harga buku!" << endl;
            system("cls");
            system("pause");
            goto bayar;
        }
        break;
    }
}*/

/*void strukPembayaran()
{
    headerMenu2();
    cout << endl;
    cout << "===================================================================================================================================" << endl;
    cout << "                                                        Struk Pembayaran " << endl;
    cout << "===================================================================================================================================" << endl;
    gotoxy(0, 14);
    cout << "| ID Pemesanan ";
    gotoxy(5, 14);
    cout << "| Nama Pemesan ";
    gotoxy(20, 14);
    cout << "| Alamat Pemesan ";
    gotoxy(37, 14);
    cout << "| Nomor Telp Pemesan ";
    gotoxy(59, 14);
    cout << "| Judul Buku ";
    gotoxy(72, 14);
    cout << "| Harga Buku ";
    gotoxy(85, 14);
    cout << "| Status Pembayaran ";
    gotoxy(105, 14);
    cout << "| Status Pemesanan ";
    gotoxy(124, 14);
    cout << "|";
}
*/

/*void tampilData(pemesanan *head)
{
    if (!cekKosong())
    {
        pemesanan *tmp;
        tmp = head;
        int i = 15;
        while (tmp != NULL)
        {
            gotoxy(0, i);
            cout << "|" << i - 14;
            gotoxy(5, i);
            cout << "|" << tmp->namaPembeli;
            gotoxy(20, i);
            cout << "|" << tmp->alamatPembeli;
            gotoxy(37, i);
            cout << "|" << tmp->telpPembeli;
            gotoxy(59, i);
            cout << "|" << tmp->idBuku;
            gotoxy(72, i);
            cout << "|" << tmp->hargaBuku;
            gotoxy(85, i);
            cout << "|" << tmp->statusPembayaran;
            gotoxy(105, i);
            cout << "|" << tmp->statusAntrian;
            gotoxy(124, i);
            cout << "|";
            i++;
            tmp = tmp->next;
        }
    }
    else
    {
        gotoxy(0, 15);
        cout << "Data Pemesanan tidak ada!" << endl;
    }
}*/

/*void simpanFile()
{
    time_t waktuSekarang;
    time(&waktuSekarang);
    ofstream filepemesanan;
    pemesanan *tmp;
    tmp = head;

    filepemesanan.open("data_pemesanan.txt", ios::app);
    filepemesanan << endl;
    filepemesanan << endl;
    filepemesanan << " Disimpan pada : " << ctime(&waktuSekarang);
    filepemesanan << "===============================================================================================================================" << endl;
    filepemesanan << "                                                     Data Laporan Pemesanan" << endl;
    filepemesanan << "===============================================================================================================================" << endl;
    filepemesanan << "      Judul Buku\t| \tHarga\t | \t\tNama\t\t | \t\tAlamat\t\t| \t\tNo Telp\t\n";

    while (tmp != NULL)
    {
        if (tmp->statusAntrian == "Selesai")
        {
            filepemesanan << " " << tmp->idBuku << "\t\t\t| \t" << tmp->hargaBuku << "\t | \t" << tmp->namaPembeli << "\t\t\t| \t" << tmp->alamatPembeli << "\t\t\t| \t" << tmp->telpPembeli << "\t" << endl;
        }
        tmp = tmp->next;
    }
    filepemesanan.close();
    headerMenu();
    cout << "Data Pemesanan Berhasil disimpan ke dalam file txt!" << endl;
}*/

/*void readFile()
{
    system("cls");
    ifstream filepemesanan;
    char text;
    filepemesanan.open("data_pemesanan.txt");

    if (!filepemesanan.fail())
    {
        while (!filepemesanan.eof())
        {
            filepemesanan.get(text);
            cout << text;
        }
        filepemesanan.close();
    }
    else
    {
        headerMenu();
        cout << "File tidak ditemukan!\nSilahkan simpan data pemesanan terlebih dahulu" << endl;
    }
}*/

/*void headerQueue()
{
    headerMenu();
    cout << "===============================================================================" << endl;
    cout << "                            Antrian Gramedia Durian Runtuh " << endl;
    cout << "===============================================================================" << endl;
    gotoxy(0, 13);
    cout << "| Id ";
    gotoxy(5, 13);
    cout << "|      Nama Pemesan ";
    gotoxy(30, 13);
    cout << "|      Alamat Pemesan ";
    gotoxy(55, 13);
    cout << "|      Judul Buku ";
    gotoxy(77, 13);
    cout << " |";
}*/

/*void inQueue()
{
    pemesanan *tmp;
    tmp = head;
    while (tmp != NULL)
    {
        if (tmp->validasiPembayaran == 1 && tmp->validasiAntrian == 0)
        {
            pemesanan *new_node, *current;
            new_node = new pemesanan;
            new_node->idAntrian = tmp->idAntrian;
            new_node->namaPembeli = tmp->namaPembeli;
            new_node->alamatPembeli = tmp->alamatPembeli;
            new_node->idBuku = tmp->idBuku;
            new_node->next = NULL;

            if (front == NULL)
            {
                front = new_node;
            }
            else
            {
                current = front;
                while (current->next != NULL)
                {
                    current = current->next;
                }
                current->next = new_node;
            }
            rear = new_node;
            tmp->validasiAntrian = 1;
        }
        tmp = tmp->next;
    }
}
*/

/*void displayQueue()
{
    pemesanan *tampilkan;

    if (front == NULL)
    {
        cout << endl;
        cout << "Antrian dalam keadaan kosong" << endl;
        cout << "Tidak ada data yang ditampilkan" << endl;
    }
    else
    {
        tampilkan = front;
        int i = 14;
        while (tampilkan != NULL)
        {
            gotoxy(0, i);
            cout << "| " << tampilkan->idAntrian;
            gotoxy(5, i);
            cout << "| " << tampilkan->namaPembeli;
            gotoxy(30, i);
            cout << "| " << tampilkan->alamatPembeli;
            gotoxy(55, i);
            cout << "| " << tampilkan->idBuku;
            gotoxy(77, i);
            cout << "| ";
            i++;
            tampilkan = tampilkan->next;
        }
    }
}
*/

/*void delQueue()
{
    pemesanan *hapus, *tmp;
    int tmpID, tmpBuku;
    string tmpNama, tmpAlamat;

    tmp = head;

    if (front != NULL)
    {
        hapus = front;
        tmpID = hapus->idAntrian;
        tmpNama = hapus->namaPembeli;
        tmpBuku = hapus->idBuku;
        tmpAlamat = hapus->alamatPembeli;
        while (tmp->statusAntrian != "Masuk ke dalam Antrian")
        {
            tmp = tmp->next;
        }
        tmp->statusAntrian = "Selesai";
        cout << endl;
        cout << endl;
        cout << "Tekan enter untuk mengeluarkan antrian yang berada pada barisan pertama" << endl;
        getch();
        cout << "Data dengan ID " << tmpID << " telah dikeluarkan dari antrian" << endl;
        front = front->next;
        delete hapus;
    }
}*/

/*void findQueue(int cariID)
{
    pemesanan *penelusuran;
    penelusuran = front;
    int temp, i = 1, posisi;

    if (front == NULL)
    {
        cout << "Maaf, antrian dalam keadaan kosong!\nTidak dapat melakukan pencarian" << endl;
    }
    else
    {
        while (penelusuran != NULL)
        {
            if (cariID == penelusuran->idAntrian)
            {
                temp = cariID;
                posisi = 1;
            }
            penelusuran = penelusuran->next;
            i++;
        }
        if (cariID == temp)
        {
            cout << "Data " << cariID << " telah ditemukan pada antrian ke- " << posisi << endl;
        }
        else
        {
            cout << "Data " << cariID << " tidak ditemukan dalam antrian" << endl;
        }
    }
}*/

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
void transaksiPinjam()
{

    listBuku();

    d++;
    cout << "\n"
         << endl;
    cout << "\t\tTRANSAKSI PEMINJAMAN\t\t" << endl;
    cout << endl;

    cout << "Masukan data Pinjaman Ke \t: " << d + 1 << endl;
    cout << "Kode Pinjaman \t\t: ";
    cin >> pinjembuku[d].kodepinjam, temp;
    cout << "Kode Buku \t\t\t: ";
    cin >> pinjembuku[d].kB, temp;
    cout << "Nama Penyewa Buku \t\t: ";
    gets(pinjembuku[d].namap);
    gets(pinjembuku[d].namap);
    cout << "Alamat Penyewa \t\t: ";
    gets(pinjembuku[d].alamat);
    cout << "Tanggal Pinjam (DDMMYY) \t: ";
    cin >> pinjembuku[d].tglpin, temp;
    cout << "Tanggal Balik (DDMMYY) \t: ";
    cin >> pinjembuku[d].tglbalik, temp;
    lp = (pinjembuku[d].tglbalik - pinjembuku[d].tglpin) / 1000000;
    cout << "Lama Pinjam\t : " << lp << " Hari" << endl;
    cout << "banyak Buku yang dipinjam \t: ";
    cin >> pinjembuku[d].dipinjem, temp;

    hs = pinjembuku[d].dipinjem * buku[d].sewa;
    cout << "Harga sewa \t\t\t: " << hs << endl;
    cout << "status dipinjam (y) \t: ";
    cin >> pinjembuku[d].status;
    cout << endl;
}

int main()
{
    system("cls");

    char backTomenu;
    string user = "";
    string pass = "";
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
            transaksiPinjam();
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
            break;
        case 6:
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
