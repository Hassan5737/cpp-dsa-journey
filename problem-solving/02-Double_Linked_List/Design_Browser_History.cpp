/*
==================================================
Problem: Design Browser History

Platform: LeetCode

Difficulty: Medium

Topics:
- Doubly Linked List
- Design
- Data Structures

Approach:
1. Implement a custom Doubly Linked List.
2. Define a private Node structure containing:
   - url
   - next
   - prev
3. Maintain:
   - head pointer
   - current pointer
4. Initialize the browser with the homepage.
5. For visit(url):
   - Delete all forward history.
   - Insert the new page after the current page.
   - Move current to the new page.
6. For back(steps):
   - Move through prev pointers until reaching the beginning
     or exhausting the required number of steps.
7. For forward(steps):
   - Move through next pointers until reaching the end
     or exhausting the required number of steps.

Time Complexity:
- BrowserHistory() : O(1)
- visit()          : O(k)   // k = deleted forward nodes
- back()           : O(steps)
- forward()        : O(steps)

Space Complexity:
O(n)

Date:
2026-08-03
==================================================
*/

#include <string>
using namespace std;


class BrowserHistory
{
private:
    struct Node
    {
        string url;
        Node* next;
        Node* prev;

        Node(string page)
            : url(page), next(nullptr), prev(nullptr)
        {}
    };

    Node* head;
    Node* current;

public:
    BrowserHistory(string homepage)
    {
        head = new Node(homepage);
        current = head;
    }

    void visit(string url)
    {
        Node* temp = current->next;

        while (temp != nullptr)
        {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }

        current->next = nullptr;

        Node* newNode = new Node(url);
        current->next = newNode;
        newNode->prev = current;

        current = newNode;
    }

    string back(int steps)
    {
        while (steps > 0 && current->prev != nullptr)
        {
            current = current->prev;
            steps--;
        }

        return current->url;
    }

    string forward(int steps)
    {
        while (steps > 0 && current->next != nullptr)
        {
            current = current->next;
            steps--;
        }

        return current->url;
    }
};