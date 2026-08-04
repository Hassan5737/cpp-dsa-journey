/*
==================================================
Problem: Merge Two Sorted Lists

Platform: LeetCode

Difficulty: Easy

Topics:
- Linked List
- Two Pointers
- Merge

Approach:
1. Handle edge cases where one of the lists is empty.
2. Compare the first nodes of both lists to determine the head.
3. Maintain two pointers:
   - head: points to the beginning of the merged list.
   - tail: always points to the last node in the merged list.
4. Traverse both lists simultaneously.
5. Always attach the smaller node to the merged list.
6. Move the corresponding list pointer forward.
7. When one list is exhausted, attach the remaining nodes of the other list.
8. Return the head of the merged list.

Time Complexity:
O(n + m)

Space Complexity:
O(1)

Date:
2026-08-04
==================================================
*/

  struct ListNode 
 {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (list1 == nullptr)
            return list2;

        if (list2 == nullptr)
            return list1;

        ListNode* head;
        ListNode* tail;

        if (list1->val <= list2->val)
        {
            head = list1;
            tail = list1;
            list1 = list1->next;
        }
        else
        {
            head = list2;
            tail = list2;
            list2 = list2->next;
        }

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                tail->next = list1;
                tail = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                tail = list2;
                list2 = list2->next;
            }
        }

        if (list1 != nullptr)
            tail->next = list1;
        else
            tail->next = list2;

        return head;
    }
};
