#include <iostream>
#include <math.h>

void display(int *arr, int size) {
    for(int i = 0; i<size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

double solve_linear_equation(int *arr, int len) {
    double i;
    double numerator = 0, deminator;
    for (int i = 0; i < len - 1; i++) numerator -= arr[i];
    std::cout << arr[len - 1] << std::endl;
    arr[0] =
    return i;
}

int main(){
    using std::cout;
    using std::cin;
    int n;
    cout << "input length of array: ";
    cin >> n;
    int arr[n];
    cout << "make random array or by input(r/i): ";
    char option;
    cin >> option;
    if (option == 'r') {
        for (int i = 0; i < n; i++){
            arr[i] = (rand()%10);
        }
    }
    else if (option == 'i') {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }
    display(arr, n);
    cout << solve_linear_equation(arr, n) << std::endl;
}

