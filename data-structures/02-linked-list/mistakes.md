# Common Mistakes

This document highlights the most common mistakes developers make when implementing a Singly Linked List.

Understanding these mistakes is just as important as understanding the implementation itself.

---

# Mistake #1

## Forgetting to Handle an Empty List

### Incorrect

```cpp
head = head->next;
```

### Why It Is Wrong

If `head` is `nullptr`, dereferencing it leads to undefined behavior and usually causes the program to crash.

### Correct

Always check whether the list is empty before accessing the first node.

```cpp
if (isEmpty())
{
    return;
}
```

---

# Mistake #2

## Losing the Head Pointer

### Incorrect

```cpp
head = head->next;
```

without storing the original node.

### Why It Is Wrong

Once the head pointer changes, the original first node becomes inaccessible.

This creates a memory leak because its allocated memory can no longer be released.

### Correct

```cpp
Node* firstNode = head;

head = head->next;

delete firstNode;
```

---

# Mistake #3

## Forgetting to Delete Removed Nodes

### Incorrect

```cpp
head = head->next;
```

### Why It Is Wrong

Updating the pointer without deleting the removed node leaks dynamically allocated memory.

### Correct

```cpp
Node* firstNode = head;

head = head->next;

delete firstNode;
```

---

# Mistake #4

## Forgetting to Update Links

### Incorrect

```cpp
delete current;
```

### Why It Is Wrong

Deleting a node without reconnecting the previous node breaks the linked list.

### Correct

```cpp
previous->next = current->next;

delete current;
```

---

# Mistake #5

## Ignoring the Single Node Case

### Why It Matters

Operations such as deleting the last node require special handling when the linked list contains only one node.

### Correct

```cpp
if (head->next == nullptr)
{
    delete head;
    head = nullptr;
}
```

---

# Mistake #6

## Forgetting to Update the List Size

### Incorrect

```cpp
delete current;
```

### Why It Is Wrong

If the list length is not updated, functions such as `size()` return incorrect results.

### Correct

```cpp
delete current;

length--;
```

---

# Mistake #7

## Traversing Past nullptr

### Incorrect

```cpp
while (current != nullptr)
{
    current = current->next;
}

cout << current->value;
```

### Why It Is Wrong

After the loop finishes, `current` becomes `nullptr`.

Accessing it results in undefined behavior.

---

# Mistake #8

## Forgetting to Initialize New Nodes

### Incorrect

```cpp
Node* newNode = new Node(value);
```

without setting `next`.

### Why It Is Wrong

Every newly created node should initially point to `nullptr`.

### Correct

```cpp
Node(int value)
    : value(value), next(nullptr)
{
}
```

---

# Mistake #9

## Forgetting to Free All Memory

### Why It Matters

Destroying the linked list object without deleting every allocated node results in memory leaks.

### Correct

Use a destructor that clears the entire linked list.

```cpp
LinkedList::~LinkedList()
{
    clear();
}
```

---

# Mistake #10

## Assuming Linked Lists Support Random Access

### Incorrect Assumption

```cpp
list[5];
```

### Why It Is Wrong

Linked lists do not provide direct indexing.

To reach the fifth element, every previous node must be visited.

Time Complexity:

```
O(n)
```

---

# Best Practices

Always remember to:

- Handle the empty list case.
- Handle the single-node case.
- Delete dynamically allocated memory.
- Update links before deleting nodes.
- Keep the list size synchronized.
- Initialize every pointer.
- Traverse until `nullptr`.
- Use descriptive function names.
- Reuse existing functions whenever possible.