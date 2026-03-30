# Binary Search Trees

## Task 1

We start with an empty binary search tree and insert the values in this order:

[1, 5, 9, 2, 4, 10, 6, 3, 8]

Rules:
- smaller goes to left
- greater goes to right

Final tree:

        1
         \
          5
         / \
        2   9
         \ / \
          4 6 10
         /   \
        3     8

## Task 2

Balanced BST search time is O(log n)

log2(1000) ~= 10

So it takes about 10 steps max to find a value.

## Task 3

To find the greatest value:
- start at root
- keep going right
- stop when no right child

Pseudocode:

greatestValue(root):
    current = root
    while current.right != null:
        current = current.right
    return current.value

## Task 4

C++ code:

    #include <iostream>
    using namespace std;

    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    Node* createNode(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    Node* insert(Node* root, int value) {
        if (root == nullptr) {
            return createNode(value);
        }

        if (value < root->data) {
            root->left = insert(root->left, value);
        } else if (value > root->data) {
            root->right = insert(root->right, value);
        }

        return root;
    }

    int main() {
        int values[] = {1, 5, 9, 2, 4, 10, 6, 3, 8};
        int size = 9;

        Node* root = nullptr;

        for (int i = 0; i < size; i++) {
            root = insert(root, values[i]);
        }

        return 0;
    }
