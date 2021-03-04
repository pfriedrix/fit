#include "stdafx.h"

using std::cout;

class String {
public:
    String() {
        str = nullptr;
    }
    String(char *str) {
        int length = strlen(str);
        this->str = new char[length + 1];
        for (int i = 0; i < length; i++) {
            this->str[i] = str[i];
        }
        this->str[length] = '\0';
    }
    ~String() {
        delete[] this->str;
    }

    String& operator = (const String &other) {
        if (this->str != nullptr) {
            delete[] str;
        }
        int length = strlen(other.str);
        this->str = new char[length + 1];
        for (int i = 0; i < length; i++) {
            this->str[i] = other.str[i];
        }
        this->str[length] = '\0';
        return *this;
    }

    String operator + (const String &other) {
        String newStr;
        newStr.str = new char[strlen(this->str) + strlen(other.str) + 1];
        int i;
        for (i = 0; i < strlen(this->str); i++) {
            newStr.str[i] = this->str[i];
        }
        for (int j = 0; j < strlen(other.str); j++, i++) {
            newStr.str[i] = other.str[j];
        }
        newStr.str[strlen(this->str) + strlen(other.str)] = '\0';
        return newStr;
    }

    void Print() {
        cout << str << "\n";
    }

private:
    char *str{};

};


int main() {
    String str;
    str = "=8998";
    String str2;
    str2 = " 898997";
    String h = str + str2;
    h.Print();


    return 0;
}
