#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Stack elements:" << endl;
    s.display();

    s.pop();

    cout << endl;
    cout << "Top element: " << s.peek() << endl;

    cout << endl;
    cout << "Stack elements:" << endl;
    s.display();

    return 0;
}
