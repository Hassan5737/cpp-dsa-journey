# Singly Linked List Practice Exercises

This document contains practical exercises designed to reinforce your understanding of the Singly Linked List implementation.

> **Recommendation:** Solve each exercise before viewing the solution.

---

# Exercise 1

## Create an Empty Linked List

Create an empty linked list object.

### Expected Result

```
The list is empty.
```

<details>
<summary><strong>Solution</strong></summary>

```cpp
LinkedList list;

list.print();
```

</details>

---

# Exercise 2

## Insert at the Back

Insert the following values:

```
10
20
30
40
```

### Expected Output

```
10 -> 20 -> 30 -> 40 -> nullptr
```

<details>
<summary><strong>Solution</strong></summary>

```cpp
LinkedList list;

list.insertBack(10);
list.insertBack(20);
list.insertBack(30);
list.insertBack(40);

list.print();
```

</details>

---

# Exercise 3

## Insert at the Front

Insert:

```
30
20
10
```

using only `insertFront()`.

### Expected Output

```
10 -> 20 -> 30 -> nullptr
```

<details>
<summary><strong>Solution</strong></summary>

```cpp
LinkedList list;

list.insertFront(30);
list.insertFront(20);
list.insertFront(10);

list.print();
```

</details>

---

# Exercise 4

## Delete the First Node

Starting from:

```
10 -> 20 -> 30 -> 40
```

Delete the first node.

### Expected Output

```
20 -> 30 -> 40 -> nullptr
```

<details>
<summary><strong>Solution</strong></summary>

```cpp
list.deleteFront();

list.print();
```

</details>

---

# Exercise 5

## Delete the Last Node

Starting from:

```
10 -> 20 -> 30 -> 40
```

Delete the last node.

### Expected Output

```
10 -> 20 -> 30 -> nullptr
```

<details>
<summary><strong>Solution</strong></summary>

```cpp
list.deleteBack();

list.print();
```

</details>

---

# Exercise 6

## Delete by Value

Starting from:

```
10 -> 20 -> 30 -> 40
```

Delete:

```
30
```

### Expected Output

```
10 -> 20 -> 40 -> nullptr
```

<details>
<summary><strong>Solution</strong></summary>

```cpp
list.deleteByValue(30);

list.print();
```

</details>

---

# Exercise 7

## Search for a Value

Determine whether the value `20` exists.

### Expected Output

```
true
```

<details>
<summary><strong>Solution</strong></summary>

```cpp
cout << boolalpha;

cout << list.contains(20);
```

</details>

---

# Exercise 8

## Print the Current Size

Print the number of nodes currently stored in the linked list.

### Expected Output

```
4
```

<details>
<summary><strong>Solution</strong></summary>

```cpp
cout << list.size();
```

</details>

---

# Exercise 9

## Clear the Linked List

Remove all nodes from the linked list.

### Expected Output

```
nullptr
```

<details>
<summary><strong>Solution</strong></summary>

```cpp
list.clear();

list.print();
```

</details>

---

# Challenge Exercise

## Build the Following Linked List

Using only the provided member functions, produce the following result:

```
5 -> 15 -> 25 -> 35 -> nullptr
```

Try to minimize the number of operations.

---

# Interview Questions

Before moving to the next data structure, make sure you can confidently answer the following questions.

### Q1

Why is insertion at the beginning **O(1)**?

---

### Q2

Why is insertion at the end **O(n)** in this implementation?

---

### Q3

How could insertion at the end become **O(1)**?

---

### Q4

Why can't a Singly Linked List support random access?

---

### Q5

Why do we need dynamic memory allocation?

---

### Q6

What is the purpose of the `head` pointer?

---

### Q7

Why do we implement a destructor?

---

### Q8

What happens if allocated nodes are never deleted?

---

# Module Checklist

Before continuing to the next topic, verify that you can:

- Explain what a node is.
- Explain how pointers connect nodes.
- Draw a Singly Linked List.
- Implement insertion at the front.
- Implement insertion at the back.
- Implement deletion at the front.
- Implement deletion at the back.
- Delete a node by value.
- Traverse the linked list.
- Search for a value.
- Calculate the time complexity of every operation.
- Explain the advantages and disadvantages of a Singly Linked List.