#include <iostream>

using namespace std;



int main() {
    cout << "Розмір квадратної матриці - ";
    int n;
    cin >> n;
    const int length = n;
    int arr[length][length];
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if ((i <= j) && (i >= length - j - 1)) arr[i][j] = 1;
            else if ((i >= j) && (i <= length - j - 1)) arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
