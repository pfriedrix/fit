#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int a[5][5] , n;
int prompt_menu_item()
{
    // Выбранный вариант менюж
    int variant;
    cout << "Choose the variant\n" << endl;
    cout << "1. Create matrix\n"
        << "2. Create random matrix\n"
        << "3. Find summ of the elements\n"
        << "4. Sort matrix\n"
        << "5. Show matrix\n"
        << "6. exit\n" << endl;
    cout << ">>> ";
    cin >> variant;
    return variant;
}

int main(int argc, char* argv[])
{
    int variant = prompt_menu_item();

    switch (variant) {
    case 1:
        void matrix(); {
            cout << "Enter matrix size-->"; cin >> n;
            cout << "Enter matrix elements:" << endl;
            for (int i = 0; i < n; i++)             //зовнішній  цикл по рядках
                for (int j = 0; j < n; j++)         //внутрішній цикл по стовпцях
                    cin >> a[i][j];                   //із клавіатури елементи                        //вводяться через символ пробілу

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    cout << a[i][j] << " ";              //вивести елементи рядка
                cout << endl;                //перевести курсор на новий рядок
            }
            break;
    case 2:
        cout << "Random matrix created!" << endl;
        int main();
        {
            srand(time(NULL)); // Инициализируем генератор случайных чисел.
            int n = 0;
            cin >> n; // Считываем с клавиатуры n
            int** a = new int* [n]; // Создаем массив указателей
            for (int i = 0; i ; n , i++)
            {
                a[i] = new int[n]; // Создаем элементы
            }
            // А дальше работа как с обычным массивом.
            for (int i = 0; i < n ; i++)
            {
                for (int j = 0; j <n ; j++)
                {
                    a[i][j] = (rand() % 10)-10; // Каждый элемент случайному числу от 0 до 9
            }
            return 0;
        }
    }
        break;
    case 3:
        cout << "Findinп summ of the elements..." << endl;
        break;
    case 4:
        cout << "Sorting..." << endl;
        break;
    case 5:
        cout << "Displaying the matrix..." << endl;
        cout << a[i][j] << " ";
        cout << endl;
        break;
    case 6:
        cout << "Exiting..." << endl;
        exit(EXIT_SUCCESS);
        break;
    default:
        cerr << "You chose something different!" << endl;
        exit(EXIT_FAILURE);
        }
        return 0;
    }
}
