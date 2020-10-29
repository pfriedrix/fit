#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void display(int *arr, int size) {
    for(int i = 0; i<size; i++) {
        cout << arr[i] << " ";
//        std::this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << endl;
}


int getMax(int array[], int size) {
   int max = array[0];
   for(int i = 1; i<=size; i++) {
      if(array[i] > max)
         max = array[i];
   }
   return max; 
}
void countSort(int *array, int size) {
    int max = getMax(array, size);
    int output[size];
    int count[max + 1];
    for(int i = 0; i < max + 1; i++) count[i] = 0;
    for(int i = 0; i < size; i++) count[array[i]]++;
    int inserted = 0;
    for (int i = 0; i < max + 1; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                output[inserted] = i;
                ++inserted;
            }
        }
    }
    for(int i = 0; i < size; i++){
        array[i] = output[i];
    }
}


int binarySearch(int *arr, int p, int r, int num) {
   if (p <= r) {
      int mid = (p + r)/2;
      if (arr[mid] == num)
      return mid ;
       if (arr[mid] > num) {
           display(arr, mid-1);
           return binarySearch(arr, p, mid-1, num);
       }
      
       if (arr[mid] < num) {
           for (int i = mid + 1; i < r + 1; i++) {
               cout << arr[i] << " ";
           }
           cout << endl;
           return binarySearch(arr, mid+1, r, num);
       }
      
   }
   return -1;
}


int main() {
    using std::cout;
    using std::cin;
    int n;
    cout << "input length of array: ";
    cin >> n;
    int arr[n];
    cout << "make random array or by input(r/i): ";
    char option;
    cin >> option;
    if (option == 'r') {
        for (int i = 0; i < n; i++){
            arr[i] = (rand()%100);
        }
    }
    else if (option == 'i') {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }
    display(arr, n);
    countSort(arr, n);
    display(arr, n);
    cout << endl;
    int len = sizeof(arr)/ sizeof(arr[0]);
    bool quit = false;
    char quit_l;
    int result;
    while (!quit) {
        cout << "You wanna search (y/n): ";
        cin >> quit_l;
        if (quit_l == 'n') {
            cout << "Goodbey!" << endl;
            return 0;
        }
        int input;
        cout << "Input number which you wanna search: ";
        cin >> input;
        display(arr, n);
        result = binarySearch(arr, 0, len - 1, input);
        cout << "searching ";
        for (int i = 1; i < 10; i++ ) {
            cout << ".";
            std::this_thread::sleep_for(chrono::milliseconds(200));
        }
        cout << endl;
        if (result != -1) {
            cout << input << " is here." << endl;
        }
        else {
            cout << input << " is not here." << endl;
        }
    }
}

