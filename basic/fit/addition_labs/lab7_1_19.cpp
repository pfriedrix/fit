#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <math.h>
#include <malloc.h>
#include <ctime>
#include <windows.h>

using namespace std;

void SetColor(int text, int bg) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

int EnterInt(string message) {
    while (true) {
        cout << message << endl;
        int size;
        cin >> size;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Error, wrong input. Try again" << endl;
            system("pause");
            system("cls");
        }
        else{
            return size;
        }

    }
}


int main()
{
    string message;
    message = "Enter size of your matrix:";
    int size, choice;
    do {
        size = EnterInt(message);
        if (size < 4) {
            cout << "Error, wrong input. Try again" << endl;
            system("pause");
            system("cls");
        }
    } while (size < 4);

    int** Matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        Matrix[i] = (int*)malloc(size * sizeof(int));
    }
      
    message = "\nHow do u want to generate matrix:\n 1)Random\n 2)Custom\n";
    do {
        choice = EnterInt(message);
        if (choice > 2 || choice < 1) {
            cout << "Error, wrong input. Try again" << endl;
            system("pause");
            system("cls");
        }
    } while (choice > 2 || choice < 1);

    message = "\n";
    srand(time(0));

    if (choice == 1) {
        cout << endl << endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int a = rand() % 2;
                Matrix[i][j] = pow(-1, a) * (rand() % 100);
            }
        }
       
    }
    if (choice == 2) {
        cout << endl << endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                while (true) {
                    cout << "Matrix[" << i << "][" << j << "] = ";
                    cin >> Matrix[i][j];
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(32767, '\n');
                        cout << "Error, wrong input. Try again" << endl;
                        system("pause");
                        system("cls");
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
    cout << endl << endl << "---------Task---------" << endl << endl;
    int sum = 0, a = 0, b = 2, max;
    max = Matrix[a][b];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((i <= j) && (i >= size - j - 1)) {
                sum += Matrix[i][j];
                if (Matrix[i][j] >= max) {
                    a = i;
                    b = j;
                    max = Matrix[i][j];
                }
            }
        }
    }

    for (int i = 0; i < size; i++) {
        
           for (int j = 0; j < size; j++) {
               if ((i<=j) && (i >= size - j - 1)) {
                   SetColor(2, 0);
                   if (i == a && j == b) {
                       SetColor(1, 0);
                   }
               }
               else {
                   SetColor(4, 0);
               }
               cout << setw(4) << Matrix[i][j] << " ";
           }
           cout << endl;
       }
    SetColor(5, 0);
    cout << endl << "Sum:" << sum << endl;
    cout << "Max el: " << max << " i: " << a << " j: "<< b;
    SetColor(7, 0);
}
