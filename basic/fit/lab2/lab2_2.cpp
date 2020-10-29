#include <iostream>
#include <math.h>

using namespace std;

double getPowSum(int a, int b, int c)
{
    return acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b)) * 180 / M_PI;
}

double *getDegrees(int a, int b, int c)
{
    static double degrees[3];

    degrees[0] = getPowSum(a, b, c);
    degrees[1] = getPowSum(b, c, a);
    degrees[2] = getPowSum(a, c, b);
    return degrees;
}

int main()
{
    bool quit = false;
    while (!quit)
    {
        cout << "Enter 3 sides of triange trough space: ";
        int a, b, c;
        cin >> a >> b >> c;

        if (a + b > c && a + c > b && b + c > a)
        {
            if ((pow(a, 2) == pow(b, 2) + pow(c, 2)) || (pow(b, 2) == pow(a, 2) + pow(c, 2)) || (pow(c, 2) == pow(b, 2) + pow(a, 2)))
            {
                cout << "This triangle is right." << endl;
            }
            else
            {
                double *results = getDegrees(a, b, c);
                if (results[0] < 90 && results[1] < 90 && results[2] < 90)
                {
                    cout << "This triangle is acute" << endl;
                }
                else if (results[0] > 90 || results[1] > 90 || results[2] > 90)
                {
                    cout << "This triangle is obtuse" << endl;
                }
            }
        }
        else
        {
            cout << "This triangle doesn't exist." << endl;
        }

        string input;
        cout << "If you want quit print 'q'. To continue print anything: ";

        cin >> input;
        if (input == "q")
        {
            quit = true;
        }
    }
    cout << "Goodbye!" << endl;
}
 
