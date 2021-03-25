#include <iostream>

using namespace std;

struct Stack {
    int key;
    Stack *next;
};

void push(Stack **top, int key) {
    Stack *instance;
    instance = new Stack();
    instance->key = key;
    if (top == NULL) {
        *top = instance;
    } else {
        instance->next = *top;
        *top = instance;
    }
}

int pop(Stack **top) {
    Stack *instance = *top;
    if (*top != NULL) {
        int tmp = instance->key;
        *top = instance->next;
        delete instance;
        instance->key = 0;
        instance->next = NULL;
        cout << tmp << endl;
        return tmp;
    } else cout << "Стек пустий" << endl;
}

bool empty(Stack *top) {
    if (top == NULL) return true;
    else return false;
}

void get_top(Stack **top) {
    Stack *instance = *top;
    if (instance) cout << instance->key << endl;
    else cout << "Стек пустий" << endl;
}

void print(Stack **top) {
    Stack *instance = *top;
    while (instance != NULL) {
        cout << instance->key << endl;
        instance = instance->next;
    }
}


int main() {
    Stack *top = NULL;
    cout << "PUSH 10 14" << endl;
    push(&top, 10);
    push(&top, 14);
    cout << "GET" << endl;
    get_top(&top);
    cout << "POP" << endl;
    cout << pop(&top) << endl;
    cout << "PUSH 70 75" << endl;
    push(&top, 70);
    push(&top, 75);
    cout << "PUSH 14 70 75" << endl;
    push(&top, 14);
    push(&top, 70);
    cout << "POP" << endl;
    cout << pop(&top) << endl;
    cout << "GET" << endl;
    get_top(&top);
    cout << "PUSH 75" << endl;
    push(&top, 75);
    cout << "GET" << endl;
    get_top(&top);
    cout << "POP" << endl;
    cout << pop(&top) << endl;
    cout << pop(&top) << endl;
    cout << "PUSH 70" << endl;
    push(&top, 70);
    cout << "POP" << endl;
    cout << pop(&top) << endl;

}