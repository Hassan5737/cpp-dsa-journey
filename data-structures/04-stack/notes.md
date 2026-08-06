# Stack Notes

## Definition

A Stack is a linear data structure that follows the **Last In, First Out (LIFO)** principle.

The last element inserted into the stack is the first one to be removed.

All insertion and deletion operations occur at a single end called the **top**.

---

## LIFO Principle

LIFO stands for:

> **Last In, First Out**

Example:

```text
Push: 10
Push: 20
Push: 30

Top
 │
 ▼
30
20
10
```

Calling `pop()` removes **30** first.

---

## Core Operations

| Operation | Description |
|-----------|-------------|
| Push | Insert an element onto the top |
| Pop | Remove the top element |
| Peek | Return the top element without removing it |
| isEmpty | Check whether the stack is empty |
| isFull | Check whether the stack is full (array implementation) |
| Size | Return the number of stored elements |
| Clear | Remove all elements |
| Display | Print all elements from top to bottom |

---

## Time Complexity

| Operation | Complexity |
|-----------|-----------:|
| Push | O(1) |
| Pop | O(1) |
| Peek | O(1) |
| isEmpty | O(1) |
| isFull | O(1) |
| Size | O(1) |
| Clear | O(1) |
| Display | O(n) |

---

## Overflow

Overflow occurs when attempting to push an element into a full stack.

For an array-based stack:

```cpp
if (topIndex == CAPACITY - 1)
```

No additional elements can be inserted.

---

## Underflow

Underflow occurs when attempting to remove or access an element from an empty stack.

For example:

```cpp
pop();

peek();
```

Both operations require checking:

```cpp
isEmpty()
```

before accessing the stack.

---

## Array-Based Stack

Characteristics:

- Fixed capacity.
- Fast access.
- Cache-friendly.
- Simple implementation.
- Overflow is possible.

---

## Linked List-Based Stack

Characteristics:

- Dynamic size.
- No fixed capacity.
- Additional memory per node.
- Overflow occurs only when memory is exhausted.

---

## Common Applications

- Function call stack
- Recursive algorithms
- Undo / Redo systems
- Browser history
- Expression evaluation
- Parentheses matching
- Backtracking algorithms
- Depth-First Search (DFS)

---

## Interview Tips

Be able to explain:

- Why a stack follows the LIFO principle.
- Why `push()` and `pop()` are O(1).
- The difference between Overflow and Underflow.
- The difference between array-based and linked list-based stacks.
- Common real-world applications of stacks.

---

## Quick Summary

✔ Linear data structure

✔ Follows the LIFO principle

✔ Insertions and deletions occur only at the top

✔ Push, Pop, and Peek are O(1)

✔ Array implementation has a fixed capacity

✔ Widely used in recursion, compilers, and backtracking