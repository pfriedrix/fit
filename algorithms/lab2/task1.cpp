#include <iostream>
using namespace std;


struct stack {
    int list[10] {};
    int top = -1;

    bool is_empty() {
        return top == -1;
    }

    bool is_full() {
        return top == 9;
    }

    void push(int key) {
        if (is_full()) {
            throw "stack is full";
        }
        else {
            top++;
            list[top] = key;
        }
    }

    int pop() {
        if (is_empty()) {
            throw "stack is empty";
        }
        else {
            top--;
            return list[top+1];
        }
    }

    int get() {
        if (is_empty()) {
            throw "stack is empty";
        }
        else {
            return list[top];
        }
    }
};

int main() {
    stack heap;

    try {
        heap.push(10);
        cout << heap.pop() << endl;
        cout << heap.pop() << endl;
    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << std::endl;
    }

}