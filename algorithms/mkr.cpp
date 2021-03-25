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

Stack pop(Stack **top) {
    Stack *instance = *top;
    if (*top != NULL) {
        Stack tmp = *instance;
        *top = instance->next;
        delete instance;
        instance->key = 0;
        instance->next = NULL;
        return tmp;
    } else throw "stack is empty";

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

///

struct Queue {
    int key;
    Queue *next;
};

bool empty(Queue *top) {
    Queue *instance = top;
    if (instance) return false;
    else return true;
}

void push(Queue **top, int key) {
    Queue *instance = *top;
    Queue *previous = NULL;
    if (empty(*top)) {
        instance = new Queue();
        instance->key = key;
        instance->next = NULL;
        *top = instance;
    } else {
        while (instance != NULL) {
            previous = instance;
            instance = instance->next;
        }
        instance = new Queue();
        instance->key = key;
        instance->next = NULL;
        previous->next = instance;
    }
}

Queue pop(Queue **top) {
    Queue *instance;
    Queue *poped;
    if (empty(*top)) {
        throw "queue is empty";
    } else {
        instance = *top;
        poped = instance;
        instance = instance->next;
        *top = instance;
    }
    return *poped;
}


void get(Queue **top) {
    Queue *instance = *top;
    Queue *previous = NULL;
    if (empty(*top)) {
        throw "queue is empty";
    } else {
        instance = *top;
        cout << instance->key << endl;
    }
}

void print(Queue **top) {
    Queue *instance = *top;
    while (instance != NULL) {
        cout << "address: " << instance << "\nkey: " << instance->key << "\nnext: " << instance->next;
        instance = instance->next;
    }
    cout << endl;
}


int main() {
    Queue *top = NULL;
    Stack *topStack = NULL;
    for (int i = 3; i < 55; i++) {
        if (i % 2 != 0) {
            push(&top, i);
        }
    }
    print(&top);
    while (1) {
        try {
            Queue i = pop(&top);
            cout << "address: " << &i << "\nkey: " << i.key << "\nnext: " << i.next;
            cout << endl;
            push(&topStack, i.key);
        }
        catch (const char *exception) {
            break;
        }
    }
    cout << "Stack" << endl;
    while (1) {
        try {
            Stack i = pop(&topStack);
            if (i.key % 3 == 0) cout << "address: " << &i << "\nkey: " << i.key << "\nnext: " << i.next << endl;
        }
        catch (const char *exception) {
            break;
        }
    }

}