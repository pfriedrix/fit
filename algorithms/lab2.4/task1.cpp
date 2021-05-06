#include <iostream>

using namespace std;

int swaps = 0, comparisons = 0;

void display(int arr[], int start, int end) {
    for (int i = start; i < end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int *arr, int low, int high, int mid, const int length) {
    int c[length];
    memset(c, 0, length * sizeof(int));
    int i = low;
    int k = low;
    int j = mid + 1;
    while (i <= mid && j <= high) {
        comparisons++;
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        } else {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    bool merged = false;
    display(c, 0, k);
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
        merged = true;
    }
//    display(c, 0, high);
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
        merged = true;
    }
    if (merged)
        if (low > 1 || k > length) display(c, 0, high);
        else display(c, 0, high);

    for (i = low; i < k; i++) {
        arr[i] = c[i];
    }
}


void merge_sort(int *arr, int low, int high, int length) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        merge_sort(arr, low, mid, length);
        merge_sort(arr, mid + 1, high, length);
        merge(arr, low, high, mid, length);

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

    merge_sort(arr, 0, length, length);
    cout << "Number of comparisons: " << comparisons << endl << endl;
}