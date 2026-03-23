#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack() {
    top = nullptr;
}

void Stack::push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void Stack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return;
    }

    Node* temp = top;
    top = top->next;
    delete temp;
}

int Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return top->data;
}

bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::display() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }

    Node* temp = top;
    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
