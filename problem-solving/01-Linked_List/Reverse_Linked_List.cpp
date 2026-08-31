/*
==================================================
Problem: Reverse Linked List

Platform: LeetCode
Problem Number: 206

Difficulty: Easy

Topics:
- Linked List
- Pointers

Approach:
- Reverse the direction of each next pointer.
- Use three pointers:
    1. prev     -> points to the previous node.
    2. cur      -> points to the current node.
    3. nextNode -> saves the next node before changing
                   the current node's next pointer.
- For each node:
    - Save cur->next.
    - Reverse cur->next to point to prev.
    - Move prev to cur.
    - Move cur to nextNode.
- At the end, prev points to the new head.

Time Complexity:
O(n)

Space Complexity:
O(1)

Date:
2026-08-31
==================================================
*/

#include <iostream>

using namespace std;

class Solution 
{
private:
    struct ListNode
    {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while(cur != nullptr)
        {
            ListNode* nextNode = cur->next;

            cur->next = prev;

            prev = cur;
            cur = nextNode;
        }

        return prev;
    }
};