#include <iostream>

using namespace std;

bool is_min_element(int *arr, int length, int element) {
    for (int i = 0; i < length; i++) {
        if (element > arr[i]) {
            return false;
        }
    }
    return true;
}

bool is_max_element(int *arr, int length, int element) {
    for (int i = 0; i < length; i++) {
        if (element < arr[i]) {
            return false;
        }
    }
    return true;
}

void clear_arr(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        arr[i] = 0;
    }
}

int has_negative_numb(int *arr, int length) {
    int sum = 0;
    bool negative = false;
    for (int i = 0; i < length; i++){
        if (arr[i] < 0) {
            negative = true;
        }
        sum += arr[i];
    }
    if (negative) {
        return sum;
    }
    return -666;
}



int main() {
    tryAgain:
    cout << "Розмір матриці - ";
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    int choice;
    cout << "Як Ви хочете заповнити матрицю?" << endl << "1) Рандомно" << endl << "2) Вручну" << endl;
    while(true)
    {
        srand((unsigned)(time(NULL)));
        cin >> choice;
        if (choice == 1)
        {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    arr[i][j] = (rand() % 10) - 5;
                }
            }
            break;
        }
        else if (choice == 2)
        {

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cin >> arr[i][j];
                }
            }
            break;

        }
        else
        {
            cout << "Ви нічого не вибрали, спробуйте ще раз: ";
            continue;
        }
    }
    int column[n];
    int sum;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) column[j] = arr[j][i];
        sum = has_negative_numb(column, n);
        if (sum != -666) {
            cout << "Сумма елементів в стовпчику " << i+1 << ", що містить від'ємний елемент " << sum << endl;
        }
        clear_arr(column, n);
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    clear_arr(column, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                column[k] = arr[k][j];
            }
            if (is_min_element(arr[i], m, arr[i][j]) && is_max_element(column, n, arr[i][j])) {
                cout << "Сідлова точка - стовпчик \"" << i+1 << "\" рядок \"" << j+1 << "\"" << endl;
            }
            clear_arr(column, n);
        }
    }

    int positive = 0;
    int negative = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] < 0 ) {
                negative++;
            }
            else {
                positive++;
            }
        }
    }
    cout << "Добуток кількості додатних і кількості від'ємних елементів - " << positive * negative;

}