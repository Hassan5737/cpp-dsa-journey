# Queue — Array-Based Implementation

## Table of Contents

1. [Introduction](#introduction)
2. [What Is a Queue?](#what-is-a-queue)
3. [Implementing a Queue Using an Array](#implementing-a-queue-using-an-array)
4. [The FIFO Principle](#the-fifo-principle)
5. [Queue Structure](#queue-structure)
6. [Core Operations](#core-operations)
7. [Time Complexity](#time-complexity)
8. [Queue Overflow and Underflow](#queue-overflow-and-underflow)
9. [Array-Based Queue Limitations](#array-based-queue-limitations)
10. [Advantages](#advantages)
11. [Disadvantages](#disadvantages)
12. [Real-World Applications](#real-world-applications)
13. [Summary](#summary)
14. [References](#references)

---

## Introduction

A **Queue** is a fundamental linear data structure used to store and manage
elements in a specific order.

Unlike a Stack, which follows the **LIFO (Last In, First Out)** principle, a
Queue follows the **FIFO (First In, First Out)** principle.

This means that the first element inserted into the Queue is the first element
removed.

Queues are widely used in computer science and software engineering whenever
elements need to be processed in the same order in which they arrive.

In this module, I implement a Queue from scratch in C++ using a
**fixed-size Array**.

The implementation focuses on understanding how a Queue works internally,
how the `front` and `rear` positions are managed, and how the main Queue
operations are performed.

The module also explores:

- FIFO behavior
- Enqueue and Dequeue operations
- Front and Rear management
- Queue Overflow and Underflow
- Time and space complexity
- Edge cases
- Limitations of a linear array-based Queue
- Common implementation pitfalls

## What Is a Queue?

A **Queue** is a linear data structure that organizes elements according to
the **FIFO (First In, First Out)** principle.

The first element added to the Queue is the first element that can be removed.

A Queue can be visualized as a line:

```text
Front                                      Rear
  ↓                                          ↓
[ 10 ] → [ 20 ] → [ 30 ] → [ 40 ] → [ 50 ]
```

The element at the `Front` is the next element to be removed, while new
elements are added from the `Rear`.

For example, if we enqueue:

```text
10
20
30
```

the Queue becomes:

```text
Front
  ↓
[ 10 ][ 20 ][ 30 ]
                 ↑
                Rear
```

The first element removed will be `10`.

After removing it:

```text
Front
  ↓
[ 20 ][ 30 ]
          ↑
         Rear
```

This ordering behavior makes Queues useful whenever data needs to be processed
in the same order in which it arrives.

---

## Implementing a Queue Using an Array

There are several ways to implement a Queue.

One simple approach is using an **Array**.

In an array-based Queue, the elements are stored in contiguous memory locations,
and two indices are used to keep track of the Queue:

```cpp
front
rear
```

The `front` index identifies the element that will be removed next.

The `rear` index identifies the position of the most recently inserted element.

For example:

```text
Index:    0      1      2      3      4
        +------+------+------+------+------+
        |  10  |  20  |  30  |      |      |
        +------+------+------+------+------+
          ↑                    ↑
        front                 rear
```

Initially, an empty Queue can be represented as:

```cpp
front = -1;
rear = -1;
```

When the first element is inserted, both `front` and `rear` are initialized
to the first valid array position:

```cpp
front = 0;
rear = 0;
```

Then the value is stored at:

```cpp
queue[rear]
```

For subsequent insertions, `rear` moves forward:

```text
Initial:

front
  ↓
[ 10 ]
   ↑
  rear


After another enqueue:

front
  ↓
[ 10 ][ 20 ]
         ↑
        rear
```

During a Dequeue operation, the value at `front` is removed and `front`
moves to the next position.

```text
Before Dequeue:

front
  ↓
[ 10 ][ 20 ][ 30 ]
                 ↑
                rear


After Dequeue:

       front
         ↓
[ 10 ][ 20 ][ 30 ]
         ↑      ↑
        next   rear
```

The removed element does not need to be physically shifted out of the array.
Instead, the `front` index advances to the next element.

This makes the basic Dequeue operation efficient, but a linear array-based
Queue also introduces some limitations that will be discussed later in this
module.

## The FIFO Principle

The defining characteristic of a Queue is the **FIFO (First In, First Out)**
principle.

FIFO means that the first element inserted into the Queue is the first element
that can be removed.

A simple real-world example is a line of people waiting for a service:

```text
First person in → First person served
```

The same behavior applies to a Queue:

```text
Enqueue
   ↓
[ 10 ][ 20 ][ 30 ]
   ↑             ↑
 Front          Rear
   ↓
Dequeue → 10
```

The element that enters first remains at the `Front` and is removed before
the elements that entered after it.

### Example

Suppose we start with an empty Queue and perform the following operations:

```text
Enqueue(10)
Enqueue(20)
Enqueue(30)
```

The Queue becomes:

```text
Front
  ↓
[ 10 ][ 20 ][ 30 ]
                 ↑
                Rear
```

The order of insertion is:

```text
10 → 20 → 30
```

Now, if we perform:

```text
Dequeue()
```

the value `10` is removed:

```text
       Front
         ↓
[ 20 ][ 30 ]
          ↑
         Rear
```

Another `Dequeue()` removes `20`:

```text
       Front
         ↓
[ 30 ]
   ↑
  Rear
```

Finally, removing the last element gives:

```text
Queue is empty
```

Therefore, the removal order is exactly the same as the insertion order:

```text
Insertion:  10 → 20 → 30
Removal:    10 → 20 → 30
```

This is what distinguishes a Queue from a Stack.

A Stack follows **LIFO (Last In, First Out)**:

```text
Insert:  10 → 20 → 30
Pop:                30
```

While a Queue follows **FIFO (First In, First Out)**:

```text
Insert:  10 → 20 → 30
Dequeue: 10
```

### Why FIFO Matters

FIFO is useful when fairness and arrival order matter.

Elements are processed based on when they entered the Queue rather than
allowing newer elements to be processed first.

This behavior is commonly used in:

- Task scheduling
- Print queues
- Request processing
- CPU scheduling
- Network packet handling
- Breadth-First Search (BFS)

Understanding FIFO is essential because every Queue implementation must preserve
this ordering behavior regardless of how the Queue is implemented internally.

## Queue Structure

An array-based Queue uses a fixed-size array along with two indices:

```cpp
front
rear
```

These two indices are responsible for keeping track of the current boundaries
of the Queue.

### Front

The `front` index points to the element that will be removed next.

For example:

```text
Index:    0      1      2
        +------+------+------+
        |  10  |  20  |  30  |
        +------+------+------+
          ↑
        front
```

Here, `10` is the first element in the Queue and will be removed by the next
`dequeue()` operation.

---

### Rear

The `rear` index points to the most recently inserted element.

```text
Index:    0      1      2
        +------+------+------+
        |  10  |  20  |  30  |
        +------+------+------+
                         ↑
                        rear
```

When a new element is inserted, `rear` moves to the next available position.

For example:

```text
Before Enqueue:

[ 10 ][ 20 ][ 30 ]
              ↑
             rear


After Enqueue(40):

[ 10 ][ 20 ][ 30 ][ 40 ]
                     ↑
                    rear
```

---

### Empty Queue

In this implementation, an empty Queue is represented by:

```cpp
front = -1;
rear = -1;
```

This means that there are currently no valid elements in the Queue.

The `isEmpty()` function checks this condition:

```cpp
bool isEmpty()
{
    return front == -1 && rear == -1;
}
```

---

### First Insertion

When inserting the first element into an empty Queue, both `front` and `rear`
must be initialized.

```text
Before:

front = -1
rear  = -1
```

After:

```text
enqueue(50)
```

the Queue becomes:

```text
front = 0
rear  = 0

[ 50 ]
   ↑
 front
   ↑
 rear
```

Both indices point to the same element because the Queue contains only one
element.

---

### Multiple Elements

After inserting more elements:

```text
enqueue(50)
enqueue(60)
enqueue(70)
```

the Queue becomes:

```text
Index:    0      1      2
        +------+------+------+
        |  50  |  60  |  70  |
        +------+------+------+
          ↑             ↑
        front          rear
```

The Queue contains three elements, with `front` pointing to the first element
and `rear` pointing to the last element.

---

### Dequeue and Front Movement

When `dequeue()` is called, the element at `front` is removed logically and
the `front` index moves forward.

Before:

```text
Index:    0      1      2
        +------+------+------+
        |  50  |  60  |  70  |
        +------+------+------+
          ↑             ↑
        front          rear
```

After `dequeue()`:

```text
Index:    0      1      2
        +------+------+------+
        |  50  |  60  |  70  |
        +------+------+------+
                 ↑      ↑
               front   rear
```

The value `50` is no longer considered part of the active Queue because
`front` now points to index `1`.

The array element itself does not need to be shifted or physically deleted.

---

### Single Element Queue

When the Queue contains only one element:

```text
front == rear
```

For example:

```text
Index:    0
        +------+
        |  70  |
        +------+
          ↑
       front/rear
```

After removing this element, the Queue becomes empty again:

```cpp
front = -1;
rear = -1;
```

This transition is an important edge case that must be handled correctly.

---

### Full Queue

Because this implementation uses a fixed-size array, the Queue has a maximum
capacity.

For an array with:

```cpp
const int Size = 3;
```

the valid indices are:

```text
0
1
2
```

The Queue is considered full when:

```cpp
rear == Size - 1;
```

For example:

```text
Index:    0      1      2
        +------+------+------+
        |  50  |  60  |  70  |
        +------+------+------+
          ↑             ↑
        front          rear
                        =
                      Size - 1
```

At this point, another `enqueue()` operation cannot insert a new element in
this linear array-based implementation.

This behavior leads to an important limitation of the implementation, which
will be discussed later in the module.

## Core Operations

A Queue provides a set of fundamental operations for adding, removing, and
inspecting elements.

The main operations in this array-based implementation are:

- `enqueue()`
- `dequeue()`
- `peek()`
- `isEmpty()`
- `isFull()`
- `display()`

---

### 1. Enqueue

The `enqueue()` operation adds a new element to the **Rear** of the Queue.

The general process is:

1. Check whether the Queue is full.
2. If the Queue is empty, initialize `front` and `rear`.
3. Otherwise, increment `rear`.
4. Store the new value at `queue[rear]`.

Example:

```cpp
enqueue(50);
enqueue(60);
enqueue(70);
```

The Queue becomes:

```text
Index:    0      1      2
        +------+------+------+
        |  50  |  60  |  70  |
        +------+------+------+
          ↑             ↑
        front          rear
```

The relevant logic is:

```cpp
if (rear == Size - 1)
{
    cout << "queue is full" << endl;
    return;
}
```

Then, for the first insertion:

```cpp
if (front == -1 && rear == -1)
{
    front = 0;
    rear = 0;
    queue[rear] = val;
}
```

For subsequent insertions:

```cpp
rear++;
queue[rear] = val;
```

### Complexity

```text
Time:  O(1)
Space: O(1) auxiliary space
```

---

### 2. Dequeue

The `dequeue()` operation removes the element from the **Front** of the Queue.

The general process is:

1. Check whether the Queue is empty.
2. Store the value at `front`.
3. If the Queue contains only one element, reset both indices.
4. Otherwise, increment `front`.
5. Return the removed value.

Example:

```text
Before:

Index:    0      1      2
        +------+------+------+
        |  50  |  60  |  70  |
        +------+------+------+
          ↑             ↑
        front          rear
```

After:

```cpp
dequeue();
```

the active Queue becomes:

```text
Index:    0      1      2
        +------+------+------+
        |  50  |  60  |  70  |
        +------+------+------+
                 ↑      ↑
               front   rear
```

The value `50` is no longer part of the active Queue because `front` has
moved to index `1`.

The array itself is not shifted.

The implementation handles the single-element case separately:

```cpp
if (front == rear)
{
    val = queue[front];
    front = -1;
    rear = -1;
}
```

Otherwise:

```cpp
val = queue[front];
front++;
```

### Complexity

```text
Time:  O(1)
Space: O(1)
```

---

### 3. Peek

The `peek()` operation returns the element at the Front without removing it.

For example:

```text
Index:    0      1      2
        +------+------+------+
        |  50  |  60  |  70  |
        +------+------+------+
          ↑
        front
```

Calling:

```cpp
peek();
```

returns:

```text
50
```

but the Queue remains unchanged.

The implementation first checks whether the Queue is empty:

```cpp
if (isEmpty())
{
    cout << "queue is empty" << endl;
    return -1;
}
```

Then it returns:

```cpp
return queue[front];
```

### Complexity

```text
Time:  O(1)
Space: O(1)
```

---

### 4. isEmpty

The `isEmpty()` operation checks whether the Queue contains any elements.

In this implementation, the Queue is empty when both indices are reset:

```cpp
front == -1 && rear == -1
```

The function is:

```cpp
bool isEmpty()
{
    return front == -1 && rear == -1;
}
```

This condition is true:

```text
front = -1
rear  = -1
```

and false when the Queue contains elements.

### Complexity

```text
Time:  O(1)
Space: O(1)
```

---

### 5. isFull

The `isFull()` operation checks whether the Rear has reached the last valid
index of the fixed-size array.

For:

```cpp
const int Size = 3;
```

the last valid index is:

```text
Size - 1 = 2
```

Therefore:

```cpp
bool isFull()
{
    return rear == Size - 1;
}
```

When:

```cpp
rear == Size - 1
```

the Queue is considered full.

### Complexity

```text
Time:  O(1)
Space: O(1)
```

---

### 6. Display

The `display()` operation prints all active elements in the Queue from
`front` to `rear`.

Example:

```text
Index:    0      1      2
        +------+------+------+
        |  50  |  60  |  70  |
        +------+------+------+
          ↑             ↑
        front          rear
```

The function traverses the active range:

```cpp
for (int i = front; i <= rear; i++)
{
    cout << queue[i] << " ";
}
```

The output is:

```text
50 60 70
```

If the Queue is empty, the operation is rejected:

```cpp
if (front == -1 && rear == -1)
{
    cout << "queue is empty" << endl;
    return;
}
```

### Complexity

```text
Time:  O(n)
Space: O(1)
```

where `n` is the number of active elements in the Queue.

---

## Operation Summary

| Operation | Purpose | Time Complexity |
|-----------|---------|-----------------|
| `enqueue()` | Add an element at Rear | O(1) |
| `dequeue()` | Remove an element from Front | O(1) |
| `peek()` | Access the Front element | O(1) |
| `isEmpty()` | Check whether Queue is empty | O(1) |
| `isFull()` | Check whether Queue is full | O(1) |
| `display()` | Display all active elements | O(n) |

## Time Complexity

Understanding the time complexity of Queue operations is important because it
shows how efficiently the data structure can perform its tasks as the number
of elements grows.

For this array-based implementation, most core Queue operations take constant
time.

---

### Enqueue — O(1)

The `enqueue()` operation inserts an element at the `rear` position.

It does not need to search for an available position or traverse the Queue.

The implementation simply updates `rear` and stores the value:

```cpp
rear++;
queue[rear] = val;
```

Therefore:

```text
Time Complexity: O(1)
```

The operation takes constant time regardless of how many elements are already
stored in the Queue.

---

### Dequeue — O(1)

The `dequeue()` operation removes the element at `front`.

Instead of shifting all remaining elements, the implementation simply moves
the `front` index forward:

```cpp
front++;
```

This avoids unnecessary element movement.

Therefore:

```text
Time Complexity: O(1)
```

This is one of the main advantages of using an index-based Queue.

---

### Peek — O(1)

The `peek()` operation directly accesses:

```cpp
queue[front]
```

Array indexing provides constant-time access.

Therefore:

```text
Time Complexity: O(1)
```

---

### isEmpty — O(1)

The `isEmpty()` function only checks the values of `front` and `rear`:

```cpp
return front == -1 && rear == -1;
```

No traversal is required.

Therefore:

```text
Time Complexity: O(1)
```

---

### isFull — O(1)

The `isFull()` function compares `rear` with the last valid array index:

```cpp
return rear == Size - 1;
```

This is a single comparison.

Therefore:

```text
Time Complexity: O(1)
```

---

### Display — O(n)

Unlike the other operations, `display()` must visit every active element:

```cpp
for (int i = front; i <= rear; i++)
{
    cout << queue[i] << " ";
}
```

If the Queue contains `n` elements, the loop executes `n` times.

Therefore:

```text
Time Complexity: O(n)
```

---

## Space Complexity

The Queue uses a fixed-size array:

```cpp
const int Size = 3;
int queue[Size];
```

The allocated storage does not grow dynamically with the number of elements.

Therefore, for a fixed capacity:

```text
Space Complexity: O(n)
```

where `n` represents the capacity of the underlying array.

The additional variables used by the Queue, such as:

```cpp
front
rear
```

require constant auxiliary space:

```text
Auxiliary Space: O(1)
```

---

## Complexity Summary

| Operation | Time Complexity | Auxiliary Space |
|-----------|-----------------|-----------------|
| `enqueue()` | O(1) | O(1) |
| `dequeue()` | O(1) | O(1) |
| `peek()` | O(1) | O(1) |
| `isEmpty()` | O(1) | O(1) |
| `isFull()` | O(1) | O(1) |
| `display()` | O(n) | O(1) |

The constant-time complexity of `enqueue()`, `dequeue()`, and `peek()` makes
the Queue efficient for its primary operations.

However, the fixed-size nature of this implementation introduces limitations
that must be considered when the Queue reaches its capacity.

## Queue Overflow and Underflow

When working with a Queue, two important edge cases must be handled correctly:

- **Queue Overflow**
- **Queue Underflow**

These conditions occur when attempting to perform an operation that cannot be
completed because of the current state of the Queue.

---

### Queue Overflow

**Queue Overflow** occurs when attempting to insert a new element into a Queue
that has reached its maximum capacity.

Since this implementation uses a fixed-size Array, the Queue has a limited
number of positions.

For example, with:

```cpp
const int Size = 3;
```

the Queue can contain at most three active elements in this linear
array-based implementation.

When the Queue reaches:

```text
[ 10 ][ 20 ][ 30 ]
   ↑             ↑
 front          rear
```

the `rear` index becomes:

```cpp
rear == Size - 1
```

The Queue is therefore considered full.

The implementation checks this condition before performing an insertion:

```cpp
if (rear == Size - 1)
{
    cout << "queue is full" << endl;
    return;
}
```

This prevents the program from attempting to access an invalid array index.

For example:

```cpp
enqueue(10);
enqueue(20);
enqueue(30);
enqueue(40);
```

The fourth insertion cannot be performed because the Queue has reached its
capacity.

---

### Queue Underflow

**Queue Underflow** occurs when attempting to remove an element from an empty
Queue.

An empty Queue in this implementation is represented by:

```cpp
front == -1 && rear == -1
```

Before performing `dequeue()`, the implementation checks whether the Queue is
empty:

```cpp
if (front == -1 && rear == -1)
{
    cout << "queue is empty" << endl;
    return -1;
}
```

This prevents the program from accessing an invalid position in the array.

For example:

```cpp
Queue is empty

dequeue();
```

The operation cannot be completed because there is no element to remove.

---

### Underflow Can Also Affect Peek

The `peek()` operation also needs to handle an empty Queue.

Attempting to access:

```cpp
queue[front]
```

when:

```cpp
front == -1
```

would result in invalid array access.

Therefore, `peek()` first checks:

```cpp
if (isEmpty())
{
    cout << "queue is empty" << endl;
    return -1;
}
```

Only after confirming that the Queue contains elements does it access:

```cpp
queue[front]
```

---

### The Single-Element Case

A particularly important edge case occurs when the Queue contains exactly one
element.

In this situation:

```cpp
front == rear
```

For example:

```text
Index:    0      1      2
        +------+------+------+
        |  50  |      |      |
        +------+------+------+
          ↑
       front/rear
```

When this element is removed, the Queue must return to the empty state:

```cpp
front = -1;
rear = -1;
```

The implementation handles this case explicitly:

```cpp
if (front == rear)
{
    val = queue[front];
    front = -1;
    rear = -1;
}
```

This is important because simply incrementing `front` would leave the Queue in
an inconsistent state.

---

### Why These Checks Matter

Overflow and Underflow checks protect the data structure from invalid
operations.

Without these checks, the program could:

- Access invalid array positions
- Produce incorrect results
- Lose track of the Queue state
- Cause undefined behavior
- Make debugging much harder

Therefore, handling these conditions is an essential part of implementing a
reliable Queue.

---

## Summary

| Condition | Meaning | Check |
|-----------|---------|-------|
| Overflow | Queue is full | `rear == Size - 1` |
| Underflow | Queue is empty | `front == -1 && rear == -1` |
| Single element | Only one element remains | `front == rear` |

Properly handling these states ensures that the Queue maintains a valid
internal state throughout its lifetime.

## Array-Based Queue Limitations

Although an array-based Queue provides simple and efficient operations, the
linear implementation used in this module has an important limitation.

The main issue is related to how the `rear` index moves through the array.

---

### Fixed Capacity

The Queue uses a fixed-size array:

```cpp
const int Size = 3;
int queue[Size];
```

This means that the Queue has a predefined maximum capacity.

Once `rear` reaches:

```cpp
Size - 1
```

the Queue is considered full.

For example:

```text
Index:    0      1      2
        +------+------+------+
        |  10  |  20  |  30  |
        +------+------+------+
          ↑             ↑
        front          rear
```

At this point:

```cpp
rear == Size - 1
```

and another `enqueue()` operation will be rejected.

---

### Wasted Space After Dequeue

The more interesting problem appears after performing one or more
`dequeue()` operations.

Consider the following Queue:

```text
Index:    0      1      2
        +------+------+------+
        |  10  |  20  |  30  |
        +------+------+------+
          ↑             ↑
        front          rear
```

Now perform:

```cpp
dequeue();
```

The `front` moves forward:

```text
Index:    0      1      2
        +------+------+------+
        |  10  |  20  |  30  |
        +------+------+------+
                 ↑      ↑
               front   rear
```

The first position is no longer part of the active Queue.

Now suppose we perform another:

```cpp
dequeue();
```

The Queue becomes:

```text
Index:    0      1      2
        +------+------+------+
        |  10  |  20  |  30  |
        +------+------+------+
                        ↑
                     front/rear
```

There are now unused positions at the beginning of the array.

However, `rear` is already at the last index.

Therefore:

```cpp
enqueue(40);
```

will still be rejected by:

```cpp
if (rear == Size - 1)
```

even though the array contains unused positions.

---

### The Problem

This creates a situation where:

```text
Available memory:
[ FREE ][ FREE ][ 30 ]
    ↑       ↑       ↑
 unused   unused   rear
```

but the Queue reports:

```text
queue is full
```

The implementation cannot reuse the empty positions at the beginning of the
array because `rear` only moves forward.

This is one of the main limitations of a simple linear array-based Queue.

---

### Why Not Shift the Elements?

One possible solution would be to shift all remaining elements toward the
beginning of the array after every `dequeue()`.

For example:

```text
Before:

[    ][    ][ 30 ]
          ↑
        front


After shifting:

[ 30 ][    ][    ]
   ↑
 front
```

However, shifting elements requires moving multiple values.

If there are `n` elements in the Queue, shifting can take:

```text
O(n)
```

time.

This would make `dequeue()` less efficient.

One of the main goals of a Queue implementation is to keep insertion and
removal efficient, so repeatedly shifting elements is not an ideal solution.

---

### Circular Queue

A better solution to this problem is the **Circular Queue**.

Instead of allowing `front` and `rear` to move only from left to right, a
Circular Queue treats the array as if the end connects back to the beginning.

Conceptually:

```text
        ┌───────────────────────┐
        ↓                       │
[ 0 ][ 1 ][ 2 ][ 3 ][ 4 ] ─────┘
```

When `rear` reaches the last index, it can wrap around to the beginning if
there is available space.

For example:

```text
[    ][    ][ 30 ]
   ↑       ↑
 free     free
```

A Circular Queue can reuse those available positions instead of reporting
the Queue as full prematurely.

The Circular Queue is a natural improvement over the simple linear
array-based implementation and is an important next concept when studying
Queues.

---

### Key Takeaway

The linear array-based Queue is simple and efficient for basic operations, but
its fixed capacity and inability to reuse freed positions can lead to wasted
space.

The main limitation can be summarized as:

```text
Linear Queue
    ↓
rear only moves forward
    ↓
freed positions at the beginning may become unusable
    ↓
wasted array space
    ↓
Circular Queue provides a better solution
```

Understanding this limitation helps explain why different Queue
implementations exist and why choosing the right implementation matters.

## Advantages

An array-based Queue has several advantages that make it useful for learning
and for certain practical scenarios.

### 1. Simple Implementation

The structure is relatively easy to understand and implement.

It mainly requires:

```cpp
front
rear
```

along with a fixed-size array.

This makes it a good starting point for understanding how Queue operations work
internally.

---

### 2. Constant-Time Core Operations

The main Queue operations can be performed in constant time:

```text
enqueue() → O(1)
dequeue() → O(1)
peek()    → O(1)
```

The implementation does not require traversing the Queue for these operations.

---

### 3. Direct Array Access

Because the elements are stored in an array, accessing an element by index is
efficient.

For example:

```cpp
queue[front]
```

directly accesses the Front element.

Array indexing provides:

```text
O(1)
```

access time.

---

### 4. Contiguous Memory

Array elements are stored in contiguous memory locations.

This can provide good cache locality because nearby elements are stored close
together in memory.

Compared with a linked-list implementation, an array does not require an
additional pointer field for every element.

---

### 5. Low Memory Overhead

The implementation only needs the array and a small number of variables such
as:

```cpp
front
rear
```

There is no need to store a pointer alongside every element.

This can make an array-based implementation memory-efficient when the required
capacity is known in advance.

---

### 6. Predictable Memory Usage

Because the array has a fixed size, the amount of memory required is known when
the Queue is created.

For example:

```cpp
const int Size = 100;
int queue[Size];
```

The Queue cannot unexpectedly allocate additional memory as elements are added.

This can be useful in systems where memory usage needs to be predictable.

---

### Summary of Advantages

| Advantage | Description |
|-----------|-------------|
| Simple implementation | Easy to understand and implement |
| Fast core operations | `enqueue`, `dequeue`, and `peek` are O(1) |
| Direct access | Array indexing provides O(1) access |
| Contiguous memory | Good memory locality |
| Low overhead | No per-element pointer storage |
| Predictable memory | Fixed capacity and known memory usage |

## Disadvantages

Although an array-based Queue is simple and efficient, it also has several
limitations that should be considered when choosing an implementation.

### 1. Fixed Capacity

The main limitation is that the Queue has a fixed maximum size.

For example:

```cpp
const int Size = 3;
```

The Queue cannot store more than the allocated capacity.

If the Queue becomes full, additional elements cannot be inserted.

```text
[ 10 ][ 20 ][ 30 ]
   ↑             ↑
 front          rear
```

This can be problematic when the required number of elements is not known in
advance.

---

### 2. Wasted Space in a Linear Queue

After performing `dequeue()` operations, positions at the beginning of the
array can become unused.

For example:

```text
[    ][    ][ 30 ]
   ↑       ↑
 unused   unused
```

However, the Queue may still report itself as full because `rear` has already
reached the last array position.

This means that available array space cannot be reused by the simple linear
implementation.

---

### 3. Requires a Circular Queue for Better Space Utilization

The limitation above can be solved by using a **Circular Queue**, where the
`front` and `rear` indices can wrap around the array.

However, this introduces additional logic for managing the circular
relationship between the indices.

Therefore, the simple implementation is easier to understand but less
flexible.

---

### 4. No Dynamic Growth

Unlike a linked-list-based Queue, this implementation cannot automatically
grow when more space is needed.

Once the allocated array reaches its capacity, the Queue cannot accept
additional elements.

A dynamically allocated or linked-list-based implementation can provide more
flexibility when the number of elements is unpredictable.

---

### 5. Capacity Must Be Chosen in Advance

The array size must be determined when the Queue is created.

Choosing a capacity that is too small can cause overflow situations.

Choosing a capacity that is much larger than necessary can result in unused
memory.

Therefore, selecting an appropriate capacity can be difficult when the
workload is unpredictable.

---

### Comparison with a Linked-List-Based Queue

The fixed-size nature of an array-based Queue becomes clearer when compared
with a linked-list-based implementation.

| Feature | Array-Based Queue | Linked-List-Based Queue |
|---------|-------------------|-------------------------|
| Capacity | Fixed | Dynamic |
| Memory allocation | Usually predetermined | Allocated as needed |
| Per-element pointer | No | Yes |
| Memory overhead | Lower | Higher |
| Cache locality | Generally better | Generally worse |
| Can grow dynamically | No | Yes |
| Implementation | Simpler | More complex |
| Space reuse | Limited in linear version | Naturally available |

The choice between the two implementations depends on the requirements of the
problem.

An array-based Queue can be preferable when the maximum capacity is known and
predictable, while a linked-list-based Queue can be more suitable when the
number of elements can change dynamically.

---

## Key Takeaway

The main trade-off of an array-based Queue is:

```text
Simple + Fast + Predictable Memory
              ↓
        Fixed Capacity
              ↓
      Limited Flexibility
```

Understanding these trade-offs is important because a data structure should
not only be evaluated by how easy it is to implement, but also by how well its
characteristics match the requirements of the problem.

## Real-World Applications

Queues are widely used in software systems whenever tasks or data need to be
processed in the same order in which they arrive.

The FIFO behavior of a Queue makes it a natural choice for many real-world
problems.

### 1. Print Queues

When multiple documents are sent to a printer, they can be placed in a Queue.

```text
Document A → Document B → Document C
     ↓
   Printer
```

The first document submitted is normally processed first.

---

### 2. Task Scheduling

Queues can be used to manage tasks waiting to be executed.

For example:

```text
Task 1 → Task 2 → Task 3 → Task 4
```

The system can process tasks according to their arrival order.

---

### 3. Request Processing

Servers can use Queues to manage incoming requests when requests arrive faster
than they can be processed immediately.

```text
Client Requests
      ↓
[ R1 ][ R2 ][ R3 ][ R4 ]
      ↓
   Processor
```

This allows requests to wait until the system is ready to process them.

---

### 4. Network Packet Processing

Network systems can use Queue-like structures to temporarily store packets
waiting to be processed or transmitted.

```text
Packet 1 → Packet 2 → Packet 3
              ↓
          Processing
```

The Queue helps maintain an ordered flow of packets.

---

### 5. Breadth-First Search (BFS)

Queues are a fundamental part of the **Breadth-First Search (BFS)** algorithm.

When traversing a graph or tree, nodes are processed level by level.

```text
        A
       / \
      B   C
     / \
    D   E
```

A BFS traversal can use a Queue to process:

```text
A → B → C → D → E
```

The Queue ensures that nodes discovered earlier are processed before nodes
discovered later.

---

### 6. Operating Systems

Queues are commonly used in operating systems for managing tasks, processes,
and other resources that need to wait for execution.

For example:

```text
Process 1 → Process 2 → Process 3
                 ↓
            CPU Scheduling
```

The exact scheduling strategy depends on the operating system and scheduling
algorithm, but Queue-based structures are an important concept in process
management.

---

### 7. Data Buffers

Queues can be used as buffers between two parts of a system operating at
different speeds.

For example:

```text
Producer
   ↓
[ Queue ]
   ↓
Consumer
```

The producer can add data while the consumer processes it at its own rate.

This pattern is widely used in systems involving streams, I/O, networking,
and asynchronous processing.

---

## Why Queues Are Important

Queues are not just an academic data structure.

They provide a simple and powerful abstraction for managing ordered work.

Whenever a system needs to answer:

> "What should be processed next?"

and the answer depends on arrival order, a Queue is often a natural solution.

Understanding Queues is therefore an important foundation for studying more
advanced topics such as:

- Circular Queues
- Priority Queues
- Deques
- BFS
- Scheduling algorithms
- Producer-Consumer systems
- Message Queues

## Summary

In this module, I implemented a **Queue from scratch using a fixed-size Array
in C++**.

The implementation helped reinforce several important Data Structures &
Algorithms concepts, including:

- The FIFO principle
- Front and Rear management
- Enqueue and Dequeue operations
- Queue Overflow and Underflow
- Edge case handling
- Array-based data storage
- Time and space complexity analysis
- The limitations of a linear Queue
- The motivation behind Circular Queues

The main operations implemented in this module are:

```text
enqueue()
dequeue()
peek()
isEmpty()
isFull()
display()
```

The most important performance characteristics are:

```text
enqueue()  → O(1)
dequeue()  → O(1)
peek()     → O(1)
isEmpty()  → O(1)
isFull()   → O(1)
display()  → O(n)
```

The implementation also demonstrated an important practical limitation of a
linear array-based Queue: once `rear` reaches the end of the array, previously
freed positions at the beginning cannot be reused.

This limitation provides the motivation for studying **Circular Queues**, which
can make better use of the available array space.

---

## References

The following resources were used to support my understanding of Queue
concepts and implementation:

- *Data Structures and Algorithms* — General Queue concepts and complexity analysis
- *C++ How to Program* — C++ fundamentals, arrays, pointers, and memory concepts
- Personal implementation and experimentation in C++

---

## Implementation

The complete implementation of the array-based Queue is available in:

```text
implementation.cpp
```

The implementation was written from scratch as part of my C++ Data Structures &
Algorithms learning journey.

---

## Module Status

**Completed**

This module is part of my ongoing **C++ Data Structures & Algorithms journey**.

Each completed data structure is documented, implemented from scratch, and
organized as a separate learning module in this repository.