//11.1. Створити матрицю, кількість рядків m>3 та кількість стовпців n>3 якої ввести з клавіатури. Передбачити меню вибору способу створення матриці: введення з клавіатури або генерація псевдовипадкових додатніх та від'ємних чисел. Визначити рядки матриці з найбільшою та найменшою кількістю однакових елементів. Поміняти ці рядки місцями. Вивести на екран вхідну матрицю, індекси рядків з найменшою та найбільшою кількістю однакових елементів та матрицю після переставлення рядків. Матриці виводити табличному вигляді.

#include <iostream>



bool is_item_in_arr(int arr[], int len, int item) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == item) {
            return true;
        }
    }
    return false;
}

int index_arr(int arr[], int len, int searched) {
    for (int i = 0; i < len; i++) if (arr[i] == searched) return i;
    return 0;
}

int main(int argc, const char * argv[]) {
    int rows, columns;
    while (true) {
        std::cout << "Enter numbers of rows and columns (more than 3): ";
        
        std::cin >> rows >> columns;
        if (rows >= 3 && columns >= 3) {
            break;
        }
    }
    char choice;
    std::cout << "Enter method of filling in matrix r - random, i - input (r/i): ";
    std::cin >> choice;
    int arr[rows][columns];
// generation
    if (choice == 'r') {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                arr[i][j] = (rand()%200)-100;
                std::cout << arr[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    else if (choice == 'i') {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                std::cin >> arr[i][j];
            }
        }
    }
    
// countrepetions
    int repeated[rows];
    for (int i = 0; i < rows; i++) {
        int set[columns], counter = 0, repeats = 0;
        
        for (int j = 0; j < columns; j++) {
            if (!is_item_in_arr(set, counter+1, arr[i][j])) {
                set[counter] = arr[i][j];
                counter++;
            }
            else {
                std::cout << "index: [" << i << "]" << "[" << j << "]" << " value: " << arr[i][j]<< std::endl;
                repeats++;
            }
        }
        repeated[i] = repeats;
    }
    int max_repeats=repeated[0], min_repeats=repeated[0];
    for (int i = 1; i < rows; i++) {
        max_repeats = repeated[i] > max_repeats ? repeated[i] : max_repeats;
        min_repeats = repeated[i] < min_repeats ? repeated[i] : min_repeats;
    }
    // swap
    int index_max = index_arr(repeated, rows, max_repeats);
    int index_min = index_arr(repeated, rows, min_repeats);
    std::cout << "index max repeats: [" << index_max << "]" << " repeats: " << repeated[index_max]<< std::endl;
    std::cout << "index min repeats: [" << index_min << "]" << " repeats: " << repeated[index_min]<< std::endl;
    
   
    int temp;
    for (int i = 0; i < columns; i++) {
        temp = arr[index_max][i];
        arr[index_max][i] = arr[index_min][i];
        arr[index_min][i] = temp;
    }
    for (int i = 0; i < rows; i++ ){
        for (int j = 0; j < columns; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


