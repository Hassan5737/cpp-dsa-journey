/*
==================================================
Problem: Linked Lists - Length & Count

Platform: Codewars

Difficulty: 6 kyu

Topics:
- Linked List
- Pointers
- Iteration

Approach:

Length():
1. If the list is empty, return 0.
2. Create a pointer (current) pointing to the head.
3. Traverse the linked list.
4. Increment the counter for each visited node.
5. Return the total count.

Count():
1. If the list is empty, return 0.
2. Create a pointer (current) pointing to the head.
3. Traverse the linked list.
4. Whenever current->data equals the target value,
   increment the counter.
5. Return the total occurrences.

Time Complexity:
Length() -> O(n)
Count()  -> O(n)

Space Complexity:
O(1)

Notes:
- Traverse the list using a separate pointer to
  preserve the original head pointer.
- Stop when current becomes nullptr.

Date:
2026-07-24
==================================================
*/


struct Node 
{
  Node * next;
  int data;
};


int Length(Node *head)
{
  if (head == nullptr)
{
    return 0;
}

  Node* current = head;
  int count = 0;

  while (current != nullptr)
    {
    count++;
    current = current->next; 
  }

  return count;
}


int Count(Node *head, int data)
{
    if (head == nullptr)
{
    return 0;
}

  Node* current = head;
  int count = 0;

  while (current != nullptr)
    {
    if (current-> data == data)
      {
      count++;
    }
    current = current->next;
  }
  
  return count;
}