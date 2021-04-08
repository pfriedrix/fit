#include <iostream>

using namespace std;


void display(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void sortInsertion(int arr[], int length) {
    int comparisons{}, changes{};
    for (int i = 1; i < length; i++) {
        int x = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] < x) {
            arr[j] = arr[j - 1];
            --j;
            comparisons++;
            changes++;
        }
        arr[j] = x;
        display(arr, length);
    }
    cout << "comparisons: " << comparisons << " changes: " << changes << "\n";
}

void sortSelection(int arr[], int length) {
    int comparisons{}, changes{};
    for (int i = 0; i < length - 1; i++) {
        int min = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] > arr[min]) {
                min = j;
                comparisons++;
            }
        }
        if (min != i) {
            swap(arr[i], arr[min]);
            comparisons++;
            changes += 2;
        }
        display(arr, length);
    }
    cout << "comparisons: " << comparisons << " changes: " << changes << "\n";
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
    sortSelection(arr, length);
    for (int l : arr) cout << l << " ";
}