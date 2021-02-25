

#include <iostream>

using std::cout; using std::endl; using std::cin;

class Tree {
private:
    struct Node {
        Node() : right(nullptr), left(nullptr) {}

        explicit Node(int key) : key(key), right(nullptr), left(nullptr) {}

        int key{};
        Node *right;
        Node *left;
    };

public:
    Node *root;

    Tree() {
        root = nullptr;
    }

    ~Tree() {
        delete root;
    }

    void insert(int key) {
        if (root == nullptr) {
            root = new Node(key);
        } else {
            Node *leaf = new Node(key);
            Node *curr = root;
            while (curr->left != nullptr || curr->right != nullptr) {
                if (key >= curr->key && curr->right != nullptr) curr = curr->right;
                else if (key < curr->key && curr->left != nullptr) curr = curr->left;
                else break;
            }
            if (key >= curr->key) curr->right = leaf;
            else curr->left = leaf;
        }
    }

    Node *search(Node *node, int key) {
        if (node == nullptr || node->key == key)
            return node;

        if (node->key < key)
            return search(node->right, key);

        return search(root->left, key);
    }

    static Node *minValueNode(Node *node) {
        Node *curr = node;

        while (curr && curr->left != nullptr)
            curr = curr->left;

        return curr;
    }


    Node *remove(Node *leaf, int key) {
        if (leaf == nullptr)
            return leaf;

        if (key < leaf->key)
            leaf->left = remove(leaf->left, key);

        else if (key > leaf->key)
            leaf->right = remove(leaf->right, key);

        else {
            if (leaf->left == nullptr) {
                Node *temp = leaf->right;
                free(leaf);
                return temp;
            } else if (leaf->right == nullptr) {
                Node *temp = leaf->left;
                free(leaf);
                return temp;
            }
            Node *temp = minValueNode(leaf->right);

            leaf->key = temp->key;

            leaf->right = remove(leaf->right, temp->key);
        }
        return leaf;
    }

    void isEmpty() {
        if (root == nullptr) cout << "Tree is clear" << endl;
        else cout << "Tree is not clear" << endl;
    }

    void print(Node *node) {
        if (node != nullptr) {
            cout << node->key << " ";
            print(node->left);
            print(node->right);
        }
    }

    static bool is_empty_node(Node *node) {
        if (node->left != nullptr || node->right != nullptr) return false;
        return true;
    }

    Tree *copyTree() {
        Tree *instance = new Tree();
        instance->root = new Node();
        instance->root = copyNode(root, instance->root);
        return instance;
    }

    Node *copyNode(Node *source, Node *output) {
        if (source->left != nullptr) {
            output->key = source->key;
            output->left = new Node();
            copyNode(source->left, output->left);
        }
        if (source->right != nullptr) {
            output->key = source->key;
            output->right = new Node();
            copyNode(source->right, output->right);
        } else {
            output->key = source->key;
            return output;
        }
    }

    static Node *inorder(Node *node) {
        if (node == nullptr) {
            return node;
        }
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }

    static Node *postorder(Node *node) {
        if (node == nullptr) {
            return node;
        }
        postorder(node->left);
        postorder(node->right);
        cout << node->key << " ";
    }

    static Node *preorder(Node *node) {
        if (node == nullptr) {
            return node;
        }
        cout << node->key << " ";
        preorder(node->left);
        preorder(node->right);
    }

};


int main() {
    Tree instance = *new Tree();
    instance.insert(5);
    instance.insert(3);
    instance.insert(4);
    instance.insert(1);
    instance.insert(2);
    instance.insert(7);
    instance.insert(6);
    instance.insert(9);
    instance.insert(8);


    cout << " jkdjfsklj" << endl;
    instance.postorder(instance.root);
    cout << endl;
    cout << " jkdjfsklj" << endl;
    instance.inorder(instance.root);
    cout << endl;
    cout << " jkdjfsklj" << endl;
    instance.preorder(instance.root);
    cout << endl;
    cout << " Другой" << endl;

    instance.print(instance.root);
    cout << endl;
    instance.remove(instance.root, 7);
    instance.print(instance.root);
    cout << endl;
    cout << " Другой" << endl;
    Tree *sec_inst = instance.copyTree();
    instance.remove(instance.root, 4);
    sec_inst->print(sec_inst->root);
    cout << endl;
    sec_inst->remove(sec_inst->root, 6);
    cout << " Старый" << endl;
    instance.print(instance.root);
    cout << endl;
    cout << " Другой" << endl;
    sec_inst->print(sec_inst->root);
    cout << endl;

}