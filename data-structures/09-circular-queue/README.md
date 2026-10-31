# Circular Queue

A Circular Queue is a linear data structure that follows the **First In, First Out (FIFO)** principle while treating the last position of its underlying array as connected to the first position.

Unlike a traditional array-based queue, a Circular Queue reuses previously occupied positions after elements are removed. This avoids wasting available space when the rear pointer reaches the end of the array.

## Table of Contents

- [Overview](#overview)
- [How It Works](#how-it-works)
- [Circular Movement](#circular-movement)
- [Core Operations](#core-operations)
- [Full and Empty Conditions](#full-and-empty-conditions)
- [Time Complexity](#time-complexity)
- [Advantages and Disadvantages](#advantages-and-disadvantages)
- [Implementation Details](#implementation-details)
- [Common Pitfalls](#common-pitfalls)
- [Learning Objectives](#learning-objectives)
- [References](#references)

## Overview

A Circular Queue is an extension of the standard Queue data structure.

It uses two pointers:

- **Front:** Points to the first element available for removal.
- **Rear:** Points to the last inserted element.

The queue follows FIFO ordering, meaning the first element inserted is the first one removed.

The circular behavior allows the rear pointer to return to index `0` after reaching the last array position, provided that position is available.

## How It Works

Consider a Circular Queue with an array capacity of 5.

Initially, both pointers are set to `-1`, indicating that the queue is empty.

After inserting elements, the queue may look like this:

```text
Index:  0    1    2    3    4
       [10] [20] [30] [  ] [  ]
        F         R
```

After removing two elements and inserting new ones, available positions can be reused:

```text
Index:  0    1    2    3    4
       [60] [70] [30] [40] [50]
        R         F
```

The actual logical order starts at `front` and continues circularly until `rear`.

## Circular Movement

The circular behavior is achieved using the modulo operator `%`.

```cpp
rear = (rear + 1) % SIZE;
front = (front + 1) % SIZE;
```

This ensures that when a pointer reaches the last array index, its next position becomes index `0`.

For an array of size 5:

| Current Index | Next Index |
|---:|---:|
| 0 | 1 |
| 1 | 2 |
| 2 | 3 |
| 3 | 4 |
| 4 | 0 |

## Core Operations

### 1. Enqueue

Adds a new element to the rear of the queue.

Before insertion, the implementation checks whether the queue is full. If the queue is empty, both pointers are initialized to `0`. Otherwise, the rear pointer moves circularly.

### 2. Dequeue

Removes the front element.

If the queue contains only one element, both pointers are reset to `-1`. Otherwise, the front pointer moves to the next position circularly.

### 3. Peek

Returns the element at the front without removing it.

### 4. Display

Prints all elements starting from `front` and continues circularly until reaching `rear`.

### 5. isEmpty

Checks whether the queue contains no elements.

### 6. isFull

Checks whether inserting another element would make the rear pointer reach the front pointer.

## Full and Empty Conditions

This implementation uses the one-empty-slot approach.

**Empty condition:**

```cpp
front == -1 && rear == -1
```

**Full condition:**

```cpp
(rear + 1) % SIZE == front
```

This approach intentionally leaves one array position unused to distinguish between the full and empty states.

Therefore, the actual usable capacity is:

```text
Usable Capacity = SIZE - 1
```

For an array of size 5, the queue can store up to 4 elements.

## Time Complexity

| Operation | Time Complexity |
|---|---:|
| Enqueue | O(1) |
| Dequeue | O(1) |
| Peek | O(1) |
| isEmpty | O(1) |
| isFull | O(1) |
| Display | O(n) |

## Advantages and Disadvantages

### Advantages

- Reuses available array positions.
- Avoids the wasted-space problem of a simple linear array queue.
- Provides constant-time insertion and deletion.
- Uses a fixed amount of memory.

### Disadvantages

- Array-based implementations have a fixed capacity.
- Circular indexing requires careful pointer management.
- Full and empty conditions require special handling.
- The one-empty-slot approach sacrifices one array position.

## Implementation Details

This module explores an array-based Circular Queue implementation in C++.

The implementation uses:

- A fixed-size array.
- Two integer pointers: `front` and `rear`.
- Modulo arithmetic for circular movement.
- Functions for insertion, deletion, inspection, and state checking.

The implementation is kept close to the underlying data structure to focus on understanding its behavior and pointer management.

## Common Pitfalls

- Using the wrong operator instead of modulo `%`.
- Forgetting to wrap the rear pointer back to index `0`.
- Forgetting to wrap the front pointer during deletion.
- Incorrectly handling the transition between empty and non-empty states.
- Incorrectly handling the last remaining element.
- Confusing the physical array order with the logical queue order.
- Forgetting that the one-empty-slot approach reduces usable capacity by one.

## Learning Objectives

By completing this module, you should understand:

- The FIFO principle.
- The difference between linear and circular queues.
- How circular indexing works using modulo arithmetic.
- How to implement enqueue and dequeue operations.
- How to manage front and rear pointers.
- How to detect full and empty conditions.
- How to analyze the time complexity of queue operations.

## References

- [GeeksforGeeks: Circular Queue](https://www.geeksforgeeks.org/dsa/circular-queue/)
- [Programiz: Circular Queue](https://www.programiz.com/dsa/circular-queue)