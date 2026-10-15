# Circular Linked List

## Table of Contents

1. [Introduction](#introduction)
2. [What Is a Circular Linked List?](#what-is-a-circular-linked-list)
3. [Why Do We Need Circular Linked Lists?](#why-do-we-need-circular-linked-lists)
4. [Structure of a Node](#structure-of-a-node)
5. [Memory Layout](#memory-layout)
6. [Head and Tail Pointers](#head-and-tail-pointers)
7. [Circular Linked List vs. Singly Linked List](#circular-linked-list-vs-singly-linked-list)
8. [Creating a Circular Linked List](#creating-a-circular-linked-list)
9. [Basic Operations](#basic-operations)
10. [Object-Oriented Design](#object-oriented-design)
11. [Time Complexity](#time-complexity)
12. [Advantages](#advantages)
13. [Disadvantages](#disadvantages)
14. [Common Pitfalls](#common-pitfalls)
15. [Summary](#summary)
16. [Resources](#resources)

---

## Introduction

A Circular Linked List is a variation of the linked list data structure in which the last node connects back to the first node instead of pointing to `nullptr`.

This structure creates a circular chain of nodes that can be traversed repeatedly without reaching a null pointer at the end.

Understanding circular linked lists strengthens knowledge of pointers, dynamic memory allocation, node manipulation, and edge-case handling in C++.

---

## What Is a Circular Linked List?

A Circular Linked List is a collection of nodes connected through pointers, where the final node points back to the first node.

Each node stores:

- A value representing the data.
- A pointer to the next node.

Example:

```text
              Head
                |
                v
          +-----------+
          |    10     |
          |   next    |------------------+
          +-----------+                  |
                |                        |
                v                        |
          +-----------+                  |
          |    20     |                  |
          |   next    |                  |
          +-----------+                  |
                |                        |
                v                        |
          +-----------+                  |
          |    30     |                  |
          |   next    |------------------+
          +-----------+
```

The last node points back to the first node, creating a cycle.

Unlike a standard Singly Linked List, a Circular Linked List does not terminate at `nullptr` during normal traversal.

---

## Why Do We Need Circular Linked Lists?

A Circular Linked List is useful when elements need to be processed repeatedly in a cyclic order.

Common applications include:

- Round-robin CPU scheduling.
- Turn-based games.
- Circular queues.
- Repeated task scheduling.
- Cyclic navigation through items.

For example, in a round-robin scheduling system, each process gets a turn before the system moves to the next process. After the final process, execution can return to the first process.

The circular structure naturally represents this behavior.

---

## Structure of a Node

Each node contains data and a pointer to the next node.

```cpp
struct Node
{
    int data;
    Node* next;
};
```

- `data` stores the node's value.
- `next` stores the address of the next node.

In an Object-Oriented implementation, the node structure and its management can be encapsulated inside a `CircularLinkedList` class.

This helps keep the internal representation separate from the public operations.

---

## Memory Layout

Linked list nodes do not need to occupy contiguous memory locations.

Each node stores the address of another node, allowing pointers to connect nodes regardless of their physical locations in memory.

Example:

```text
Node A
+--------+--------+
|   10   | 0x2000 | ----+
+--------+--------+     |
                       |
Node B                 |
+--------+--------+    |
|   20   | 0x3000 |    |
+--------+--------+    |
                       |
Node C                 |
+--------+--------+    |
|   30   | 0x1000 | ---+
+--------+--------+
```

The addresses above are illustrative. The important point is that the final node stores the address of the first node rather than `nullptr`.

---

## Head and Tail Pointers

Two useful pointers for managing a Circular Linked List are `head` and `tail`.

- **Head:** Points to the first node.
- **Tail:** Points to the last node.

When the list contains at least one node:

```cpp
tail->next == head
```

This relationship maintains the circular structure.

### Empty List

```text
head = nullptr
tail = nullptr
```

### Single-Node List

```text
       +-----------+
  +--->|    10     |---+
  |    +-----------+   |
  +--------------------+

head and tail point to the same node.
```

### Multiple Nodes

```text
head                         tail
 |                             |
 v                             v
10 --------> 20 --------> 30 --+
^                             |
|_____________________________|
```

Maintaining a tail pointer can make insertion at the beginning and end more efficient because the last node can be accessed directly.

---

## Circular Linked List vs. Singly Linked List

| Feature | Singly Linked List | Circular Linked List |
|---|---|---|
| Last node points to | `nullptr` | First node |
| Traversal termination | Reaches `nullptr` | Returns to the starting node |
| Natural cyclic traversal | No | Yes |
| Dynamic memory allocation | Yes | Yes |
| Direct indexing | No | No |
| Risk of infinite traversal | Possible if links are corrupted | Possible if the stopping condition is incorrect |

The main difference is the connection between the final node and the first node.

This difference affects traversal logic, insertion, deletion, and memory management.

---

## Creating a Circular Linked List

When creating the first node, both `head` and `tail` point to that node.

The node's `next` pointer points to itself.

```text
       head, tail
           |
           v
       +--------+
   +-->|   10   |---+
   |   +--------+   |
   +----------------+
```

For a list containing multiple nodes, the tail points to the final node, and the final node points back to `head`.

Maintaining this invariant is essential for correct insertion and deletion.

---

## Basic Operations

### Insert at Beginning

Adds a new node before the current first node.

Before:

```text
head
 |
 v
10 --------> 20 --------> 30
^                         |
|_________________________|
```

After inserting `5`:

```text
head
 |
 v
5 ---------> 10 ---------> 20 ---------> 30
^                                      |
|______________________________________|
```

The new node becomes the head, and the tail must continue pointing to the final node.

### Insert at End

Adds a new node after the current final node.

Before:

```text
10 --------> 20
^             |
|_____________|
```

After inserting `30`:

```text
10 --------> 20 --------> 30
^                         |
|_________________________|
```

The new node becomes the tail, and its `next` pointer must point to `head`.

### Delete from Beginning

Removes the first node.

Before:

```text
head
 |
 v
10 --------> 20 --------> 30
^                         |
|_________________________|
```

After deleting the first node:

```text
head
 |
 v
20 --------> 30
^             |
|_____________|
```

The head moves to the next node, and the tail's `next` pointer must be updated to the new head.

If the list contains only one node, deleting it must leave both `head` and `tail` equal to `nullptr`.

### Delete from End

Removes the final node.

Before:

```text
10 --------> 20 --------> 30
^                         |
|_________________________|
```

After deleting the final node:

```text
10 --------> 20
^             |
|_____________|
```

In a singly circular linked list, the node before the tail must be found before the final node can be removed.

### Traversal

Traversal visits each node exactly once during a complete pass.

```text
10 --------> 20 --------> 30
^                         |
|_________________________|
```

Traversal begins at `head` and stops when the pointer returns to `head`.

A `do-while` loop is a natural choice because it processes the first node before checking the stopping condition.

Care must be taken not to use a termination condition intended for a non-circular list, such as waiting for `nullptr`.

---

## Object-Oriented Design

The implementation in this module uses an Object-Oriented approach to organize the Circular Linked List.

The `CircularLinkedList` class is responsible for managing its nodes and maintaining the list's structural invariants.

The design separates the public interface from the internal implementation.

### Encapsulation

The internal node structure and pointers are kept private so that external code cannot directly modify the links.

Public member functions provide controlled access to the supported operations.

### Dynamic Memory Management

Nodes are allocated dynamically and must be released when they are removed or when the entire list is destroyed.

A robust implementation must prevent memory leaks and avoid accessing deleted nodes.

### Edge-Case Handling

Every operation should account for the relevant states:

- An empty list.
- A list containing a single node.
- A list containing multiple nodes.

These cases are especially important because removing or inserting nodes can affect both `head` and `tail`.

### Class Responsibilities

The class should manage:

- Node creation and linking.
- Insertion at the beginning and end.
- Deletion from the beginning and end.
- Traversal and display.
- Empty-list checks.
- Cleanup of dynamically allocated nodes.

---

## Time Complexity

The following complexities assume that the implementation maintains both `head` and `tail`, uses a singly linked circular structure, and does not maintain a separate pointer to the node before the tail.

| Operation | Time Complexity |
|---|---:|
| Insert at Beginning | O(1) |
| Insert at End | O(1) |
| Delete from Beginning | O(1) |
| Delete from End | O(n) |
| Traversal | O(n) |
| Search | O(n) |
| Check Whether Empty | O(1) |
| Clear the Entire List | O(n) |

The exact complexity depends on the implementation.

For example, insertion at the end takes O(n) if only `head` is maintained and the final node must be found by traversal. Maintaining `tail` allows this operation to take O(1).

Deleting the final node still takes O(n) in a singly linked structure because the preceding node must be located.

---

## Advantages

- Supports cyclic traversal without restarting from a separate list.
- Dynamically grows and shrinks as nodes are added or removed.
- Supports efficient insertion at the beginning and end when a tail pointer is maintained.
- Does not require contiguous memory.
- Naturally represents repeating sequences and round-robin processing.

---

## Disadvantages

- Each node requires additional memory for a pointer.
- Direct indexing is unavailable.
- Traversal can continue indefinitely if the stopping condition is incorrect.
- Deleting the final node requires locating its predecessor in a singly linked implementation.
- Pointer updates require care to preserve the circular structure.
- Dynamic memory must be managed correctly to avoid leaks and invalid memory access.

---

## Common Pitfalls

### Forgetting to Link the Tail to the Head

The final node must point to the first node.

If this relationship is broken, the list is no longer circular.

### Incorrect Handling of a Single Node

When the list contains one node, that node points to itself.

Deleting it must correctly reset the list to its empty state.

### Incorrect Traversal Conditions

Waiting for `nullptr` can cause an infinite loop because the final node normally points back to the first node.

### Updating Pointers in the Wrong Order

Insertion and deletion must preserve valid links while the structure is being modified.

### Forgetting Memory Cleanup

Every dynamically allocated node must eventually be released.

A destructor or a dedicated cleanup operation should safely release all remaining nodes.

---

## Summary

A Circular Linked List is a dynamic data structure in which the final node points back to the first node.

This structure is useful for applications that require repeated cyclic traversal, including round-robin scheduling and circular queues.

Implementing it in C++ provides practical experience with pointers, dynamic memory allocation, encapsulation, and edge-case handling.

A reliable implementation must maintain the circular relationship after every insertion and deletion and release allocated memory when it is no longer needed.

---

## Resources

1. [GeeksforGeeks: Circular Linked List](https://www.geeksforgeeks.org/dsa/circular-linked-list/)
2. [Programiz: Circular Linked List](https://www.programiz.com/dsa/circular-linked-list)
3. [cppreference: `new` expression](https://en.cppreference.com/w/cpp/language/new)
4. [cppreference: `delete` expression](https://en.cppreference.com/w/cpp/language/delete)
5. [cppreference: Classes](https://en.cppreference.com/w/cpp/language/classes)

These resources provide additional explanations of circular linked lists, C++ classes, dynamic allocation, and memory deallocation.