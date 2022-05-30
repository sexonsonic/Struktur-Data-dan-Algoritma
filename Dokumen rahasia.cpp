#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <ctime>
#include <windows.h>

#define INF 99

using namespace std;
int jumlahKapster = 0;

struct kapster
{
    int nomor;
    string namaKapster;
    string jKelaminKapster;
    int umurKapster;
    string alamatKapster;
    string nomorKapster;
	int level;
};

struct pemesanan
{
	int nomerantrian;
    string namaPelanggan;
    string alamatPelanggan;
    kapster barber;
    int pilihanPaket;
    int hargaPaket;
	pemesanan *next;
	string statusPembayaran = "Unpaid";
	string statusAntrian = "Not in queue";
    string kesamaanAntrian;
	int validasiPembayaran = 0;
	int validasiAntrian = 0;
};

struct jabatan
{
	int level;
	string keterangan;
	jabatan *left, *right;
};
jabatan *pohon, *root;

void deklarasi_awal()
{
    pohon = NULL;
}

void insertJabatan(jabatan** root, int level, string ket)
{
    jabatan *new_node;
    if ((*root) == NULL)
    {
        new_node = new jabatan;
        new_node -> level = level;
		new_node -> keterangan = ket;
        new_node -> left = new_node -> right = NULL;

        (*root) = new_node;
    }
	if (level < (*root) -> level)
	{
		insertJabatan(&(*root) -> left,level,ket);
	}
	if (level > (*root) -> level)
	{
		insertJabatan(&(*root) -> right,level,ket);
	}
}

pemesanan *head = NULL;
pemesanan *front = NULL;
pemesanan *rear = NULL;

void gotoxy(int x, int y){
	COORD c = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void headerMenu()
{
    system("CLS");
	cout << endl;
	cout << "                           ========================" << endl;
	cout << "                 ===========================================" << endl;
	cout << "        ==============================================================" << endl;
	cout << "============================== ASGARD BARBERSHOP ============================= " << endl;
	cout << "                Jl. Kita Masih Panjang No.1 Telp.(022)8880009" << endl;
	cout << "                  Cibiru, Bandung Melipir, Jawa Barat 40402" << endl;
	cout << "===============================================================================" << endl;
	cout << "===============================================================================" << endl;
	cout << endl;
}

void headerMenu2()
{
    system("CLS");
	cout << endl;
	cout << "                           		   	      ========================" << endl;
	cout << "              			  	      ===========================================" << endl;
	cout << "        			   ==============================================================" << endl;
	cout << "			   ============================== ASGARD BARBERSHOP ============================== " << endl;
	cout << "            				      Jl. Kita Masih Panjang No.1 Telp.(022)8880009" << endl;
	cout << "            			  		Cibiru, Bandung Melipir, Jawa Barat 40402" << endl;
	cout << "			   ===============================================================================" << endl;
	cout << "			   ===============================================================================" << endl;
	cout << endl;
}

void headerMenu3()
{
    system("CLS");
	cout << "                              ========================" << endl;
	cout << "                    ===========================================" << endl;
	cout << "           ==============================================================" << endl;
	cout << "   ============================== ASGARD BARBERSHOP ============================= " << endl;
	cout << "                   Jl. Kita Masih Panjang No.1 Telp.(022)8880009" << endl;
	cout << "                     Cibiru, Bandung Melipir, Jawa Barat 40402" << endl;
	cout << "   ===============================================================================" << endl;
	cout << "   ===============================================================================" << endl;
}

void menu()
{
	headerMenu();
	cout << "                     ====================================" << endl;
	cout << "                     |            Daftar Menu           |" << endl;
	cout << "                     ====================================" << endl;
    cout << endl;
    cout << "1. Tampil Data Kapster (Admin)\n"; // Membaca data dari file txt
    cout << "2. Pemesanan Barbershop\n";
	cout << "3. Pembayaran\n";
    cout << "4. Tampil Data Pemesanan\n";
	cout << "5. Monitoring Antrian Barbershop \n";
	cout << "6. Konfirmasi Pesanan Selesai (Admin) \n";
    cout << "7. Simpan Laporan Pemesanan (Admin)\n"; // Menulis data ke dalam bentuk file txt
	cout << "8. Tampil Laporan Pemesanan (Admin)\n"; // Membaca data dari file txt
	cout << "9. Cek Gaji Kapster (Admin)\n";
	cout << "10. Peta Panduan\n";
    cout << "11. Exit Program\n";
}

void keyAdmin()
{
    string keyword;

    headerMenu();
    cout << "Perhatian! Menu Khusus Admin.\nSilahkan masukkan kata kunci : "; cin >> keyword;

	while (keyword != "admin")
    {
		headerMenu();
		cout << endl;
		cout << "Kata kunci yang Anda masukkan salah!" << endl;
		cout << "Silahkan masukkan kata kunci : "; cin >> keyword;
    }

	headerMenu();
	cout << endl;
	cout << "Selamat! Anda dapat mengakses fitur ini!\nTekan enter untuk melanjutkan" << endl;
	getch();

}

void getjumlahKapster()
{
	string line;
	ifstream myfile ("Data_Karyawan.txt");
	size_t found;
	if (myfile.is_open())
	{
	    while (getline (myfile,line))
	    {
	        found = line.find(",");
	        char arr[] = ",";
		    int i = 0;
		    int awal = 0;
		    int jml;

		    while(found != string::npos)
			{
		    	found = line.find(arr, found+i);
		    	jml = found - awal ;
		        i++;
		        awal = found+1;
			}
			jumlahKapster++;
	    }
	    myfile.close();
	}
}

bool cekKosong()
{
    if (head == NULL)
        return true;
    return false;
}

void headerDataKapster()
{
    headerMenu3();
    gotoxy(0,8);cout << "======================================================================================";
    gotoxy(0,9);cout << "                                     Data Kapster ";
    gotoxy(0,10);cout << "======================================================================================";
    gotoxy(0,11);   cout << "| Id ";
	gotoxy(5,11);   cout << "| Nama Kapster ";
	gotoxy(20,11);  cout << "| Jenis Kelamin ";
	gotoxy(36,11);  cout << "| Umur Kapster ";
	gotoxy(52,11);  cout << "| Alamat Kapster ";
	gotoxy(69,11);  cout << "| Nomor Kapster ";
	gotoxy(85,11);  cout << "|";
}

void headerFormPemesanan()
{
	headerMenu3();
	cout << "======================================================================================" << endl;
    cout << "                             Pemesanan Asgard Barbershop" << endl;
    cout << "======================================================================================" << endl;
	gotoxy(0,11);   cout << "| Id ";
	gotoxy(5,11);   cout << "| Nama Kapster ";
	gotoxy(20,11);  cout << "| Jenis Kelamin ";
	gotoxy(36,11);  cout << "| Umur Kapster ";
	gotoxy(52,11);  cout << "| Alamat Kapster ";
	gotoxy(69,11);  cout << "| Nomor Kapster ";
	gotoxy(85,11); cout << "|";
}

void headerListPaket()
{
	headerMenu();
	cout << "================================================================" << endl;
    cout << "                 List Paket Asgard Barbershop" << endl;
    cout << "================================================================" << endl;
	cout << "                         Paket                   |    Harga" << endl;
	cout << "1. Signature Cut (Full Service)                  |     50K" << endl;
	cout << "2. Basic Cut (No Hair Wash)                      |     45K" << endl;
	cout << "3. Junior Cut (<9th)                             |     40K" << endl;
	cout << "4. Shaving                                       |     35K" << endl;
	cout << "5. Creambath                                     |     50K" << endl;
	cout << "6. Cut, Shave & Creambath                        |     100K" << endl;
	cout << "7. Coloring                                      |     80K" << endl;
}

void pembayaran(pemesanan *head)
{
	headerMenu();
	int nominal;
	int angka;
	int selisih;
	int i = 0;
	pemesanan *tmp;
	tmp = head;
	int cari;

	cout << "===============================================================================" << endl;
    cout << "                                  Payment Page" << endl;
    cout << "===============================================================================" << endl;
	cout << "Masukkan Nomor Id Pesanan yang ingin dicari : "; cin >> cari;

	tmp = head;

    while (tmp != NULL)
	{
		if (cari == tmp -> nomerantrian)
		{
			tmp -> kesamaanAntrian == "cocok";
            break;
		} else {
            tmp = tmp -> next;
        }
	}

    if (tmp == NULL)
    {
        cout << "Maaf, tidak terdapat data yang tersedia" << endl;
    }
	else if (tmp -> validasiPembayaran == 1)
	{
		cout << "Maaf, data pesanan atas nama " << tmp -> namaPelanggan << " telah terbayar" << endl;
	}

    while (tmp != NULL && tmp -> validasiPembayaran == 0)
    {
	cout << "=================================================" << endl;
	cout << " Pesanan atas nama : " << tmp -> namaPelanggan << endl;
	cout << " Pilihan Paket     : Paket " << tmp -> pilihanPaket << endl;
	cout << " Total harga       : Rp." << tmp -> hargaPaket << endl;
	cout << "=================================================" << endl;
	cout << " Masukkan Jumlah Pembayaran : "; cin >> nominal;
	selisih = tmp ->hargaPaket - nominal;
	while (selisih > 0)
	{
		cout << "Pembayaran Anda tidak memenuhi total harga. Pembayaran Anda kurang senilai Rp." << selisih << endl;
		cout << "Silahkan Masukan Sisa Pembayaran : "; cin >> angka;
		nominal += angka;
		selisih = tmp ->hargaPaket - nominal;
	}

	if (nominal == tmp -> hargaPaket)
	{
		tmp -> statusPembayaran = "Paid";
		tmp -> statusAntrian = "In queue";
		tmp -> validasiPembayaran = 1;
		cout << " Terima kasih! Pembayaran Anda sebesar Rp." << nominal << " telah kami terima! " << endl;
	} else
	{
		selisih = nominal - tmp -> hargaPaket;
		tmp -> statusPembayaran = "Paid";
		tmp -> statusAntrian = "In queue";
		tmp -> validasiPembayaran = 1;
		cout << " Terima kasih! Pembayaran Anda sebesar Rp." << nominal << " telah kami terima, namun terdapat kelebihan pembayaran senilai Rp."<< nominal - tmp -> hargaPaket << ". Jangan khawatir! Anda dapat mengambil kembalian tersebut saat berada di lokasi kami" << endl;
	}
        break;
    }
}

void headerDataSelesai()
{
    headerMenu2();
    cout << "===================================================================================================================================" << endl;
    cout << "                                                           Data Selesai " << endl;
    cout << "===================================================================================================================================" << endl;
	gotoxy(0,13);   cout << "| Id ";
	gotoxy(5,13);   cout << "| Nama Pemesan ";
	gotoxy(20,13);  cout << "| Alamat Pemesan Paket ";
	gotoxy(45,13);  cout << "| Pilihan Paket ";
	gotoxy(61,13);  cout << "| Nama Kapster ";
	gotoxy(76,13);  cout << "| Harga Paket ";
	gotoxy(91,13);  cout << "| Status Pembayaran ";
	gotoxy(111,13);  cout << "| Status Pemesanan";
	gotoxy(129,13); cout << " |";
}

void tampilSelesai(pemesanan *head)
{
	if (!cekKosong())
    {
        pemesanan *tmp;
        tmp = head;
		int i = 14;
        while (tmp != NULL)
        {
				gotoxy(0,i);   cout << "| " << i-13;
				gotoxy(5,i);   cout << "| " << tmp ->namaPelanggan;
				gotoxy(20,i);  cout << "| " << tmp ->alamatPelanggan;
				gotoxy(45,i);  cout << "| " << tmp ->pilihanPaket;
				gotoxy(76,i);  cout << "| " << tmp ->hargaPaket;
				gotoxy(61,i);  cout << "| " << tmp ->barber.namaKapster;
				gotoxy(91,i);  cout << "| " << tmp ->statusPembayaran;
				gotoxy(111,i); cout << "| " << tmp ->statusAntrian;
				gotoxy(129,i); cout << " |";
				i++;
            tmp = tmp -> next;
        }
    }else{
		gotoxy(0,14); cout << "Data Pemesanan Tidak Ada!\n";
	}
}

void simpanFile()
{
	time_t waktuSekarang;
 	time (&waktuSekarang);
    ofstream filepemesanan;
	pemesanan *tmp;
	tmp = head;

    filepemesanan.open("laporan_pemesanan.txt", ios::app);
		filepemesanan << endl;
		filepemesanan << endl;
		filepemesanan << "---------------------------------------------" << endl;
		filepemesanan << " Disimpan pada : " << ctime(&waktuSekarang);
    	filepemesanan << "===============================================================================================================================" << endl;
    	filepemesanan << "                                                     Data Laporan Pemesanan" << endl;
    	filepemesanan << "===============================================================================================================================" << endl;
    	filepemesanan << "      Nama Kapster\t| \tPaket\t | \tHarga\t | \t\tNama\t\t| \t\tAlamat\t\n";

		while (tmp != NULL)
        {
			if (tmp -> statusAntrian == "Done")
			{
            filepemesanan << " " << tmp -> barber.namaKapster << "\t\t\t| \t" << tmp -> pilihanPaket << "\t | \t" << tmp -> hargaPaket << "\t | " << tmp -> namaPelanggan << "\t\t\t| " << tmp -> alamatPelanggan << "\t\n";
			}
			tmp = tmp -> next;
        }

    filepemesanan.close();
	headerMenu();
	cout << "Data Laporan Pemesanan berhasil disimpan ke dalam file txt!" << endl;
}

void readFile()
{
	system("CLS");
	ifstream filepemesanan;
	char text;
	filepemesanan.open("laporan_pemesanan.txt");

	if(!filepemesanan.fail())
	{
		while (!filepemesanan.eof())
		{
			filepemesanan.get(text);
			cout << text;
		}
		filepemesanan.close();
	} else {
		headerMenu();
		cout << "File tidak ditemukan!\nSilahkan simpan laporan pemesanan terlebih dahulu" << endl;
	}
}

void headerQueue()
{
    headerMenu();
    cout << "===============================================================================" << endl;
    cout << "                              Antrian Barbershop " << endl;
    cout << "===============================================================================" << endl;
	gotoxy(0,13);   cout << "| Id ";
	gotoxy(5,13);   cout << "|      Nama Pemesan ";
	gotoxy(30,13);  cout << "|      Pilihan Paket ";
	gotoxy(55,13);  cout << "|      Nama Kapster ";
	gotoxy(77,13); cout << " |";
}

void inQueue()
{
	pemesanan *tmp;
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp -> validasiPembayaran == 1 && tmp -> validasiAntrian == 0)
		{
			pemesanan *new_node, *current;
			new_node = new pemesanan;
    		new_node -> nomerantrian = tmp -> nomerantrian;
			new_node -> namaPelanggan = tmp -> namaPelanggan;
			new_node -> pilihanPaket = tmp -> pilihanPaket;
			new_node -> barber.namaKapster = tmp -> barber.namaKapster;
    		new_node -> next = NULL; // mengisi node next pada node baru dengan NULL

    		if (front == NULL) // cek kondisi apakah front bernilai NULL
    		{
        		front = new_node; // Jika ya, maka node baru akan dijadikan sebagai front
    		}
    		else
    		{
        		current = front; // menjadikan node current sebagai front
        		while (current -> next != NULL) // cek kondisi apakah node next pada node current tidak sama dengan NULL
        		{
            		current = current -> next; // Jika ya, maka node current akan bergeser menuju node selanjutnya
        		}
        		current -> next = new_node; // mengisi node next pada node current dengan menunjukkan node baru
    		}
    		rear = new_node; // menjadikan node baru sebagai rear
			tmp -> validasiAntrian = 1;
		}
		tmp = tmp -> next;
	}
}

void displayQueue()
{
	pemesanan *tampilkan; // mendeklarasikan node tampilkan

    if (front == NULL) // cek kondisi apakah front bernilai NULL
    {
		cout << endl;
        cout << "Antrean dalam keadaan kosong" << endl; // Jika ya, maka command ini akan dijalankan
        cout << "Tidak ada data yang dapat ditampilkan" << endl;
    }
    else // Jika tidak, maka command di bawah akan dijalankan
    {
        tampilkan = front; // menjadikan node tampilkan sebagai front
		int i = 14;
        while (tampilkan != NULL) // cek kondisi apakah node tampilkan bernilai tidak sama dengan NULL
        {
            gotoxy(0,i);   cout << "| " << tampilkan -> nomerantrian;
			gotoxy(5,i);   cout << "| " << tampilkan -> namaPelanggan;
			gotoxy(30,i);  cout << "| " << tampilkan -> pilihanPaket;
			gotoxy(55,i);  cout << "| " << tampilkan -> barber.namaKapster;
			gotoxy(77,i);  cout << " |";
			i++;
            tampilkan = tampilkan -> next; // node tampilkan bergeser menjadi node next
        }
    }
}

void deQueue()
{
    pemesanan *hapus, *tmp; // mendeklarasikan node hapus
    int tmpId, tmpPaket;
	string tmpNama, tmpKapster;

	tmp = head;

	if (front != NULL)
    {
        hapus = front; // menjadikan node hapus sebagai front
		tmpId = hapus -> nomerantrian;
		tmpNama = hapus -> namaPelanggan;
		tmpPaket = hapus -> pilihanPaket;
		tmpKapster = hapus -> barber.namaKapster;
		while (tmp -> statusAntrian != "In queue")
		{
			tmp = tmp -> next;
		}
		tmp -> statusAntrian = "Done";
		cout << endl;
		cout << endl;
		cout << "Tekan enter untuk mengeluarkan antrian yang berada di posisi pertama" << endl;
		getch();
        cout << "Data dengan id " << tmpId << " telah dikeluarkan dari antrean" << endl;
        front = front -> next; // front berpindah posisi menjadi node next
        delete hapus; // menghapus node hapus
	}
}

void findQueue(int cariId)
{
    pemesanan *penelusuran;
    penelusuran = front;
    int temp, i = 1, posisi;

    if (front == NULL) // cek kondisi apakah front bernilai NULL
    {
        cout << "Maaf, queue dalam keadaan kosong" << endl;
        cout << "Tidak dapat melakukan pencarian" << endl;
    }
    else
    {
        while (penelusuran != NULL)
        {
            if (cariId == penelusuran -> nomerantrian)
            {
                temp = cariId;
                posisi = i;
            }
            penelusuran = penelusuran -> next;
            i++;
        }
		if (cariId == temp)
		{
			cout << "Data " << cariId << " ditemukan pada antrean ke-" << posisi << endl;
		}
		else
		{
			cout << "Data " << cariId << " tidak ditemukan dalam antrean" << endl;
		}
    }
}

int getgaji(jabatan* root,int level,int pengurangan)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root -> level == level)
	{
		return pengurangan;
	}
	int downlevel = getgaji(root->left,level,pengurangan+1);
	if (downlevel != 0)
	{
		return downlevel;
	}
	downlevel = getgaji(root->right,level,pengurangan+1);
	return downlevel;
}

int jarakMinimum(int jarak[], bool set[])
{
    int kecil = INF;
    int indeks;

    for (int i = 0; i < 10; i++)
    {
        if (set[i] == false && jarak[i] <= kecil)
        {
            kecil = jarak[i];
            indeks = i;
        }
    }
    return indeks;
}

void cetakRute(int simpan[], int j, int awal)
{
    string keteranganDaerah;
    if (j == 1)
    {
        keteranganDaerah = "Ujung Berung";
    } else if (j == 2)
    {
        keteranganDaerah = "Cinambo";
    } else if (j == 3)
    {
        keteranganDaerah = "Soekarno Hatta";
    } else if (j == 4)
    {
        keteranganDaerah = "Antapani";
    } else if (j == 5)
    {
        keteranganDaerah = "Cicaheum";
    } else if (j == 6)
    {
        keteranganDaerah = "Buah Batu";
    } else if (j == 7)
    {
        keteranganDaerah = "Gasibu";
    } else if (j == 8)
    {
        keteranganDaerah = "Dago";
    } else if (j == 9)
    {
        keteranganDaerah = "Baleendah";
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
            cout << "Kemudian pergi ke Cibiru" << endl;
            cout << "Lalu lanjutkan perjalanan hingga sampai di Asgard Barbershop" << endl;
        }
        else
        {
            cout << "Kemudian pergi ke " << keteranganDaerah << endl;
        }
    }
}

int tampilkanRute(int jarak[], int n, int simpan[], int awal)
{
    string keterangan;
    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            cout << endl;
            if (awal == 1)
            {
                keterangan = "Ujung Berung";
            } else if (awal == 2)
            {
                keterangan = "Cinambo";
            } else if (awal == 3)
            {
                keterangan = "Soekarno Hatta";
            } else if (awal == 4)
            {
                keterangan = "Antapani";
            } else if (awal == 5)
            {
                keterangan = "Cicaheum";
            } else if (awal == 6)
            {
                keterangan = "Buah Batu";
            } else if (awal == 7)
            {
                keterangan = "Gasibu";
            } else if (awal == 8)
            {
                keterangan = "Dago";
            } else if (awal == 9)
            {
                keterangan = "Baleendah";
            }
            cout << "Dari " << keterangan << endl;
            cetakRute(simpan, i, awal);
            cout << endl;
            cout << "\"Utamakan keselamatan, bukan kecepatan. Sampai bertemu di lokasi\" " << endl;
            cout << "---------------------------------" << endl;
            cout << "Total Jarak yang ditempuh : " << jarak[i] << "km" << endl;
            cout << "---------------------------------" << endl;
        }
    }
}

int dijkstra(int graf[10][10], int awal)
{
    int jarak[10];
    bool set[10];
    int simpan[10];

    for (int i = 0; i < 10; i++)
    {
        jarak[i] = INF;
        set[i] = false;
        simpan[i] = -1;
    }

    jarak[awal] = 0;

    for (int i = 0; i < 10; i++)
    {
        int m = jarakMinimum(jarak, set);
        set[m] = true;

        for (int i = 0; i < 10; i++)
        {
            if (!set[i] && graf[m][i] && jarak[m] + graf[m][i] < jarak[i])
            {
                simpan[i] = m;
                jarak[i] = jarak[m] + graf[m][i];
            }
        }
    }
    tampilkanRute(jarak, 10, simpan, awal);
}

void headerMap()
{
    system("CLS");
	cout << endl;
	cout << "                           ========================" << endl;
	cout << "                 ===========================================" << endl;
	cout << "        ==============================================================" << endl;
	cout << "============================== ASGARD BARBERSHOP ============================= " << endl;
	cout << "                Jl. Kita Masih Panjang No.1 Telp.(022)8880009" << endl;
	cout << "                  Cibiru, Bandung Melipir, Jawa Barat 40402" << endl;
	cout << "===============================================================================" << endl;
	cout << "===============================================================================" << endl;
    cout << "                           Peta Panduan Kota Bandung" << endl;
    cout << "                Mencari Rute Tercepat Menuju Lokasi Barbershop" << endl;
    cout << "===============================================================================" << endl;
    cout << "1. Ujung Berung" << endl;
    cout << "2. Cinambo" << endl;
    cout << "3. Soekarno Hatta" << endl;
    cout << "4. Antapani" << endl;
    cout << "5. Cicaheum" << endl;
    cout << "6. Buah Batu" << endl;
    cout << "7. Gasibu" << endl;
    cout << "8. Dago" << endl;
    cout << "9. Baleendah" << endl;
    cout << "=============================================" << endl;
}

int main()
{
	pohon = NULL;
	insertJabatan(&pohon,5,"admin");
	insertJabatan(&pohon,3,"kasir");
	insertJabatan(&pohon,6,"kapster_senior");
	insertJabatan(&pohon,7,"kapster_junior");
    getjumlahKapster();
    kapster *identitasTP;
    identitasTP = new kapster [jumlahKapster];
	int pilihan, cariId;
    char backToMenu = 'y';
	char cariData = 'y';
    string line;
	ifstream myfile ("Data_Karyawan.txt");
	size_t found;
	int baris = 0;
	string nama;
	int cariNama = 0;
	int level = 0;
    int graf[10][10] = { // matriks hubungan antar simpul
        {0, 4, 0, 5, 0, 0, 0, 0, 0, 0}, // Barbershop Cibiru
        {4, 0, 1, 0, 4, 5, 0, 0, 0, 0}, // Ujung Berung
        {0, 1, 0, 2, 6, 0, 0, 0, 0, 0}, // Cinambo
        {5, 0, 2, 0, 5, 0, 8, 0, 0, 0}, // Soekarno Hatta
        {0, 4, 6, 5, 0, 2, 7, 7, 0, 0}, // Antapani
        {0, 5, 0, 0, 2, 0, 0, 5, 7, 0}, // Cicaheum
        {0, 0, 0, 8, 7, 0, 0, 6, 0, 8}, // Buah Batu
        {0, 0, 0, 0, 7, 5, 6, 0, 3, 0}, // Gasibu
        {0, 0, 0, 0, 0, 7, 0, 3, 0, 0}, // Dago
        {0, 0, 0, 0, 0, 0, 8, 0, 0, 0}, // Baleendah
    };
    int asalDaerah;

	if (myfile.is_open())
	{
	    while (getline (myfile,line))
	    {
	        found = line.find(",");
	        char arr[] = ",";
		    int i = 0;
		    int awal = 0;
		    int jml;

		    while(found != string::npos)
			{
		    	found = line.find(arr, found+i);
		    	jml = found - awal;
		    	switch(i){
		    		case 0 : {
		    			stringstream sno(line.substr(awal,jml));
		    			sno >> identitasTP[baris].nomor;
						break;
					}
					case 1 : {
		    			stringstream snama(line.substr(awal,jml));
		    			snama >> identitasTP[baris].namaKapster;
						break;
					}
					case 2 : {
		    			stringstream sjk(line.substr(awal,jml));
		    			sjk >> identitasTP[baris].jKelaminKapster;
						break;
					}
					case 3 : {
		    			stringstream sumur(line.substr(awal,jml));
		    			sumur >> identitasTP[baris].umurKapster;
						break;
					}
					case 4 : {
		    			stringstream salamat(line.substr(awal,jml));
		    			salamat >> identitasTP[baris].alamatKapster;
						break;
					}
					case 5 : {
		    			stringstream snomor(line.substr(awal,jml));
		    			snomor >> identitasTP[baris].nomorKapster;
						break;
					}
					case 6 : {
		    			stringstream slevel(line.substr(awal,jml));
		    			slevel >> identitasTP[baris].level;
						break;
					}
				}
		        i++;
		        awal = found+1;
			}
			baris++;
	    }
	    myfile.close();
	}

    do
    {
        menu();
        cout << "Masukkan Pilihan Anda (1-11) : "; cin >> pilihan;
		int antrian = 1;
        switch(pilihan)
        {
            case 1 :
                keyAdmin();
				headerDataKapster();

                for ( int i = 0; i < jumlahKapster; i++ )
                {
                	gotoxy(0,i+12);   cout << "| " << i+1;
					gotoxy(5,i+12);   cout << "| " << identitasTP[i].namaKapster;
					gotoxy(20,i+12);  cout << "| " << identitasTP[i].jKelaminKapster;
					gotoxy(36,i+12);  cout << "| " << identitasTP[i].umurKapster;
					gotoxy(52,i+12);  cout << "| " << identitasTP[i].alamatKapster;
					gotoxy(69,i+12);  cout << "| " << identitasTP[i].nomorKapster;
					gotoxy(85,i+12); cout << "|";
				}
				break;

            case 2 :
				int barber;
				int paket;
				pemesanan *new_pemesanan, *tmp;
				new_pemesanan = new pemesanan;
                headerFormPemesanan();

                for ( int i = 0; i < jumlahKapster; i++ )
				{
					gotoxy(0,i+12);   cout << "| " << i+1;
					gotoxy(5,i+12);   cout << "| " << identitasTP[i].namaKapster;
					gotoxy(20,i+12);  cout << "| " << identitasTP[i].jKelaminKapster;
					gotoxy(36,i+12);  cout << "| " << identitasTP[i].umurKapster;
					gotoxy(52,i+12);  cout << "| " << identitasTP[i].alamatKapster;
					gotoxy(69,i+12);  cout << "| " << identitasTP[i].nomorKapster;
					gotoxy(85,i+12); cout << "|";
				}

				cout << "\nMasukan Kapster Pilihan Anda dengan input angka (Id Sebelah Kiri) : "; cin >> barber;

				while (barber > jumlahKapster )
				{
					cout << "Maaf, Pilihan Kapster tidak tersedia!" << endl;
					cout << "\nMasukan Kapster Pilihan Anda dengan input angka (Id Sebelah Kiri) : "; cin >> barber;
				}

				cout << "Masukan Nama Anda (Pemesan) : "; getline ( cin >> ws, new_pemesanan -> namaPelanggan );
				cout << "Masukan Alamat Anda (Pemesan) : "; getline ( cin >> ws, new_pemesanan -> alamatPelanggan );

				headerListPaket();
				cout << endl;
				cout << "Masukkan Paket Pilihan Anda (1-7) : "; cin >> new_pemesanan -> pilihanPaket;

				while ( new_pemesanan -> pilihanPaket > 7)
				{
					cout << "Maaf, Pilihan Paket tidak tersedia!" << endl;
					cout << "\nMasukkan Paket Pilihan Anda (1-7) : "; cin >> new_pemesanan -> pilihanPaket;
				}
				if (new_pemesanan -> pilihanPaket == 1) {
					new_pemesanan -> hargaPaket = 50000;
				} else if (new_pemesanan -> pilihanPaket == 2) {
					new_pemesanan -> hargaPaket = 45000;
				} else if (new_pemesanan -> pilihanPaket == 3) {
					new_pemesanan -> hargaPaket = 40000;
				} else if (new_pemesanan -> pilihanPaket == 4) {
					new_pemesanan -> hargaPaket = 35000;
				} else if (new_pemesanan -> pilihanPaket == 5) {
					new_pemesanan -> hargaPaket = 50000;
				} else if (new_pemesanan -> pilihanPaket == 6) {
					new_pemesanan -> hargaPaket = 100000;
				} else {
					new_pemesanan -> hargaPaket = 80000;
				}


				new_pemesanan -> barber = identitasTP[barber-1];
				new_pemesanan -> next = NULL;

				if (cekKosong())
				{
					new_pemesanan -> nomerantrian = antrian;
					head = new_pemesanan;
					head -> next = NULL;
				} else {
					antrian++;
					tmp = head;
					while (tmp -> next != NULL)
					{
						antrian++;
						tmp = tmp -> next;
					}
					new_pemesanan -> nomerantrian = antrian;
					tmp -> next = new_pemesanan;
				}
				headerMenu();
				cout << "Selamat " << new_pemesanan -> namaPelanggan << "! Pemesanan Anda telah berhasil!" << endl;
				cout << "Dengan Id Antrian = " << antrian;
				cout << "\nSilahkan menuju menu pembayaran untuk proses selanjutnya" << endl;
				break;

            case 3 :
				pembayaran(head);
				break;

            case 4 :
				headerDataSelesai();
				tampilSelesai(head);
				break;

			case 5 :
				headerQueue();
				inQueue();
				displayQueue();

				cout << "\nApakah ingin melakukan pencarian data? (Y/N) : "; cin >> cariData;
				if (cariData == 'y' || cariData == 'Y')
				{
					cout << "Masukkan id yang ingin dicari : "; cin >> cariId;
					findQueue(cariId);
				}

				break;

			case 6 :
				keyAdmin();
				headerQueue();
				displayQueue();
				deQueue();
				break;

            case 7 :
				keyAdmin();
				simpanFile();
				break;

			case 8 :
				keyAdmin();
				readFile();
				break;

			case 9 :
				keyAdmin();

				cout << "Masukan Nama Anda : "; cin >> nama;
				for (int i = 0; i < jumlahKapster; i++)
				{
					if (nama == identitasTP[i].namaKapster)
					{
						level = identitasTP[i].level;
						cariNama = 1;
					}
				}

				if (cariNama == 1)
				{
				cout << "Gaji " << nama << " = " << 3000000 - (getgaji(pohon,level,1)*500000);
				} else
				{
					cout << "Data atas nama " << nama << " tidak terdapat dalam data kapster";
					cout << endl;
				}
				break;

			case 10:
				headerMap();
				cout << "Dari daerah manakah Anda berasal?  (1-9): "; cin >> asalDaerah;
    			while ( asalDaerah > 9)
				{
        			cout << endl;
					cout << "Maaf, daerah tidak tersedia!" << endl;
					cout << "Dari daerah manakah Anda berasal?  (1-9): "; cin >> asalDaerah;
				}
    			cout << endl;
    			cout << "Mencari rute tercepat menuju barbershop...";
    			Sleep(2000);
    			cout << endl;
    			cout << "Rute tercepat menuju barbershop adalah sebagai berikut : ";
    			cout << endl;
    			dijkstra(graf, asalDaerah);
				break;

			case 11 :
				cout << "Tekan enter untuk keluar program";
				getch();
				return 0;
        }
		if (pilihan > 11)
		{
			cout << "\nMaaf, pilihan tidak tersedia";
		}
		cout << "\nKembali Ke Menu Utama? (Y/N) : "; cin >> backToMenu;
    } while (backToMenu == 'y' || backToMenu == 'Y');
}
