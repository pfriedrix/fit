//
// Created by Ivan Romancev on 17.03.2021.
//
#include <iostream>


void computePrefix(char line[], int length, int arr[]) {
    arr[0] = 0;
    int i = 1, j = 0;
    while (i < length) {
        if (line[i] != line[j]) {
            if (j == 0) {
                arr[i] = 0;
                i++;
            } else {
                j = arr[j - 1];
            }
        } else {
            arr[i] = j + 1;
            i++;
            j++;
        }
    }
}


void search(char line[], char searched[], const int arr[]) {
    int k = 0, l = 0;
    while (k < strlen(line)) {
        if (line[k] == searched[l]) {
            k++;
            l++;
            if (l == strlen(searched) - 1) {
                std::cout << k - l << " ";
                l = arr[l - 1];
            }
        } else if (line[k] != searched[l] && l != 0) {
            l = arr[l - 1];
        } else if (line[k] != searched[l] && l == 0) {
            k++;
            if (k == strlen(line) - 1) {
                break;
            }
        }
    }
}

int main() {
    char abc[] = "polpoldpolh";
    int arr[11];

    computePrefix(abc, 11, arr);


    char bcc[] = "pol";
    std::cout << abc << "\n";
    std::cout << bcc << "\n";
    search(abc, bcc, arr);
}
/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void computeLPSArray(string pat, int M, int *lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }

    }
}

void KMPSearch(string pat, string txt) {
    bool x = true;
    int M = pat.length();
    int N = txt.length();
    int count{};
    int *lps = new int[M];
    computeLPSArray(pat, M, lps);
    int i = 0;
    int j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
            count++;
        }
        if (j == M) {
            printf("\nindex %d ", i - j);
            j = lps[j - 1];
            x = false;
        } else if (i < N && pat[j] != txt[i]) {
            count++;
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    if (x == true) {
        cout << "\n not found" << endl;
    }
}

int main() {
    string full;
    getline(cin, full);
    string part;
    getline(cin, part);
    KMPSearch(part, full);
}
*/
