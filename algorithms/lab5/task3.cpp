#include<iostream>
#include<map>
#include <utility>


using namespace std;

bool getAI(int *a, int len, int &n, int int_) {
    int maxi = a[0];
    int position = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 7 == 0 && a[i] >= maxi) maxi = a[i], position = i;
    }

    if (position == 0 && a[0] % 7 != 0) return false;


    if (n == len) return false;

    for (int i = n - 1; i > position; --i) {
        a[i] = a[i - 1];
    }
    a[position] = int_;

    return true;
}

class University {
public:
    std::string town;
    std::string title;
    int count;
    std::map<std::string, int> faculties;

    University() {

    }

    University(std::string town, std::string title, int count) : town(std::move(town)), title(std::move(title)),
                                                                 count(count) {}

    bool compareIsBigger(University *instance) {
        int sum = 0;
        int sum2 = 0;
        for (const auto&[key, value] : faculties) {
            sum += value;
        }

        for (const auto&[key, value] : instance->faculties) {
            sum += value;
        }
        if (sum > sum2) {
            return true;
        }
        return false;
    }

    void addFaculty(std::string faculty, int students) {
        faculties[faculty] = students;
    }

    void display() {
        cout << town << " " << title;
    }
};


int main() {
//    int a[6] = {1, 2, 3, 7, 5};
//    int b = 5;
//    cout << getAI(a, 6, b, 4);
//
//
//    return 0;
}

