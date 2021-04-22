#include <iostream>
#include <list>
#include "prettyprint.hpp"


using namespace std;

void display(int arr[], int start, int end) {
    for (int i = start; i < end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void quickSort(int arr[], int left, int right, int length, int &comparisons, int &swaps) {
    display(arr, 0, length);
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        comparisons++;
        if (arr[i] < pivot)
            i++;
        else {
            if (arr[j] > pivot)
                j--;
            else {
                swap(arr[i], arr[j]);
                swaps++;
                i++;
                j--;
            }
        }

    }
    if (left < j) quickSort(arr, left, j, length, comparisons, swaps);
    if (i < right) quickSort(arr, i, right, length, comparisons, swaps);
}

void cocktailSort(int arr[], int right, int left, bool reversed, int length, int &comparisons, int &swaps) {
    if (right == left) return;
    if (reversed) {
        for (int i = left - 1; i >= right; i--) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swaps++;
                comparisons++;
            }
        }
        display(arr, 0, length);
        cocktailSort(arr, right + 1, left, !reversed, length, comparisons, swaps);
    } else {
        for (int i = right; i < left; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swaps++;
                comparisons++;
            }
        }
        display(arr, 0, length);
        cocktailSort(arr, right, left - 1, !reversed, length, comparisons, swaps);
    }
}

void countSort(int arr[], int length, int result[]) {
    int map[51]{0};
    for (int i = 0; i < length; i++) map[arr[i]]++;
    for (int el : map) cout << el << " ";
    cout << endl;
    int inst = 0;
    for (int i = 0; i < 51; i++) {
        if (i != 0 && map[i] == 0) continue;
        for (int j = 0; j < map[i]; j++) {
            result[inst] = i;
            inst++;
        }
    }
}


void radixSort(int arr[], int length) {
    int max = arr[0];
    for (int i = 0; i < length; i++) if (max < arr[i]) max = arr[i];
    int radix = 1;
    while (max / 10 > 0) {
        radix++;
        max /= 10;
    }
    for (int i = 0; i < radix; i++) {
        list<int> map[10];
        for (int j = 0; j < length; j++) {
            int r = arr[j] % (int) pow(10, i + 1);
            r /= pow(10, i);
            map[r].push_back(arr[j]);
        }
        cout << map << std::endl;
        int c = 0;
        for (int j = 0; j < 10; j++) {
            while (!map[j].empty()) {
                arr[c] = *(map[j].begin());
                map[j].erase(map[j].begin());
                c++;
            }
        }
    }
}


int main() {
    cout << "input length: ";
    int length;
    cin >> length;
    int arr[length];
    srand(time(nullptr));
    for (int i = 0; i < length; i++) {
//        arr[i] = rand() % 500;
        cin >> arr[i];
//        arr[i] = i + 1;
    }
    display(arr, 0, length);
    int swaps = 0, comparisons = 0;
    int result[length];
    radixSort(arr, length);

//    cout << "Number of swaps: " << swaps << endl;
//    cout << "Number of comparisons: " << comparisons << endl << endl;
    for (int l : arr) cout << l << " ";
    cout << endl;
}