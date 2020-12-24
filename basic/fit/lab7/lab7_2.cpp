//
//  lab7_2.cpp
//  lab7
//
//  Created by Ivan Romancev on 11.11.2020.
//

#include <iostream>


int main()
{
    int rows, columns;
    std::cout << "Enter numbers of rows: ";
    std::cin >> rows;
    char choice;
    std::cout << "Enter method of filling in matrix r - random, i - input (r/i): ";
    std::cin >> choice;
    int a[rows][rows];
    double b[rows];
    // generation
    if (choice == 'r')
    {
        std::cout << "a matrix: " << std::endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                a[i][j] = (rand() % 10) - 5;
                std::cout << a[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "b matrix: " << std::endl;
        for (int i = 0; i < rows; i++)
        {
            b[i] = (rand() % 10) - 5;
            std::cout << b[i] << " ";
        }
        std::cout << std::endl;
    }
    else if (choice == 'i')
    {
        std::cout << "Input a matrix: " << std::endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                std::cin >> a[i][j];
            }
        }
        std::cout << "Input b matrix: " << std::endl;
        for (int i = 0; i < rows; i++)
        {
            std::cin >> b[i];
        }
    }
    // gauss
    
    float temp;//Line 1
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    temp=a[j][i]/a[i][i];//Line 2
                    for(int k=i;k<n+1;k++)
                    {
                          a[j][k]-=temp*a[i][k];//Line 3
                        //a[j][k]-=a[j][i]*a[i][k]/a[i][i];//Line 4
                    }
                }
            }
    std::cout << "x: ";
    for (int i = 0; i < rows; i++) {
        std::cout << x[i] << " ";
    }
}
