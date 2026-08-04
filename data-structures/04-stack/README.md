# Stack

## Table of Contents

1. Introduction
2. What Is a Stack?
3. The LIFO Principle
4. Memory Representation
5. Common Operations
6. Time Complexity
7. Stack Overflow
8. Stack Underflow
9. Array-Based vs Linked List-Based Stack
10. Advantages
11. Disadvantages
12. Real-World Applications
13. Summary
14. References

---

## Introduction

A Stack is one of the most fundamental linear data structures in computer science. It stores elements in a specific order where insertion and deletion are performed from the same end, known as the **top** of the stack.

Unlike arrays or linked lists, a stack restricts how data can be accessed and modified. This behavior follows the **Last In, First Out (LIFO)** principle, making it ideal for problems that require reversing order or tracking the most recently added element.

Stacks are widely used in software engineering, operating systems, compilers, expression evaluation, recursion, browser navigation, and many other real-world applications.

This module implements a stack completely from scratch in C++, without relying on the Standard Template Library (STL), in order to understand how the data structure works internally.

---

## What Is a Stack?

A Stack is a linear data structure in which elements are added and removed only from the **top**.

The two primary operations are:

- **Push** — Inserts a new element onto the top of the stack.
- **Pop** — Removes the element currently at the top.

Unlike queues, arrays, or linked lists, elements cannot be inserted or removed from the middle of a stack.

This restriction makes the implementation simple, efficient, and suitable for many algorithmic problems.

A stack maintains a single access point, ensuring that only the most recently inserted element can be accessed or removed first.

---

## The LIFO Principle

A Stack follows the **Last In, First Out (LIFO)** principle.

This means that the most recently inserted element is always the first one to be removed.

For example:

```text
Push(10)
Push(20)
Push(30)
Push(40)

Top
 │
 ▼
+-----+
| 40  |
+-----+
| 30  |
+-----+
| 20  |
+-----+
| 10  |
+-----+
```

If we perform one `pop()` operation:

```text
Pop()

Top
 │
 ▼
+-----+
| 30  |
+-----+
| 20  |
+-----+
| 10  |
+-----+
```

The value **40** is removed because it was the last element inserted into the stack.

This behavior is the exact opposite of a Queue, which follows the **First In, First Out (FIFO)** principle.

---

## Memory Representation

In this module, the stack is implemented using a fixed-size array.

A variable named `top` keeps track of the current top element.

Initially:

```text
top = -1
```

which indicates that the stack is empty.

After pushing four values:

```text
Index

 4  +-----+
    |     |
    +-----+
 3  | 40  |  ← Top
    +-----+
 2  | 30  |
    +-----+
 1  | 20  |
    +-----+
 0  | 10  |
    +-----+
```

The `top` variable always points to the last inserted element.

Whenever a new value is pushed, `top` is incremented.

Whenever an element is popped, `top` is decremented.

This makes both operations extremely efficient because no existing elements need to be shifted.

---

## Common Operations

A stack supports a small set of operations, all of which are performed at the **top** of the stack.

### Push

Adds a new element to the top of the stack.

```text
Before Push(40)

Top
 │
 ▼
+-----+
| 30  |
+-----+
| 20  |
+-----+
| 10  |
+-----+

After Push(40)

Top
 │
 ▼
+-----+
| 40  |
+-----+
| 30  |
+-----+
| 20  |
+-----+
| 10  |
+-----+
```

---

### Pop

Removes and returns the top element.

```text
Before Pop()

Top
 │
 ▼
+-----+
| 40  |
+-----+
| 30  |
+-----+
| 20  |
+-----+
| 10  |
+-----+

Removed: 40

Top
 │
 ▼
+-----+
| 30  |
+-----+
| 20  |
+-----+
| 10  |
+-----+
```

---

### Peek

Returns the value at the top of the stack without removing it.

```text
Top
 │
 ▼
+-----+
| 40  | ← Peek
+-----+
| 30  |
+-----+
| 20  |
+-----+
| 10  |
+-----+
```

The stack remains unchanged after a `peek()` operation.

---

### Display

Traverses the stack from the top element down to the bottom.

Example output:

```text
40
30
20
10
```

---

### Utility Operations

Additional helper functions commonly provided by stack implementations include:

- `isEmpty()` — Checks whether the stack contains no elements.
- `isFull()` — Checks whether the stack has reached its maximum capacity.
- `size()` — Returns the number of elements currently stored.
- `clear()` — Removes all elements from the stack.

---

## Time Complexity

| Operation | Time Complexity |
|-----------|-----------------|
| Push | O(1) |
| Pop | O(1) |
| Peek | O(1) |
| isEmpty | O(1) |
| isFull | O(1) |
| Size | O(1)* |
| Display | O(n) |

> **Note**
>
> In this implementation, the size can be calculated in **O(1)** using the `top` index:
>
> ```cpp
> size = top + 1;
> ```
>
> Display requires visiting every element in the stack, resulting in **O(n)** time complexity.

---

## Stack Overflow

A **Stack Overflow** occurs when attempting to push a new element into a stack that has already reached its maximum capacity.

For an array-based implementation:

```cpp
if (top == CAPACITY - 1)
```

the stack is full, and no additional elements can be inserted.

Attempting to push another value should be prevented to avoid writing beyond the array bounds.

---

## Stack Underflow

A **Stack Underflow** occurs when attempting to remove or access an element from an empty stack.

For example:

```cpp
pop();
peek();
```

Both operations are invalid when:

```cpp
top == -1
```

A robust implementation should always check whether the stack is empty before performing these operations.

---

## Array-Based vs Linked List-Based Stack

Stacks can be implemented using either an array or a linked list. Each approach has its own advantages and trade-offs.

| Feature | Array-Based Stack | Linked List-Based Stack |
|---------|-------------------|--------------------------|
| Memory Allocation | Fixed Size | Dynamic |
| Overflow | Possible | Only when memory is exhausted |
| Push | O(1) | O(1) |
| Pop | O(1) | O(1) |
| Peek | O(1) | O(1) |
| Memory Overhead | Lower | Higher |
| Implementation | Simpler | More Flexible |

An array-based stack is simple, cache-friendly, and efficient when the maximum size is known in advance.

A linked list-based stack grows dynamically and avoids fixed-size limitations, making it more suitable when the required capacity is unknown.

---

## Advantages

The Stack data structure offers several important benefits.

- Simple and efficient implementation.
- Constant-time insertion and removal.
- Ideal for solving recursive and backtracking problems.
- Efficient memory access in array-based implementations.
- Widely supported across programming languages and systems.

---

## Disadvantages

Despite its simplicity, a stack also has limitations.

- Only the top element is directly accessible.
- Searching for an element requires traversing the stack.
- Array-based implementations have a fixed capacity.
- Overflow and underflow conditions must be handled carefully.

---

## Real-World Applications

Stacks are used extensively in software engineering and computer science.

Some common applications include:

- Function call management (Call Stack).
- Recursive algorithms.
- Expression evaluation.
- Parentheses matching.
- Undo and redo functionality.
- Browser navigation history.
- Backtracking algorithms.
- Depth-First Search (DFS).
- Syntax parsing in compilers.
- Memory management within program execution.

---

## Summary

A Stack is a fundamental linear data structure that follows the **Last In, First Out (LIFO)** principle.

It provides efficient insertion and removal operations while restricting access to the top element only.

In this module, the stack is implemented from scratch using a fixed-size array to reinforce the core concepts behind stack operations, memory representation, overflow, underflow, and time complexity.

Understanding stacks provides a strong foundation for studying more advanced data structures and algorithms, including queues, recursion, expression evaluation, graph traversal, and tree traversal.

---

## References

- Thomas H. Cormen, *Introduction to Algorithms*
- Robert Lafore, *Data Structures and Algorithms in C++*
- Bjarne Stroustrup, *Programming: Principles and Practice Using C++*
- GeeksforGeeks – Stack Data Structure
- cppreference.com
