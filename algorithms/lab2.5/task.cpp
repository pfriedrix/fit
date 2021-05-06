

#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <time.h>

using namespace std;

FILE *f, *f1, *f2, *f3;

void ExternalMerge() {
    string line;
    cout << "Your array: ";
    ifstream main("main.txt");
    if (main.is_open()) {
        while (!main.eof()) {
            getline(main, line);
            cout << line << endl;
        }
        main.close();
    }
    int a1, a2, k, i, j, kol, tmp;
    kol = 0;
    if ((f = fopen("main.txt", "r")) == NULL)
        printf("\nInvalid name for file . .");
    else {
        while (!feof(f)) {
            fscanf(f, "%d", &a1);
            kol++;
        }
        fclose(f);
    }
    k = 1;
    while (k < kol) {
        f = fopen("main.txt", "r");
        f1 = fopen("fileA.txt", "w");
        f2 = fopen("fileB.txt", "w");
        if (!feof(f)) {
            fscanf(f, "%d", &a1);
        }
        while (!feof(f)) {
            for (i = 0; i < k && !feof(f); i++) {
                fprintf(f1, "%d ", a1);
                fscanf(f, "%d", &a1);
            }
            for (j = 0; j < k && !feof(f); j++) {
                fprintf(f2, "%d ", a1);
                fscanf(f, "%d", &a1);
            }
        }

        fclose(f2);
        fclose(f1);
        fclose(f);

        ifstream file1("fileA.txt");
        cout << "Temp fileA: ";
        if (file1.is_open()) {
            while (!file1.eof()) {
                getline(file1, line);
                cout << line << endl;
            }
            file1.close();
        }
        cout << "Temp fileB: ";
        ifstream file2("fileB.txt");
        if (file2.is_open()) {
            while (!file2.eof()) {
                getline(file2, line);
                cout << line << endl;
            }
            file2.close();
        }


        f = fopen("main.txt", "w");
        f1 = fopen("fileA.txt", "r");
        f2 = fopen("fileB.txt", "r");
        if (!feof(f1)) fscanf(f1, "%d", &a1);
        if (!feof(f2)) fscanf(f2, "%d", &a2);
        while (!feof(f1) && !feof(f2)) {
            i = 0;
            j = 0;
            while (i < k && j < k && !feof(f1) && !feof(f2)) {
                if (a1 < a2) {
                    fprintf(f, "%d ", a1);
                    fscanf(f1, "%d", &a1);
                    i++;
                } else {
                    fprintf(f, "%d ", a2);
                    fscanf(f2, "%d", &a2);
                    j++;
                }
            }
            while (i < k && !feof(f1)) {
                fprintf(f, "%d ", a1);
                fscanf(f1, "%d", &a1);
                i++;
            }
            while (j < k && !feof(f2)) {
                fprintf(f, "%d ", a2);
                fscanf(f2, "%d", &a2);
                j++;
            }
        }
        while (!feof(f1)) {
            fprintf(f, "%d ", a1);
            fscanf(f1, "%d", &a1);
        }
        while (!feof(f2)) {
            fprintf(f, "%d ", a2);
            fscanf(f2, "%d", &a2);
        }
        fclose(f2);
        fclose(f1);
        fclose(f);
        k *= 2;
    }
    remove("fileA.txt");
    remove("fileB.txt");
}

void ExternalNaturalMerge() {
    int a1, a2, a3, a4;
    string line;
    cout << "Your array: ";
    ifstream main("main.txt");
    if (main.is_open()) {
        while (!main.eof()) {
            getline(main, line);
            cout << line << endl;
        }
        main.close();
    }

    while (true) {

        int indexFirst = 0;
        int indexSecond = 0;

        bool isInsertInFirst = true;

        f = fopen("main.txt", "r");
        f1 = fopen("fileA.txt", "w");
        f2 = fopen("fileB.txt", "w");

        if (!feof(f)) fscanf(f, "%d", &a1);
        while (!feof(f)) {
            if (indexFirst == 0 && indexSecond == 0) {
                a2 = a1;
                fprintf(f1, "%d ", a1);
                fscanf(f, "%d", &a1);
                indexFirst++;
            } else {
                if (a1 < a2) isInsertInFirst = !isInsertInFirst;
                a2 = a1;
                if (isInsertInFirst) {
                    fprintf(f1, "%d ", a1);
                    fscanf(f, "%d", &a1);
                    indexFirst++;
                } else {
                    fprintf(f2, "%d ", a1);
                    fscanf(f, "%d", &a1);
                    indexSecond++;
                }
            }
        }
        fclose(f);
        fclose(f1);
        fclose(f2);

        ifstream file1("fileA.txt");
        cout << "Temp fileA: ";
        if (file1.is_open()) {
            while (!file1.eof()) {
                getline(file1, line);
                cout << line << endl;
            }
            file1.close();
        }
        cout << "Temp fileB: ";
        ifstream file2("fileB.txt");
        if (file2.is_open()) {
            while (!file2.eof()) {
                getline(file2, line);
                cout << line << endl;
            }
            file2.close();
        }

        if (indexFirst == 0 || indexSecond == 0)
            break;

        f = fopen("main.txt", "w");
        f1 = fopen("fileA.txt", "r");
        f2 = fopen("fileB.txt", "r");

        if (!feof(f1)) fscanf(f1, "%d", &a1);
        if (!feof(f2)) fscanf(f2, "%d", &a2);
        while (!feof(f1) && !feof(f2)) {
            int i = 0;
            int j = 0;
            while (i < indexFirst && j < indexSecond && !feof(f1) && !feof(f2)) {
                if (a1 < a2) {
                    fprintf(f, "%d ", a1);
                    fscanf(f1, "%d", &a1);
                    i++;
                } else {
                    fprintf(f, "%d ", a2);
                    fscanf(f2, "%d", &a2);
                    j++;
                }
            }
            while (i < indexFirst && !feof(f1)) {
                fprintf(f, "%d ", a1);
                fscanf(f1, "%d", &a1);
                i++;
            }
            while (j < indexSecond && !feof(f2)) {
                fprintf(f, "%d ", a2);
                fscanf(f2, "%d", &a2);
                j++;
            }
        }
        fclose(f);
        fclose(f1);
        fclose(f2);
    }
    remove("fileA.txt");
    remove("fileB.txt");
}

void MultiPathSorting() {
    string line;
    cout << "Your array: ";
    ifstream main("main.txt");
    if (main.is_open()) {
        while (!main.eof()) {
            getline(main, line);
            cout << line << endl;
        }
        main.close();
    }

    while (true) {
        int a1, a2, a3;
        int fInd = 0;
        int sInd = 0;
        int tInd = 0;

        int row = 1;

        f = fopen("main.txt", "r");
        f1 = fopen("fileA.txt", "w");
        f2 = fopen("fileB.txt", "w");
        f3 = fopen("fileC.txt", "w");

        if (!feof(f)) fscanf(f, "%d", &a1);
        while (!feof(f)) {
            if (fInd == 0 && sInd == 0 && tInd == 0) {
                a2 = a1;
                {
                    fprintf(f1, "%d ", a1);
                    fscanf(f, "%d", &a1);
                    fInd++;
                }
            } else {
                if (a1 < a2) {
                    switch (row) {
                        case 1:
                            row = 2;
                            break;
                        case 2:
                            row = 3;
                            break;
                        case 3:
                            row = 1;
                            break;
                    }
                }
                a2 = a1;
                switch (row) {
                    case 1:
                        fprintf(f1, "%d ", a1);
                        fscanf(f, "%d", &a1);
                        fInd++;
                        break;
                    case 2:
                        fprintf(f2, "%d ", a1);
                        fscanf(f, "%d", &a1);
                        sInd++;
                        break;
                    case 3:
                        fprintf(f3, "%d ", a1);
                        fscanf(f, "%d", &a1);
                        tInd++;
                        break;
                }
            }
        }
        fclose(f);
        fclose(f1);
        fclose(f2);
        fclose(f3);

        if (fInd == 0 && sInd == 0 || fInd == 0 && tInd == 0 || sInd == 0 && tInd == 0)
            break;

        ifstream file1("fileA.txt");
        cout << "Temp fileA: ";
        if (file1.is_open()) {
            while (!file1.eof()) {
                getline(file1, line);
                cout << line << endl;
            }
            file1.close();
        }
        cout << "Temp fileB: ";
        ifstream file2("fileB.txt");
        if (file2.is_open()) {
            while (!file2.eof()) {
                getline(file2, line);
                cout << line << endl;
            }
            file2.close();
        }
        cout << "Temp fileC: ";
        ifstream file3("fileC.txt");
        if (file3.is_open()) {
            while (!file3.eof()) {
                getline(file3, line);
                cout << line << endl;
            }
            file3.close();
        }

        f = fopen("main.txt", "w");
        f1 = fopen("fileA.txt", "r");
        f2 = fopen("fileB.txt", "r");
        f3 = fopen("fileC.txt", "r");

        if (!feof(f1)) fscanf(f1, "%d", &a1);
        if (!feof(f2)) fscanf(f2, "%d", &a2);
        if (!feof(f3)) fscanf(f3, "%d", &a3);
        while (!feof(f1) && !feof(f2) && !feof(f3)) {
            int i = 0;
            int j = 0;
            int k = 0;
            while (i < fInd && j < sInd && k < tInd
                   && !feof(f1) && !feof(f2) && !feof(f3)) {
                if (a1 < a2) {
                    if (a1 < a3) {
                        fprintf(f, "%d ", a1);
                        fscanf(f1, "%d", &a1);
                        i++;
                    } else {
                        fprintf(f, "%d ", a3);
                        fscanf(f3, "%d", &a3);
                        k++;
                    }
                } else {
                    if (a2 < a3) {
                        fprintf(f, "%d ", a2);
                        fscanf(f2, "%d", &a2);
                        j++;
                    } else {
                        fprintf(f, "%d ", a3);
                        fscanf(f3, "%d", &a3);
                        k++;
                    }
                }
            }

            while (i < fInd && j < sInd && !feof(f1) && !feof(f2)) {
                if (a1 < a2) {
                    fprintf(f, "%d ", a1);
                    fscanf(f1, "%d", &a1);
                    i++;
                } else {
                    fprintf(f, "%d ", a2);
                    fscanf(f2, "%d", &a2);
                    j++;
                }
            }

            while (i < fInd && k < tInd && !feof(f1) && !feof(f3)) {
                if (a1 < a3) {
                    fprintf(f, "%d ", a1);
                    fscanf(f1, "%d", &a1);
                    i++;
                } else {
                    fprintf(f, "%d ", a3);
                    fscanf(f3, "%d", &a3);
                    k++;
                }
            }

            while (k < tInd && j < sInd && !feof(f3) && !feof(f2)) {
                if (a3 < a3) {
                    fprintf(f, "%d ", a3);
                    fscanf(f3, "%d", &a3);
                    k++;
                } else {
                    fprintf(f, "%d ", a2);
                    fscanf(f2, "%d", &a2);
                    j++;
                }
            }

            while (i < fInd && !feof(f1)) {
                fprintf(f, "%d ", a1);
                fscanf(f1, "%d", &a1);
                i++;
            }
            while (j < sInd && !feof(f2)) {
                fprintf(f, "%d ", a2);
                fscanf(f2, "%d", &a2);
                j++;
            }
            while (k < tInd && !feof(f3)) {
                fprintf(f, "%d ", a3);
                fscanf(f3, "%d", &a3);
                k++;
            }
        }
        fclose(f);
        fclose(f1);
        fclose(f2);
        fclose(f3);
    }
    remove("fileA.txt");
    remove("fileB.txt");
    remove("fileC.txt");
}

int main() {
    srand(time(NULL));

    cout << "Do you want to enter value in file randomly or by yourself?(1/2)" << endl;
    cout << "or press any key to leave. . ." << endl;
    int answer;
    cin >> answer;
    vector<int> values;
    switch (answer) {
        case 1: {
            cout << "Enter the count of values to generate: ";
            int size;
            cin >> size;
            for (int i = 0; i < size; i++) {
                values.push_back(rand() % 100);
            }
            break;
        }
        case 2: {
            char answ = ' ';
            while (answ != 'y') {
                int value;
                cout << "Enter the value to add in your array: ";
                cin >> value;
                values.push_back(value);
                cout << value << " were successfully added to your file" << endl;
                cout << "do you want to stop process of adding values?(y/n)" << endl;
                cin >> answ;
            }
            break;
        }
        default:
            exit(0);
    }
    cout << "array: ";
    for (int i = 0; i < values.size(); i++) {
        cout << values[i] << " ";
    }
    cout << ", were successfully added to file 'main.txt'." << endl;
    ofstream stream;
    stream.open("main.txt");
    for (int i = 0; i < values.size(); i++) {
        stream << values[i] << " ";
    }
    stream.close();
    cout << "[1]" << "   -->   " << "to process the algorithm for external merge sorting." << endl;
    cout << "[2]" << "   -->   " << "to process the external sorting algorithm by natural fusion." << endl;
    cout << "[3]" << "   -->   " << "to process the algorithm for external sorting by multi - path merging." << endl;
    cout << "or press any key to leave. . ." << endl;
    int key;
    cin >> key;
    switch (key) {
        case 1: {
            ExternalMerge();
            break;
        }
        case 2: {
            ExternalNaturalMerge();
            break;
        }
        case 3: {
            MultiPathSorting();
            break;
        }
        default:
            exit(0);
    }
}

