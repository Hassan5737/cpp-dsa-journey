# Stack Using a Singly Linked List — Quick Notes

## Core Concept

A Stack is a linear data structure that follows the:

> **LIFO — Last In, First Out**

principle.

The last element inserted is the first element removed.

In this implementation, a Singly Linked List is used as the underlying storage structure.

The `top` pointer always points to the first node of the linked list.

```text
top
 ↓
30 → 20 → 10 → nullptr
```

---

## Node Structure

Each element is stored inside a dynamically allocated node.

```cpp
struct Node
{
    int data;
    Node* next;
};
```

Each node contains:

- `data` — the stored value.
- `next` — pointer to the next node.

---

## Empty Stack

An empty Stack is represented by:

```cpp
top == nullptr
```

```text
top
 ↓
nullptr
```

---

## Push

Adds a new element to the top of the Stack.

```cpp
void push(int value)
{
    Node* newNode = new Node(value, top);
    top = newNode;
}
```

Example:

```text
Before:

top → 30 → 20 → 10 → nullptr


push(40)


After:

top → 40 → 30 → 20 → 10 → nullptr
```

### Complexity

```text
Time:  O(1)
Space: O(1) auxiliary space
```

---

## Pop

Removes the element at the top of the Stack.

```cpp
int pop()
{
    if (isEmpty())
    {
        return -1;
    }

    Node* removedNode = top;
    int removedValue = removedNode->data;

    top = top->next;

    delete removedNode;

    return removedValue;
}
```

Example:

```text
Before:

top → 40 → 30 → 20 → 10 → nullptr


pop()


After:

top → 30 → 20 → 10 → nullptr
```

### Complexity

```text
Time:  O(1)
Space: O(1)
```

---

## Peek

Returns the value at the top without removing it.

```cpp
int peek() const
{
    if (isEmpty())
    {
        return -1;
    }

    return top->data;
}
```

Example:

```text
top → 30 → 20 → 10 → nullptr

peek() → 30
```

The Stack remains unchanged.

### Complexity

```text
Time:  O(1)
Space: O(1)
```

---

## Display

Traverses the linked list from `top` to the end.

```cpp
void display() const
{
    Node* current = top;

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
}
```

Example:

```text
top → 30 → 20 → 10 → nullptr
```

Output:

```text
30 20 10
```

### Complexity

```text
Time:  O(n)
Space: O(1)
```

---

## Empty Check

The Stack is empty when:

```cpp
top == nullptr
```

A helper function can encapsulate this check:

```cpp
bool isEmpty() const
{
    return top == nullptr;
}
```

### Complexity

```text
Time: O(1)
```

---

## Underflow

Stack Underflow occurs when attempting to perform an operation that requires an element while the Stack is empty.

Common examples:

```cpp
pop();
peek();
```

The implementation should check:

```cpp
if (isEmpty())
{
    // Handle underflow
}
```

---

## Memory Management

The linked-list implementation uses dynamic memory.

### Allocation

Every pushed element creates a new node:

```cpp
Node* newNode = new Node(value, top);
```

### Deallocation

When an element is removed:

```cpp
delete removedNode;
```

This is important because dynamically allocated nodes must be properly released to prevent memory leaks.

---

## Destructor

The Stack destructor releases all remaining nodes when the Stack object is destroyed.

Conceptually:

```text
top → 30 → 20 → 10 → nullptr

        ↓ destructor

delete 30
delete 20
delete 10

top → nullptr
```

The destructor traverses the remaining nodes and deletes them one by one.

---

## Complexity Summary

| Operation | Time | Auxiliary Space |
|-----------|------|-----------------|
| Push | O(1) | O(1) |
| Pop | O(1) | O(1) |
| Peek | O(1) | O(1) |
| isEmpty | O(1) | O(1) |
| Display | O(n) | O(1) |

The Stack itself requires **O(n)** memory for `n` stored elements because every element occupies a dynamically allocated node.

---

## Array-Based vs Linked List-Based

### Array-Based Stack

```text
Fixed capacity
Contiguous memory
Low per-element overhead
Possible overflow when capacity is reached
```

### Linked List-Based Stack

```text
Dynamic size
Non-contiguous memory
Additional pointer overhead
Grows until memory allocation fails
```

Both implementations provide:

```text
push() → O(1)
pop()  → O(1)
peek() → O(1)
```

---

## Key Takeaways

- A Stack follows the LIFO principle.
- The beginning of the linked list acts as the Stack's top.
- `push()` inserts at the beginning of the list.
- `pop()` removes from the beginning of the list.
- `peek()` accesses the first node without removing it.
- `push()`, `pop()`, and `peek()` are O(1).
- Linked-list-based stacks have dynamic capacity.
- Every dynamically allocated node must eventually be deleted.
- The implementation uses a destructor to clean up remaining nodes.

