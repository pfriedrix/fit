#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
using namespace std;

ifstream start;
ofstream fout;

char curr_str[100];

void input()
{

    cout << "Task 1 and Bilet 22: Lucenko Andrew IPZ-12" << endl;
    ofstream file("input.txt");
    cout << "Enter length of line: ";
    int n;
    cin >> n;
    const int length = 9999;
    cin.clear();
    cin.ignore(1);
    cout << "Enter number of lines: ";
    cin >> n;
    cin.clear();
    cin.ignore(1);
    const int lines = n;
    char line[length];
    for (int i = 0; i < lines; i++) {
        cin.getline(line, length);
        file << line << endl;
    }
    file.close();
}
void output()
{
    system("cls");
    start.open("input.txt", ios::in);
    cout << "Your file contents: " << endl;

    while (start.getline(curr_str, 100)) {
        cout << curr_str << endl;
    }

    start.close();

    cout << "\nPress any key to return to the menu" << endl;
    _getch();
}

void delete_words()
{
    system("cls");
    int length;
    cout << "Input size of word: ";
    cin >> length;
    start.open("input.txt", ios::in);
    fout.open("output.txt", ios::out);
    int deleted_words = 0;
    while (start.getline(curr_str, 100))
    {
        char* pch = strtok(curr_str, " ");
        while (pch != NULL)
        {
            if (strlen(pch) > length)
            {
                fout << pch << ' ';
            }
            else {
                deleted_words++;
            }
            pch = strtok(NULL, " ");
        }
        fout << '\n';
    }
    fout << "Number of deleted words: " << deleted_words;

    start.close();
    fout.close();

    remove("input.txt");
    rename("output.txt", "input.txt");
}
int main()
{
    input();
    output();
    delete_words();
}
