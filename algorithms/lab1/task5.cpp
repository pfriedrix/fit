#include <iostream>
#include <math.h>

using namespace std;

void gausMethod()
{

    int rows, cols;

    cout << "==========TASK 3==========" << endl << "Enter amount of rows of an matrix: ";
    cin >> rows;
    cout << endl << "Enter amount of columns of an matrix: ";
    cin >> cols;
    double matrix[10][10];
    cout << "Your matrix: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = pow(-1, rand()%2) * (rand()%100);
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < rows; i++)
    {
        int tmp = matrix[i][i];
        if (tmp != 0)
        {
            for (int j = 0; j < cols; j++)
            {
                if (j < i) continue;
                matrix[i][j] /= tmp;
            }
        }
        int tmp2 = 0;
        for (int j = 0; j < cols; j++)
        {
            tmp2 = matrix[i][j] * matrix[i+1][j];
            if (tmp2 == 0)
            {
                matrix[i+1][j] *= tmp2;
            }
            else matrix[i+1][j] -= tmp2;
        }

    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    gausMethod();
//    cout << "Розмір квадратної матриці - ";
//    int n;
//    cin >> n;
//    const int length = n;
//    int arr[length][length];
//    for (int i = 0; i < length; i++) {
//        for (int j = 0; j < length; j++) {
//            if ((i <= j) && (i >= length - j - 1)) arr[i][j] = 1;
//            else if ((i >= j) && (i <= length - j - 1)) arr[i][j] = 1;
//            else arr[i][j] = 0;
//        }
//    }
//    for (int i = 0; i < length; i++) {
//        for (int j = 0; j < length; j++) {
//            cout << arr[i][j] << " ";
//        }
//        cout << endl;
//    }
}
