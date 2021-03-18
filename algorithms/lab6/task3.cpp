#include <iostream>

using std::cout; using std::cin; using std::string;

bool search(string line, string sample) {
    bool result = false;
    int i = 0;
    while ((i <= line.size() - sample.size() + 1) && !result) {
        cout << line.substr(i, sample.size()) << "\n";
        if (line.substr(i, sample.size()) == sample) {
            result = true;
        } else i += 1;
    }
    return result;
}

int main() {
    string line = "Lorem Ipsum is simply dummy text.";
    string sample = "l";
    cout << line << " ==? " << sample << std::endl;
    bool res = search(line, sample);
    if (res) cout << "Found" << std::endl;
    else cout << "Not found" << std::endl;
}