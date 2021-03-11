#include <iostream>

using std::cout; using std::cin; using std::string;

bool search(string line, string sample) {
    bool result = false;
    int i = 1;
    while ((i <= line.size() - sample.size() + 1) && !result) {
        if (line.substr(i, sample.size()) == sample) {
            result = true;
        } else i += 1;
    }
    return result;
}

int main() {
    string line = "hello";
    string sample = "lel";
    cout << search(line, sample);
}