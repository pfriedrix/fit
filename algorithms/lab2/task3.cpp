#include <iostream>
using namespace std;

struct queue {
    int list[10] {};
    int top = -1;

    bool empty() {
        return top == -1;
    }

    bool full() {
        return top == 9;
    }

    void push(int key) {
        if (full()) {
            throw "queue is full";
        }
        else {
            top++;
            list[top] = key;
        }
    }

    int pop() {
        if (empty()) {
            throw "queue is empty";
        }
        else {
            int tmp = list[0];
            for (int i = 1; i <= top; i++) {
                list[i-1] = list[i];
            }
            top--;
            return tmp;
        }
    }
};

int main() {
    queue q;
    try {
        cout << "PUSH 70 75" << endl;
        q.push(70);
        q.push(75);
        cout << "PUSH 14 77" << endl;
        q.push(14);
        q.push(77);
        cout << "POP" << endl;
        cout << q.pop() << endl;
        cout << "POP" << endl;
        cout << q.pop() << endl;
        cout << q.pop() << endl;
        cout << "POP" << endl;
        cout << q.pop() << endl;
    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << std::endl;
    }
}

