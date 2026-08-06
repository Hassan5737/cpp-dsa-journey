/*
==================================================
Problem: Remove Linked List Elements

Platform: LeetCode

Difficulty: Easy

Topics:
- Linked List
- Pointer Manipulation

Approach:
1. Remove all matching nodes from the beginning of the list.
2. If the list becomes empty, return nullptr.
3. Traverse the remaining list using a current pointer.
4. Whenever current->next matches the target value:
   - Bypass the node.
   - Delete it.
5. Otherwise, move to the next node.
6. Return the updated head.

Time Complexity:
O(n)

Space Complexity:
O(1)

Date:
2026-08-06
==================================================
*/

struct ListNode
{
    int val;
    ListNode *next;

    ListNode()
        : val(0), next(nullptr)
    {
    }

    ListNode(int x)
        : val(x), next(nullptr)
    {
    }

    ListNode(int x, ListNode *next)
        : val(x), next(next)
    {
    }
};

class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        while (head != nullptr && head->val == val)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        if (head == nullptr)
            return nullptr;

        ListNode* current = head;

        while (current->next != nullptr)
        {
            if (current->next->val == val)
            {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            else
            {
                current = current->next;
            }
        }

        return head;
    }
};
