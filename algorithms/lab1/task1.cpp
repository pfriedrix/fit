#include <iostream>
#include <vector>

using namespace std;


void display(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int search_min_element(int *arr, int length) {
    int min_el = arr[0];
    int min_index = 0;
    for (int i = 1; i < length; i++) {
        if (min_el > arr[i]) {
            min_el = arr[i];
            min_index = i;
        }
    }
    return min_index;
}

vector<int> search_slicer(int *arr, int length) {
    int start_index, end_index;
    for (int i = 0; i < length; i++) {
        if (arr[i] > 0) {
            start_index = i;
            break;
        }
    }
    for (int i = length - 1; 0 <= i; i--) {
        if (arr[i] > 0) {
            end_index = i;
            break;
        }
    }
    vector<int> slicer = {start_index, end_index};
    return slicer;
}

int count_sum_by_slicer(int *arr, int start_index, int end_index) {
    int sum = 0;
    for (int i = start_index; i <= end_index; i++) {
        sum += arr[i];
    }
    return sum;
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
            for (int i = 0; i < n; i++) {
                arr[i] = (rand() % 10) - 5;
            }
            break;
        }
        else if (choice == 2)
        {

            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            break;
        }
        else
        {
            cout << "Ви нічого не вибрали, спробуйте ще раз: ";
            continue;
        }
    }
    display(arr, length);
    int index = search_min_element(arr, length);
    cout << "Мінімальним елементом массива є число \""
         << arr[index] << "\" з індексом \""
         << index << "\"." << endl;
    vector<int> slicer = search_slicer(arr, length);
    cout << "Сумма елементів масиву, що розташовані між першим і останнім додатними елементами - "
         << count_sum_by_slicer(arr, slicer[0], slicer[1]);
}
