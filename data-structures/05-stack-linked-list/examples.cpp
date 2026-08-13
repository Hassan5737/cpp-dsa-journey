#include <iostream>
#include <string>

using namespace std;

/*
===============================================================================
                Stack Using a Singly Linked List - Examples
===============================================================================

This file contains standalone examples demonstrating practical applications
of a Stack implemented using a Singly Linked List.

Examples:
    1. Reverse a String
    2. Check Balanced Parentheses
    3. Decimal to Binary Conversion

The Stack implementation is intentionally kept simple so that the focus
remains on understanding how Stack operations can be applied to problems.

===============================================================================
*/

class Stack
{
private:

    struct Node
    {
        char data;
        Node* next;

        Node(char value, Node* nextNode = nullptr)
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

    ~Stack()
    {
        while (top != nullptr)
        {
            Node* current = top;
            top = top->next;
            delete current;
        }
    }

    bool isEmpty() const
    {
        return top == nullptr;
    }

    void push(char value)
    {
        Node* newNode = new Node(value, top);
        top = newNode;
    }

    char pop()
    {
        if (isEmpty())
        {
            return '\0';
        }

        Node* removedNode = top;
        char value = removedNode->data;

        top = top->next;

        delete removedNode;

        return value;
    }

    char peek() const
    {
        if (isEmpty())
        {
            return '\0';
        }

        return top->data;
    }
};


/*
===============================================================================
Example 1: Reverse a String
===============================================================================
*/

string reverseString(const string& text)
{
    Stack stack;

    for (char character : text)
    {
        stack.push(character);
    }

    string reversed;

    while (!stack.isEmpty())
    {
        reversed += stack.pop();
    }

    return reversed;
}


/*
===============================================================================
Example 2: Balanced Parentheses
===============================================================================
*/

bool isBalanced(const string& expression)
{
    Stack stack;

    for (char character : expression)
    {
        if (character == '(')
        {
            stack.push(character);
        }
        else if (character == ')')
        {
            if (stack.isEmpty())
            {
                return false;
            }

            stack.pop();
        }
    }

    return stack.isEmpty();
}


/*
===============================================================================
Example 3: Decimal to Binary
===============================================================================
*/

string decimalToBinary(int number)
{
    if (number == 0)
    {
        return "0";
    }

    Stack stack;

    while (number > 0)
    {
        stack.push(static_cast<char>('0' + number % 2));
        number /= 2;
    }

    string binary;

    while (!stack.isEmpty())
    {
        binary += stack.pop();
    }

    return binary;
}


/*
===============================================================================
Main
===============================================================================
*/

int main()
{
    cout << "=== Reverse String ===\n";

    string text = "hello";

    cout << "Original: " << text << '\n';
    cout << "Reversed: " << reverseString(text) << '\n';


    cout << "\n=== Balanced Parentheses ===\n";

    string expression1 = "((()))";
    string expression2 = "(()))";

    cout << expression1 << " -> "
         << (isBalanced(expression1) ? "Balanced" : "Not Balanced")
         << '\n';

    cout << expression2 << " -> "
         << (isBalanced(expression2) ? "Balanced" : "Not Balanced")
         << '\n';


    cout << "\n=== Decimal to Binary ===\n";

    int number = 10;

    cout << "Decimal: " << number << '\n';
    cout << "Binary: " << decimalToBinary(number) << '\n';


    return 0;
}
