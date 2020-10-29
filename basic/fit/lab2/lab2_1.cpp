#include <iostream>
using namespace std;
int main() {
    bool quit = false;
    while (!quit)
    {
        double a, b;
        cout << "Enter a and b: " << endl;
        cin >> a >> b;
        if (a <= 1) cout << "Result: " << min(a, b) << endl;
        else if (1 < a && a < 5) cout << "Result: " << max(a, b) << endl;
        else if (b == 0) cout << "b can't be 0." << endl;
        else if (b != 0 && a > 5) cout << "Result: " << a / b << endl;
        else cout << "Out of memory" << endl;
        string input;
        cout << "If you want quit print 'q'. To continue print anything else: ";
        cin >> input;
        if (input == "q") {
            quit = true;
            
        }
    }
    cout << "Goodbye!";
}
