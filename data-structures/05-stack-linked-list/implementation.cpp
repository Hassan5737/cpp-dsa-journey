/*
===============================================================================
                    Stack Using a Singly Linked List
===============================================================================

This implementation demonstrates a Stack built from scratch using a
Singly Linked List.

The Stack follows the LIFO (Last In, First Out) principle.

Core operations:
    - Push
    - Pop
    - Peek
    - Display
    - Empty check

Memory is managed dynamically using new/delete.

===============================================================================
*/

#include <iostream>

using namespace std;

class Stack
{
private:

    struct Node
    {
        int data;
        Node* next;

        Node(int value, Node* nextNode = nullptr)
            : data(value), next(nextNode)
        {
        }
    };

    Node* top;

public:

    Stack()
        : top(nullptr)
    {
    }

    ~Stack();

    bool isEmpty() const;

    void push(int value);

    int pop();

    int peek() const;

    void display() const;
};

Stack::~Stack()
{
    while (top != nullptr)
    {
        Node* current = top;
        top = top->next;
        delete current;
    }
}

bool Stack::isEmpty() const
{
    return top == nullptr;
}

void Stack::push(int value)
{
    Node* newNode = new Node(value, top);
    top = newNode;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow." << endl;
        return -1;
    }

    Node* removedNode = top;
    int removedValue = removedNode->data;

    top = top->next;

    delete removedNode;

    return removedValue;
}

int Stack::peek() const
{
    if (isEmpty())
    {
        cout << "Stack Underflow." << endl;
        return -1;
    }

    return top->data;
}

void Stack::display() const
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
        return;
    }

    Node* current = top;

    cout << "Stack (Top -> Bottom): ";

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    cout << '\n';
}

int main()
{
    Stack stack;

    cout << "Pushing elements...\n";

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    cout << "\nTop element: " << stack.peek() << '\n';

    cout << "\nPopped element: " << stack.pop() << '\n';

    stack.display();

    cout << "\nTop element after pop: "
         << stack.peek() << '\n';

    cout << "\nPopping remaining elements:\n";

    cout << stack.pop() << '\n';
    cout << stack.pop() << '\n';

    cout << "\nIs stack empty? "
         << (stack.isEmpty() ? "Yes" : "No")
         << '\n';

    cout << "\nTrying to pop from an empty stack:\n";
    stack.pop();

    return 0;
}