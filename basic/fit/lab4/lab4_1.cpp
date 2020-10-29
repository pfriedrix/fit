//
//  main.cpp
//  lab4
//
//  Created by Ivan Romancev on 08.10.2020.
//
// unfortunately, 3 formulas apply to different ranges of x
// atan(x) = x - x^3/3 + x^5/5 - ...                                     for -1 < x < 1
// atan(x) =  PI/2 - x^-1 + (3*x^3)^-1 - (5*x^5)^-1 + ... for x > 1
// atan(x) = -PI/2 - x^-1 + ... as above                              for x < -1


#include <iostream>
#include <math.h>
#include <iomanip>

#define PI M_PI

double eps;

double expon(double x)
{
    double a = 0.0;
    double sum = 0.0,
    n = eps * 100000000;

    if( x == 1.0 ) return PI/4.0;
    if( x == -1.0 ) return -PI/4.0;

    if(n > 0)
    {
        if( (x < -1.0) || (x > 1.0) )
        {
            if( x > 1.0 )
                sum = PI/2.0;
            else
                sum = -PI/2.0;
            a = -1.0/x;
            for(int j=1; j<=n; j++)
            {
                sum += a;
                a *= -1.0*(2.0*j-1)/((2.0*j+1)*x*x);
            }
        }
        else
        {
            sum = 0.0;
            a = x;
            for(int j=1; j<=n; j++)
            {
                sum += a;
                a *= -1.0*(2.0*j-1)*x*x/(2.0*j+1);
            }
        }
    }

    return M_PI_2 - sum;
}

void outputSum(double x, double k, double member, double sum) {
    std::cout << std::setw(7) << x << std::setw(12) << k << std::setw(21) << member << std::setw(17) << sum << std::endl;
}


int main(int argc, const char * argv[])
{
    bool quit = false;
    while (!quit) {
        std::cout << "lab4: calculation exponention function" << std::endl;
        double start, end, step, member = 0.0, error = 0.0, y = 0.0;
        std::cout << "input start, end, step: ";
        std::cin >> start >> end >> step;
        std::cout << "input precision: ";
        std::cin >> eps;
        std::cout << "===============================================================" << std::endl;
        std::cout << "      x           y             standart            error" << std::endl;
        for (double x = start; x <= end; x += step)
        {
            bool flag = true;
            if (x > 1) {
                double dec = expon(x), nem = expon(x - 5);
                if (nem != 0) {
                    y = dec / nem;
                    member = (M_PI_2 - atan(x)) / (M_PI_2 - atan(x - 5));
                    error = fabs(member - y);
                }
                else {
                    std::cout << "      Error zero!" << std::endl;
                    continue;
                }
            }
            else if (x >= 0 && x <= 1) {
                y = expon(x) + expon(2 * x);
                member = M_PI_2 - atan(x) + M_PI_2 - atan(2 * x);
                error = fabs(member - y);
            }
            else if (x < 0) flag = false;
            if (flag) outputSum(x, y, member, error);
            else std::cout << x << "          not define" << std::endl;
        }
        std::string input;
        std::cout << "If you want quit print 'q'. To continue print anything: ";

        std::cin >> input;
        if (input == "q")
        {
            quit = true;
        }
    }
    std::cout << "Goodbye!";
}
