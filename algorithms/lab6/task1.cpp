#include <iostream>

using std::cout; using std::cin;

int LinearSearch(int arr[], int length, int key) {
    for (int i = 0; i < length; i++) {
        cout << arr[i];
        if (arr[i] == key) return i;
        cout << " not equal " << key << "\n";
    }
    return -1;
}

int main() {
    cout << "Enter length: ";
    int length;
    cin >> length;
    int arr[length];
    srand((unsigned) (time(nullptr)));
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 2000 - 1000;
    }
    for (int i:arr) cout << i << " ";
    cout << "\n";
    cout << "Enter number which you wanna search: ";
    int key;
    cin >> key;
    int res = LinearSearch(arr, length, key);
    cout << "\n";
    cout << "Index: " << res;
}