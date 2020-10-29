//
//  main.cpp
//  lab5
//
//  Created by Ivan Romancev on 14.10.2020.
//

#include <iostream>

unsigned long long int iter_fib(int n) {
    if (n < 2)
            return n;
        unsigned long long int mask = 1, m = n;
        while (m > 1) {
            m >>= 1;
            mask <<= 1;
        }
        unsigned long long int fn = 1, fn1 = 1, gn, gn1;
        while (mask > 1) {
            mask >>= 1;
            gn = fn;
            gn1 = fn1;
            if (n & mask) {
                fn = gn1 * gn1 + gn * gn;
                fn1 = gn1 * gn1 + 2 * gn * gn1;
            } else {
                fn = 2 * gn * gn1 - gn * gn;
                fn1 = gn1 * gn1 + gn * gn;
            }
        }
    return fn;
}

int main(int argc, const char * argv[]) {
    bool quit = false;
    while (!quit) {
        int m, n;
        std::cout << "Input m and n: ";
        std::cin >> m >> n;
        if (m < n) {
            std::cout << "Int m should be more than int n" << std::endl;
        }
        else {
            unsigned long long int res;
            for (int i = 0; i < m; i++) std::cout << iter_fib(i) << " ";
            std::cout << std::endl;
            auto t1 = std::chrono::high_resolution_clock::now();
            res = iter_fib(n);
            auto t2 = std::chrono::high_resolution_clock::now();
            std::cout << res << std::endl;
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();
            std::cout << "duration of iterative: " << duration << "ms" << std::endl;
            
        }
        std::string input;
        std::cout << "If you want quit print 'q'. To continue print anything: ";

        std::cin >> input;
        if (input == "q")
        {
            quit = true;
        }
    }
    std::cout << "Goodbye!" << std::endl;
}
