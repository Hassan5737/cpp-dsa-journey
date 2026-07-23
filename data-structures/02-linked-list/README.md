# Singly Linked List

## Table of Contents

1. Introduction
2. What Is a Linked List?
3. Why Do We Need Linked Lists?
4. Structure of a Node
5. Memory Layout
6. Head Pointer
7. Singly Linked List
8. Creating a Linked List
9. Basic Operations
10. Time Complexity
11. Advantages
12. Disadvantages
13. Summary

---

# Introduction

A Linked List is one of the most fundamental linear data structures in computer science.

Unlike arrays, linked lists do not store elements in contiguous memory locations. Instead, each element (called a **node**) contains both data and a pointer to the next node.

Understanding linked lists is essential because they introduce dynamic memory allocation and pointer manipulation, which are core concepts in systems programming and many advanced data structures.

---

# What Is a Linked List?

A linked list is a linear collection of nodes connected together through pointers.

Each node stores:

- A value (data)
- A pointer to the next node

Unlike arrays, elements are connected logically rather than physically.

Example:

```text
Head
 │
 ▼
+--------+      +--------+      +--------+
|  10    | ---> |  20    | ---> |  30    | ---> nullptr
+--------+      +--------+      +--------+
```

---

# Why Do We Need Linked Lists?

Arrays have several limitations.

- Their size is fixed after creation.
- Inserting or deleting elements is expensive because many elements may need to be shifted.
- They require contiguous memory.

Linked lists solve these problems by allocating memory dynamically.

Advantages include:

- Dynamic size
- Efficient insertion
- Efficient deletion
- Flexible memory usage

---

# Structure of a Node

Each node consists of two parts.

```cpp
class Node
{
public:
    int value;
    Node* next;
};
```

The first member stores the actual data.

The second member stores the address of the next node.

---

# Memory Layout

Unlike arrays, linked list nodes are not stored next to each other in memory.

Example:

```text
Memory

0x1050
+--------+
|  20    |
| 0x4000 |
+--------+

0x4000
+--------+
|  30    |
| 0x8000 |
+--------+

0x8000
+--------+
|  40    |
| nullptr|
+--------+
```

The nodes can exist anywhere in memory.

Pointers connect them together.

---

# Head Pointer

The **head** is a pointer that stores the address of the first node.

```text
Head
 │
 ▼
+--------+      +--------+      +--------+
|  10    | ---> |  20    | ---> |  30    | ---> nullptr
+--------+      +--------+      +--------+
```

If the head is `nullptr`, the linked list is empty.

```cpp
Node* head = nullptr;
```

---

# Singly Linked List

A Singly Linked List allows movement in only one direction.

```text
Head
 │
 ▼
10 ---> 20 ---> 30 ---> nullptr
```

Each node only knows the location of the next node.

There is no way to move backwards.

---

# Creating a Linked List

The first node becomes the head.

```text
Before

Head
 │
 ▼
nullptr
```

After inserting the first node:

```text
Head
 │
 ▼
+--------+
|   10   |
|nullptr |
+--------+
```

Every additional node is connected using the `next` pointer.

---

# Basic Operations

## Insert at Beginning

Before

```text
Head
 │
 ▼
10 ---> 20 ---> 30
```

After

```text
Head
 │
 ▼
5 ---> 10 ---> 20 ---> 30
```

---

## Insert at End

Before

```text
10 ---> 20 ---> nullptr
```

After

```text
10 ---> 20 ---> 30 ---> nullptr
```

---

## Delete from Beginning

Before

```text
Head
 │
 ▼
10 ---> 20 ---> 30
```

After

```text
Head
 │
 ▼
20 ---> 30
```

---

## Delete from End

Before

```text
10 ---> 20 ---> 30
```

After

```text
10 ---> 20
```

---

## Delete by Value

Before

```text
10 ---> 20 ---> 30 ---> 40
```

Delete:

```text
30
```

After

```text
10 ---> 20 ---> 40
```

---

## Traversal

Traversal means visiting every node exactly once.

```text
Head
 │
 ▼
10 ---> 20 ---> 30 ---> nullptr
```

Visit order:

```text
10

20

30
```

Traversal continues until reaching `nullptr`.

---

# Time Complexity

| Operation | Complexity |
|-----------|-----------:|
| Access by Index | O(n) |
| Search | O(n) |
| Insert at Beginning | O(1) |
| Insert at End* | O(n) |
| Delete from Beginning | O(1) |
| Delete from End | O(n) |
| Delete by Value | O(n) |
| Traversal | O(n) |

> *Insert at End becomes **O(1)** if a tail pointer is maintained.

---

# Advantages

- Dynamic size
- Efficient insertion at the beginning
- Efficient deletion at the beginning
- No contiguous memory requirement
- Memory is allocated only when needed

---

# Disadvantages

- Extra memory is required for pointers
- Sequential access only
- No direct indexing
- Poor cache locality compared to arrays
- Reverse traversal is not possible in a singly linked list

---

# Summary

A Singly Linked List is a dynamic linear data structure built from nodes connected through pointers.

Compared to arrays, it provides more flexibility for insertion and deletion while sacrificing direct indexing and cache efficiency.

Mastering linked lists is an important step because many advanced data structures—such as stacks, queues, hash tables, graphs, and trees—rely on the same pointer-based concepts.