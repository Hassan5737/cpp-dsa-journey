# Circular Linked List Cheat Sheet

## Definition

A Circular Linked List is a linked data structure in which the last node points back to the first node instead of pointing to `nullptr`.

Each node stores a value and a pointer to the next node.

---

# Node Structure

```cpp
struct Node
{
    int data;
    Node* next;
};
```

Each node contains:

- Data
- Pointer to the next node

---

# Head and Tail Pointers

The `head` pointer stores the address of the first node.

The `tail` pointer stores the address of the last node.

```text
Head                       Tail
 |                           |
 v                           v
10 -> 20 -> 30 -> 40 --------+
 ^                           |
 |___________________________|
```

In a Circular Linked List with at least one node:

```cpp
tail->next == head
```

If:

```cpp
head == nullptr
```

the list is empty.

When the list contains one node:

```cpp
head == tail
head->next == head
```

---

# Memory Layout

Unlike arrays, linked list nodes are not necessarily stored contiguously in memory.

Nodes are connected using pointers. In a Circular Linked List, the final node links back to the first node, forming a cycle.

---

# Operations

## Insert at Beginning

```cpp
list.insertAtBeginning(value);
```

Complexity: `O(1)` when both `head` and `tail` are maintained.

The new node becomes the head, and the tail must point to the new head.

---

## Insert at End

```cpp
list.insertAtEnd(value);
```

Complexity: `O(1)` when both `head` and `tail` are maintained.

The new node becomes the tail, and its `next` pointer must point to `head`.

---

## Delete from Beginning

```cpp
list.deleteFromBeginning();
```

Complexity: `O(1)` when both `head` and `tail` are maintained.

The head moves to the next node, and the tail's `next` pointer must be updated.

The empty-list and single-node cases require special handling.

---

## Delete from End

```cpp
list.deleteFromEnd();
```

Complexity: `O(n)` for a singly circular linked list, even when a tail pointer is maintained.

The node before the tail must be found before updating the tail.

---

## Search

```cpp
list.contains(value);
```

Complexity: `O(n)`.

Traversal stops when the target is found or the current node returns to the head.

---

## Display

```cpp
list.display();
```

Complexity: `O(n)`.

Every node is visited once. Traversal stops when it returns to the starting node.

---

## Clear

```cpp
list.clear();
```

Complexity: `O(n)`.

Every allocated node is deleted, and the list pointers and size are reset.

---

## Size

```cpp
list.size();
```

Complexity: `O(1)` when the list maintains a node counter.

---

## Is Empty

```cpp
list.isEmpty();
```

Complexity: `O(1)`.

The list is empty when `head == nullptr`.

---

# Complexity Summary

| Operation | Complexity |
|-----------|-----------:|
| Access by Index | O(n) |
| Search | O(n) |
| Insert at Beginning | O(1) |
| Insert at End | O(1) |
| Delete from Beginning | O(1) |
| Delete from End | O(n) |
| Traversal | O(n) |
| Clear | O(n) |
| Size | O(1) |
| Is Empty | O(1) |

These complexities assume the implementation maintains both `head` and `tail`, as well as a node counter for `size()`.

---

# Advantages

- Dynamic size.
- Efficient insertion at the beginning.
- Efficient insertion at the end when a tail pointer is maintained.
- Efficient deletion from the beginning.
- No need for contiguous memory.
- Useful for cyclic processes and repeated traversal.
- The last node connects directly to the first node.

---

# Disadvantages

- No built-in random access.
- Sequential traversal is required.
- Extra memory is needed for pointers.
- Traversal can become infinite if the stopping condition is incorrect.
- Deleting nodes requires careful pointer updates.
- In a singly circular linked list, backward traversal is not directly supported.

---

# Comparison with Arrays

| Feature | Array | Circular Linked List |
|---------|------:|---------------------:|
| Memory | Contiguous | Non-contiguous |
| Size | Fixed for built-in arrays | Dynamic |
| Access by Index | O(1) | O(n) |
| Insert at Beginning | O(n) | O(1) |
| Insert at End | O(1)* | O(1)** |
| Delete at Beginning | O(n) | O(1) |
| Delete at End | O(1)* | O(n) |

*Array insertion and deletion costs depend on capacity and the number of elements shifted.

**Circular linked list insertion at the end is O(1) when a tail pointer is maintained.

---

# Circular Traversal

A Circular Linked List does not terminate at `nullptr`.

A common traversal pattern is:

```cpp
if (!isEmpty())
{
    Node* current = head;

    do
    {
        // Process current node.
        current = current->next;
    }
    while (current != head);
}
```

The `do-while` loop ensures that the first node is processed before checking whether traversal has returned to the head.

---

# Interview Tips

Remember the following:

- The first node is referenced by `head`.
- The last node is referenced by `tail`.
- The last node points back to `head`.
- An empty list has `head == nullptr` and `tail == nullptr`.
- A single-node list points to itself.
- Traversal must stop when it returns to the starting node.
- Insertion and deletion must preserve the circular connection.
- A singly circular linked list does not directly support backward traversal.
- Deleting the last node requires finding its predecessor.

---

# Key Takeaways

- A Circular Linked List forms a cycle instead of ending at `nullptr`.
- Nodes are connected through pointers.
- Maintaining a tail pointer enables O(1) insertion at the end.
- Traversal requires a circular stopping condition.
- Empty and single-node cases need special handling.
- Pointer updates must preserve the circular connection.
- Circular Linked Lists are useful for round-robin scheduling, cyclic iteration, and other repeated processes.
