//11.1. Створити два текстових файли. Рядки першого файлу містять назву товару та його ціну. Рядки другого файлу містять назву товару та значення кількості кожного товару. Створити третій текстовий файл, кожний рядок якого має містить назву товару, його кількість та ціну. У третьому файлі рядки повинні містити назви тих товарів, що не повторюються.


#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <sstream>
#include <set>

using std::string;
using std::set;

std::vector<string> split(string source, char delimeter) {
    std::vector<string> arr;
    std::istringstream is(source);
    string line;
    while (std::getline(is, line, delimeter)) arr.push_back(line);
    return arr;
}

void worker(std::ifstream &phones, std::ofstream &complete) {
    string line;
    string line_2;
    string complete_line;
    int counter_line = 0;
    
    while (std::getline(phones, line)) {
        counter_line++;
        std::vector<string> model = split(line, ',');
        complete_line = model[0];
        std::ifstream phones_count("/Users/dnl-krsvch/Documents/Projects/FIT/basic/fit/lab11/phones_with_count_product.csv");
        while (std::getline(phones_count, line_2)) {
            if (line_2.substr(0, line_2.find(",")) == model[0]) {
                complete_line += "," + split(line, ',')[1] + "," + split(line_2, ',')[1];
                complete << complete_line << std::endl;
                break;
            }
        }
        std::cout << complete_line << std::endl;
        phones_count.close();
    }
    phones.close();
    complete.close();
}

int main()
{

    std::ifstream phones("/Users/dnl-krsvch/Documents/Projects/FIT/basic/fit/lab11/phones.csv");
    std::ofstream complete("/Users/dnl-krsvch/Documents/Projects/FIT/basic/fit/lab11/complete.csv");
    
    if (phones.is_open())
    {
        worker(phones, complete);
    }
    else std::cout << "Unable to open file";
}
        
