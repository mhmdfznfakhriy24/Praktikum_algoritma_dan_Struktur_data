#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>  // untuk parsing input spasi

using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
};

TNode *head, *tail;

int pil;
char pilihan[2];
string dataBaru, dataHapus;

void init();
int isEmpty();

void tambahDepan();
void tambahBelakang();
void hapusDepan();
void hapusBelakang();
void tampilkan();
void reset();
void cariData();
void hapusData();
void sisipkanSebelum();
void sisipkanSetelah();

// =============================================
// Fungsi bantu: hitung jumlah node
// =============================================
int hitungNode() {
    if (isEmpty() == 1) return 0;
    int count = 1;
    TNode *bantu = head;
    while (bantu->next != head) {
        count++;
        bantu = bantu->next;
    }
    return count;
}

int main()
{
    init();
    do {
        cout << "Single Linked List Circular (SLLC)" << endl;
        cout << "=====================================" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Hapus Depan" << endl;
        cout << "4. Hapus Belakang" << endl;
        cout << "5. Tampilkan Data" << endl;
        cout << "6. Hapus Semua Elemen" << endl;
        cout << "7. Cari Data" << endl;
        cout << "8. Hapus Setiap Data Tertentu" << endl;
        cout << "9. Sisipkan Node/Data Baru Sebelum Data Tertentu" << endl;
        cout << "10. Sisipkan Node/Data Baru Setelah Data Tertentu" << endl;
        cout << "11. Quit" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        pil = atoi(pilihan);

        switch(pil) {
            case 1:
                tambahDepan();
                break;
            case 2:
                tambahBelakang();
                break;
            case 3:
                hapusDepan();
                break;
            case 4:
                hapusBelakang();
                break;
            case 5:
                tampilkan();
                break;
            case 6:
                reset();
                break;
            case 7:
                cariData();
                break;
            case 8:
                hapusData();
                break;
            case 9:
                sisipkanSebelum();
                break;
            case 10:
                sisipkanSetelah();
                break;
            default:
                cout << "\nTERIMA KASIH" << endl;
                cout << "Program was made by Nama (NIM)." << endl;
        }

        cout << "\nPress any key to continue!" << endl;
        getch();
        system("cls");

    } while (pil < 11);
}

void init(){
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    if(head == NULL) return 1;
    else return 0;
}

// =============================================
// MODIFIKASI 1: tambahDepan()
// - Menerima beberapa data dalam satu baris
// - Dipisahkan spasi
// - Urutan linked list sama dengan urutan input
// =============================================
void tambahDepan() {
    cout << "Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore();
    string inputLine;
    getline(cin, inputLine);

    // Parse setiap token dari input
    istringstream iss(inputLine);
    string token;

    // Tampung semua token dulu ke array sementara
    // agar urutan list = urutan input
    // Caranya: sisipkan dari depan tapi dalam urutan terbalik
    // Atau: kumpulkan semua token, lalu masukkan dari belakang ke depan
    string tokens[100];
    int jumlah = 0;
    while (iss >> token) {
        tokens[jumlah++] = token;
    }

    // Masukkan dari token terakhir ke pertama
    // sehingga token pertama jadi head (urutan terjaga)
    for (int i = jumlah - 1; i >= 0; i--) {
        TNode *baru;
        baru = new TNode;
        baru->data = tokens[i];
        baru->next = baru;

        if (isEmpty() == 1) {
            head = baru;
            tail = baru;
        } else {
            baru->next = head;
            head = baru;
            tail->next = head;
        }
    }

    cout << "Data \"" << inputLine << "\" berhasil dimasukkan di bagian depan." << endl;
}

void tambahBelakang() {
    cout << "Masukkan data : ";
    TNode *baru;
    baru = new TNode;
    cin >> dataBaru;
    baru->data = dataBaru;
    baru->next = baru;

    if(isEmpty() == 1) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
    cout << "Data \"" << dataBaru << "\" berhasil dimasukkan di bagian belakang." << endl;
}

// =============================================
// MODIFIKASI 3: hapusDepan()
// - Menghapus node pada posisi ke-N dari depan
// - Jika N > jumlah node, hapus tail
// =============================================
void hapusDepan() {
    if(isEmpty() == 0) {
        int N;
        cout << "Hapus node ke-N dari depan. Masukkan N : ";
        cin >> N;

        int total = hitungNode();

        // Jika N > jumlah node, hapus tail
        if (N > total) {
            cout << "N melebihi jumlah node (" << total << "), menghapus tail." << endl;
            // Hapus tail: cari node sebelum tail
            if (head == tail) {
                // hanya 1 node
                dataHapus = head->data;
                delete head;
                init();
            } else {
                TNode *bantu = head;
                while (bantu->next != tail) {
                    bantu = bantu->next;
                }
                dataHapus = tail->data;
                delete tail;
                tail = bantu;
                tail->next = head;
            }
            cout << "Data \"" << dataHapus << "\" yang berada di posisi tail telah berhasil dihapus." << endl;
        } else {
            // Hapus node ke-N dari depan
            if (N == 1) {
                // Hapus head
                TNode *hapus = head;
                dataHapus = hapus->data;
                if (head == tail) {
                    delete hapus;
                    init();
                } else {
                    head = head->next;
                    tail->next = head;
                    delete hapus;
                }
            } else {
                // Jalan ke node ke-(N-1)
                TNode *bantu = head;
                for (int i = 1; i < N - 1; i++) {
                    bantu = bantu->next;
                }
                TNode *hapus = bantu->next;
                dataHapus = hapus->data;
                bantu->next = hapus->next;
                if (hapus == tail) {
                    tail = bantu;
                    tail->next = head;
                }
                delete hapus;
            }
            cout << "Data \"" << dataHapus << "\" yang berada di posisi ke-" << N << " dari depan telah berhasil dihapus." << endl;
        }
    } else {
        cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

// =============================================
// MODIFIKASI 2: hapusBelakang()
// - Menghapus node ke-N dari belakang
// - Jika N > jumlah node, hapus head
// =============================================
void hapusBelakang() {
    if(isEmpty() == 0) {
        int N;
        cout << "Hapus node ke-N dari belakang. Masukkan N : ";
        cin >> N;

        int total = hitungNode();

        // Jika N > jumlah node, hapus head
        if (N > total) {
            cout << "N melebihi jumlah node (" << total << "), menghapus head." << endl;
            TNode *hapus = head;
            dataHapus = hapus->data;
            if (head == tail) {
                delete hapus;
                init();
            } else {
                head = head->next;
                tail->next = head;
                delete hapus;
            }
            cout << "Data \"" << dataHapus << "\" yang berada di posisi head telah berhasil dihapus." << endl;
        } else {
            // Node ke-N dari belakang = node ke-(total - N + 1) dari depan
            int posisiDariDepan = total - N + 1;

            if (posisiDariDepan == 1) {
                // Hapus head
                TNode *hapus = head;
                dataHapus = hapus->data;
                if (head == tail) {
                    delete hapus;
                    init();
                } else {
                    head = head->next;
                    tail->next = head;
                    delete hapus;
                }
            } else {
                TNode *bantu = head;
                for (int i = 1; i < posisiDariDepan - 1; i++) {
                    bantu = bantu->next;
                }
                TNode *hapus = bantu->next;
                dataHapus = hapus->data;
                bantu->next = hapus->next;
                if (hapus == tail) {
                    tail = bantu;
                    tail->next = head;
                }
                delete hapus;
            }
            cout << "Data \"" << dataHapus << "\" yang berada di posisi ke-" << N << " dari belakang telah berhasil dihapus." << endl;
        }
    } else {
        cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

void tampilkan() {
    if(isEmpty() == 0) {
        TNode *bantu;
        bantu = head;
        do {
            cout << bantu->data << ' ';
            bantu = bantu->next;
        } while(bantu != head);
        cout << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

// =============================================
// MODIFIKASI 4: reset()
// - Node dihapus satu per satu
// - Setiap penghapusan menampilkan node ke berapa dan isinya
// =============================================
void reset() {
    if(isEmpty() == 0) {
        int urutan = 1;
        while (head != NULL) {
            TNode *hapus = head;
            cout << "Menghapus node ke-" << urutan << " : \"" << hapus->data << "\"" << endl;

            if (head == tail) {
                // Hanya tersisa 1 node
                delete hapus;
                init();
            } else {
                head = head->next;
                tail->next = head;
                delete hapus;
            }
            urutan++;
        }
        cout << "Seluruh elemen pada Linked List telah dibersihkan." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void cariData() {
    if(isEmpty() == 0) {
        string cari;
        cout << "Masukkan data yang ingin dicari : ";
        cin >> cari;

        TNode *bantu, *hapus, *newTail, *bantuTampilkan;
        bool apaDitemukan = false;

        bantu = head;

        do {
            if(cari == bantu->data){
                cout << "Setiap data yang berada di dalam tanda kurung siku ([...]) "
                     << "merupakan data yang anda cari." << endl;
                cout << "Linked List : ";
                bantuTampilkan = head;

                do {
                    if(cari == bantuTampilkan->data)
                        cout << "[" << bantuTampilkan->data << "] ";
                    else
                        cout << bantuTampilkan->data << ' ';
                    bantuTampilkan = bantuTampilkan->next;
                } while(bantuTampilkan != head);

                apaDitemukan = true;
                cout << endl;
                break;
            }
            bantu = bantu->next;
        } while(bantu != head);

        if(apaDitemukan == false)
            cout << "Data \"" << cari << "\" tidak ditemukan pada Linked List." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void hapusData() {
    if(isEmpty() == 0) {
        string cari;
        cout << "Masukkan data yang ingin dihapus : ";
        cin >> cari;

        TNode *bantu, *sebelum, *hapus[255], *bantu2;
        int hitung = 0;
        bool apaDitemukan = false;

        bantu = head;

        do {
            bantu2 = bantu;
            if(cari == bantu->data){
                hapus[hitung++] = bantu;
                apaDitemukan = true;
                if(bantu != head && bantu != tail) {
                    sebelum->next = bantu->next;
                    bantu2 = sebelum;
                }
            }
            sebelum = bantu2;
            bantu = bantu->next;
        } while(bantu != head);

        if(apaDitemukan == true) {
            for(int i = 0; i < hitung; i++) {
                if(hapus[i] == head){
                    hapusDepan();  // panggil versi asli hapus head
                } else if(hapus[i] == tail) {
                    // hapus tail langsung
                    TNode *prev = head;
                    while (prev->next != tail) prev = prev->next;
                    delete tail;
                    tail = prev;
                    tail->next = head;
                } else {
                    delete hapus[i];
                }
            }
            cout << "Setiap data \"" << cari << "\" yang terdapat pada Linked List telah dihapus" << endl;
        } else cout << "Data \"" << cari << "\" tidak ditemukan pada Linked List." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void sisipkanSebelum() {
    if(isEmpty() == 0) {
        TNode *bantu, *sebelum;
        string nextData;
        bool apaAda;

        bantu = head;
        sebelum = tail;

        cout << "Sisipkan data baru sebelum data : ";
        cin >> nextData;

        do {
            if(nextData == bantu->data){
                apaAda = true;
                break;
            } else {
                sebelum = bantu;
                bantu = bantu->next;
            }
        } while(bantu != head);

        if(apaAda==true) {
            cout << "Masukkan data yang ingin ditambahkan : ";
            cin >> dataBaru;

            TNode *baru;
            baru = new TNode;

            baru->data = dataBaru;
            baru->next = bantu;

            sebelum->next = baru;

            if(bantu == head){
                head = baru;
            }

            cout << "Data \"" << dataBaru << "\" berhasil disisipkan sebelum data \"" << nextData << "\"." << endl;
        } else {
            cout << "Tidak terdapat data \"" << nextData << "\" pada Linked List." << endl;
        }
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void sisipkanSetelah() {
    if(isEmpty() == 0) {
        TNode *bantu;
        string prevData;
        bool apaAda;

        bantu = head;

        cout << "Sisipkan data baru setelah data : ";
        cin >> prevData;

        do {
            if(prevData == bantu->data){
                apaAda = true;
                break;
            } else {
                bantu = bantu->next;
            }
        } while(bantu != head);

        if(apaAda==true) {
            cout << "Masukkan data yang ingin ditambahkan : ";
            cin >> dataBaru;

            TNode *baru;
            baru = new TNode;

            baru->data = dataBaru;
            baru->next = bantu->next;

            bantu->next = baru;

            if(bantu == tail){
                tail = baru;
            }

            cout << "Data \"" << dataBaru << "\" berhasil disisipkan setelah data \"" << prevData << "\"." << endl;
        } else {
            cout << "Tidak terdapat data \"" << prevData << "\" pada Linked List." << endl;
        }
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}