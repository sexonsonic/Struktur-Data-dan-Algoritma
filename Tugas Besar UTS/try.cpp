#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

int input, merk, model, jmlmerk, jmlmodel, wrna, ukr, byr, kembali, total = 0, totalbiaya = 0, hargatot = 0;
int hargamerk[1000] = {100000, 150000, 170000, 155000, 200000, 300000, 135000, 120000, 500000};
int hargamodel[100] = {50000, 40000, 45000, 70000, 65000, 55000};

void menu()
{
    system("CLS");
    cout << "==================================================\n";
    cout << "            PEMBLIAN HELM & AKSESORIS HELM\n";
    cout << "==================================================\n";
    cout << "1. Buat Pesanan\n";
    cout << "2. Tampilkan Pesanan\n";
    cout << "3. Keluar\n";
    cout << "==================================================\n";
}

void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    cout.flush();
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
} // untuk memanggil fungsi gotoxy

void tampilanHelm()
{
    system("cls");
    gotoxy(1, 1);
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n";
    gotoxy(52, 2);
    cout << "HELM CIGARATES\n";
    gotoxy(37, 3);
    cout << "Jl.Istiqomah 1,Cinunuk,kab.Bandung,Jawa Barat 40624\n";
    gotoxy(1, 4);
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
    gotoxy(29, 6);
    cout << "                                      | PEMBELIAN HELM |";
    gotoxy(29, 8);
    cout << "        + Masukkan kode merk helm <spasi> jumlah helm <spasi> warna helm <spasi> ukuran helm\n";
    gotoxy(29, 9);
    cout << "        + Contoh : 1 2 3 4\n";
    gotoxy(29, 10);
    cout << "        +Ketik 0 <spasi> 0 Jika sudah selesai\n";
    gotoxy(30, 11);
    cout << "===================================================================================\n";
    gotoxy(30, 12);
    cout << "|Kode | Merk Helm         ||  Harga                 || Warna        || Ukuran     |\n";
    gotoxy(30, 13);
    cout << "===================================================================================\n";
    gotoxy(30, 14);
    cout << "|  1  | KYT               || Rp.100.000,00          || Merah        || S          |\n";
    gotoxy(30, 15);
    cout << "|  2  | TRX               || Rp.150.000,00          || Hijau        || M          |\n";
    gotoxy(30, 16);
    cout << "|  3  | SHARK             || Rp.170.000,00          || Kuning       || L          |\n";
    gotoxy(30, 17);
    cout << "|  4  | INK               || Rp.155.000,00          || Biru         || XL         |\n";
    gotoxy(30, 18);
    cout << "|  5  | SHOEI             || Rp.200.000,00          || Hitam        ||            |\n";
    gotoxy(30, 19);
    cout << "|  6  | NOLAN             || Rp.300.000,00          || Abu-Abu      ||            |\n";
    gotoxy(30, 20);
    cout << "|  7  | CARGLOSS          || Rp.135.000,00          ||              ||            |\n";
    gotoxy(30, 21);
    cout << "|  8  | KBC               || Rp.120.000,00          ||              ||            |\n";
    gotoxy(30, 22);
    cout << "|  9  | ARAI              || Rp.500.000,00          ||              ||            |\n";
    gotoxy(30, 23);
    cout << "===================================================================================\n";
    gotoxy(1, 24);
    cout << endl;

    cout << "      BELANJA     :  ";
    cin >> merk;
    cin >> jmlmerk;
    cin >> wrna;
    cin >> ukr;
    total = total + (hargamerk[(merk - 1)]) * jmlmerk;
    cout << "    TOTAL       : Rp." << total << endl;
    cout << "\n\t\tpress Enter to continue....";
    getch();

    system("cls");
    gotoxy(1, 1);
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n";
    gotoxy(52, 2);
    cout << "HELM CIGARATES\n";
    gotoxy(37, 3);
    cout << "Jl.Istiqomah 1,Cinunuk,kab.Bandung,Jawa Barat 40624\n";
    gotoxy(1, 4);
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
    gotoxy(29, 6);
    cout << "                                      | PEMBELIAN HELM |";
    gotoxy(29, 8);
    cout << "        + Masukkan kode merk helm <spasi> jumlah helm <spasi> warna helm <spasi> ukuran helm\n";
    gotoxy(29, 9);
    cout << "        + Contoh : 1 2 3 4\n";
    gotoxy(29, 10);
    cout << "        +Ketik 0 <spasi> 0 Jika sudah selesai\n";
    gotoxy(30, 11);
    cout << "======================================================\n";
    gotoxy(30, 12);
    cout << "|Kode | Model Helm         ||  Harga                 |\n";
    gotoxy(30, 13);
    cout << "======================================================\n";
    gotoxy(30, 14);
    cout << "|  1  | FULL-FACE          || Rp.50.000,00          |\n";
    gotoxy(30, 15);
    cout << "|  2  | OPEN-FACE          || Rp.40.000,00          |\n";
    gotoxy(30, 16);
    cout << "|  3  | HALF-FACE          || Rp.45.000,00          |\n";
    gotoxy(30, 17);
    cout << "|  4  | FLIP-UP            || Rp.70.000,00          |\n";
    gotoxy(30, 18);
    cout << "|  5  | OFFROAD            || Rp.65.000,00          |\n";
    gotoxy(30, 19);
    cout << "|  6  | DUAL SPORT         || Rp.55.000,00          |\n";
    gotoxy(30, 20);
    cout << "======================================================\n";
    gotoxy(1, 21);
    cout << endl;
    do
    {
        cout << "     BELANJA     :  ";
        cin >> model;
        cin >> jmlmodel;
        totalbiaya = (totalbiaya + (hargamodel[(model - 1)]) * jmlmodel);
        hargatot = total + totalbiaya;
    } while (model != 0 && jmlmodel != 0);
    cout << "\n     TOTAL HARGA : Rp." << hargatot;
tunai:
    cout << "\n     TUNAI       : Rp.";
    cin >> byr;

    if (byr < totalbiaya)
    {
        cout << "\n==============================================================================\n";
        cout << "\n\tSilahkan Masukkan Nominal Pembayaran Kembali sesuai total harga\n";
        cout << "\tPembayaran kurang : " << hargatot - byr << ",00" << endl;
        cout << "\n==============================================================================\n";
        goto tunai;
    }
    else
    {
        kembali = byr - hargatot;
        cout << "     KEMBALI     : Rp." << kembali << ",00" << endl;
        cout << "\n\n\t\t  ===========================================================================\n";
        cout << "\n  \t\t             Terimakasih telah berbelanja di Helm Cigarates\n";
        cout << "\t\t  ===========================================================================\n";
    }
    getch();
}

void masuk()
{
    system("CLS");
    string user = "";
    string pass = "";
    do
    {
        cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n";
        cout << "======================================================================================================================\n";
        cout << "|                                            LOGIN HELM CIGARATES                                                  |\n";
        cout << "======================================================================================================================\n";
        cout << "\t\t\t\t\tUSERNAME  : ";
        cin >> user;
        cout << "\t\t\t\t\tPASSWORD  : ";
        cin >> pass;
        cout << "\n\t\tpress Enter to continue....";
        getch();
        system("cls");
    } while (user != "user" || pass != "user");
    tampilanHelm();
}
void struk()
{
    system("cls");
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int jam = ltm->tm_hour;
    int menit = ltm->tm_min;
    int detik = ltm->tm_sec;
    if (total == 0)
    {
        cout << "=================================================\n";
        cout << "               Tidak ada pesanan \n";
        cout << "=================================================\n";
    }
    else
    {
        cout << "Anda Telah membeli barang dengan kode Dengan Harga\n";
        cout << "Dengan Harga                          : Rp." << hargatot << endl;
        cout << "Kembali                               : Rp." << kembali << endl;
        cout << "Pada Jam  " << jam << "." << menit << "." << detik << endl;
    }
}

int main()
{
    system("CLS");
    int pilihmenu;
    char kembali = 'y';
    do
    {
        menu();
        cout << "Silahkan Pilih Menu (1-3) : ";
        cin >> pilihmenu;
        switch (pilihmenu)
        {
        case 1:
            masuk();
            break;
        case 2:
            struk();
            break;
        case 3:
            return 0;
            break;
        default:
            cout << " Menu Tidak Tersedia \n";
        }
        cout << "Kembali Ke Menu Utama?(Y/N) : ";
        cin >> kembali;
    } while (kembali == 'y' || kembali == 'Y');
}