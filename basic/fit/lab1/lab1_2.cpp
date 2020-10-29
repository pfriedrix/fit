#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int A, B, C, D;

    cout << "Enter number A: " << endl;
    cin >> A;
    cout << "Enter number B: " << endl;
    cin >> B;
    cout << "Enter number C: " << endl;
    cin >> C;
    cout << "Enter number D: " << endl;
    cin >> D;

    double x;
    x = pow(sin(A), 3) * pow(cos(B), 2) / (pow(exp(1), C) + 1 + sin(D));
    cout << "Result: " << x << endl;
}
