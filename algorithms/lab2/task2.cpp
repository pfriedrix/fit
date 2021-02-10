#include <iostream>
using namespace std;

struct component {
    int key;
    component *next;
};

void push(component **top, int key) {
    component *instance;
    instance = new component();
    instance->key = key;
    if (top == NULL) {
        *top = instance;
    }
    else {
        instance->next = *top;
        *top = instance;
    }
}

int pop(component **top) {
    component *instance = *top;
    component *previous = NULL;
    int tmp = instance->key;
    while (instance != NULL) {
        if (instance == *top) {
            *top = instance->next;
            delete instance;
            instance->key = 0;
            instance->next = NULL;
        }
        else
        {
            previous->next = instance->next;
            delete instance;
            instance->key = 0;
            instance->next = NULL;
        }
        previous = instance;
        instance = instance->next;
    }
    cout << tmp << endl;
    return tmp;
}

bool empty(component *top) {
    component *instance = top;
    if (instance) return false;
    else return true;
}

void get_top(component **top) {
    component *instance = *top;
    if (instance) cout << instance->key << endl;
    else cout << "Стек пустий" << endl;
}

void print(component **top) {
    component *instance = *top;
    while (instance != NULL){
        cout << instance->key << endl;
        instance = instance->next;
    }
}


int main() {
    component *top = NULL;
    get_top(&top);
    cout << empty(top) << endl;
    srand((unsigned)(time(NULL)));
    for (int i = 0; i < 1000000; i++) {
        push(&top, i);
    }
    pop(&top);

    cout << empty(top) << endl;
}