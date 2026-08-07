/*
==================================================
Problem: Middle of the Linked List

Platform: LeetCode

Difficulty: Easy

Topics:
- Linked List
- Two Pointers
- Slow and Fast Pointers

Approach:
1. Initialize two pointers at the head:
   slow and fast.
2. Move slow one node at a time.
3. Move fast two nodes at a time.
4. When fast reaches the end, slow will be
   pointing to the middle node.
5. Return slow.

For an even-sized list, this naturally returns
the second middle node.

Time Complexity:
O(n)

Space Complexity:
O(1)

Date:
2026-08-07
==================================================
*/



#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode()
        : val(0), next(nullptr)
    {}

    ListNode(int x)
        : val(x), next(nullptr)
    {}

    ListNode(int x, ListNode* next)
        : val(x), next(next)
    {}
};

class Solution
{
public:
    ListNode* middleNode(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};