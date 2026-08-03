# Doubly Linked List

## Table of Contents

1. Introduction
2. What Is a Doubly Linked List?
3. Node Structure
4. Memory Layout
5. Forward Traversal
6. Backward Traversal
7. Common Operations
8. Time Complexity
9. Advantages
10. Disadvantages
11. Singly vs Doubly Linked List
12. Real-World Applications
13. Summary
14. References

---

## Introduction

A Doubly Linked List is a linear data structure in which each node stores data along with two pointers: one pointing to the next node and another pointing to the previous node.

Unlike a Singly Linked List, which supports traversal in only one direction, a Doubly Linked List allows efficient traversal both forward and backward.

This additional flexibility makes insertion, deletion, and navigation easier in many scenarios, although it comes at the cost of extra memory for storing the additional pointer.

In this module, the implementation is built completely from scratch in C++, without relying on the Standard Template Library (STL), to better understand how the data structure works internally.

---

## What Is a Doubly Linked List?

A Doubly Linked List consists of a sequence of nodes connected in both directions.

Each node contains:

- A data value
- A pointer to the next node
- A pointer to the previous node

The first node is called the **head**, and the last node is commonly referred to as the **tail**.

Unlike arrays, nodes are not stored in contiguous memory locations. Instead, each node is dynamically allocated and connected through pointers.

Because every node knows both its successor and predecessor, the list can be traversed from head to tail or from tail to head efficiently.

---

## Node Structure

Each node in a Doubly Linked List stores three components:

- **Data** – The value stored in the node.
- **Next Pointer** – Points to the next node in the list.
- **Previous Pointer** – Points to the previous node in the list.

```text
+--------+-----------+-----------+
|  Prev  |   Data    |   Next    |
+--------+-----------+-----------+
```

Unlike a Singly Linked List, every node maintains a reference to both neighboring nodes. This allows traversal in both directions and simplifies several operations.

---

## Memory Layout

Although a Doubly Linked List appears as a continuous sequence, its nodes are allocated dynamically and may reside anywhere in memory.

The logical connections are established through pointers rather than physical memory locations.

```text
Head
 │
 ▼
nullptr ← [10] ⇄ [20] ⇄ [30] → nullptr
```

Each node contains:

- A pointer to the previous node.
- A data value.
- A pointer to the next node.

The first node always has:

```text
prev = nullptr
```

because there is no node before it.

The last node always has:

```text
next = nullptr
```

because there is no node after it.

---

## Forward Traversal

Forward traversal begins at the head node.

At each step, the algorithm visits the current node and moves to the next node using the `next` pointer.

```text
Head
 │
 ▼
10 ⇄ 20 ⇄ 30 ⇄ 40

Traversal:

10 → 20 → 30 → 40
```

Forward traversal is commonly used for:

- Displaying the list.
- Searching for a value.
- Iterating through all elements.

---

## Backward Traversal

Backward traversal starts from the tail node.

Instead of following the `next` pointer, the algorithm repeatedly follows the `prev` pointer until reaching the head.

```text
Tail
 │
 ▼
10 ⇄ 20 ⇄ 30 ⇄ 40

Traversal:

40 → 30 → 20 → 10
```

Backward traversal is one of the key advantages of a Doubly Linked List and is impossible in a standard Singly Linked List without additional processing.

---

## Common Operations

The following operations are commonly performed on a Doubly Linked List.

### Insertion

- Insert at the front
- Insert at the back
- Insert after a specific node
- Insert before a specific node

### Deletion

- Delete the first node
- Delete the last node
- Delete a node by value
- Delete a specific node

### Traversal

- Traverse from head to tail
- Traverse from tail to head

### Searching

- Find a node by its value.

### Utility Operations

- Check whether the list is empty.
- Count the number of nodes.
- Clear the entire list.

---

## Time Complexity

| Operation | Time Complexity |
|-----------|-----------------|
| Access by Index | O(n) |
| Search | O(n) |
| Insert at Front | O(1) |
| Insert at Back (without tail pointer) | O(n) |
| Insert at Back (with tail pointer) | O(1) |
| Delete Front | O(1) |
| Delete Back (with tail pointer) | O(1) |
| Delete by Value | O(n) |
| Forward Traversal | O(n) |
| Backward Traversal | O(n) |

> **Note**
>
> The implementation in this repository maintains only a head pointer.
> Therefore, inserting at the end requires traversing the entire list, resulting in **O(n)** time complexity.
> Maintaining a tail pointer would reduce this operation to **O(1)**.

---

## Advantages

A Doubly Linked List offers several advantages over a Singly Linked List.

- Supports traversal in both directions.
- Deletion is simpler because every node knows its previous node.
- Easier insertion before a given node.
- Convenient for applications requiring backward navigation.
- Flexible dynamic memory allocation.

---

## Disadvantages

Despite its flexibility, a Doubly Linked List also has some drawbacks.

- Requires additional memory for the previous pointer.
- More pointer updates are required during insertion and deletion.
- Implementation is more complex than a Singly Linked List.
- Slightly higher memory overhead.
- Greater chance of pointer-related bugs if links are not updated correctly.

---

## Singly Linked List vs Doubly Linked List

| Feature | Singly Linked List | Doubly Linked List |
|---------|--------------------|--------------------|
| Pointers per Node | One (`next`) | Two (`next`, `prev`) |
| Forward Traversal | ✔️ | ✔️ |
| Backward Traversal | ❌ | ✔️ |
| Memory Usage | Lower | Higher |
| Insert Before a Node | Less Convenient | Easier |
| Delete a Node | Requires Previous Node | More Convenient |
| Implementation Complexity | Simpler | More Complex |

A Doubly Linked List provides greater flexibility than a Singly Linked List by maintaining links in both directions. However, this flexibility comes with additional memory usage and more pointer updates during insertion and deletion.

The choice between the two depends on the application's requirements and the trade-off between memory consumption and operational convenience.

---

## Real-World Applications

Doubly Linked Lists are commonly used in scenarios where bidirectional traversal is required.

Some practical applications include:

- Browser back and forward navigation.
- Undo and redo functionality in text editors.
- Music and video playlists.
- Image viewers.
- LRU (Least Recently Used) Cache implementations.
- Navigation history.
- Task scheduling systems.
- Operating system memory management.

---

## Summary

A Doubly Linked List extends the concept of a Singly Linked List by allowing traversal in both forward and backward directions.

Although it requires additional memory for storing the previous pointer, it simplifies many operations such as deletion and backward navigation.

Understanding this data structure is an important step toward mastering more advanced data structures such as stacks, queues, trees, graphs, and cache implementations.

This module focuses on building the data structure from scratch in C++, reinforcing pointer manipulation, dynamic memory management, and object-oriented design principles.

---

## References

- Cormen, T. H., *Introduction to Algorithms*
- Robert Lafore, *Data Structures and Algorithms in C++*
- Bjarne Stroustrup, *Programming: Principles and Practice Using C++*
- GeeksforGeeks – Doubly Linked List
- cppreference.com

