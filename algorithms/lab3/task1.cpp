#include <iostream>
#include <iomanip>
using namespace std;

bool toContinue = true;
const int listSize = 10;

struct List
{
    int arrValues[listSize];
    int arrLinks[listSize];
    int head = -1;
    int currSize = 0;
    int actualSize = 0;
};

List* list;
int index_list, value;

void insertInTheStart(List*& list, int value)
{
    List* newElement = new List();
    int size = list->actualSize;
    newElement->arrValues[size] = value;
    newElement->arrLinks[list->actualSize] = NULL;
    newElement->head = list->actualSize;

    list = newElement;
}

int insertInTheEnd(List*& list, int value)
{

    int size = list->actualSize;
    int currElement = list->head;
    while (list->arrLinks[currElement] != NULL)
    {
        currElement = list->arrLinks[currElement];
    }
    list->arrValues[size] = value;
    list->arrLinks[size] = NULL;
    return currElement;
}

List* createEmptyList()
{

    List* newList = new List();
    cout << "The empty list was created" << endl;
    cout << "\n\nPress any key to return to the menu" << endl;


    return newList;
}

void insert(List*& list, int value)
{
    if (list->actualSize == 0) insertInTheStart(list, value);
    else
    {
        int currElement = insertInTheEnd(list, value);
        list->arrLinks[currElement] = list->actualSize;
    }
    list->currSize++;
    list->actualSize++;
    cout << "The element was inserted successfully" << endl;
    cout << "\n\nPress any key to return to the menu" << endl;


}


void insertByIndex(List*& list, int value, int index)
{
    if (list->currSize == 0) insertInTheStart(list, value);
    else
    {
        insertInTheEnd(list, value);

        int prevElement = -1;
        int currElement = list->head;
        for (int i = 0; i <= index; i++)
        {
            prevElement = currElement;
            currElement = list->arrLinks[currElement];
        }
        list->arrLinks[prevElement] = list->actualSize;
        list->arrLinks[list->actualSize] = currElement;
    }

    list->currSize++;
    list->actualSize++;
    cout << "The element was inserted successfully" << endl;
    cout << "\n\nPress any key to return to the menu" << endl;


}

void deleteElement(List*& list, int index)
{
    int prevElement = -1;
    int currElement = list->head;
    for (int i = 0; i <= index; i++)
    {
        if (i != index) prevElement = currElement;
        currElement = list->arrLinks[currElement];
    }
    list->arrLinks[prevElement] = currElement;
    list->currSize--;
    cout << "The element was deleted successfully" << endl;
    cout << "\n\nPress any key to return to the menu" << endl;


}


void findElement(List*& list, int value)
{
    int count = 0;
    bool isFound = false;
    int currElement = list->head;
    for (int i = 0; i < list->actualSize; i++)
    {
        if (list->arrValues[currElement] == value)
        {
            count = i;
            isFound = true;
            break;
        }
        currElement = list->arrLinks[currElement];
    }
    if (isFound) cout << "The element was found on index " << count << endl;
    else cout << "The element is not in the list" << endl;

    cout << "\n\nPress any key to return to the menu" << endl;


}

void sortList(List*& list)
{
    int tempArr[listSize];
    int size = list->currSize;
    int currElement = list->head;
    for (int i = 0; i < size; i++)
    {
        tempArr[i] = list->arrValues[currElement];
        currElement = list->arrLinks[currElement];
    }
    int tmp = size;
    const float factor = 1.3;
    while (tmp != 1)
    {
        tmp = tmp / factor;
        for (int i = 0; i < (size - tmp); i++)
        {
            if (tempArr[i] > tempArr[i + tmp])
            {
                int tmp_el = tempArr[i];
                tempArr[i] = tempArr[i + tmp];
                tempArr[i + tmp] = tmp_el;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        list->arrValues[i] = tempArr[i];
    }
    for (int i = 0; i < size-1; i++)
    {
        list->arrLinks[i] = i + 1;
    }

    list->actualSize = size;
    cout << "\n\nPress any key to return to the menu" << endl;


}

void insertInSorted(List*& list, int value)
{
    if (list->actualSize == 0)
    {
        insertInTheStart(list, value);
    }
    else
    {
        insertInTheEnd(list, value);

        int prevElement = -1;
        int currElement = list->head;
        bool wasBreaked = false;
        while (list->arrLinks[currElement] != NULL)
        {
            if (list->arrValues[currElement] > value)
            {
                wasBreaked = true;
                break;
            }
            prevElement = currElement;
            currElement = list->arrLinks[currElement];
        }
        if (wasBreaked)
        {
            list->arrLinks[prevElement] = list->actualSize;
            list->arrLinks[list->actualSize] = currElement;
        }
        else {
            list->arrLinks[currElement] = list->actualSize;
        }

    }
    list->actualSize++;
    list->currSize++;
    cout << "The element was inserted successfully" << endl;
    cout << "\n\nPress any key to return to the menu" << endl;


}

void outputList(List*&)
{
    cout << "Your list: ";
    int currElement = list->head;
    while (list->arrLinks[currElement] != NULL)
    {
        cout << list->arrValues[currElement] << " ";
        currElement = list->arrLinks[currElement];
    }
    cout << list->arrValues[currElement] << " ";
    cout << "\n\nPress any key to return to the menu" << endl;


}


int main()
{

}
