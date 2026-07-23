/*
===============================================================================
                        Singly Linked List Implementation
===============================================================================

Project : cpp-dsa-journey
Module  : Data Structures / Singly Linked List

Description:
    A complete implementation of a Singly Linked List from scratch using
    modern C++ and object-oriented programming principles.

Features:
    - Insert at the front
    - Insert at the back
    - Delete from the front
    - Delete from the back
    - Delete by value
    - Search for a value
    - Print the linked list
    - Check if the list is empty
    - Get the current size
    - Clear the entire list automatically

Author:
    Hassan Ahmed

Repository:
    https://github.com/Hassan5737/cpp-dsa-journey

===============================================================================
*/

#include <iostream>

using namespace std;

//=============================================================================
// Node
// Represents a single element inside the linked list.
//=============================================================================

class Node
{
public:

    int value;
    Node* next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

//=============================================================================
// LinkedList
// A singly linked list implementation.
//=============================================================================

class LinkedList
{
private:

    Node* head;
    int length;

public:

    LinkedList();

    ~LinkedList();

    bool isEmpty() const;

    int size() const;

    void insertFront(int value);

    void insertBack(int value);

    void deleteFront();

    void deleteBack();

    void deleteByValue(int value);

    bool contains(int value) const;

    void print() const;

    void clear();
};

//=============================================================================
// Constructor
//
// Initializes an empty linked list.
//
// Time Complexity : O(1)
// Space Complexity: O(1)
//=============================================================================

LinkedList::LinkedList()
{
    head = nullptr;
    length = 0;
}

//=============================================================================
// Destructor
//
// Releases all dynamically allocated memory.
//
// Time Complexity : O(n)
// Space Complexity: O(1)
//=============================================================================

LinkedList::~LinkedList()
{
    clear();
}

//=============================================================================
// isEmpty
//
// Returns true if the linked list contains no nodes.
//
// Time Complexity : O(1)
// Space Complexity: O(1)
//=============================================================================

bool LinkedList::isEmpty() const
{
    return head == nullptr;
}

//=============================================================================
// size
//
// Returns the current number of nodes.
//
// Time Complexity : O(1)
// Space Complexity: O(1)
//=============================================================================

int LinkedList::size() const
{
    return length;
}

//=============================================================================
// print
//
// Prints all nodes from head to tail.
//
// Example:
// 10 -> 20 -> 30 -> nullptr
//
// Time Complexity : O(n)
// Space Complexity: O(1)
//=============================================================================

void LinkedList::print() const
{
    Node* current = head;

    while (current != nullptr)
    {
        cout << current->value << " -> ";
        current = current->next;
    }

    cout << "nullptr" << endl;
}

//=============================================================================
// clear
//
// Deletes all nodes in the linked list.
//
// Time Complexity : O(n)
// Space Complexity: O(1)
//=============================================================================

void LinkedList::clear()
{

}

//=============================================================================
// insertFront
//
// Inserts a new node at the beginning of the linked list.
//
// Before:
// Head
//  |
//  v
// 10 -> 20 -> 30 -> nullptr
//
// After inserting 5:
//
// Head
//  |
//  v
// 5 -> 10 -> 20 -> 30 -> nullptr
//
// Time Complexity : O(1)
// Space Complexity: O(1)
//=============================================================================

void LinkedList::insertFront(int value)
{
    Node* newNode = new Node(value);

    newNode->next = head;

    head = newNode;

    length++;
}

//=============================================================================
// insertBack
//
// Inserts a new node at the end of the linked list.
//
// Before:
//
// 10 -> 20 -> nullptr
//
// After inserting 30:
//
// 10 -> 20 -> 30 -> nullptr
//
// Time Complexity : O(n)
// Space Complexity: O(1)
//=============================================================================

void LinkedList::insertBack(int value)
{
    Node* newNode = new Node(value);

    if (isEmpty())
    {
        head = newNode;
        length++;
        return;
    }

    Node* current = head;

    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode;

    length++;
}

//=============================================================================
// deleteFront
//
// Removes the first node from the linked list.
//
// Before:
//
// Head
//  |
//  v
// 10 -> 20 -> 30 -> nullptr
//
// After:
//
// Head
//  |
//  v
// 20 -> 30 -> nullptr
//
// Time Complexity : O(1)
// Space Complexity: O(1)
//=============================================================================

void LinkedList::deleteFront()
{
    if (isEmpty())
    {
        cout << "The linked list is empty." << endl;
        return;
    }

    Node* firstNode = head;

    head = head->next;

    delete firstNode;

    length--;
}

//=============================================================================
// deleteBack
//
// Removes the last node from the linked list.
//
// Time Complexity : O(n)
// Space Complexity: O(1)
//=============================================================================

void LinkedList::deleteBack()
{
    if (isEmpty())
    {
        cout << "The linked list is empty." << endl;
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        length--;
        return;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current->next != nullptr)
    {
        previous = current;
        current = current->next;
    }

    previous->next = nullptr;

    delete current;

    length--;
}

//=============================================================================
// deleteByValue
//
// Removes the first node containing the specified value.
//
// Example:
//
// 10 -> 20 -> 30 -> 40
//
// deleteByValue(30)
//
// Result:
//
// 10 -> 20 -> 40
//
// Time Complexity : O(n)
// Space Complexity: O(1)
//=============================================================================

void LinkedList::deleteByValue(int value)
{
    if (isEmpty())
    {
        cout << "The linked list is empty." << endl;
        return;
    }

    if (head->value == value)
    {
        deleteFront();
        return;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->value != value)
    {
        previous = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Value not found." << endl;
        return;
    }

    previous->next = current->next;

    delete current;

    length--;
}

//=============================================================================
// contains
//
// Checks whether a value exists in the linked list.
//
// Returns:
// true  -> if the value is found.
// false -> otherwise.
//
// Time Complexity : O(n)
// Space Complexity: O(1)
//=============================================================================

bool LinkedList::contains(int value) const
{
    Node* current = head;

    while (current != nullptr)
    {
        if (current->value == value)
        {
            return true;
        }

        current = current->next;
    }

    return false;
}

//=============================================================================
// clear
//
// Removes all nodes from the linked list.
//
// Time Complexity : O(n)
// Space Complexity: O(1)
//=============================================================================

void LinkedList::clear()
{
    while (!isEmpty())
    {
        deleteFront();
    }
}

//=============================================================================
// Demonstration
//=============================================================================

int main()
{
    LinkedList list;

    cout << "===============================" << endl;
    cout << " Singly Linked List Demo" << endl;
    cout << "===============================" << endl;

    cout << "\nInsert at Back:\n";

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);
    list.insertBack(40);

    list.print();

    cout << "\nInsert at Front:\n";

    list.insertFront(5);

    list.print();

    cout << "\nCurrent Size: "
         << list.size()
         << endl;

    cout << boolalpha;

    cout << "\nContains 20: "
         << list.contains(20)
         << endl;

    cout << "Contains 100: "
         << list.contains(100)
         << endl;

    cout << "\nDelete Front:\n";

    list.deleteFront();

    list.print();

    cout << "\nDelete Back:\n";

    list.deleteBack();

    list.print();

    cout << "\nDelete By Value (20):\n";

    list.deleteByValue(20);

    list.print();

    cout << "\nFinal Size: "
         << list.size()
         << endl;

    return 0;
}

