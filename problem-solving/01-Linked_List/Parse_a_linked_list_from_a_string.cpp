/*
==================================================
Problem: Parse a linked list from a string

Platform: Codewars

Difficulty: 6 kyu

Topics:
- Linked List
- Strings
- StringStream
- Parsing

Approach:
1. Handle the special case where the input is "nullptr".
2. Create a stringstream from the input string.
3. Read each integer from the stream.
4. Create a new node for every parsed value.
5. Build the linked list using head and tail pointers.
6. Continue until "nullptr" is reached.
7. Return the head of the constructed linked list.

Time Complexity:
O(n)

Space Complexity:
O(n)

Notes:
- Used stringstream to parse the input string.
- Used head and tail pointers to build the linked list in O(1) per insertion.
- Avoided traversing the linked list for every new node.

Date:
2026-07-25
==================================================
*/

class Node
{
public:
    int data;
    Node* next;

    Node(int data, Node* next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

#include <sstream>
#include <string>

using namespace std;

Node* parse(const string& s)
{
    if (s == "nullptr")
        return nullptr;

    stringstream ss(s);

    Node* head = nullptr;
    Node* tail = nullptr;

    while (true)
    {
        int value;
        ss >> value;

        Node* newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        char dash, arrow;
        ss >> dash >> arrow;

        string end;
        streampos pos = ss.tellg();

        if (!(ss >> end))
            break;

        if (end == "nullptr")
            break;

        ss.seekg(pos);
    }

    return head;
}