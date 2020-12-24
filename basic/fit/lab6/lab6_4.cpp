// 2x4 + 5x3 - 11x2 - 20x + 12 = 0                          x = ±2; -3; 0.5;
// 4x3 - 19x2 + 19x + 6 = 0                                 x = 2; 3; -0.25;
// x6 + 2x5 - 21x4 -20x3 + 71x2 + 114x + 45 = 0             x = 3; -5; -1;
// х3 + 4х2 + х – 6 = 0                                     x = -3; 1; -2;
// x3 + 6x — x — 30 = 0                                     x = -3; -5; 2;


#include <iostream>
#include <math.h>

void display(int *arr, int size) {
    for(int i = 0; i<size; i++) {
        std::cout << arr[i] << "; ";
    }
    std::cout << std::endl;
}

int is_sum_zero(int arr[], int len, int x){
    int sum = arr[len-1];
    for (int j = 0; j < len-1; j++) {
        sum += arr[j] * pow(x, len-1-j);
    }
    if (sum == 0) {
        return x;
    }
    else {
        sum = arr[len-1];
        for (int j = 0; j < len-1; j++) {
            sum += arr[j] * pow(-x, len-1-j);
        }
        if (sum == 0) {
            return -x;
        }
    }
    return 0;
}

int get_x(int arr[], int len) {
    for (int i = 1; i < len; i++) {
        int res = is_sum_zero(arr, len, i);
        if (res != 0) {
            return res;
        }
    }
    return 0;
}


void solve_linear_equation(int arr[], int len) {
    display(arr, len);
    double x_arr[len];
    int x_exists=0;
    for (int i = 0; i < len; len--) {
        int x = get_x(arr, len);
        if (x == 0) {
            break;
        }
        x_arr[x_exists] = x; x_exists++;
        int sum = arr[0];
        for (int j = 1; j < len - 1; j++) {
            sum = sum * x + arr[j];
            arr[j] = sum;
        }
        display(arr, len-1);
    }
    double x;
    if (len <= 2) {
        x = -arr[1]/arr[0];
        x_arr[x_exists] = x; x_exists++;
    }
    else if (len == 3) {
        double x_1, x_2, d;
        d = pow(arr[1], 2) - 4 * arr[0] * arr[2];
        d = sqrt(d);
        x_1 = (-arr[1] + d) / (2*arr[0]);
        x_arr[x_exists] = x_1; x_exists++;
        x_2 = (-arr[1] - d) / (2*arr[0]);
        x_arr[x_exists] = x_2; x_exists++;
    }
    else {
        std::cout << "x: can't find x except these - ";
    }
    std::cout << "x: ";
    for (int i = 0; i < x_exists; i++) {
        std::cout << x_arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "x not whole: ";
    for (int i = 0; i < x_exists; i++) {
        if (floor(x_arr[i]) != x_arr[i]) {
            double numerator = 1 / x_arr[i];
            std::cout << 1 << "/" << numerator << " ";
        }
    }
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
            arr[i] = (rand()%10) - 5;
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    else if (option == 'i') {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }
    solve_linear_equation(arr, n);
}

