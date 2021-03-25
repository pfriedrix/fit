

#include <iostream>

using std::cout; using std::endl; using std::cin;


class Tree {
public:
    struct Node {
        Node() : right(nullptr), left(nullptr) {}

        explicit Node(int key) : key(key), right(nullptr), left(nullptr) {}

        int key{};
        Node *right;
        Node *left;
    };

    Node *root;

    Tree() {
        root = nullptr;
    }

    ~Tree() {
        delete root;
    }

    Node *insert(Node *node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }
        if (key >= node->key) {
            node->right = insert(node->right, key);
        } else {
            node->left = insert(node->left, key);
        }
        return node;
    }

    Node *search(Node *node, int key) {
        if (node == nullptr || node->key == key)
            return node;

        if (node->key < key)
            return search(node->right, key);
        return search(node->left, key);
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
    Tree::Node *root = instance.insert(instance.root, 45);

    instance.insert(root, 35);
    instance.insert(root, 12);
    instance.insert(root, 0);
    instance.insert(root, 34);
    instance.insert(root, 57);
    instance.insert(root, 100);
    instance.insert(root, 2);
    instance.insert(root, 14);
    instance.insert(root, 25);
    instance.insert(root, 78);
    instance.print(root);
    cout << endl;
    instance.remove(root, 2);
    instance.print(root);
    cout << endl;
    instance.insert(root, 80);
    instance.print(root);
    cout << endl;
    instance.postorder(root);
    cout << endl;
    instance.print(root);
    cout << endl;

}