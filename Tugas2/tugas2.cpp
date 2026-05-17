#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;

int pil, menu;
char pilihan[1];
string dataBaru;

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();

// Fungsi baru tugas 2
void hapusTargetH();
void hapusTargetHT();

// =============================================
// Fungsi bantu: hitung jumlah node (H)
// =============================================
int hitungNodeH() {
    int count = 0;
    TNode *bantu = head;
    while (bantu != NULL) {
        count++;
        bantu = bantu->next;
    }
    return count;
}

// =============================================
// Fungsi bantu: hitung jumlah node (HT)
// =============================================
int hitungNodeHT() {
    int count = 0;
    TNode *bantu = head;
    while (bantu != NULL) {
        count++;
        bantu = bantu->next;
    }
    return count;
}

int main()
{
    initHT(); // inisialisasi awal
    menu:
    cout << "Double Linked List Non Circular (DLLNC)" << endl;
    cout << "=========================================" << endl;
    cout << "Silahkan pilih program DLLNC yang ingin dijalankan!" << endl;
    cout << "1. DLLNC dengan Head" << endl;
    cout << "2. DLLNC dengan Head dan Tail" << endl;
    cout << "3. Quit" << endl;
    cout << "Pilihan : ";
    cin >> menu;
    system("cls");

    if(menu==1){
        do {
            cout << "Double Linked List Non Circular (DLLNC) (Head)" << endl;
            cout << "================================================" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Hapus Depan" << endl;
            cout << "5. Hapus Belakang" << endl;
            cout << "6. Reset" << endl;
            cout << "7. Hapus Berdasarkan Target" << endl;
            cout << "8. Kembali ke Menu" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            pil = atoi(pilihan);
            system("cls");

            switch(pil) {
                case 1:
                    tambahDepanH();
                    break;
                case 2:
                    tambahBelakangH();
                    break;
                case 3:
                    tampilkanH();
                    break;
                case 4:
                    hapusDepanH();
                    break;
                case 5:
                    hapusBelakangH();
                    break;
                case 6:
                    clearH();
                    break;
                case 7:
                    hapusTargetH();
                    break;
                default:
                    system("cls");
                    goto menu;
            }

            cout << "\npress any key to continue" << endl;
            getch();
            system("cls");

        } while (pil<8);
    } else if(menu==2){
        do {
            cout << "Double Linked List Non Circular (DLLNC) (Head dan Tail)" << endl;
            cout << "==========================================================" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Hapus Depan" << endl;
            cout << "5. Hapus Belakang" << endl;
            cout << "6. Reset" << endl;
            cout << "7. Hapus Berdasarkan Target" << endl;
            cout << "8. Kembali ke Menu" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            pil = atoi(pilihan);
            system("cls");

            switch(pil) {
                case 1:
                    tambahDepanHT();
                    break;
                case 2:
                    tambahBelakangHT();
                    break;
                case 3:
                    tampilkanHT();
                    break;
                case 4:
                    hapusDepanHT();
                    break;
                case 5:
                    hapusBelakangHT();
                    break;
                case 6:
                    clearHT();
                    break;
                case 7:
                    hapusTargetHT();
                    break;
                default:
                    system("cls");
                    goto menu;
            }

            cout << "\npress any key to continue" << endl;
            getch();
            system("cls");

        } while (pil<8);
    } else {
        cout << "\nTERIMA KASIH" << endl;
        cout << "Program was made by Fauzan (2510817310017)." << endl;
    }
}

void initH(){
    head = NULL;
}

void initHT(){
    head = NULL;
    tail = NULL;
}

int isEmptyH(){
    if(head == NULL) return 1;
    else return 0;
}

int isEmptyHT(){
    if(tail == NULL) return 1;
    else return 0;
}

// =============================================
// MODIFIKASI 1a: tambahDepanH()
// - Input beberapa data sekaligus dipisah spasi
// - Urutan list sama dengan urutan input
// - Data baru ditambahkan SEBELUM data lama
// =============================================
void tambahDepanH() {
    cout << "Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore();
    string inputLine;
    getline(cin, inputLine);

    istringstream iss(inputLine);
    string token;
    string tokens[100];
    int jumlah = 0;
    while (iss >> token) {
        tokens[jumlah++] = token;
    }

    // Masukkan dari token terakhir ke pertama
    // agar urutan list = urutan input, dan data baru di depan data lama
    for (int i = jumlah - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = tokens[i];
        baru->next = NULL;
        baru->prev = NULL;

        if (isEmptyH() == 1) {
            head = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }
    cout << "Data \"" << inputLine << "\" berhasil dimasukkan di bagian depan." << endl;
}

// =============================================
// MODIFIKASI 1b: tambahDepanHT()
// - Input beberapa data sekaligus dipisah spasi
// - Urutan list sama dengan urutan input
// - Data baru ditambahkan SEBELUM data lama
// =============================================
void tambahDepanHT() {
    cout << "Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore();
    string inputLine;
    getline(cin, inputLine);

    istringstream iss(inputLine);
    string token;
    string tokens[100];
    int jumlah = 0;
    while (iss >> token) {
        tokens[jumlah++] = token;
    }

    for (int i = jumlah - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = tokens[i];
        baru->next = NULL;
        baru->prev = NULL;

        if (isEmptyHT() == 1) {
            head = baru;
            tail = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }
    cout << "Data \"" << inputLine << "\" berhasil dimasukkan di bagian depan." << endl;
}

// =============================================
// MODIFIKASI 1c: tambahBelakangH()
// - Input beberapa data sekaligus dipisah spasi
// - Urutan list sama dengan urutan input
// - Data baru ditambahkan SETELAH data lama
// =============================================
void tambahBelakangH() {
    cout << "Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore();
    string inputLine;
    getline(cin, inputLine);

    istringstream iss(inputLine);
    string token;

    while (iss >> token) {
        TNode *baru = new TNode;
        baru->data = token;
        baru->next = NULL;
        baru->prev = NULL;

        if (isEmptyH() == 1) {
            head = baru;
        } else {
            TNode *bantu = head;
            while (bantu->next != NULL) {
                bantu = bantu->next;
            }
            bantu->next = baru;
            baru->prev = bantu;
        }
    }
    cout << "Data \"" << inputLine << "\" berhasil dimasukkan di bagian belakang." << endl;
}

// =============================================
// MODIFIKASI 1d: tambahBelakangHT()
// - Input beberapa data sekaligus dipisah spasi
// - Urutan list sama dengan urutan input
// - Data baru ditambahkan SETELAH data lama
// =============================================
void tambahBelakangHT() {
    cout << "Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore();
    string inputLine;
    getline(cin, inputLine);

    istringstream iss(inputLine);
    string token;

    while (iss >> token) {
        TNode *baru = new TNode;
        baru->data = token;
        baru->next = NULL;
        baru->prev = NULL;

        if (isEmptyHT() == 1) {
            head = baru;
            tail = baru;
        } else {
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }
    }
    cout << "Data \"" << inputLine << "\" berhasil dimasukkan di bagian belakang." << endl;
}

void hapusDepanH() {
    TNode *hapus;
    string dataH;
    if(isEmptyH() == 0) {
        hapus = head;
        dataH = hapus->data;
        if(head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            initH();
        }
        delete hapus;
        cout << "Data \"" << dataH << "\" yang berada di depan telah berhasil dihapus." << endl;
    } else cout << "Tidak terdapat data pada Linked List" << endl;
}

void hapusDepanHT() {
    TNode *hapus;
    string dataH;
    if(isEmptyHT() == 0) {
        hapus = head;
        dataH = hapus->data;
        if(head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            initHT();
        }
        delete hapus;
        cout << "Data \"" << dataH << "\" yang berada di depan telah berhasil dihapus." << endl;
    } else cout << "Tidak terdapat data pada Linked List" << endl;
}

// =============================================
// MODIFIKASI 4a: hapusBelakangH()
// - Hapus node ke-N dari belakang
// - Jika N terlalu besar, gunakan sistem mundur (modulo)
// =============================================
void hapusBelakangH() {
    if(isEmptyH() == 0) {
        int N;
        cout << "Hapus node ke-N dari belakang. Masukkan N : ";
        cin >> N;

        int total = hitungNodeH();

        // Sistem mundur: jika N > total, N = N mod total
        // jika hasil mod = 0, berarti hapus node paling belakang
        if (N > total) {
            N = N % total;
            if (N == 0) N = total;
            cout << "N terlalu besar, menggunakan sistem mundur. N efektif = " << N << endl;
        }

        // Posisi dari depan = total - N + 1
        int posisi = total - N + 1;

        TNode *hapus = head;
        string dataH;

        if (posisi == 1) {
            // hapus head
            dataH = head->data;
            if (head->next != NULL) {
                head = head->next;
                head->prev = NULL;
            } else {
                initH();
            }
            delete hapus;
        } else {
            for (int i = 1; i < posisi; i++) {
                hapus = hapus->next;
            }
            dataH = hapus->data;
            if (hapus->next != NULL) {
                hapus->prev->next = hapus->next;
                hapus->next->prev = hapus->prev;
            } else {
                hapus->prev->next = NULL;
            }
            delete hapus;
        }
        cout << "Data \"" << dataH << "\" yang berada di posisi ke-" << N << " dari belakang telah berhasil dihapus." << endl;
    } else cout << "Tidak terdapat data pada Linked List" << endl;
}

// =============================================
// MODIFIKASI 4b: hapusBelakangHT()
// - Hapus node ke-N dari belakang
// - Jika N terlalu besar, gunakan sistem mundur (modulo)
// =============================================
void hapusBelakangHT() {
    if(isEmptyHT() == 0) {
        int N;
        cout << "Hapus node ke-N dari belakang. Masukkan N : ";
        cin >> N;

        int total = hitungNodeHT();

        // Sistem mundur
        if (N > total) {
            N = N % total;
            if (N == 0) N = total;
            cout << "N terlalu besar, menggunakan sistem mundur. N efektif = " << N << endl;
        }

        TNode *hapus = tail;
        string dataH;

        // Mundur N-1 langkah dari tail
        for (int i = 1; i < N; i++) {
            hapus = hapus->prev;
        }

        dataH = hapus->data;

        if (hapus == head && hapus == tail) {
            // hanya 1 node
            initHT();
        } else if (hapus == head) {
            head = head->next;
            head->prev = NULL;
        } else if (hapus == tail) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            hapus->prev->next = hapus->next;
            hapus->next->prev = hapus->prev;
        }
        delete hapus;

        cout << "Data \"" << dataH << "\" yang berada di posisi ke-" << N << " dari belakang telah berhasil dihapus." << endl;
    } else cout << "Tidak terdapat data pada Linked List" << endl;
}

void tampilkanH() {
    TNode *bantu;
    bantu = head;
    if(isEmptyH() == 0) {
        while(bantu != NULL) {
            cout << bantu->data << ' ';
            bantu = bantu->next;
        }
        cout << endl;
    } else cout << "Tidak terdapat data pada Linked List" << endl;
}

void tampilkanHT() {
    TNode *bantu;
    bantu = head;
    if(isEmptyHT() == 0) {
        while(bantu != tail->next) {
            cout << bantu->data << ' ';
            bantu = bantu->next;
        }
        cout << endl;
    } else cout << "Tidak terdapat data pada Linked List" << endl;
}

// =============================================
// MODIFIKASI 3a: clearH()
// - Hapus bergantian dari depan dan belakang
// - Dimulai dari depan
// - Tampilkan urutan dan isi node yang dihapus
// =============================================
void clearH() {
    if(isEmptyH() == 0) {
        int urutan = 1;
        // Cari tail dulu untuk H (tidak ada tail pointer)
        TNode *belakang = head;
        while (belakang->next != NULL) belakang = belakang->next;

        bool giliranDepan = true; // mulai dari depan

        while (head != NULL) {
            if (head == belakang) {
                // hanya tersisa 1 node
                cout << "Menghapus node ke-" << urutan << " (depan & belakang) : \"" << head->data << "\"" << endl;
                delete head;
                initH();
                break;
            }

            if (giliranDepan) {
                TNode *hapus = head;
                cout << "Menghapus node ke-" << urutan << " (dari depan) : \"" << hapus->data << "\"" << endl;
                head = head->next;
                if (head != NULL) head->prev = NULL;
                delete hapus;
            } else {
                TNode *hapus = belakang;
                cout << "Menghapus node ke-" << urutan << " (dari belakang) : \"" << hapus->data << "\"" << endl;
                belakang = belakang->prev;
                if (belakang != NULL) belakang->next = NULL;
                delete hapus;
            }

            giliranDepan = !giliranDepan;
            urutan++;
        }
        initH();
        cout << "Seluruh data pada Linked List telah dibersihkan." << endl;
    } else cout << "Tidak terdapat data pada Linked List" << endl;
}

// =============================================
// MODIFIKASI 3b: clearHT()
// - Hapus bergantian dari depan dan belakang
// - Dimulai dari depan
// - Tampilkan urutan dan isi node yang dihapus
// =============================================
void clearHT() {
    if(isEmptyHT() == 0) {
        int urutan = 1;
        bool giliranDepan = true;

        while (head != NULL) {
            if (head == tail) {
                // hanya tersisa 1 node
                cout << "Menghapus node ke-" << urutan << " (depan & belakang) : \"" << head->data << "\"" << endl;
                delete head;
                initHT();
                break;
            }

            if (giliranDepan) {
                TNode *hapus = head;
                cout << "Menghapus node ke-" << urutan << " (dari depan) : \"" << hapus->data << "\"" << endl;
                head = head->next;
                head->prev = NULL;
                delete hapus;
            } else {
                TNode *hapus = tail;
                cout << "Menghapus node ke-" << urutan << " (dari belakang) : \"" << hapus->data << "\"" << endl;
                tail = tail->prev;
                tail->next = NULL;
                delete hapus;
            }

            giliranDepan = !giliranDepan;
            urutan++;
        }
        cout << "Seluruh data pada Linked List telah dibersihkan." << endl;
    } else cout << "Tidak terdapat data pada Linked List" << endl;
}

// =============================================
// MODIFIKASI 2a: hapusTargetH()
// - Hapus semua node yang datanya sama dengan target
// - Jika lebih dari satu, semua dihapus
// - Jika tidak ada, tampilkan pesan
// =============================================
void hapusTargetH() {
    if(isEmptyH() == 0) {
        string target;
        cout << "Masukkan data target yang ingin dihapus : ";
        cin >> target;

        bool ditemukan = false;
        TNode *bantu = head;

        while (bantu != NULL) {
            TNode *next = bantu->next;
            if (bantu->data == target) {
                ditemukan = true;
                if (bantu == head) {
                    head = bantu->next;
                    if (head != NULL) head->prev = NULL;
                } else if (bantu->next == NULL) {
                    bantu->prev->next = NULL;
                } else {
                    bantu->prev->next = bantu->next;
                    bantu->next->prev = bantu->prev;
                }
                delete bantu;
            }
            bantu = next;
        }

        if (ditemukan)
            cout << "Semua node dengan data \"" << target << "\" telah berhasil dihapus." << endl;
        else
            cout << "Data \"" << target << "\" tidak ditemukan pada Linked List." << endl;
    } else cout << "Tidak terdapat data pada Linked List" << endl;
}

// =============================================
// MODIFIKASI 2b: hapusTargetHT()
// - Hapus semua node yang datanya sama dengan target
// - Jika lebih dari satu, semua dihapus
// - Jika tidak ada, tampilkan pesan
// =============================================
void hapusTargetHT() {
    if(isEmptyHT() == 0) {
        string target;
        cout << "Masukkan data target yang ingin dihapus : ";
        cin >> target;

        bool ditemukan = false;
        TNode *bantu = head;

        while (bantu != NULL) {
            TNode *next = bantu->next;
            if (bantu->data == target) {
                ditemukan = true;
                if (bantu == head && bantu == tail) {
                    initHT();
                    delete bantu;
                    bantu = NULL;
                    break;
                } else if (bantu == head) {
                    head = bantu->next;
                    head->prev = NULL;
                    delete bantu;
                } else if (bantu == tail) {
                    tail = bantu->prev;
                    tail->next = NULL;
                    delete bantu;
                } else {
                    bantu->prev->next = bantu->next;
                    bantu->next->prev = bantu->prev;
                    delete bantu;
                }
            }
            bantu = next;
        }

        if (ditemukan)
            cout << "Semua node dengan data \"" << target << "\" telah berhasil dihapus." << endl;
        else
            cout << "Data \"" << target << "\" tidak ditemukan pada Linked List." << endl;
    } else cout << "Tidak terdapat data pada Linked List" << endl;
}