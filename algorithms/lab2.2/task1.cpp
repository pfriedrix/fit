
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
        bool flag = false;
        for (int j = 0; j < length; j++) {
            comp++;
            if (arr[j] > arr[j + 1]) {
                swaps++;
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        i++;
        display(arr, length);
        if (!flag) break;
    }
    cout << "comparisons: " << comp << " changes: " << swaps << "\n";
}

void shellSort(int arr[], int length) {
    int comp = 0, swaps = 0;
    for (int step = length / 2; step > 0; step /= 2) {
        if (step % 2 == 0) step++;
        for (int i = step; i < length; i++) {
            int temp = arr[i];
            int j;
            bool flag = false;
            for (j = i; j >= step && arr[j - step] > temp; j -= step) {
                arr[j] = arr[j - step];
                swaps++;
                comp++;
                flag = true;
            }
            if (!flag) comp++;
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
        cin >> arr[i];
    }
    for (int el: arr) cout << el << " ";
    cout << endl;
    shellSort(arr, length);
    for (int l : arr) cout << l << " ";
}