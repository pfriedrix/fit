#include <iostream>
using namespace std;

struct queue {
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
            throw "queue is full";
        }
        else {
            top++;
            list[top] = key;
        }
    }

    int pop() {
        if (is_empty()) {
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
        q.push(1);
        q.push(2);
        cout << q.pop() << endl;
        q.push(3);
        cout << q.pop() << endl;
        q.push(4);
        cout << q.pop() << endl;
        q.push(5);
        cout << q.pop() << endl;
        cout << q.pop() << endl;
    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << std::endl;
    }
}

