
#include <iostream>

int counter_rec(int a, int b) {
    if (b == 1) {
        return a;
    }
    else if (a == 1) {
        return b;
    }
    else if (a == 0 || b == 0) {
        return 0;
    }
    else {
        return a + counter_rec(a, b - 1);
    }
}

int counter_iter(int a, int b) {
    if (b == 1) {
        return a;
    }
    else if (a == 1) {
        return b;
    }
    else if (a == 0 || b == 0) {
        return 0;
    }
    else {
        int sum = a * 2;
        for (int i = 2; i < b; i++) {
            sum += a;
        }
        return sum;
    }
}

int main() {
    int a, b;
    std::cout << "Input a and b: ";
    std::cin >> a >> b;
    if (a < 0 || b < 0) {
        std::cout << "not define with these numbers" << std::endl;
        return 0;
    }
    std::cout << "recursive: " << counter_rec(a, b) << std::endl;
    std::cout << "number entries of recursive is: " << b << std::endl;
    std::cout << "iterative: " << counter_iter(a, b) << std::endl;
    std::cout << "number iterations of iterative is: " << b << std::endl;
}
