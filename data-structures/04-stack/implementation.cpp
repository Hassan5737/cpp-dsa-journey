/*
===============================================================================
                            Stack (Array-Based)
===============================================================================

This implementation demonstrates a Stack built completely from scratch using
a fixed-size array without relying on the C++ Standard Template Library (STL).

Features:
    - Push
    - Pop
    - Peek
    - Display
    - Check if the stack is empty
    - Check if the stack is full
    - Get the current size
    - Clear the stack

===============================================================================
*/

#include <iostream>

using namespace std;

class Stack
{
private:
    static const int CAPACITY = 5;

    int data[CAPACITY];
    int topIndex;

public:

    Stack()
        : topIndex(-1)
    {
    }

    bool isEmpty() const
    {
        return topIndex == -1;
    }

    bool isFull() const
    {
        return topIndex == CAPACITY - 1;
    }

    void push(int value);

    int pop();

    int peek() const;

    int size() const;

    void clear();

    void display() const;
};

void Stack::push(int value)
{
    if (isFull())
    {
        cout << "Stack Overflow: Cannot push into a full stack.\n";
        return;
    }

    data[++topIndex] = value;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow: The stack is empty.\n";
        return -1;
    }

    return data[topIndex--];
}

int Stack::peek() const
{
    if (isEmpty())
    {
        cout << "The stack is empty.\n";
        return -1;
    }

    return data[topIndex];
}

int Stack::size() const
{
    return topIndex + 1;
}

void Stack::clear()
{
    topIndex = -1;
}

void Stack::display() const
{
    if (isEmpty())
    {
        cout << "The stack is empty.\n";
        return;
    }

    cout << "Stack (Top -> Bottom):\n";

    for (int i = topIndex; i >= 0; --i)
    {
        cout << data[i] << '\n';
    }
}

int main()
{
    Stack stack;

    cout << "Pushing elements...\n";

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    stack.display();

    cout << "\nCurrent size: " << stack.size() << '\n';

    cout << "\nTop element: " << stack.peek() << '\n';

    cout << "\nPopping: " << stack.pop() << '\n';

    cout << "\nStack after pop:\n";
    stack.display();

    cout << "\nCurrent size: " << stack.size() << '\n';

    cout << "\nClearing the stack...\n";
    stack.clear();

    stack.display();

    cout << "\nIs stack empty? "
         << (stack.isEmpty() ? "Yes" : "No")
         << '\n';

    return 0;
}