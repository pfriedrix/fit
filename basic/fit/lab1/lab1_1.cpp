#include <iostream>

using namespace std;

int main(int argc, const char** argv) {

    cout << "Func getchar():" << endl;
    int b = getchar();
    cout << b << endl;

    cout << "Func putchar():" << endl;
    int re_b = putchar(b);
    cout << endl;

    cout << "Func puts():" << endl;
    puts("Hello with func on new line");
    
    cout << "Func printf():" << endl;
    printf("Hello, %s!\n", "Danylo");

    char line[80];
    int n;
    cout << "Func scanf():" << endl;
    scanf("%s %d", line, &n);
    cout << "int: " << n << " char: " << line << endl;


    cout << "Func sprintf():" << endl;
    char str[80];
    sprintf(str, "%s %d %d", "one", 2, 3);
    cout << str << endl;

    cout << "Func sscanf():" << endl;
    char new_line[80];
    int q;
    sscanf("search 1 2 3", "%s%d", new_line, &q);
    cout << "char: " << new_line << " int: " << q << endl;

}
