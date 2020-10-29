#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double ln(double x, double eps){
    if (x <= 0) {
        return NAN;
    }
    eps *= 1000000;
    double count = 1, totalValue = 0, z, powe = 1, y;
    z = (x + 1) / (x - 1);
    double step = ((x - 1) * (x - 1)) / ((x + 1) * (x + 1));
    while (count <= eps)
    {
        z *= step;
        y = (1 / powe)*z;
        totalValue = totalValue + y;
        powe = powe + 2;
        count++;
    }

    return 2*totalValue;

}

void outputSum(double x, double k, double member, double sum) {
    std::cout << std::setw(7) << x << std::setw(12) << k << std::setw(21) << member << std::setw(17) << sum << std::endl;
}


int main()
{
    std::cout << "lab4: calculation exponention function" << std::endl;
    bool flag = true;
    double start, end, step, standart = 0.0, error = 0.0, y = 0.0, eps;
    std::cout << "input start, end, step: ";
    std::cin >> start >> end >> step;
    std::cout << "input precision: ";
    std::cin >> eps;
    std::cout << "===============================================================" << std::endl;
    std::cout << "      x           y             standart            error" << std::endl;
    for (double x = start; x <= end; x += step)
    {
        if (x > 0 && x < 2) {
            y = ln(x, eps) / ln(x - 2, eps);
            standart = log(x) / log(x - 2);
            error = fabs(y - standart);
        } else if (x >= 2 && x <= 4) {
            y = ln(x/2, eps);
            standart = log(x/2);
            error = fabs(y - standart);
        }
        else if (x < 0 || x > 4) flag = false;
        if (flag) outputSum(x, y, standart, error);
        else std::cout << x << "not define" << std::endl;
    }
}



