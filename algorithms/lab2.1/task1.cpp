

#include <iostream>

using namespace std;

void sortInsertion(int arr[], int length) {
    for (int i = 1; i < length; i++) {
        int x = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > x) {
            arr[j] = arr[j - 1];
            j = j - 1;
        }
        arr[j] = x;
    }
}

void sortSelection(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        int min = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[min]) min = j;
        }
        if (min != i) swap(arr[i], arr[min]);
    }
}


int main() {
    cout << "input length: ";
    int length;
    cin >> length;
    int arr[length];
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }
    sortSelection(arr, length);
    for (int l : arr) cout << l << " ";
}