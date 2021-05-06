#include <iostream>

using namespace std;

int swaps = 0, comparisons = 0;

void display(int arr[], int start, int end) {
    for (int i = start; i < end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void heapy(int arr[], int length, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    comparisons++;
    if (left < length && arr[left] > arr[largest]) largest = left;
    comparisons++;
    if (right < length && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swaps++;
        swap(arr[i], arr[largest]);
        heapy(arr, length, largest);
    }
}

void heapSort(int arr[], int length) {
    for (int i = length / 2 - 1; i >= 0; i--) {
        heapy(arr, length, i);
    }
    display(arr, 0, length);

    for (int i = length - 1; i >= 0; i--) {
        swaps++;
        swap(arr[0], arr[i]);
        heapy(arr, i, 0);
        display(arr, 0, length);
    }
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
    display(arr, 0, length);
    heapSort(arr, length);
    for (int i = 0; i < length; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "Number of swaps: " << swaps << endl;
    cout << "Number of comparisons: " << comparisons << endl << endl;
}