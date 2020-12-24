//
//  main.cpp
//  lab9
//
//  Created by Ivan Romancev on 27.11.2020.
//

#include <iostream>
#include <string.h>
#include <map>

void displayMenu() {
    using std::cout;
    using std::endl;
    cout << "Menu: " << endl;
    cout << "1) Count how manu words in line" << endl;
    cout << "2) Search which word is the most often" << endl;
    cout << "3) Correct line" << endl;
}

int count_words(std::string line) {
    int counter = 0;
    char prev = line[0];
    for (char &l : line) {
        if ((l == ',' || l == '.' || l == ' ') && (prev != ' ' && prev != ',' && prev != '.')) {
            counter += 1;
        }
        prev = l;
    }
    return counter+1;
}
std::string popular_word(std::string line) {
    std::string new_line;
    for (char &l : line) {
        if (!(l == ',' || l == '.' || l == ' ')) {
            new_line += l;
        }
        else {
            new_line += " ";
        }
    }
    
    std::map<std::string, int> words;
    std::string word;
    for (char &l : new_line) {
        if (!(l == ',' || l == '.' || l == ' ')) {
            word += l;
        }
        else {
            if (word != " ") {
                words[word] += 1;
                word.clear();
            }
        }
    }
    
    std::map<int, std::string> r_words;
    for (auto word : words) r_words[word.second] = word.first;
    int max_times = 0;
    for (auto word : r_words) if (word.first > max_times) max_times = word.first;
    return r_words[max_times];
}

void correct_line(std::string &line) {
    char prev = line[0];
    for (char &l : line) {
        if (prev == '.') {
            l = toupper(l);
        }
        prev = l;
    }
}


int main(int argc, const char * argv[]) {
    std::cout << "Enter line: ";
    std::string line;
    std::getline(std::cin, line);
    displayMenu();
    while (true) {
        std::cout << "Choose number for menu: ";
        int option;
        std::cin >> option;
        switch (option) {
            case 1:
                std::cout << "Words: " << count_words(line) << std::endl;
                break;
               
            case 2:
                std::cout << "The most popular: " << popular_word(line) << std::endl;
                break;
            
            case 3:
                correct_line(line);
                std::cout << line << std::endl;
                break;
                
            default:
                break;
        }
    }
}
