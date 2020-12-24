//
//  main.cpp
//  lab8
//
//  Created by Ivan Romancev on 21.11.2020.
//

#include <iostream>
#include <math.h>

double fx(int x) {
    return 2 * x - cos(x);
}

double fx_derivative(int x) {
    return 2 + sin(x);
} 

double fx_second_derivation(int x) {
    return cos(x);
}

void displayMenu() {
    using std::cout;
    using std::endl;
    cout << "Menu: " << endl;
    cout << "1) Input a and b for f(x) = 0" << endl;
    cout << "2) Solve 2x - cosx = 0 by tangent method" << endl;
    cout << "3) Solve 2x - cosx = 0 by method of half division" << endl;
    cout << "4) Check answer" << endl;
    cout << "5) Compare two method and find error" << endl;
}

void set_distance(double &a, double &b) {
    while (true) {
        std::cout << "Enter distance for f(x) (a and b): ";
        std::cin >> a >> b;
        if (a > b) {
            std::cout << "b should be more than a" << std::endl;
        }
        else {
            break;
        }
    }
}

double solve_by_tangent_method(int a, int b, double eps) {
    double x;
    std::cin >> x;
    double h = fx(x) / fx_derivative(x);
    do {
        h = fx(x) / fx_derivative(x);
        x = x - h;
    } while (abs(h) > eps);
    return x;
}

double solve_by_half_division(int a, int b, double eps) {
    double x = 0.0;
    
    while (abs(a - b) >= eps) {
        x = (a + b) / 2;
        if ((fx(a) * fx(x)) <= 0) {
            b = x;
        }
        else {
            a = x;
        }
    }
    return x;
}

int main(int argc, const char * argv[]) {
    displayMenu();
    double eps = 0.000001, tangement_method, half_div;
    double a = 0, b = 0;
    int option;
    while (true) {
        std::cout << "Choose number from menu: ";
        std::cin >> option;
        switch (option) {
            case 1:
                set_distance(a, b);
                break;
            case 2:
                if (a != 0 && b != 0) {
                    tangement_method = solve_by_tangent_method(a, b, eps);
                }
                else {
                    std::cout << "Firstly, input distance" << std::endl;
                }
                break;
            case 3:
                half_div = solve_by_half_division(a, b, eps);
                std::cout << half_div << std::endl;
            default:
                break;
        }
    }
}
