#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cout << "Enter number a: " << endl;
    cin >> a;
    cout << "Enter number b: " << endl;
    cin >> b;
    cout << "Enter number c: " << endl;
    cin >> c;
    cout << "Enter number d: " << endl;
    cin >> d;
    double x;
    if (a - c == 0) {
        cout << "Devision on zero is not allowed.";
        return 1;
    }
    x = (d - b) / (a - c);
    cout << "Result: " << x;
}
