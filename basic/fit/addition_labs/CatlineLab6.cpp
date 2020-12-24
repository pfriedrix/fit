
#include <iostream>
#include <time.h>
using namespace std;


int LinearSearch(int x, int arr[], int i, int length) {
    if (i < length) {
        if (arr[i] == x) {
            return i;
        }
        else {
            return LinearSearch(x, arr, ++i, length);
        }
    }
    else {
        return -1;
    }
}

void display(int arr[], int size) {
    for(int i = 0; i<size; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
}


int main() {
    int n;
    cout << "input length of array: ";
    cin >> n;
    int arr[n];
    cout << "make random array or by input(r/i): ";
    char option;
    cin >> option;
    if (option == 'r') {
        for (int i = 0; i < n; i++){
            arr[i] = (rand()%100);
        }
    }
    else if (option == 'i') {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }
    display(arr, n);
    int input;
    cout << "Input number which you wanna search: ";
    cin >> input;
    int result = LinearSearch(input, arr, 0, n);
    if (result == -1) {
        cout << "Element is not found" << endl;
    }
    else {
        cout << "Element " << input << " has index: " << result << endl;
    }
    
}
