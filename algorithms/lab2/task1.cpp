#include <iostream>

using namespace std;


struct stack {
    int list[10]{};
    int top = -1;

    bool empty() {
        return top == -1;
    }

    bool full() {
        return top == 9;
    }

    void push(int key) {
        if (full()) {
            throw "stack is full";
        } else {
            top++;
            list[top] = key;
        }
    }

    int pop() {
        if (empty()) {
            throw "stack is empty";
        } else {
            top--;
            return list[top + 1];
        }
    }

    int get() {
        if (empty()) {
            throw "stack is empty";
        } else {
            return list[top];
        }
    }
};

int main() {
    stack heap;

    try {
        cout << "POP" << endl;
        cout << heap.pop() << endl;
        cout << "PUSH 70 75" << endl;
        heap.push(70);
        heap.push(75);
        cout << "GET" << endl;
        cout << heap.get() << endl;
        cout << "PUSH 14 70" << endl;
        heap.push(14);
        heap.push(70);
        cout << "POP" << endl;
        cout << heap.pop() << endl;
        cout << "GET" << endl;
        cout << heap.get() << endl;
        cout << "PUSH 75" << endl;
        heap.push(75);
        cout << "GET" << endl;
        cout << heap.get() << endl;
        cout << "POP" << endl;
        cout << heap.pop() << endl;
        cout << heap.pop() << endl;
        cout << "GET" << endl;
        cout << heap.get() << endl;
        cout << "PUSH 70" << endl;
        heap.push(70);
        cout << "POP" << endl;
        cout << heap.pop() << endl;
    }
    catch (const char *exception) {
        std::cerr << "Error: " << exception << std::endl;
    }

}