/*
==================================================
Problem: Flatten a Multilevel Doubly Linked List

Platform: LeetCode
Problem Number: 430

Difficulty: Medium

Topics:
- Doubly Linked List
- Recursion
- Pointers

Approach:
- Traverse the doubly linked list.
- When a node has a child, recursively flatten
  the child list.
- Connect the child list between the current node
  and its original next node.
- Restore the correct prev and next pointers.
- Remove the child pointer after flattening.

Time Complexity:
O(n)

Space Complexity:
O(n) - recursion stack in the worst case

Date:
2026-09-02
==================================================
*/

#include <iostream>
using namespace std;

class Solution
{
private:
    struct Node 
    {
    int val;
    Node* prev;
    Node* next;
    Node* child;
    };
public:

    Node* flatten(Node* head)
    {
        if(head == nullptr)
        {
            return nullptr;
        }

        flattenAndGetTail(head);

        return head;
    }

private:

    Node* flattenAndGetTail(Node* head)
    {
        Node* cur = head;
        Node* last = head;

        while(cur != nullptr)
        {
            Node* nextNode = cur->next;

            if(cur->child != nullptr)
            {
                Node* childHead = cur->child;

                Node* childTail = flattenAndGetTail(childHead);

                cur->next = childHead;
                childHead->prev = cur;

                cur->child = nullptr;

                if(nextNode != nullptr)
                {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }

                last = childTail;
            }
            else
            {
                last = cur;
            }

            cur = nextNode;
        }

        return last;
    }
};
