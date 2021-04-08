
#include <iostream>

using namespace std;

void display(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int length) {
    int i = 0;
    int comp = 0, swaps = 0;
    while (i < length) {
        for (int j = 0; j < length; j++) {
            comp++;
            if (arr[j] > arr[j + 1]) {
                swaps++;
                swap(arr[j], arr[j + 1]);
            }
        }
        i++;
        display(arr, length);
    }
    cout << "comparisons: " << comp << " changes: " << swaps << "\n";
}

void shellSort(int arr[], int length) {
    int comp = 0, swaps = 0;
    for (int step = length / 2; step > 0; step /= 2) {
        for (int i = step; i < length; i++) {
            int temp = arr[i];
            int j;
            comp++;
            for (j = i; j >= step && arr[j - step] > temp; j -= step) {
                arr[j] = arr[j - step];
                swaps++;
                comp++;
            }

            arr[j] = temp;
        }
        display(arr, length);
    }
    cout << "comparisons: " << comp << " changes: " << swaps << "\n";
}

int main() {
    cout << "input length: ";
    int length;
    cin >> length;
    int arr[length];
    srand(time(nullptr));
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 100 - 50;
    }
    for (int el: arr) cout << el << " ";
    cout << endl;
    shellSort(arr, length);
    for (int l : arr) cout << l << " ";
}