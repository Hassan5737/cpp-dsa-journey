# Common Doubly Linked List Mistakes

This document highlights common mistakes developers make when implementing a Doubly Linked List and explains how to avoid them.

---

# Mistake 1

## Forgetting to Initialize Pointers

### Incorrect

```cpp
Node* newNode = new Node(value);
```

without initializing the pointers.

### Correct

```cpp
Node(int value)
    : data(value), next(nullptr), prev(nullptr)
{
}
```

Always initialize pointers immediately after creating a node.

---

# Mistake 2

## Forgetting to Update Both Links

A Doubly Linked List has two links per node.

Updating only one pointer breaks the list.

### Incorrect

```cpp
current->next = newNode;
```

### Correct

```cpp
current->next = newNode;
newNode->prev = current;
```

Whenever a connection changes, always verify both directions.

---

# Mistake 3

## Not Handling an Empty List

Operations should always check whether the list is empty.

### Incorrect

```cpp
head->next = newNode;
```

### Correct

```cpp
if (isEmpty())
{
    head = newNode;
    return;
}
```

---

# Mistake 4

## Ignoring the Single-Node Case

Many implementations handle empty and multiple-node lists but forget about lists containing only one node.

Always check:

```cpp
if (head->next == nullptr)
```

before accessing additional nodes.

---

# Mistake 5

## Losing Node References Before Deletion

Deleting a node before saving the next pointer results in losing access to the remaining nodes.

### Incorrect

```cpp
delete current;
current = current->next;
```

### Correct

```cpp
Node* nextNode = current->next;

delete current;

current = nextNode;
```

---

# Mistake 6

## Forgetting to Reset Head

After deleting the first node, the head pointer must point to the new first node.

```cpp
head = head->next;
head->prev = nullptr;
```

Failing to update the head leaves the list in an invalid state.

---

# Mistake 7

## Creating Memory Leaks

Every dynamically allocated node should eventually be deleted.

A destructor or a dedicated `clear()` function should release all allocated memory.

---

# Mistake 8

## Dereferencing a Null Pointer

Never assume a pointer is valid.

Always verify it before accessing its members.

### Incorrect

```cpp
current->next->next
```

without checking whether `current->next` exists.

---

# Mistake 9

## Assuming Constant-Time Access

Unlike arrays, linked lists do not support random access.

Accessing the nth element always requires traversal.

Complexity:

```
O(n)
```

---

# Mistake 10

## Forgetting That Backward Traversal Starts at the Tail

A Doubly Linked List cannot traverse backward directly from the head.

You must first locate the tail, then follow the `prev` pointers.

---

# Best Practices

- Keep pointer updates simple and readable.
- Handle edge cases before the general case.
- Use descriptive variable names.
- Initialize pointers immediately.
- Release allocated memory.
- Test empty, single-node, and multi-node lists.
- Prefer reusable helper functions when appropriate.

---

# Quick Checklist

Before considering your implementation complete, verify that:

- All pointers are initialized.
- Both `next` and `prev` links are updated correctly.
- Empty lists are handled safely.
- Single-node lists are handled correctly.
- Memory is released properly.
- No null pointer is dereferenced.
- Forward traversal works.
- Backward traversal works.
- Every operation behaves correctly after insertion and deletion.