# Doubly Linked List Notes

## Definition

A Doubly Linked List is a linear data structure where each node contains:

- Data
- A pointer to the next node
- A pointer to the previous node

Unlike a Singly Linked List, it supports traversal in both forward and backward directions.

---

## Node Structure

Each node stores:

```cpp
class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};
```

---

## Key Characteristics

- Dynamic memory allocation.
- Non-contiguous memory layout.
- Bidirectional traversal.
- Efficient insertion and deletion at the beginning.
- Easier deletion of known nodes than in a Singly Linked List.

---

## Common Operations

| Operation | Complexity |
|-----------|-----------:|
| Insert Front | O(1) |
| Insert Back* | O(n) |
| Delete Front | O(1) |
| Delete Back* | O(n) |
| Search | O(n) |
| Forward Traversal | O(n) |
| Backward Traversal | O(n) |
| Access by Index | O(n) |

> **Note:** In this implementation, only a `head` pointer is maintained. Using an additional `tail` pointer would reduce insertion and deletion at the back to **O(1)**.

---

## Advantages

- Supports forward and backward traversal.
- Simplifies deletion operations.
- Convenient insertion before or after a node.
- Well suited for navigation-based applications.

---

## Disadvantages

- Requires extra memory for the `prev` pointer.
- More pointer updates are needed.
- More complex implementation than a Singly Linked List.

---

## Common Applications

- Browser navigation history.
- Undo / Redo functionality.
- Music and video playlists.
- LRU Cache.
- Image viewers.
- Navigation systems.

---

## Important Concepts

- Every node has two links.
- The first node has `prev == nullptr`.
- The last node has `next == nullptr`.
- Traversal starts from the head.
- Reverse traversal starts from the tail.

---

## Interview Tips

Be able to explain:

- Why a Doubly Linked List requires more memory.
- Why backward traversal is possible.
- When a Doubly Linked List is preferred over a Singly Linked List.
- How insertion and deletion differ from a Singly Linked List.
- Why maintaining a tail pointer improves performance.

---

## Quick Summary

✔ Two pointers per node

✔ Forward and backward traversal

✔ Dynamic memory allocation

✔ Efficient insertion and deletion at the beginning

✔ Higher memory usage than a Singly Linked List