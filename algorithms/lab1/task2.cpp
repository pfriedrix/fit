#include <iostream>

using namespace std;


void display(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort_arr(int *arr, const int length) {
    int sorted[length];
    int counter = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] == 0) {
            sorted[counter] = arr[i];
            counter++;
        }
    }
    for (int i = 0; i < length; i++) {
        if (arr[i] != 0) {
            sorted[counter] = arr[i];
            counter++;
        }
    }
    display(sorted, length);
}



int main() {
    cout << "N дійсних елементів - ";
    int n;
    cin >> n;
    const int length = n;
    int arr[length];
    int choice;
    cout << "Як Ви хочете заповнити массив?" << endl << "1) Рандомно" << endl << "2) Вручну" << endl;
    while(true)
    {
        srand((unsigned)(time(NULL)));
        cin >> choice;
        if (choice == 1)
        {
            for (int i = 0; i < length; i++) {
                arr[i] = (rand() % 10) - 5;
            }
            break;

        }
        else if (choice == 2)
        {

            for (int i = 0; i < length; i++) {
                cin >> arr[i];
            }
            break;
        }
    }
    display(arr, length);
    sort_arr(arr, length);
}
