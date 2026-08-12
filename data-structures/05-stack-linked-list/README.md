# Stack Using a Singly Linked List

## Table of Contents

1. Introduction
2. What Is a Stack?
3. Implementing a Stack Using a Linked List
4. The LIFO Principle
5. Stack Structure
6. Core Operations
7. Time Complexity
8. Memory Management
9. Array-Based vs Linked List-Based Stack
10. Advantages
11. Disadvantages
12. Real-World Applications
13. Summary
14. References

---

## Introduction

A Stack is a fundamental linear data structure that follows the **Last In, First Out (LIFO)** principle.

In the previous Stack module, the data structure was implemented using a fixed-size array. In this module, the same Stack concept is implemented using a **Singly Linked List**.

This implementation provides a different approach to managing the stack's memory. Instead of relying on a fixed-size array, each stack element is stored inside a dynamically allocated node.

The goal of this module is to understand how the Stack abstraction can be built on top of a linked list while practicing:

* Dynamic memory allocation
* Pointer manipulation
* Node-based data structures
* Stack operations
* Memory management
* Edge-case handling
* Time complexity analysis

The implementation is built from scratch in C++ without using the Standard Template Library (STL).

---

## What Is a Stack?

A Stack is a linear data structure in which elements are inserted and removed from one end called the **top**.

It follows the:

> **Last In, First Out (LIFO)** principle.

This means that the most recently inserted element is the first element to be removed.

For example:

```text
Push(10)
Push(20)
Push(30)

       TOP
        ↓
    +-------+
    |  30   |
    +-------+
    |  20   |
    +-------+
    |  10   |
    +-------+
```

If we perform:

```cpp
pop();
```

the value `30` is removed first because it was the last element inserted.

After the operation:

```text
       TOP
        ↓
    +-------+
    |  20   |
    +-------+
    |  10   |
    +-------+
```

The Stack therefore provides controlled access to data through its top element rather than allowing arbitrary insertion and deletion.


---

## Implementing a Stack Using a Linked List

A Stack can be implemented using a Singly Linked List by treating the **head of the linked list as the top of the stack**.

Each stack element is represented by a dynamically allocated node containing:

- The stored value.
- A pointer to the next node.

The basic node structure is:

```cpp
struct Node
{
    int data;
    Node* next;
};
```

The stack maintains a pointer called `top`:

```cpp
Node* top = nullptr;
```

When the stack is empty:

```text
top
 ↓
nullptr
```

When elements are added, each new node is inserted at the beginning of the linked list.

For example, after:

```cpp
push(10);
push(20);
push(30);
```

the structure becomes:

```text
             TOP
              ↓
        +-----------+
        |    30     |
        |  next ──────────┐
        +-----------+     │
                          ↓
        +-----------+  +-----------+
        |    20     |  |    10     |
        |  next ──────────┐       |
        +-----------+     │       |
                          ↓       ↓
                       nullptr
```

Conceptually:

```text
top → 30 → 20 → 10 → nullptr
```

The most recently inserted element is always located at `top`.

This allows the main Stack operations to be performed at the beginning of the linked list.

---

## Why Use the Beginning of the Linked List?

A Stack requires insertion and removal from the same end.

Using the beginning of the linked list as the top provides constant-time operations.

### Push

A new node is inserted before the current `top`:

```text
Before:

top → 30 → 20 → 10 → nullptr


Push(40)


After:

top → 40 → 30 → 20 → 10 → nullptr
```

The new node becomes the new top of the stack.

The operation takes **O(1)** time because no traversal is required.

---

### Pop

The node currently pointed to by `top` is removed:

```text
Before:

top → 40 → 30 → 20 → 10 → nullptr


Pop()


After:

top → 30 → 20 → 10 → nullptr
```

The old top node is then released from memory.

This operation also takes **O(1)** time.

---

## The LIFO Principle

The Stack follows the **Last In, First Out (LIFO)** principle.

Consider the following sequence:

```cpp
push(10);
push(20);
push(30);
```

The resulting structure is:

```text
TOP
 ↓
30
20
10
```

The first `pop()` removes:

```text
30
```

The second `pop()` removes:

```text
20
```

The third `pop()` removes:

```text
10
```

Therefore:

```text
Last element inserted
        ↓
       30
        ↓
First element removed
```

This behavior is the defining characteristic of a Stack.

---

## Stack Structure

The linked-list implementation can be visualized as:

```text
                 Stack
                   │
                   ▼
                 top
                   │
                   ▼
              +---------+
              |   30    |
              |  next ─────────┐
              +---------+      │
                               ▼
              +---------+
              |   20    |
              |  next ─────────┐
              +---------+      │
                               ▼
              +---------+
              |   10    |
              |  next ────────► nullptr
              +---------+
```

The important relationship is:

```text
top → first node → second node → ... → nullptr
```

Unlike an array-based Stack, there is no fixed capacity defined by an array size.

Each new element requires allocating a new node dynamically.

---

## Empty Stack

When the Stack contains no elements:

```cpp
top == nullptr
```

The structure is:

```text
top
 ↓
nullptr
```

Operations such as `pop()` and `peek()` must check this condition before accessing the stack.

This prevents invalid pointer access and represents the **Stack Underflow** condition.


---

## Core Operations

The linked-list-based Stack supports the same fundamental Stack operations as the array-based implementation.

The main difference is how the elements are stored internally.

In this implementation, the `top` pointer always refers to the first node in the linked list.

---

### Push

The `push()` operation inserts a new element at the top of the Stack.

A new node is dynamically allocated, its value is stored, and its `next` pointer is connected to the current top.

The new node then becomes the new top.

Implementation:

```cpp
void push(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = top;

    top = newNode;
}
```

Before pushing:

```text
top → 30 → 20 → 10 → nullptr
```

After:

```cpp
push(40);
```

the structure becomes:

```text
top → 40 → 30 → 20 → 10 → nullptr
```

### Complexity

```text
Time:  O(1)
Space: O(1) auxiliary space
```

The operation does not require traversing the linked list.

---

### Pop

The `pop()` operation removes the element currently located at the top of the Stack.

First, the current top node is saved.

Then `top` is moved to the next node.

Finally, the old top node is released using `delete`.

Implementation:

```cpp
void pop()
{
    if (top == nullptr)
    {
        cout << "Stack Underflow." << endl;
        return;
    }

    Node* firstNode = top;

    top = firstNode->next;

    delete firstNode;
}
```

Before:

```text
top → 40 → 30 → 20 → 10 → nullptr
```

After `pop()`:

```text
top → 30 → 20 → 10 → nullptr
```

The removed node is no longer part of the Stack and its dynamically allocated memory is released.

### Complexity

```text
Time:  O(1)
Space: O(1) auxiliary space
```

---

### Peek

The `peek()` operation returns the value stored at the top of the Stack without removing it.

Implementation:

```cpp
int peek()
{
    if (top == nullptr)
    {
        cout << "Stack Underflow." << endl;
        return -1;
    }

    return top->data;
}
```

For:

```text
top → 30 → 20 → 10 → nullptr
```

calling:

```cpp
peek();
```

returns:

```text
30
```

The Stack remains unchanged:

```text
top → 30 → 20 → 10 → nullptr
```

### Complexity

```text
Time:  O(1)
Space: O(1)
```

---

### Display

The `display()` operation traverses the linked list starting from `top` and prints each element.

Implementation:

```cpp
void display()
{
    if (top == nullptr)
    {
        cout << "Stack is empty." << endl;
        return;
    }

    Node* current = top;

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    cout << '\n';
}
```

For:

```text
top → 30 → 20 → 10 → nullptr
```

the output is:

```text
30 20 10
```

The elements are displayed from **top to bottom**, which matches the natural representation of the Stack.

### Complexity

```text
Time:  O(n)
Space: O(1) auxiliary space
```

The entire linked list must be traversed to display all elements.

---

## Underflow

Stack Underflow occurs when an operation attempts to access or remove an element while the Stack is empty.

For the linked-list implementation, an empty Stack is represented by:

```cpp
top == nullptr
```

Therefore, operations such as `pop()` and `peek()` must verify this condition before accessing the node.

Example:

```cpp
if (top == nullptr)
{
    cout << "Stack Underflow." << endl;
    return;
}
```

This check prevents dereferencing a null pointer.

---

## Memory Management

Unlike the array-based implementation, the linked-list-based Stack allocates memory dynamically for every inserted element.

When pushing:

```cpp
Node* newNode = new Node;
```

a new node is allocated.

When popping:

```cpp
delete firstNode;
```

the removed node's dynamically allocated memory is released.

This is essential because every node created with `new` should eventually have its memory released with `delete`.

The lifetime of a node therefore follows the Stack operation that created and removed it:

```text
push()
  ↓
new
  ↓
Node becomes part of Stack
  ↓
pop()
  ↓
delete
  ↓
Memory released
```

Proper memory management prevents memory leaks and keeps the implementation safe and predictable.

---

## Time Complexity

One of the main advantages of implementing a Stack using a Singly Linked List is that the fundamental Stack operations remain constant-time operations.

| Operation | Time Complexity | Explanation |
|-----------|-----------------|-------------|
| `push()` | O(1) | Inserts a new node at the top |
| `pop()` | O(1) | Removes the node at the top |
| `peek()` | O(1) | Accesses the top node directly |
| `display()` | O(n) | Traverses all nodes |
| Empty check | O(1) | Checks whether `top == nullptr` |

The reason `push()`, `pop()`, and `peek()` are **O(1)** is that none of these operations require traversing the linked list.

The `top` pointer always provides direct access to the first node.

---

## Space Complexity

The linked-list implementation uses dynamic memory.

For `n` elements, the Stack requires:

```text
O(n)
```

space.

Each element is stored inside a separate node containing:

```text
data
next pointer
```

Therefore, unlike a fixed-size array, the memory usage grows as elements are added to the Stack.

---

## Array-Based vs Linked List-Based Stack

Both implementations provide the same Stack abstraction and follow the same LIFO principle, but their internal memory management is different.

| Feature | Array-Based Stack | Linked List-Based Stack |
|---------|-------------------|--------------------------|
| Storage | Fixed-size array | Dynamically allocated nodes |
| Capacity | Fixed | Dynamic |
| `push()` | O(1) | O(1) |
| `pop()` | O(1) | O(1) |
| `peek()` | O(1) | O(1) |
| Memory allocation | Fixed in advance | Allocated per node |
| Overflow | When capacity is reached | When memory allocation fails |
| Extra memory per element | Low | Pointer overhead per node |
| Memory layout | Contiguous | Non-contiguous |
| Resizing | Not available in fixed array | Not required |

---

## Choosing Between the Two Implementations

Neither implementation is universally better.

The appropriate choice depends on the requirements of the application.

### Array-Based Stack

An array-based Stack can be a good choice when:

- The maximum size is known.
- Predictable memory usage is important.
- Minimal per-element overhead is preferred.
- Contiguous memory provides better cache locality.

### Linked List-Based Stack

A linked-list-based Stack can be a good choice when:

- The number of elements is unpredictable.
- Dynamic growth is required.
- A fixed capacity is undesirable.
- The implementation needs to grow and shrink naturally.

---

## Advantages of the Linked List Implementation

### Dynamic Size

The Stack does not have a predefined capacity.

New nodes can be allocated as elements are pushed.

### Constant-Time Core Operations

The main Stack operations remain:

```text
push()  → O(1)
pop()   → O(1)
peek()  → O(1)
```

### No Fixed Array Capacity

The implementation does not need to reserve a fixed number of elements beforehand.

---

## Disadvantages of the Linked List Implementation

### Additional Memory Overhead

Every node stores a pointer in addition to its actual data.

```text
Node
├── data
└── next
```

### Dynamic Memory Allocation

Each `push()` requires dynamic allocation.

This introduces memory-management responsibilities that do not exist in the same way with a fixed-size array.

### Non-Contiguous Memory

Nodes may be located in different areas of memory, which can result in poorer cache locality compared with an array.

---

## Key Takeaways

The important idea is that the **Stack is an abstraction**, while the linked list is simply one possible way to implement it.

The Stack still follows:

```text
LIFO
```

regardless of whether its internal storage uses:

```text
Array
```

or:

```text
Singly Linked List
```

With the linked-list implementation, the beginning of the list becomes the top of the Stack:

```text
top → Node → Node → Node → nullptr
```

This design allows insertion and removal from the top in **O(1)** time while providing dynamic memory usage.

---

## Summary

A Stack implemented using a Singly Linked List combines two fundamental data structure concepts:

1. The **LIFO behavior** of a Stack.
2. The **dynamic node-based structure** of a Singly Linked List.

The implementation demonstrates how different data structures can be combined to create a new abstraction while preserving efficient operations.

The most important operations are:

```text
push()  → O(1)
pop()   → O(1)
peek()  → O(1)
```

The main trade-off compared with an array-based Stack is between **dynamic capacity** and **additional memory overhead per node**.

---

## Real-World Applications

Stacks are widely used in software systems because many problems naturally require
**Last In, First Out** behavior.

Some common applications include:

### Function Calls and Recursion

Programming languages use stack-based mechanisms to manage function calls,
local variables, and return information.

When a function calls another function, the most recent call must be completed
before execution returns to the previous one.

---

### Undo and Redo Systems

Applications such as text editors can use stacks to keep track of previous
actions.

For example:

```text
Action 1
   ↓
Action 2
   ↓
Action 3
```

Undoing the latest action removes `Action 3` first.

---

### Expression Evaluation

Stacks are commonly used when processing mathematical and logical expressions,
including tasks such as:

- Parentheses matching
- Infix-to-postfix conversion
- Postfix expression evaluation

---

### Backtracking

Backtracking algorithms can use a Stack to keep track of previous states.

This is useful in problems such as:

- Maze solving
- Depth-First Search
- State exploration
- Combinatorial problems

---

### Browser Navigation

A stack-like structure can be used to model navigation history.

When navigating backward, the most recently visited page is processed first.

---

## What I Learned

Implementing a Stack using a Singly Linked List reinforced several important
concepts:

- How an abstract data structure can have multiple implementations.
- How a linked list can be used as the underlying storage for a Stack.
- Why the top of the Stack should correspond to the beginning of the linked list.
- How pointer manipulation enables constant-time `push()` and `pop()` operations.
- How dynamic memory allocation and deallocation work together.
- Why memory management is an important part of low-level C++ programming.
- How implementation choices introduce different performance and memory trade-offs.

The most important takeaway is that the Stack's behavior is defined by its
**LIFO abstraction**, not by the specific data structure used to implement it.

---

## Repository Structure

```text
05-stack-linked-list/
│
├── README.md
├── implementation.cpp
├── notes.md
├── mistakes.md
├── exercises.md
└── examples.cpp
```

---

## References

- NIST Dictionary of Algorithms and Data Structures — Stack
- Programiz — Stack Data Structure
- Baeldung — Stack Data Structure

---

## Next Step

This module is part of my ongoing **C++ Data Structures & Algorithms journey**.

The next modules will continue exploring fundamental data structures and their
different implementation strategies.

> Learn the concept.  
> Implement it from scratch.  
> Analyze it.  
> Document it.  
> Move forward.

