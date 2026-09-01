/*
==================================================
Problem: Reverse Linked List II

Platform: LeetCode
Problem Number: 92

Difficulty: Medium

Topics:
- Linked List
- Pointers

Approach:
- Use a dummy node before the head to simplify the
  case where left == 1.
- Move a pointer to the node immediately before
  the reversal range.
- Reverse only the nodes between left and right.
- Reconnect the reversed part with the nodes before
  and after the range.

Time Complexity:
O(n)

Space Complexity:
O(1)

Date:
2026-09-01
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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if (head == nullptr || left == right)
        {
            return head;
        }

        ListNode dummy(0, head);
        ListNode* before = &dummy;

 
        for (int i = 1; i < left; i++)
        {
            before = before->next;
        }

        ListNode* cur = before->next;

  
        for (int i = 0; i < right - left; i++)
        {
            ListNode* nextNode = cur->next;

            cur->next = nextNode->next;
            nextNode->next = before->next;
            before->next = nextNode;
        }

        return dummy.next;
    }
};




