//Послідовність 1,1,2,3,5,8, ... складається з чисел Фібоначчі. Кожен елемент, починаючи з третього, дорівнює сумі двох попередніх. Рекурентне співвідношення для розрахунку чисел Фібоначчі таке:
//.
//Ввести з клавіатури два натуральних числа m та n, які означають кількість чисел та номер числа в послідовності Фібоначчі. Вивести послідовність чисел Фібоначчі в кількості m елементів та значення n--го числа. Передбачити випадок m < n. Реалізувати рекурсивний та ітеративний варіанти розв'язку задачі, використовуючи рекурсію та оператор циклу. Порівняти ефективність рекурсивної та ітеративної реалізацій, визначивши глибину рекурсії та кількість ітерацій циклу.

#include <iostream>


int fibonacci(int f) {
    if (f == 0) return 0;
    if (f == 1) return 1;
    return fibonacci(f-1) + fibonacci(f-2);
}

void rec_fib(int n, int m) {
    unsigned long long int res;
    for (int count = 0; count < m; ++count) std::cout << fibonacci(count) << " ";
    std::cout << std::endl;
    auto t1 = std::chrono::high_resolution_clock::now();
    res = fibonacci(n);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << res << std::endl;
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();
    std::cout << "duration of recursive: " << duration << "ms" << std::endl;
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
            rec_fib(n, m);
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
