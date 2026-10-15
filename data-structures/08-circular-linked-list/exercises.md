# Circular Linked List Practice Exercises

This document contains practical exercises designed to reinforce your understanding of Circular Linked Lists, including insertion, deletion, traversal, searching, and circular pointer management.

> **Recommendation:** Solve each exercise before viewing the solution. Use the `CircularLinkedList` implementation from this module whenever possible.

---

# Exercise 1

## Create an Empty Circular Linked List

Create an empty `CircularLinkedList` object and display its contents.

### Expected Output

```text
List is empty.
```

<details>
<summary><strong>Solution</strong></summary>

```cpp
CircularLinkedList list;

list.display();
```

</details>

---

# Exercise 2

## Insert at the End

Insert the following values into an initially empty circular linked list:

```text
10
20
30
40
```

### Expected Output

```text
10 -> 20 -> 30 -> 40 -> (back to head)
```

<details>
<summary><strong>Solution</strong></summary>

```cpp
CircularLinkedList list;

list.insertAtEnd(10);
list.insertAtEnd(20);
list.insertAtEnd(30);
list.insertAtEnd(40);

list.display();
```

</details>

---

# Exercise 3

## Insert at the Beginning

Insert the values `30`, `20`, and `10`, in that order, using only `insertAtBeginning()`.

### Expected Output

```text
10 -> 20 -> 30 -> (back to head)
```

<details>
<summary><strong>Solution</strong></summary>

```cpp
CircularLinkedList list;

list.insertAtBeginning(30);
list.insertAtBeginning(20);
list.insertAtBeginning(10);

list.display();
```

</details>

---

# Exercise 4

## Delete the First Node

Starting with the following list:

```text
10 -> 20 -> 30 -> 40 -> (back to head)
```

Delete the first node using `deleteFromBeginning()`.

### Expected Output

```text
20 -> 30 -> 40 -> (back to head)
```

<details>
<summary><strong>Solution</strong></summary>

```cpp
list.deleteFromBeginning();

list.display();
```

</details>

---

# Exercise 5

## Delete the Last Node

Starting with:

```text
10 -> 20 -> 30 -> 40 -> (back to head)
```

Delete the last node using `deleteFromEnd()`.

### Expected Output

```text
10 -> 20 -> 30 -> (back to head)
```

<details>
<summary><strong>Solution</strong></summary>

```cpp
list.deleteFromEnd();

list.display();
```

</details>

---

# Exercise 6

## Search for a Value

Create a circular linked list containing `10`, `20`, `30`, and `40`.

Determine whether the values `20` and `99` exist in the list.

### Expected Output

```text
Contains 20? Yes
Contains 99? No
```

<details>
<summary><strong>Solution</strong></summary>

```cpp
std::cout << "Contains 20? "
          << (list.contains(20) ? "Yes" : "No") << '\n';

std::cout << "Contains 99? "
          << (list.contains(99) ? "Yes" : "No") << '\n';
```

</details>

---

# Exercise 7

## Print the Current Size

Create a list containing the values `10`, `20`, `30`, and `40`. Print the number of nodes currently stored in the list.

### Expected Output

```text
4
```

<details>
<summary><strong>Solution</strong></summary>

```cpp
std::cout << list.size() << '\n';
```

</details>

---

# Exercise 8

## Delete from a Single-Node List

Create a list containing only one node with the value `10`.

Delete that node using `deleteFromBeginning()`.

### Expected Output

```text
List is empty.
Size: 0
```

<details>
<summary><strong>Solution</strong></summary>

```cpp
CircularLinkedList list;

list.insertAtEnd(10);
list.deleteFromBeginning();

list.display();
std::cout << "Size: " << list.size() << '\n';
```

</details>

---

# Exercise 9

## Delete from an Empty List

Create an empty circular linked list. Attempt to delete the first node and then the last node.

Check the returned values from both operations.

### Expected Output

```text
Delete from beginning? No
Delete from end? No
```

<details>
<summary><strong>Solution</strong></summary>

```cpp
CircularLinkedList list;

std::cout << "Delete from beginning? "
          << (list.deleteFromBeginning() ? "Yes" : "No") << '\n';

std::cout << "Delete from end? "
          << (list.deleteFromEnd() ? "Yes" : "No") << '\n';
```

</details>

---

# Exercise 10

## Verify the Circular Connection

Create a circular linked list containing three nodes:

```text
10 -> 20 -> 30 -> (back to head)
```

Without changing the list, explain how you could verify that the last node points back to the first node.

### Expected Result

You should be able to explain:

- Why traversal eventually returns to the head.
- Why a circular traversal must not continue until `nullptr`.
- Why a normal `while (current != nullptr)` loop is unsuitable for traversing a valid circular list.

<details>
<summary><strong>Solution</strong></summary>

In a circular linked list, the last node's `next` pointer points to `head`. Therefore, traversal ends when the current pointer returns to `head`, not when it becomes `nullptr`.

For example:

```cpp
Node* current = head;

do {
    // Process current node.
    current = current->next;
} while (current != head);
```

The example assumes access to the internal `Node` and `head` pointers. In a class with private members, this traversal belongs inside a member function.

</details>

---

# Exercise 11

## Clear the Circular Linked List

Create a list containing `10`, `20`, `30`, and `40`. Call `clear()` and then check whether the list is empty.

### Expected Output

```text
List is empty.
Size: 0
```

<details>
<summary><strong>Solution</strong></summary>

```cpp
list.clear();

list.display();
std::cout << "Size: " << list.size() << '\n';
```

</details>

---

# Challenge Exercise

## Build the Following Circular Linked List

Using the available member functions, produce this result:

```text
5 -> 15 -> 25 -> 35 -> (back to head)
```

Requirements:

- Start with an empty list.
- Use insertion operations only.
- Minimize the number of operations.
- Explain why the final node must point back to the head.

---

# Advanced Challenge

## Simulate Repeated Traversal

Create a circular linked list containing `1`, `2`, and `3`.

Print the values while traversing the list twice, starting from the head each time.

### Expected Output

```text
1 -> 2 -> 3 -> 1 -> 2 -> 3
```

Try to solve this without modifying the linked list or breaking its circular connection.

---

# Interview Questions

Before moving to the next topic, make sure you can confidently answer the following questions.

### Q1

What makes a Circular Linked List different from a Singly Linked List?

### Q2

Why does the last node point to `head` instead of `nullptr`?

### Q3

How can you traverse a Circular Linked List without creating an infinite loop?

### Q4

What special cases must be handled when deleting the first node?

### Q5

What happens when deleting the only node in a circular linked list?

### Q6

Why is maintaining a `tail` pointer useful?

### Q7

What are the time complexities of insertion at the beginning and insertion at the end when both `head` and `tail` are maintained?

### Q8

Why must the `tail->next` pointer be updated when inserting or deleting nodes?

### Q9

What problems can occur if a circular traversal incorrectly waits for `nullptr`?

### Q10

Why should a circular linked list destructor handle the circular structure carefully?

---

# Module Checklist

Before continuing to the next topic, verify that you can:

- Explain what makes a linked list circular.
- Draw a Circular Linked List and identify its `head` and `tail`.
- Explain why the last node points to the head.
- Insert a node at the beginning.
- Insert a node at the end.
- Delete the first node.
- Delete the last node.
- Search for a value.
- Traverse the list without an infinite loop.
- Handle an empty list and a single-node list.
- Clear all nodes safely.
- Explain the time complexity of each operation.
- Explain the advantages and disadvantages of a Circular Linked List.
- Explain how circular traversal differs from normal singly linked traversal.

---

# Resources

- [GeeksforGeeks: Circular Linked List](https://www.geeksforgeeks.org/dsa/circular-linked-list/)
- [Programiz: Circular Linked List](https://www.programiz.com/dsa/circular-linked-list)
- [cppreference: Classes](https://en.cppreference.com/w/cpp/language/classes)
- [cppreference: `new` expression](https://en.cppreference.com/w/cpp/language/new)
- [cppreference: `delete` expression](https://en.cppreference.com/w/cpp/language/delete)
