#include <iostream>
#include <math.h>
using namespace std;
double Function(int n) // функція обрахування через рекурсію
{
  if (n == 1 || n == 2) {
    return 0;
  }
  else if (n == 3) {
    return 1;
  }
  else if (n % 2 == 0){
      cout << n << endl;
      return 2 * Function(n / 2);
  }
  else {
      cout << n << endl;
      return Function(n / 2) + Function(n / 2 + 1);
  }
      
}

//Головна функція
int main()
{
  char key = ' ';
  while (key != 'f') {
    int n, r;
    cout << "IPZ-12/2 Davydenko Vladyslav. Laboratorna robota 5.1" << endl;
    cout << "Calculate the number of abilities that can form groups of scouts " << endl;
    cout << "Number of soldiers n: ";
    cin >> n;
      r = Function(n);
      
    cout << "Result= " << r << endl;
    cout << "Press f to exit or any key to continue program" << endl;
      cin >> key;
  }
}
