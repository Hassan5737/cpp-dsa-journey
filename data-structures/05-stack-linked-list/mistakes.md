# Common Stack Using Linked List Mistakes

This document covers common mistakes when implementing a Stack using a
Singly Linked List.

The main areas to pay attention to are:

- Pointer manipulation
- Dynamic memory management
- Empty-stack handling
- Node lifetime
- Edge cases

---

## Mistake 1 — Forgetting to Update `top`

When pushing a new node, the new node must become the new top.

### Incorrect

```cpp
Node* newNode = new Node(value, top);
```

If `top` is never updated, the new node is not actually connected as the
Stack's top.

### Correct

```cpp
Node* newNode = new Node(value, top);
top = newNode;
```

The final step is essential.

---

## Mistake 2 — Losing the Existing Stack

The new node must point to the current top before changing `top`.

### Incorrect

```cpp
Node* newNode = new Node(value);

top = newNode;

newNode->next = top;
```

This makes:

```text
newNode->next
       ↓
      itself
```

The existing Stack is lost and the node points to itself.

### Correct

```cpp
Node* newNode = new Node(value, top);

top = newNode;
```

The original top must be preserved before updating the `top` pointer.

---

## Mistake 3 — Popping Without Checking for an Empty Stack

Attempting to access `top` when it is `nullptr` can result in invalid
pointer dereferencing.

### Incorrect

```cpp
Node* removedNode = top;

top = top->next;
```

If the Stack is empty:

```cpp
top == nullptr
```

then:

```cpp
top->next
```

is invalid.

### Correct

```cpp
if (isEmpty())
{
    return -1;
}
```

before accessing the node.

---

## Mistake 4 — Forgetting to Delete the Removed Node

Moving `top` does not automatically release the old node.

### Incorrect

```cpp
Node* removedNode = top;

top = top->next;
```

The old node is no longer reachable from the Stack, but its memory is still
allocated.

This creates a **memory leak**.

### Correct

```cpp
Node* removedNode = top;

top = top->next;

delete removedNode;
```

---

## Mistake 5 — Deleting the Node Before Moving `top`

The order of operations matters.

### Incorrect

```cpp
delete top;

top = top->next;
```

After deleting `top`, accessing:

```cpp
top->next
```

uses a pointer to memory that has already been released.

### Correct

```cpp
Node* removedNode = top;

top = top->next;

delete removedNode;
```

First move the Stack's top pointer, then release the old node.

---

## Mistake 6 — Moving `top` During Display

The `top` pointer represents the actual beginning of the Stack and should not
be modified during traversal.

### Incorrect

```cpp
while (top != nullptr)
{
    cout << top->data << " ";
    top = top->next;
}
```

After this loop:

```text
top == nullptr
```

The Stack has effectively lost its entry point.

### Correct

Use a temporary traversal pointer:

```cpp
Node* current = top;

while (current != nullptr)
{
    cout << current->data << " ";
    current = current->next;
}
```

The Stack remains unchanged.

---

## Mistake 7 — Forgetting the Destructor

Because every node is dynamically allocated using `new`, remaining nodes
must eventually be released.

Without a destructor, destroying a Stack object containing nodes can leave
allocated memory behind.

### Correct Approach

```cpp
Stack::~Stack()
{
    while (top != nullptr)
    {
        Node* current = top;
        top = top->next;
        delete current;
    }
}
```

The destructor releases every remaining node.

---

## Mistake 8 — Returning the Node Instead of Its Value

The `peek()` operation should expose the stored value, not the internal node.

### Incorrect

```cpp
Node* peek();
```

This exposes an implementation detail.

### Better

```cpp
int peek() const;
```

The caller only needs the value at the top.

This preserves encapsulation.

---

## Mistake 9 — Forgetting That `peek()` Does Not Remove

`peek()` should only inspect the top element.

### Incorrect

```cpp
int Stack::peek() const
{
    return top->data;
    // followed by changing top
}
```

The Stack must remain unchanged after `peek()`.

### Correct

```cpp
int Stack::peek() const
{
    if (isEmpty())
    {
        return -1;
    }

    return top->data;
}
```

---

## Mistake 10 — Traversing the List for `push()` or `pop()`

A Stack only needs to operate at the top.

### Inefficient Approach

Traversing to the end of the linked list before every insertion or deletion
would make the operation:

```text
O(n)
```

### Correct Approach

Use the beginning of the linked list as the Stack's top.

```text
top → Node → Node → Node
```

This allows:

```text
push() → O(1)
pop()  → O(1)
```

---

## Mistake 11 — Confusing Underflow With Overflow

These two conditions represent different problems.

### Underflow

Occurs when attempting to access or remove an element from an empty Stack.

```cpp
if (isEmpty())
{
    // Underflow
}
```

### Overflow

For a linked-list-based Stack, there is no fixed array capacity.

A push normally continues allocating nodes until the system cannot satisfy
the memory allocation request.

Therefore, the concept of fixed-capacity overflow from an array-based Stack
does not apply in the same way here.

---

## Mistake 12 — Returning a Magic Value Without Considering the Data Type

A common implementation uses:

```cpp
return -1;
```

to indicate an error.

This can be ambiguous if `-1` is also a valid Stack value.

For example:

```cpp
stack.push(-1);
```

Now `peek()` returning `-1` could mean either:

```text
The top value is -1
```

or:

```text
The Stack is empty
```

For production-quality APIs, error handling should be designed so that valid
data cannot be confused with an error state.

The current implementation uses `-1` for simplicity and educational purposes.

---

## Edge Cases to Test

A Stack implementation should be tested against at least these cases:

### Empty Stack

```text
top → nullptr
```

Test:

```cpp
pop();
peek();
display();
```

---

### One Element

```text
top → 10 → nullptr
```

Test:

```cpp
push(10);
pop();
```

The Stack should return to:

```text
top → nullptr
```

---

### Multiple Elements

```text
top → 30 → 20 → 10 → nullptr
```

Test:

```cpp
push(40);
pop();
peek();
display();
```

---

### Destroying a Non-Empty Stack

Create a Stack containing multiple nodes and allow the object to go out of
scope.

The destructor should release every allocated node.

---

# Best Practices

- Keep `top` private.
- Always check for an empty Stack before dereferencing `top`.
- Update pointers in the correct order.
- Delete removed nodes.
- Use a temporary pointer for traversal.
- Implement a destructor for proper cleanup.
- Keep `push()` and `pop()` at the beginning of the linked list.
- Avoid exposing internal `Node` objects unnecessarily.
- Test empty and single-element cases.
- Be careful when choosing error-return values.

---

# Final Checklist

Before considering the implementation complete:

- [ ] `top` starts as `nullptr`.
- [ ] `push()` correctly connects the new node.
- [ ] `push()` updates `top`.
- [ ] `pop()` handles an empty Stack.
- [ ] `pop()` updates `top` correctly.
- [ ] Removed nodes are deleted.
- [ ] `peek()` does not modify the Stack.
- [ ] `display()` does not modify `top`.
- [ ] The destructor releases all remaining nodes.
- [ ] Empty and single-element cases have been tested.

