#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

// ===== FUNGSI SEQUENTIAL SEARCH =====
int randomNum(int bil) {
    return rand() % bil;
}

void randomize() {
    srand(time(NULL));
}

void clrscr() {
    system("cls");
}

void sequentialSearching() {
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save;

    randomize();
    printf("generating 100 number . . .\n");
    for (int i = 0; i < 100; i++) {
        data[i] = randomNum(100) + 1;
        printf("%d ", data[i]);
    }
    printf("\ndone.\n");

    for (int i = 0; i < 100; i++) {
        if (data[i] == cari) {
            counter++;
            flag = 1;
            save = i;
        }
    }

    if (flag == 1) {
        printf("Data ada, sebanyak %d\n", counter);
        printf("pada indeks ke-%d\n", save);
    } else {
        printf("Data tidak ada!\n");
    }
}

// ===== FUNGSI BINARY SEARCH =====
void binarySearching() {
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Masukan jumlah data? ";
    cin >> n;
    int angka[n];

    for (int i = 0; i < n; i++) {
        cout << "Angka ke - [" << i << "] : ";
        cin >> angka[i];
    }

    // Sorting bubble sort dulu (syarat binary search: data terurut)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (angka[j] > angka[j + 1]) {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }

    cout << "\n------------------------------------------------------------------------\n";
    cout << "Data yang telah diurutkan adalah:\n";
    for (int i = 0; i < n; i++) {
        cout << angka[i] << " ";
    }
    cout << "\n------------------------------------------------------------------------\n";
    cout << "Masukan angka yang dicari: ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;
    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah]) {
            ketemu = true;
            break;
        } else if (key < angka[tengah]) {
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }

    if (ketemu == true) {
        cout << "Angka ditemukan! ";
    } else {
        cout << "Angka tidak ditemukan!";
    }
    cout << endl;
}

// ===== FUNGSI PENJELASAN PERBEDAAN =====
void jelaskanPerbedaan() {
    cout << "\n========================================================\n";
    cout << "   PERBEDAAN SEQUENTIAL SEARCH DAN BINARY SEARCH\n";
    cout << "========================================================\n\n";

    cout << "1. SEQUENTIAL SEARCHING\n";
    cout << "   - Mencari data satu per satu dari awal hingga akhir\n";
    cout << "   - Data TIDAK harus terurut\n";
    cout << "   - Kompleksitas: O(n)\n";
    cout << "   + Kelebihan:\n";
    cout << "     * Sederhana dan mudah diimplementasikan\n";
    cout << "     * Cocok untuk data tidak terurut\n";
    cout << "     * Efektif untuk data kecil\n";
    cout << "   - Kekurangan:\n";
    cout << "     * Lambat untuk data besar\n";
    cout << "     * Makin besar data, makin berat beban komputer\n\n";

    cout << "2. BINARY SEARCHING\n";
    cout << "   - Mencari data dengan membagi array menjadi 2 bagian\n";
    cout << "   - Data HARUS terurut terlebih dahulu\n";
    cout << "   - Kompleksitas: O(log n)\n";
    cout << "   + Kelebihan:\n";
    cout << "     * Jauh lebih cepat untuk data besar\n";
    cout << "     * Kompleksitas lebih kecil dari sequential\n";
    cout << "   - Kekurangan:\n";
    cout << "     * Data wajib diurutkan dulu\n";
    cout << "     * Implementasi lebih kompleks\n";
    cout << "========================================================\n";
}

// ===== MAIN MENU =====
int main() {
    int pilih;

    do {
        cout << "\nPilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                clrscr();
                sequentialSearching();
                break;
            case 2:
                clrscr();
                binarySearching();
                break;
            case 3:
                clrscr();
                jelaskanPerbedaan();
                break;
            case 4:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 4);

    return 0;
}