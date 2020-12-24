#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void clear_char(char str[], int length) {
    for (int i = 0; i < length; i++) {
        str[i] = 0;
    }
}

int main()
{
    const int length = 1000;
    string str;
    cin >> str;
    string num;
    int nums[length];
    int numbs = 0;
    int inserted = 0;
    for ( int i = 0; i < length; i++) {
        if (isdigit(str[i])) {
            num += str[i];
            inserted++;
        }
        else {
            if (num.empty()) {
                continue;
            }
            else {
                nums[numbs] = atoi(num.c_str());
                numbs++;
                num.clear();
            }
        }
    }
    for (int i = 0; i < numbs-2; i++) {
        cout << nums[i] << " ";
    }
}

