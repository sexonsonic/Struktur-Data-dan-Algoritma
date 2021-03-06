#include <iostream>
#include <conio.h>

using namespace std;

struct node { // mendefinisikan struct node
    int data; // data dari node
    node *next; // pointer yang menunjukkan alamat node selanjutnya
};

node *head = NULL; // pointer yang berfungsi sebagai head sekaligus mendeklarasikan head = NULL

bool cekKosong() {
    if ( head == NULL ) // cek kondisi head = NULL
    return true; // mengembalikan nilai true
    return false; // mengembalikan nilai false
}

void insertAfter( node *prev_node, int nilai) {
    if ( prev_node == NULL ) { // cek kondisi head = NULL
        cout << "Nilai sebelumnya tidak boleh NULL";
    }
    node *new_node; // mendeklarasikan node baru
    new_node = new node; // alokasi memori dinamis
    new_node -> data = nilai; // mengisi node data dengan value dari int nilai
    new_node -> next = prev_node -> next; // mengisi node next dengan node next yang ditunjukkan head
    prev_node -> next = new_node; // nengisi node next head dengan menunjukkan node yang baru
}

void insertAkhir( int nilai ) { // fungsi insert pada akhir linked list
    node *new_node; // mendeklarasikan node baru
    node *temp; // pointer untuk operasi insert akhir linked list
    new_node = new node; // alokasi memori dinamis
    new_node -> data = nilai; // mengisi node data dengan value dari int nilai
    new_node -> next = NULL; // mengisi node next pada node baru dengan NULL

    if ( cekKosong()) {
        head = new_node; // pointer head menunjukkan alamat dari node baru
        head -> next = NULL; // mengisi node next pada node baru dengan NULL
    } else {
        temp = head; // pointer temp menunjukkan alamat dari node pertama (yang sebelumnya ditunjukkan oleh pointer head)
        while ( temp -> next != NULL) { // mengecek node next pada temp apakah tidak sama dengan NULL
            temp = temp -> next; // jika tidak sama dengan NULL, maka temp bergeser menuju alamat yang terdapat di node next
        }
        temp -> next = new_node; // jika sama dengan NULL, maka node next akan menunjukkan alamat dari node baru
    }
}

void deleteAwal() // fungsi delete pada awal linked list
{
    if (head == NULL) // kondisi apabila head NULL (kosong)
    {
        cout << "List Empty"; // Menampilkan keterangan
    }
    else
    {
        node *hps = head; // mendeklarasi node hps menjadi head
        head = head->next; // memindahkan posisi HEAD yang sekarang ke head->next, dimana adalah node setelah head saat ini
        free(hps); // free adalah fungsi untuk menghapus
    }
    
}

void deleteTengah(node **head_ref, int key) // fungsi delete tengah linked list
{
    // Store head node
    node *temp = *head_ref;
    node *prev = NULL;

    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }

    // Else Search for the key to be deleted,
    // keep track of the previous node as we
    // need to change 'prev->next' */
    else
    {
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        // If key was not present in linked list
        if (temp == NULL)
            return;

        // Unlink the node from linked list
        prev->next = temp->next;

        // Free memory
        delete temp;
    }
}

void deleteAkhir()
{
  node *hps, *prev;
  if (head == NULL)
  {
      cout << "List Empty";
  } // kondisi jika head tidak mempunyai value atau isi
  else if (head->next == NULL)
  {
      hps = head; // mendeklarasikan variable hps menjadi head
      head = NULL; // menjadikan head sebagai NULL atau kosong
      free(hps); // menghapus isi variabel hps
  } 
  else
  {
      hps = head; // mendeklarasikan variable hps menjadi head
      while (hps->next != NULL) // kondisi apabila hps->next tidak sama dengan NULL atau kosong
      {
          prev = hps; // mengubah variabel prev menjadi hps
          hps = hps->next; // mendeklarasikan variable hps menjadi hps->next
      }
    prev->next = NULL; // varibel prev->next diubah menjadi NULL/Kosong
    free(hps); // menghapus value dari variable hps
  }
  
}

void tampilkanList() { // menampilkan isi dari linked list
    if ( !cekKosong()) { // cek kondisi list apakah kosong atau tidak
        node *telusur; // membuat node baru untuk pengecekan penelusuran
        telusur = head; // penelusuran dimulai dari head
        cout << "===== Data Linked List =====" << endl;
        while ( telusur != NULL ) { 
            cout << telusur -> data << " "; // menampilkan node data linked list
            telusur = telusur -> next; // bergeser menuju alamat yang terdapat di node next
        }
    }
}

int main() {

    system("CLS");
    insertAkhir(1);
    insertAkhir(2);
    insertAkhir(3);
    insertAfter(head,15);
    tampilkanList();
    deleteAwal();
    cout << endl;
    tampilkanList();
    deleteTengah(&head, 2);
    cout << endl;
    tampilkanList();
    deleteAkhir();
    cout << endl;
    tampilkanList();
}