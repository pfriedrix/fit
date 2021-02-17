#include <iostream>
#include <iomanip>
using namespace std;



const int listSize = 100;

struct List
{
    int value;
    List* nextGenerated;
    List* nextSorted;
};

List* headGenerated = NULL;
List* headSorted = NULL;

void generateList(List*& list)
{
    srand((unsigned)(time(NULL)));
    List* currElement = NULL;

    for (int i = 0; i < listSize; i++)
    {
        List* temp = new List();
        temp->value = rand() % listSize;
        temp->nextGenerated = NULL;
        temp->nextSorted = NULL;

        if (i == 0) list = temp;
        else currElement->nextGenerated = temp;

        currElement = temp;
    }

}

void sortList(List*& list)
{
    List** arr = new List*[listSize];
    List* ptr = list;
    for (int i = 0; i < listSize; i++)
    {
        arr[i] = ptr;
        ptr = ptr->nextGenerated;
    }

    for (int i = 0; i < listSize; i++)
    {
        int min = i;
        for (int j = i + 1; j < listSize; j++)
        {
            if (arr[j]->value < arr[min]->value) min = j;
        }
        List* temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    ptr = arr[0];
    for (int i = 1; i < listSize; i++)
    {
        ptr->nextSorted = arr[i];
        ptr = arr[i];
    }

    headSorted = arr[0];

}

void printGenerated(List*& list)
{
    List* ptr = list;
    while (ptr != NULL)
    {
        cout << ptr->value << " ";
        ptr = ptr->nextGenerated;
    }
    cout << endl;
}

void printSorted(List*& list)
{
    List* ptr = list;
    while (ptr != NULL)
    {
        cout << ptr->value << " ";
        ptr = ptr->nextSorted;
    }
    cout << endl;
}


int main()
{
    generateList(headGenerated);
    printGenerated(headGenerated);
    sortList(headGenerated);
    printSorted(headSorted);
}
