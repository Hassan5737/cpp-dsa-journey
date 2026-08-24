# Queue Using a Singly Linked List

## Table of Contents

1. [Introduction](#introduction)
2. [What Is a Queue?](#what-is-a-queue)
3. [FIFO Principle](#fifo-principle)
4. [Why Use a Linked List?](#why-use-a-linked-list)
5. [Queue Structure](#queue-structure)
6. [Core Operations](#core-operations)
   - [Enqueue](#enqueue)
   - [Dequeue](#dequeue)
   - [Peek](#peek)
   - [Is Empty](#is-empty)
   - [Display](#display)
7. [Time Complexity](#time-complexity)
8. [Space Complexity](#space-complexity)
9. [Memory Management](#memory-management)
10. [Array-Based vs Linked List-Based Queue](#array-based-vs-linked-list-based-queue)
11. [Advantages](#advantages)
12. [Disadvantages](#disadvantages)
13. [Edge Cases](#edge-cases)
14. [Real-World Applications](#real-world-applications)
15. [Implementation Approach](#implementation-approach)
16. [Summary](#summary)
17. [References](#references)

---

## Introduction

A **Queue** is a fundamental linear data structure that follows the **FIFO (First In, First Out)** principle.

Unlike a fixed-size array-based Queue, a Queue can also be implemented using a **Singly Linked List**, allowing the structure to grow and shrink dynamically as elements are added and removed.

In this module, the Queue is implemented completely from scratch in C++ using dynamically allocated nodes.

The implementation focuses on understanding:

- FIFO behavior
- Singly Linked List integration
- Dynamic memory allocation
- Pointer manipulation
- Front and Rear management
- Enqueue and Dequeue operations
- Memory deallocation
- Edge cases
- Time and space complexity
- Object-oriented design

The goal is not only to implement the Queue, but to understand how the same abstract data structure can be implemented using a different underlying storage mechanism.

---

## What Is a Queue?

A Queue is a linear data structure in which:

- Elements are inserted from the **Rear**
- Elements are removed from the **Front**

This behavior follows the FIFO principle.

For example:

```text
Front                           Rear
  ↓                               ↓
[ 10 ] → [ 20 ] → [ 30 ] → [ 40 ]
```

If we remove an element:

```text
dequeue()
```

The element `10` is removed first.

The Queue becomes:

```text
Front                    Rear
  ↓                        ↓
[ 20 ] → [ 30 ] → [ 40 ]
```

The first element inserted is always the first element removed.

---

## FIFO Principle

FIFO stands for:

**First In, First Out**

Consider the following operations:

```text
enqueue(10)
enqueue(20)
enqueue(30)
enqueue(40)
```

The Queue becomes:

```text
Front                           Rear
  ↓                               ↓
[ 10 ] → [ 20 ] → [ 30 ] → [ 40 ]
```

The removal order will be:

```text
10 → 20 → 30 → 40
```

This is what makes a Queue different from a Stack.

### Queue

```text
First In → First Out
```

### Stack

```text
Last In → First Out
```

The Queue therefore processes elements in the same order in which they
entered the structure.

---

## Why Use a Linked List?

A Queue can be implemented using several underlying data structures.

One common approach is an array.

However, a fixed-size array introduces a capacity limitation.

For example:

```text
[ 10 ][ 20 ][ 30 ][ 40 ][ 50 ]
```

Once the allocated capacity is reached, no additional elements can be added
without resizing or using another strategy.

A Singly Linked List provides dynamic memory allocation.

Instead of allocating a fixed number of elements, each new element is stored
inside a dynamically allocated node.

For example:

```text
Front
  ↓
[ 10 | • ] → [ 20 | • ] → [ 30 | nullptr ]
                                      ↑
                                     Rear
```

The Queue can therefore grow as long as sufficient memory is available.

---

## Queue Structure

The Queue implemented in this module uses two pointers:

```text
front
rear
```

### Front

`front` points to the first node in the Queue.

It identifies the element that will be removed by the next `dequeue()`.

### Rear

`rear` points to the last node in the Queue.

It identifies where the next element will be inserted.

Example:

```text
front                         rear
  ↓                             ↓
[ 10 | • ] → [ 20 | • ] → [ 30 | nullptr ]
```

This design allows both insertion and removal to be performed efficiently.

---

## Core Operations

The Queue implementation provides the following operations:

| Operation | Description | Time Complexity |
|-----------|-------------|-----------------|
| `enqueue()` | Adds an element to the Rear | O(1) |
| `dequeue()` | Removes an element from the Front | O(1) |
| `peek()` | Returns the Front element | O(1) |
| `isEmpty()` | Checks whether the Queue is empty | O(1) |
| `display()` | Displays all elements | O(n) |

---

## Enqueue

The `enqueue()` operation adds a new element to the Rear of the Queue.

A new node is dynamically allocated and connected to the current Rear.

### Empty Queue

If the Queue is empty:

```text
front = nullptr
rear  = nullptr
```

The new node becomes both the Front and Rear.

Before:

```text
front = nullptr
rear  = nullptr
```

After:

```text
front
  ↓
[ 10 | nullptr ]
  ↑
 rear
```

Both pointers point to the same node.

### Non-Empty Queue

If the Queue already contains elements:

```text
front                         rear
  ↓                             ↓
[ 10 | • ] → [ 20 | nullptr ]
```

After:

```text
enqueue(30)
```

The new node is connected after the current Rear:

```text
front                                  rear
  ↓                                      ↓
[ 10 | • ] → [ 20 | • ] → [ 30 | nullptr ]
```

Then `rear` is updated to point to the new node.

### Complexity

`enqueue()` runs in:

```text
O(1)
```

Because the Queue maintains a direct pointer to the Rear, no traversal is
required.

---

## Dequeue

The `dequeue()` operation removes the element at the Front.

Example:

```text
front                         rear
  ↓                             ↓
[ 10 | • ] → [ 20 | • ] → [ 30 | nullptr ]
```

After:

```text
dequeue()
```

The first node is removed:

```text
front                  rear
  ↓                      ↓
[ 20 | • ] → [ 30 | nullptr ]
```

The old Front node must be deleted from memory after moving `front` to the
next node.

### Single-Element Case

If the Queue contains only one node:

```text
front
  ↓
[ 10 | nullptr ]
  ↑
 rear
```

After removing it, both pointers must become `nullptr`:

```text
front = nullptr
rear  = nullptr
```

This correctly restores the empty Queue state.

### Complexity

`dequeue()` runs in:

```text
O(1)
```

because the Front node can be accessed directly.

---

## Peek

The `peek()` operation returns the value stored at the Front without removing
the element.

Example:

```text
front
  ↓
[ 10 | • ] → [ 20 | • ] → [ 30 | nullptr ]
```

Calling:

```text
peek()
```

returns:

```text
10
```

The Queue remains unchanged.

### Complexity

`peek()` runs in:

```text
O(1)
```

because the Front pointer provides direct access to the first element.

---

## Is Empty

The `isEmpty()` operation determines whether the Queue contains any elements.

A Queue implemented using Front and Rear pointers is empty when:

```text
front == nullptr
```

A consistent empty state should have:

```text
front = nullptr
rear  = nullptr
```

### Complexity

`isEmpty()` runs in:

```text
O(1)
```

---

## Display

The `display()` operation traverses the linked list starting from the Front.

Example:

```text
front
  ↓
[ 10 ] → [ 20 ] → [ 30 ] → nullptr
```

The traversal visits each node:

```text
10 20 30
```

Because every node must be visited, the operation takes:

```text
O(n)
```

where `n` is the number of elements in the Queue.

---

## Time Complexity

The main Queue operations have the following complexity:

| Operation | Time Complexity |
|-----------|-----------------|
| `enqueue()` | O(1) |
| `dequeue()` | O(1) |
| `peek()` | O(1) |
| `isEmpty()` | O(1) |
| `display()` | O(n) |

The constant-time performance of `enqueue()` is achieved by maintaining a
direct pointer to the Rear.

Without a Rear pointer, inserting at the end of a Singly Linked List would
require traversing the entire list.

That would make insertion:

```text
O(n)
```

Maintaining both Front and Rear pointers is therefore an important design
decision.

---

## Space Complexity

The Queue requires one dynamically allocated node for every stored element.

For `n` elements:

```text
Space Complexity = O(n)
```

Each node contains:

- The stored data
- A pointer to the next node

Unlike an array-based Queue with a predefined capacity, the linked-list-based
implementation allocates memory as elements are inserted.

---

## Memory Management

Because the Queue uses dynamically allocated nodes, memory management is an
important part of the implementation.

When a new element is inserted:

```text
new Node
```

allocates memory dynamically.

When an element is removed:

```text
delete node
```

releases the memory occupied by that node.

For example:

```text
Before dequeue:

front
  ↓
[ 10 | • ] → [ 20 | nullptr ]

After dequeue:

front
  ↓
[ 20 | nullptr ]

The old node containing 10 has been deleted.
```

Proper memory management prevents memory leaks.

The implementation must ensure that every dynamically allocated node is
eventually released.

---

## Array-Based vs Linked List-Based Queue

Both implementations provide the same Queue abstraction, but they use
different underlying storage mechanisms.

| Feature | Array-Based Queue | Linked List-Based Queue |
|---------|-------------------|--------------------------|
| Storage | Array | Nodes |
| Capacity | Fixed in simple implementation | Dynamic |
| Memory allocation | Contiguous | Dynamic per node |
| Growth | Limited by capacity | Can grow dynamically |
| Memory overhead | Lower per element | Extra pointer per node |
| Cache locality | Generally better | Generally worse |
| Enqueue | O(1) | O(1) |
| Dequeue | O(1) | O(1) |
| Random access | Possible | Not efficient |
| Implementation complexity | Relatively simple | Pointer management required |

The choice depends on the requirements of the application.

---

## Advantages

### 1. Dynamic Size

The Queue does not require a fixed capacity.

New nodes can be allocated as needed.

### 2. Efficient Enqueue

Because the implementation maintains a Rear pointer:

```text
enqueue() → O(1)
```

No traversal is necessary.

### 3. Efficient Dequeue

The Front pointer provides direct access to the first element:

```text
dequeue() → O(1)
```

### 4. No Fixed Array Capacity

The Queue is not restricted by a predefined array size.

Its practical limit is the available memory.

### 5. Efficient Memory Usage for Sparse Queues

Memory is allocated only when nodes are actually inserted.

---

## Disadvantages

### 1. Extra Memory Per Node

Every node stores a pointer in addition to the actual data.

This increases memory overhead compared with a simple array.

### 2. Dynamic Allocation Overhead

Each insertion may require a dynamic memory allocation.

This can be more expensive than using preallocated contiguous memory.

### 3. Poorer Cache Locality

Linked List nodes are not necessarily stored next to each other in memory.

This can result in poorer cache performance compared with arrays.

### 4. Pointer Management

The implementation requires careful pointer manipulation.

Incorrect pointer updates can lead to:

- Lost nodes
- Memory leaks
- Dangling pointers
- Invalid memory access

### 5. No Direct Access

Unlike an array, linked-list nodes cannot be accessed efficiently by index.

To reach an arbitrary node, traversal is required.

---

## Edge Cases

A robust Queue implementation must handle several important edge cases.

### Empty Queue

Operations such as `dequeue()` and `peek()` must handle an empty Queue safely.

```text
front = nullptr
rear  = nullptr
```

### Single Element

When the Queue contains one element:

```text
front == rear
```

After removing that element:

```text
front = nullptr
rear  = nullptr
```

### Multiple Elements

The Front and Rear pointers must always reference the correct nodes.

### Dequeue Until Empty

After removing the final element, the Queue must return to a valid empty
state.

### Reuse After Becoming Empty

The Queue should continue working correctly after becoming empty and then
receiving new elements.

For example:

```text
enqueue(10)
dequeue()
enqueue(20)
```

The new element should correctly become both Front and Rear.

---

## Real-World Applications

Queues are widely used in software systems where tasks must be processed in
the order they arrive.

### 1. Print Queues

Print jobs can wait in a Queue until the printer is ready.

```text
Job 1 → Job 2 → Job 3 → Job 4
```

The first submitted job is processed first.

### 2. CPU Scheduling

Operating systems can use Queue-based structures to manage processes waiting
for execution.

### 3. Network Requests

Servers may use Queues to manage incoming requests waiting to be processed.

### 4. Breadth-First Search

The Queue is a fundamental component of the **Breadth-First Search (BFS)**
algorithm.

Vertices are processed in the order they are discovered.

### 5. Task Processing Systems

Background workers can process tasks from a Queue.

### 6. Message Processing

Messaging systems can use Queue-based structures to manage messages waiting
to be processed.

---

## Implementation Approach

The implementation in this module follows a simple design based on a Singly
Linked List.

Each node contains:

```text
data
next
```

The Queue maintains:

```text
front
rear
```

The main invariants are:

### Empty Queue

```text
front == nullptr
rear  == nullptr
```

### Non-Empty Queue

```text
front != nullptr
rear  != nullptr
```

### Enqueue

1. Allocate a new node.
2. Store the value inside the node.
3. If the Queue is empty, make both Front and Rear point to the new node.
4. Otherwise, connect the current Rear to the new node.
5. Move Rear to the new node.

### Dequeue

1. Check whether the Queue is empty.
2. Store the current Front node.
3. Move Front to the next node.
4. If the Queue becomes empty, reset Rear to `nullptr`.
5. Delete the old Front node.

### Peek

1. Check whether the Queue is empty.
2. Return the value stored at Front.

This design keeps the core Queue operations efficient while demonstrating
how pointers and dynamic memory work together.

---

## Summary

A Queue is a fundamental linear data structure based on the FIFO principle.

When implemented using a Singly Linked List, the Queue uses dynamically
allocated nodes instead of a fixed-size array.

The implementation maintains two important pointers:

```text
front
rear
```

These pointers allow the Queue to perform its core operations efficiently:

```text
enqueue() → O(1)
dequeue() → O(1)
peek()    → O(1)
isEmpty() → O(1)
display() → O(n)
```

The Linked List-based implementation provides dynamic growth and avoids the
fixed-capacity limitation of a simple array-based Queue.

However, this flexibility comes with additional memory overhead, dynamic
allocation costs, and pointer-management complexity.

The most important lesson from this module is that the **Queue abstraction**
does not depend on one specific implementation.

The same FIFO behavior can be implemented using different underlying data
structures, and each implementation introduces different trade-offs.

Understanding these trade-offs is an important part of learning Data
Structures and developing stronger software engineering fundamentals.

---

## References

- [cppreference — Containers Library](https://en.cppreference.com/w/cpp/container)
- [GeeksforGeeks — Queue Data Structure](https://www.geeksforgeeks.org/queue-data-structure/)
- [Programiz — Queue Data Structure](https://www.programiz.com/dsa/queue)
- [cppreference — Dynamic Memory Management](https://en.cppreference.com/w/cpp/memory)