# Queue — Quick Notes

## 1. Definition

A **Queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle.

The first element inserted into the Queue is the first element removed.

Front                         Rear
  ↓                             ↓
[ 10 ][ 20 ][ 30 ][ 40 ]
  ↑
removed first

---

## 2. Main Components

The array-based Queue implementation uses the following main components:

int* arr;
int capacity;
int front;
int rear;
int count;

### Front

`front` represents the position of the first active element in the Queue.

### Rear

`rear` represents the position of the last active element in the Queue.

### Capacity

`capacity` represents the maximum number of elements the Queue can hold.

### Count

`count` represents the current number of elements stored in the Queue.

---

## 3. Core Operations

| Operation | Purpose | Time Complexity |
|-----------|---------|-----------------|
| `enqueue()` | Add an element at Rear | O(1) |
| `dequeue()` | Remove an element from Front | O(1) |
| `peek()` | Access the Front element | O(1) |
| `isEmpty()` | Check whether Queue is empty | O(1) |
| `isFull()` | Check whether Queue is full | O(1) |
| `display()` | Display all active elements | O(n) |

---

## 4. Enqueue

`enqueue()` adds a new element to the Rear of the Queue.

Example:

queue.enqueue(10);

Before:

[ 20 ][ 30 ]

After enqueue(10):

[ 20 ][ 30 ][ 10 ]
                  ↑
                 Rear

For a linear Queue, the `rear` position moves forward after every successful
insertion.

---

## 5. Dequeue

`dequeue()` removes the element from the Front of the Queue.

Example:

int value;
queue.dequeue(value);

Before:

[ 10 ][ 20 ][ 30 ]
  ↑
Front

After dequeue():

[ 10 ][ 20 ][ 30 ]
         ↑
        Front

The element `10` is logically removed by moving `front`.

The remaining elements are not shifted.

---

## 6. Peek

`peek()` returns the Front element without removing it.

Example:

int value;

if (queue.peek(value))
{
    cout << value;
}

Example state:

[ 10 ][ 20 ][ 30 ]
  ↑
Front

peek() → 10

The Queue remains unchanged after a successful `peek()` operation.

---

## 7. isEmpty

The Queue is considered empty when it contains zero active elements.

The implementation checks:

return count == 0;

Example:

[     ][     ][     ]

count = 0

An empty Queue cannot perform a successful `dequeue()` or `peek()` operation.

---

## 8. isFull

The Queue is considered full when the number of active elements reaches its
maximum capacity.

The implementation checks:

return count == capacity;

Example:

[ 10 ][ 20 ][ 30 ]

count    = 3
capacity = 3

At this point, another `enqueue()` operation will fail.

---

## 9. Overflow

**Queue Overflow** occurs when attempting to insert an element into a full
Queue.

Example:

Capacity = 3

[ 10 ][ 20 ][ 30 ]
                 ↓
             enqueue(40)
                 ↓
              Overflow

The implementation checks the condition before inserting:

if (isFull())
{
    return false;
}

This prevents insertion beyond the allocated capacity.

---

## 10. Underflow

**Queue Underflow** occurs when attempting to remove an element from an empty
Queue.

Example:

[     ][     ][     ]
        ↓
     dequeue()
        ↓
     Underflow

The implementation checks:

if (isEmpty())
{
    return false;
}

before accessing the Front element.

---

## 11. FIFO Principle

The defining property of a Queue is:

First In → First Out

Example:

queue.enqueue(10);
queue.enqueue(20);
queue.enqueue(30);

The Queue becomes:

Front
  ↓
[ 10 ][ 20 ][ 30 ]
                  ↑
                 Rear

The removal order is:

10 → 20 → 30

The first inserted element is therefore the first one removed.

---

## 12. Linear Array-Based Queue

This module implements a **linear Queue using an Array**.

The `front` and `rear` positions move through the array in one direction.

Example:

[ 10 ][ 20 ][ 30 ][ 40 ][ 50 ]
  ↑                         ↑
Front                      Rear

After several dequeue operations:

[    ][    ][ 30 ][ 40 ][ 50 ]
              ↑             ↑
            Front          Rear

The elements at the beginning have been removed logically, but their array
positions are no longer available to the simple linear implementation once
`rear` reaches the end.

---

## 13. Linear Queue Limitation

Consider:

[    ][    ][ 30 ][ 40 ][ 50 ]

There are unused positions at the beginning of the array.

However:

rear == capacity - 1

so the Queue can still report itself as full.

This happens because `rear` only moves forward.

The freed positions cannot be reused without either shifting elements or
changing the Queue design.

---

## 14. Why We Do Not Shift Elements

One possible solution is to shift all remaining elements toward the beginning
after every `dequeue()`.

For example:

Before:

[    ][    ][ 30 ][ 40 ]
              ↑

After shifting:

[ 30 ][ 40 ][    ][    ]
  ↑
Front

However, shifting elements requires moving multiple values.

If there are `n` elements, shifting can take:

O(n)

time.

This would make `dequeue()` less efficient.

Therefore, the simple implementation keeps `dequeue()` at:

O(1)

and accepts the space-utilization limitation.

---

## 15. Circular Queue

A **Circular Queue** solves the space-utilization problem by allowing the
`front` and `rear` positions to wrap around the array.

Conceptually:

        ┌─────────────────┐
        │                 ↓
[ 0 ][ 1 ][ 2 ][ 3 ][ 4 ]
  ↑                       │
  └───────────────────────┘

When `rear` reaches the last position, it can return to the beginning if
space is available.

This allows previously freed positions to be reused.

Circular Queue is therefore a natural improvement over the simple linear
array-based Queue.

---

## 16. Array-Based vs Linked-List-Based Queue

| Feature | Array-Based Queue | Linked-List-Based Queue |
|---------|-------------------|-------------------------|
| Capacity | Fixed | Dynamic |
| Memory allocation | Predetermined | Allocated as needed |
| Memory layout | Contiguous | Non-contiguous |
| Pointer overhead | No per-element pointer | Pointer per node |
| Dynamic growth | No | Yes |
| Cache locality | Generally better | Generally worse |
| Memory predictability | High | Lower |
| Implementation | Simpler | More complex |

An array-based Queue is useful when the maximum capacity is known in advance.

A linked-list-based Queue is more suitable when the number of elements can
change dynamically.

---

## 17. Important Edge Cases

### Empty Queue

dequeue() on an empty Queue

peek() on an empty Queue

Both operations must be rejected safely.

### Full Queue

enqueue() on a full Queue

The operation must not write beyond the allocated array.

### Single Element

When the Queue contains exactly one element:

front == rear

Removing that element should return the Queue to an empty state.

### Repeated Operations

After multiple `enqueue()` and `dequeue()` operations, always verify that:

front
rear
count

still correctly represent the Queue state.

---

## 18. Memory Management

The professional implementation uses dynamic memory:

arr = new int[capacity];

Because the array is allocated dynamically, it must be released when the Queue
object is destroyed.

The destructor handles this:

~Queue()
{
    delete[] arr;
}

This prevents dynamically allocated memory from leaking.

---

## 19. Encapsulation

The Queue implementation keeps its internal state private:

private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int count;

Users interact with the Queue through public operations such as:

enqueue()
dequeue()
peek()
isEmpty()
isFull()

This prevents external code from directly modifying the internal Queue state.

Encapsulation makes the implementation safer and easier to maintain.

---

## 20. Key Takeaways

Queue
  ↓
FIFO
  ↓
Insert at Rear
  ↓
Remove from Front

For the array-based implementation:

enqueue() → O(1)
dequeue() → O(1)
peek()    → O(1)
isEmpty() → O(1)
isFull()  → O(1)
display() → O(n)

The most important limitation of the simple linear implementation is that
freed positions at the beginning of the array cannot be reused once `rear`
reaches the end.

This limitation is the main motivation behind the **Circular Queue**.

---

## Quick Reference

FIFO
    ↓
enqueue() → Rear
dequeue() → Front
peek()    → Front

Empty:
count == 0

Full:
count == capacity

Overflow:
enqueue() when full

Underflow:
dequeue()/peek() when empty

Main limitation:
Linear Queue cannot efficiently reuse freed positions
at the beginning of the array.