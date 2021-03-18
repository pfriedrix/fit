#include <iostream>

using std::cout; using std::cin;

void display(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << std::endl;
}

int bubbleSort(int *arr, int length) {
    for (int i = 0; i < length - 1; i++)
        for (int j = 0; j < length - i - 1; j++)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}

int binarySearch(int *arr, int start, int end, int num) {
    if (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == num)
            return mid;
        if (arr[mid] > num) {
            for (int i = start; i < mid; i++) {
                cout << arr[i] << " ";
            }
            cout << std::endl;

            return binarySearch(arr, start, mid - 1, num);
        }

        if (arr[mid] < num) {
            for (int i = mid + 1; i < end + 1; i++) {
                cout << arr[i] << " ";
            }
            cout << std::endl;
            return binarySearch(arr, mid + 1, end, num);
        }

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
        cin >> arr[i];
    }
    display(arr, length);
    bubbleSort(arr, length);
    display(arr, length);
    cout << "Enter number which you wanna search: ";
    int key;
    cin >> key;
    int res = binarySearch(arr, 0, length - 1, key);
    cout << "Index: " << res;
}
