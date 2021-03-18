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


int search(char line[], char searched[], const int arr[]) {
    int k = 0, l = 0;
    while (l < strlen(searched)) {
        if (line[k] == searched[l]) {
            k++;
            l++;
            if (l == strlen(searched) - 1) return k;
        } else if (line[k] != searched[l] && l != 0) {
            l = arr[l - 1];
        } else if (line[k] != searched[l] && l == 0) {
            k++;
            if (k == strlen(line) - 1) return -1;
        }
    }
    return k;
}

int main() {
    char abc[] = "ролролдролщ";
    int arr[11];

    computePrefix(abc, 11, arr);
    for (int i = 0; i < 11; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    char bcc[] = "рол";
    std::cout << abc << "\n";
    std::cout << bcc << "\n";
    int res = search(abc, bcc, arr);

    std::cout << res;
}