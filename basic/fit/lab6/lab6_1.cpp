#include <iostream>
#include <cmath>
using namespace std;

float eps = 0.0001;
double F(float *x)
{
     return tan(*x) + 2;
}

void brute_force(float* start, float* y) {
    float ymin=fabs(F(start));
    for ( float x = *start; x <= *y; x += eps )
    {
        float temp = fabs(F(&x));
        if (ymin>temp )
        {
             ymin=temp;
             *start=x;
        }
    }
    cout << "метод перебора - x = " << *start << endl;
}

void chord(float* start, float* y) {
    float next = 0, tmp;
    do {
        tmp = next;
        next = *y - F(&(*y)) * (*start - *y) / (F(&(*start)) - F(&(*y)));
        *start = *y;
        *y = tmp;
    } while (abs(next - *y) > eps);
    cout << "метод хорды - x = " << next << endl;
}

int main()
{
    float start, y;
    cout << "Input x and y: ";
    cin >> start >> y;
    float* pr = &start;
    float* pl = &y;
    brute_force(pr, pl);
    float* prd = &start;
    float* pld = &y;
    chord(prd, pld);
}
