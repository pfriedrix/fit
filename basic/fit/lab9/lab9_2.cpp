//11.2. Увести з клавіатури фрагмент коду, який містить декілька рядків. Фрагмент містить коментарі, які відкиваються лексемою "/*" і закриваються лексемою "*/" і можуть розміщуватися будь-де в коді. Код містить арифметичний вираз, який складається з дужок, арифметичних операцій "+, -, *, /", та операндів, записаних цифрами. Арифметичнй вираз має починатися з дужки і завершуватися дужкою. Дужки можуть бути вкладеними. В такому випадку кількість правих дужок має відповідти кількості лівих дужок. Інший текст може містити будь-які символи. Перевірити фрагмент коду на синтаксисну коректність.


#include <iostream>
#include <ctype.h>

using std::string;

bool is_operation(const char l) {
    if (!(l == '+' || l == '-' || l == '*' || l == '/')) {
        return false;
    }
    return true;
}

string delete_comments(string &code) {
    bool skip = false;
    int length =  sizeof(code);
    string refactor;
    for (auto l = &code[0]; l != (&code[0] + length+1); ++l) {
        if ((*(l-1) == '/' && *l == '*') || ((*l == '/' && *(l+1) == '*'))) {
            skip = true;
        }
        else if ((*(l-1) == '*' && *l == '/') || ((*l == '*' && *(l+1) == '/'))) {
            skip = false;
        }
        else if (!skip){
            refactor += *l;
        }
    }
    return refactor;
}

bool check_code(string &code) {
    int length = sizeof(code);
    if (code[0] != '(' && !(isdigit(code[0]))) {
        return false;
    }
    int brace_sum = 0;

    for (auto l = &code[0]; l != (&code[0] + length+1); ++l) {
        if (*l == '(') {
            if (isdigit(*(l-1)) || *(l-1) == ')') return false;
            ++brace_sum;
        }
        else if (*l == ')') {
            if (brace_sum - 1 < 0 || *(l+1) == '(') return false;
            --brace_sum;
        }
        else if (is_operation(*l)) {
            if (is_operation(*(l-1)) || *(l+1) == ')') return false;
        }
        else if (isdigit(*l)) {
            continue;
        }
        else if (*l == '\0') return true;
        else {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "Input code here: " << std::endl;
    string code;
    std::getline(std::cin, code);
    code = delete_comments(code);
    if (check_code(code)) {
        std::cout << "Code is clear" << std::endl;
    }
    else {
        std::cout << "WRONG! Please check your code!" << std::endl;
    }
}
