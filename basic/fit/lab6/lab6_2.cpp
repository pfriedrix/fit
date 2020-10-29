//
//  lab6_2.cpp
//  lab6
//
//  Created by Ivan Romancev on 19.10.2020.
//

#include <iostream>
using namespace std;

void display(int *arr, int size) {
    for(int i = 0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int max_arr(int *arr, int len){
    int max_value = arr[1];
    for (int i = 3; i < len; i += 2) if (max_value < arr[i]) max_value = arr[i];
    return max_value;
}

int min_arr(int *arr, int len) {
    int min_value = arr[2];
    for (int i = 4; i < len; i += 2) if (min_value > arr[i]) min_value = arr[i];
    return min_value;
}

int index_arr(int *arr, int len, int searched) {
    for (int i = 0; i < len; i++) if (arr[i] == searched) return i;
    return 0;
}

void swap_items(int *arr, int a, int b, int len) {
    int x = arr[a], y = arr[b];
    arr[a] = y;
    arr[b] = x;
    for (int i = 0; i < len; i++) cout << arr[i] << " ";
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
            arr[i] = rand()%100;
        }
    }
    else if (option == 'i') {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }
    display(arr, n);
    int max_value_index, min_value_index;
    max_value_index = index_arr(arr, n, max_arr(arr, n));
    min_value_index = index_arr(arr, n, min_arr(arr, n));

    cout << "max = " << arr[max_value_index] << " index = " << max_value_index << "; min = " << arr[min_value_index] << " index = " << min_value_index << endl;
    swap_items(arr, max_value_index, min_value_index, n);
}
