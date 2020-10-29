//
//  lab4_2.cpp
//  lab4
//
//  Created by Ivan Romancev on 12.10.2020.
//

#include <iostream>
#include <math.h>

double excellent_number(int p) {
    return pow(2, p - 1) * (pow(2, p) - 1);
}

int main() {
    bool quit = false;
    while (!quit) {
        
        int n;
        double sum;
        
        std::cout << "Input n: ";
        std::cin >> n;
    
        for (int i = 2; i <= n; ++i) {
            sum = excellent_number(i);
            if (sum > n) {
                break;
            }
            std::cout << sum << std::endl;
        }
        std::cout << "Programm is finished" << std::endl;
        
        std::string input;
        std::cout << "If you want quit print 'q'. To continue print anything: ";

        std::cin >> input;
        if (input == "q")
        {
            quit = true;
        }
    }
}
