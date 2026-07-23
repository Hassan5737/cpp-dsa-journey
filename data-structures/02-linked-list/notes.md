# Singly Linked List Cheat Sheet

## Definition

A Singly Linked List is a linear data structure consisting of nodes, where each node stores a value and a pointer to the next node.

---

# Node Structure

```cpp
class Node
{
public:
    int value;
    Node* next;
};
```

Each node contains:

- Data
- Pointer to the next node

---

# Head Pointer

The head pointer stores the address of the first node.

```text
Head
 │
 ▼
10 -> 20 -> 30 -> nullptr
```

If:

```cpp
head == nullptr
```

the linked list is empty.

---

# Memory Layout

Unlike arrays, linked list nodes are **not stored contiguously** in memory.

Nodes are connected using pointers.

---

# Operations

## Insert at Front

```cpp
list.insertFront(value);
```

Complexity:

```
O(1)
```

---

## Insert at Back

```cpp
list.insertBack(value);
```

Complexity:

```
O(n)
```

---

## Delete Front

```cpp
list.deleteFront();
```

Complexity:

```
O(1)
```

---

## Delete Back

```cpp
list.deleteBack();
```

Complexity:

```
O(n)
```

---

## Delete by Value

```cpp
list.deleteByValue(value);
```

Complexity:

```
O(n)
```

---

## Search

```cpp
list.contains(value);
```

Complexity:

```
O(n)
```

---

## Print

```cpp
list.print();
```

Complexity:

```
O(n)
```

---

## Clear

```cpp
list.clear();
```

Complexity:

```
O(n)
```

---

## Size

```cpp
list.size();
```

Complexity:

```
O(1)
```

---

## Is Empty

```cpp
list.isEmpty();
```

Complexity:

```
O(1)
```

---

# Complexity Summary

| Operation | Complexity |
|-----------|-----------:|
| Access by Index | O(n) |
| Search | O(n) |
| Insert at Front | O(1) |
| Insert at Back | O(n) |
| Delete Front | O(1) |
| Delete Back | O(n) |
| Delete by Value | O(n) |
| Traversal | O(n) |
| Size | O(1) |

---

# Advantages

- Dynamic size
- Efficient insertion at the beginning
- Efficient deletion at the beginning
- Does not require contiguous memory
- Memory is allocated only when needed

---

# Disadvantages

- No random access
- Sequential traversal only
- Extra memory for pointers
- Poor cache locality
- Reverse traversal is not possible

---

# Comparison with Arrays

| Feature | Array | Singly Linked List |
|---------|------:|-------------------:|
| Memory | Contiguous | Non-contiguous |
| Size | Fixed | Dynamic |
| Access | O(1) | O(n) |
| Insert at Front | O(n) | O(1) |
| Delete at Front | O(n) | O(1) |
| Insert at End | O(1)* | O(n)** |

> *When capacity is available.  
> **Without maintaining a tail pointer.

---

# Interview Tips

Remember the following:

- The first node is referenced by `head`.
- The last node always points to `nullptr`.
- Traversal always starts from `head`.
- Every node stores exactly one pointer in a singly linked list.
- You cannot move backwards in a singly linked list.

---

# Key Takeaways

- Linked lists are dynamic data structures.
- Nodes are connected through pointers.
- Insertion and deletion at the beginning are very efficient.
- Random access is not supported.
- They are a fundamental building block for stacks, queues, graphs, hash tables, and many other data structures.