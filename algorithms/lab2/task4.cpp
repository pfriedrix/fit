#include <iostream>
using namespace std;

struct component {
    int key;
    component *next;
};

bool empty(component *top) {
    component *instance = top;
    if (instance) return false;
    else return true;
}

void push(component **top, int key) {
    component *instance = *top;
    component *previous = NULL;
    if (empty(*top)) {
        instance = new component();
        instance->key = key;
        instance->next = NULL;
        *top = instance;
    }
    else {
        while (instance != NULL) {
            previous = instance;
            instance = instance->next;
        }
        instance = new component();
        instance->key = key;
        instance->next = NULL;
        previous->next = instance;
    }
}

int pop(component **top) {
    component *instance;
    int tmp;
    if (empty(*top)) {
        throw "queue is empty";
    }
    else {
        instance = *top;
        tmp = instance->key;
        instance = instance->next;
        *top = instance;
    }
    return tmp;
}



void get(component **top) {
    component *instance = *top;
    component *previous = NULL;
    if (empty(*top)) {
        throw "queue is empty";
    }
    else {
        instance = *top;
        cout << instance->key << endl;
    }
}

void print(component **top) {
    component *instance = *top;
    while (instance != NULL){
        cout << instance->key << " ";
        instance = instance->next;
    }
    cout << endl;
}


int main() {
    try {
        component *top = NULL;
        cout << "PUSH" << endl;
        srand((unsigned)(time(NULL)));
        for (int i = 0; i < 5; i++) {
            push(&top, i);
        }
        cout << "POP" << endl;
        cout << pop(&top) << endl;
        cout << "PUSH" << endl;
        push(&top, 10);
        push(&top, 15);
        cout << "PUSH" << endl;
        cout << pop(&top) << endl;
        cout << "PEEK" << endl;
        get(&top);
        cout << "POP" << endl;
        cout << pop(&top) << endl;
        cout << "PEEK" << endl;
        get(&top);
        cout << "POP" << endl;
        cout << pop(&top) << endl;
        cout << "PEEK" << endl;
        get(&top);
        cout << "POP" << endl;
        cout << pop(&top) << endl;

    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << std::endl;
    }
}