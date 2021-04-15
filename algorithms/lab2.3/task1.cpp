#include <iostream>
#include <list>


using namespace std;

void display(int arr[], int start, int end) {
    for (int i = start; i < end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int *quickSort(int arr[], int left, int right, int length) {
    display(arr, 0, length);
    int comparisons, swaps;
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
    if (left < j) {
        int *res = quickSort(arr, left, j, length);
        comparisons += res[0];
        swaps += res[1];
    }
    if (i < right) {
        int *res = quickSort(arr, i, right, length);
        comparisons += res[0];
        swaps += res[1];
    }
    int res[2];
    res[0] = comparisons;
    res[1] = swaps;
    return res;
}

void cocktailSort(int arr[], int right, int left, bool reversed) {
    if (right == left) return;
    if (reversed) {
        for (int i = left - 1; i >= right; i--) {
            if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
        }
        cocktailSort(arr, right + 1, left, !reversed);
    } else {
        for (int i = right; i < left; i++) {
            if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
        }
        cocktailSort(arr, right, left - 1, !reversed);
    }
}

void countSort(int arr[], int length, int result[]) {
    int map[50]{0};
    for (int i = 0; i < length; i++) map[arr[i]]++;
    int inst = 0;
    for (int i = 0; i < 50; i++) {
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
        arr[i] = rand() % 500;
    }
    display(arr, 0, length);
    int result[length];
    radixSort(arr, length);
    for (int l : arr) cout << l << " ";
    cout << endl;
}