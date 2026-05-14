#include <iostream>
#include <string>
using namespace std;

void shellSort(string arr[], int n) {
    // Mulai dengan gap setengah dari ukuran array
    for (int gap = n / 2; gap > 0; gap /= 2) {

        // Lakukan insertion sort dengan jarak gap
        for (int i = gap; i < n; i++) {
            string temp = arr[i];
            int j = i;

            // Geser elemen yang lebih besar dari temp sejauh gap
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            // Tempatkan temp di posisi yang tepat
            arr[j] = temp;
        }
    }
}

int main() {
    string nama[] = {"Muhammad", "Fauzan", "Fakhriy", "Hartono"};
    int n = 4;

    cout << "==============================" << endl;
    cout << "         SHELL SORT           " << endl;
    cout << "==============================" << endl;

    cout << "\nData Sebelum Sorting: ";
    for (int i = 0; i < n; i++) cout << nama[i] << " ";
    cout << endl;

    shellSort(nama, n);

    cout << "Data Sesudah Sorting: ";
    for (int i = 0; i < n; i++) cout << nama[i] << " ";
    cout << endl;

    return 0;
}