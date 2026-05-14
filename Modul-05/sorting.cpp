#include <iostream>
#include <string>
using namespace std;

// ==================== DATA ====================
string nama[] = {"Muhammad", "Fauzan", "Fakhriy", "Hartono"};
int nim[] = {2, 5, 1, 0, 8, 1, 7, 3, 1, 0, 0, 1, 7};
int totalNama = 4;
int totalNim = 13;

// ==================== TAMPILAN MENU ====================
void tampilMenu() {
    cout << "================================" << endl;
    cout << "            SORTING             " << endl;
    cout << "================================" << endl;
    cout << "  1. Insertion Sort" << endl;
    cout << "  2. Merge Sort" << endl;
    cout << "  3. Shell Sort" << endl;
    cout << "  4. Quick Sort" << endl;
    cout << "  5. Bubble Sort" << endl;
    cout << "  6. Selection Sort" << endl;
    cout << "  7. Exit" << endl;
    cout << "================================" << endl;
    cout << "Masukkan Pilihan : ";
}

void tampilNama(string arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void tampilNim(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void resetNama(string arr[]) {
    string temp[] = {"Muhammad", "Fauzan", "Fakhriy", "Hartono"};
    for (int i = 0; i < 4; i++) arr[i] = temp[i];
}

void resetNim(int arr[]) {
    int temp[] = {2, 5, 1, 0, 8, 1, 7, 3, 1, 0, 0, 1, 7};
    for (int i = 0; i < 13; i++) arr[i] = temp[i];
}

// ==================== 1. INSERTION SORT ====================
void insertionSort(string arr[], int n) {
    for (int i = 1; i < n; i++) {
        string key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void menuInsertionSort() {
    resetNama(nama);
    cout << "\n--- INSERTION SORT (NAMA) ---" << endl;
    cout << "Sebelum Sorting: "; tampilNama(nama, totalNama);
    insertionSort(nama, totalNama);
    cout << "Sesudah Sorting: "; tampilNama(nama, totalNama);
}

// ==================== 2. MERGE SORT ====================
void merge(string arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    string L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { arr[k] = L[i]; i++; }
        else { arr[k] = R[j]; j++; }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

void mergeSort(string arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void menuMergeSort() {
    resetNama(nama);
    cout << "\n--- MERGE SORT (NAMA) ---" << endl;
    cout << "Sebelum Sorting: "; tampilNama(nama, totalNama);
    mergeSort(nama, 0, totalNama - 1);
    cout << "Sesudah Sorting: "; tampilNama(nama, totalNama);
}

// ==================== 3. SHELL SORT ====================
void shellSort(string arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            string temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void menuShellSort() {
    resetNama(nama);
    cout << "\n--- SHELL SORT (NAMA) ---" << endl;
    cout << "Sebelum Sorting: "; tampilNama(nama, totalNama);
    shellSort(nama, totalNama);
    cout << "Sesudah Sorting: "; tampilNama(nama, totalNama);
}

// ==================== 4. QUICK SORT ====================
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }
    int temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void menuQuickSort() {
    resetNim(nim);
    cout << "\n--- QUICK SORT (NIM) ---" << endl;
    cout << "Sebelum Sorting: "; tampilNim(nim, totalNim);
    quickSort(nim, 0, totalNim - 1);
    cout << "Sesudah Sorting: "; tampilNim(nim, totalNim);
}

// ==================== 5. BUBBLE SORT ====================
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void menuBubbleSort() {
    resetNim(nim);
    cout << "\n--- BUBBLE SORT (NIM) ---" << endl;
    cout << "Sebelum Sorting: "; tampilNim(nim, totalNim);
    bubbleSort(nim, totalNim);
    cout << "Sesudah Sorting: "; tampilNim(nim, totalNim);
}

// ==================== 6. SELECTION SORT ====================
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        if (minIndex != i) {
            int temp = arr[i]; arr[i] = arr[minIndex]; arr[minIndex] = temp;
        }
    }
}

void menuSelectionSort() {
    resetNim(nim);
    cout << "\n--- SELECTION SORT (NIM) ---" << endl;
    cout << "Sebelum Sorting: "; tampilNim(nim, totalNim);
    selectionSort(nim, totalNim);
    cout << "Sesudah Sorting: "; tampilNim(nim, totalNim);
}

// ==================== MAIN ====================
int main() {
    int pilihan;
    do {
        tampilMenu();
        cin >> pilihan;
        switch (pilihan) {
            case 1: menuInsertionSort(); break;
            case 2: menuMergeSort(); break;
            case 3: menuShellSort(); break;
            case 4: menuQuickSort(); break;
            case 5: menuBubbleSort(); break;
            case 6: menuSelectionSort(); break;
            case 7: cout << "\nProgram selesai. Terima kasih!" << endl; break;
            default: cout << "\nPilihan tidak valid!" << endl;
        }
        cout << endl;
    } while (pilihan != 7);

    return 0;
}