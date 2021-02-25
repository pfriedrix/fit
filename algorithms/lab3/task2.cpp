

#include <iostream>

using std::cout; using std::endl; using std::cin;

class List {
private:
    struct Node {
        Node(): next(NULL) {}
        Node(int key) : key(key), next(NULL) {}
        int key;
        Node *next;
    };
    Node *head;
public:
    List() {
        head = NULL;
    }
    ~List() {
        delete head;
    }

    void append(int key) {
        Node *node = new Node(key);
        if (head == NULL) {
            head = node;
        }
        else {
            Node *curr = head;
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = node;
        }
    }

    void remove() {
        if (head) {
            Node *node = head;
            Node *prev;
            while (node->next) {
                prev = node;
                node = node->next;
            }
            prev->next = NULL;
            delete node;
        }
    }

    Node* search(int key) {
        Node *node = head;
        while (node) {
            if (key == node->key) return node;
            else node = node->next;
        }
    }

    void insert(int keyItemList, int key) {
        Node *node = search(keyItemList);
        Node *newNode = new Node(key);
        newNode->next = node->next;
        node->next = newNode;
    }

    int size() {
        int size = 0;
        Node *node = head;
        while (node) {
            size++;
            node = node->next;
        }
        return size;
    }

    void print() {
        Node *node = head;
        while (node) {
            cout << node->key << " ";
            node = node->next;
        }
        cout << endl;
    }

    void sort() {
        if (head) {
            for (int i = 0; i < size(); i++) {
                Node *node = head;
                Node *curr = head;
                Node *prevNode;
                Node *nextNode = curr->next;
                if (curr->key > nextNode->key) {
                    curr->next = nextNode->next;
                    nextNode->next = curr;
                    head = nextNode;
                    node = nextNode;
                    prevNode = node;
                }
                while (node->next) {
                    curr = node;
                    nextNode = node->next;
                    if (curr->key > nextNode->key) {
                        curr->next = nextNode->next;
                        nextNode->next = curr;
                        prevNode->next = nextNode;
                        node = nextNode;
                        prevNode = curr;
                    } else {
                        prevNode = node;
                        node = node->next;
                    }
                }
            }
        }
    }

    void appendInSorted(int key) {
        append(key);
        sort();
    }
};

int main() {

}