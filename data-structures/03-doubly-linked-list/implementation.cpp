/*
===============================================================================
                            Doubly Linked List
===============================================================================

This implementation demonstrates a Doubly Linked List built completely from
scratch without using the C++ Standard Template Library (STL).

Features:
    - Insert at the front
    - Insert at the back
    - Delete from the front
    - Delete from the back
    - Search for a value
    - Print forward
    - Print backward
    - Check if the list is empty
    - Count the number of nodes
    - Clear the entire list

===============================================================================
*/

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value)
        : data(value), next(nullptr), prev(nullptr)
    {
    }
};

class DoublyLinkedList
{
private:
    Node* head;

public:

    DoublyLinkedList()
        : head(nullptr)
    {
    }

    ~DoublyLinkedList()
    {
        clear();
    }

    bool isEmpty() const
    {
        return head == nullptr;
    }

    void insertFront(int value);

    void insertBack(int value);

    void deleteFront();

    void deleteBack();

    bool contains(int value) const;

    int size() const;

    void clear();

    void printForward() const;

    void printBackward() const;
};

//=============================================================================
// Insert at the Front
//=============================================================================

void DoublyLinkedList::insertFront(int value)
{
    Node* newNode = new Node(value);

    if (isEmpty())
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

//=============================================================================
// Insert at the Back
//=============================================================================

void DoublyLinkedList::insertBack(int value)
{
    Node* newNode = new Node(value);

    if (isEmpty())
    {
        head = newNode;
        return;
    }

    Node* current = head;

    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

//=============================================================================
// Delete the First Node
//=============================================================================

void DoublyLinkedList::deleteFront()
{
    if (isEmpty())
    {
        cout << "The list is empty.\n";
        return;
    }

    Node* firstNode = head;

    if (head->next == nullptr)
    {
        delete firstNode;
        head = nullptr;
        return;
    }

    head = head->next;
    head->prev = nullptr;

    delete firstNode;
}

//=============================================================================
// Delete the Last Node
//=============================================================================

void DoublyLinkedList::deleteBack()
{
    if (isEmpty())
    {
        cout << "The list is empty.\n";
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;

    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->prev->next = nullptr;

    delete current;
}

//=============================================================================
// Search for a Value
//=============================================================================

bool DoublyLinkedList::contains(int value) const
{
    Node* current = head;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            return true;
        }

        current = current->next;
    }

    return false;
}

//=============================================================================
// Get the Number of Nodes
//=============================================================================

int DoublyLinkedList::size() const
{
    int count = 0;

    Node* current = head;

    while (current != nullptr)
    {
        ++count;
        current = current->next;
    }

    return count;
}

//=============================================================================
// Remove All Nodes
//=============================================================================

void DoublyLinkedList::clear()
{
    Node* current = head;

    while (current != nullptr)
    {
        Node* nextNode = current->next;

        delete current;

        current = nextNode;
    }

    head = nullptr;
}

//=============================================================================
// Print the List (Forward)
//=============================================================================

void DoublyLinkedList::printForward() const
{
    if (isEmpty())
    {
        cout << "The list is empty.\n";
        return;
    }

    Node* current = head;

    while (current != nullptr)
    {
        cout << current->data;

        if (current->next != nullptr)
        {
            cout << " <-> ";
        }

        current = current->next;
    }

    cout << " -> nullptr\n";
}

//=============================================================================
// Print the List (Backward)
//=============================================================================

void DoublyLinkedList::printBackward() const
{
    if (isEmpty())
    {
        cout << "The list is empty.\n";
        return;
    }

    Node* current = head;

    while (current->next != nullptr)
    {
        current = current->next;
    }

    while (current != nullptr)
    {
        cout << current->data;

        if (current->prev != nullptr)
        {
            cout << " <-> ";
        }

        current = current->prev;
    }

    cout << " -> nullptr\n";
}

//=============================================================================
// Demonstration
//=============================================================================

int main()
{
    DoublyLinkedList list;

    cout << "==============================\n";
    cout << " Insert at the Back\n";
    cout << "==============================\n";

    list.insertBack(20);
    list.insertBack(30);
    list.insertBack(40);

    list.printForward();

    cout << "\n==============================\n";
    cout << " Insert at the Front\n";
    cout << "==============================\n";

    list.insertFront(10);

    list.printForward();

    cout << "\n==============================\n";
    cout << " Forward Traversal\n";
    cout << "==============================\n";

    list.printForward();

    cout << "\n==============================\n";
    cout << " Backward Traversal\n";
    cout << "==============================\n";

    list.printBackward();

    cout << "\n==============================\n";
    cout << " Search\n";
    cout << "==============================\n";

    cout << boolalpha;

    cout << "Contains 30: "
         << list.contains(30)
         << '\n';

    cout << "Contains 100: "
         << list.contains(100)
         << '\n';

    cout << "\n==============================\n";
    cout << " Size\n";
    cout << "==============================\n";

    cout << "Number of nodes: "
         << list.size()
         << '\n';

    cout << "\n==============================\n";
    cout << " Delete Front\n";
    cout << "==============================\n";

    list.deleteFront();

    list.printForward();

    cout << "\n==============================\n";
    cout << " Delete Back\n";
    cout << "==============================\n";

    list.deleteBack();

    list.printForward();

    cout << "\n==============================\n";
    cout << " Clear\n";
    cout << "==============================\n";

    list.clear();

    list.printForward();

    cout << "\n==============================\n";
    cout << " Empty Check\n";
    cout << "==============================\n";

    cout << boolalpha
         << list.isEmpty()
         << '\n';

    return 0;
}