# Doubly Linked List Exercises

These exercises are designed to reinforce the concepts covered in this module.

Try solving each problem before looking at any reference implementation.

---

# Beginner Level

## Exercise 1

Create an empty Doubly Linked List.

---

## Exercise 2

Insert the following values at the back:

10 20 30 40 50

Print the list.

Expected output:

```text
10 <-> 20 <-> 30 <-> 40 <-> 50 -> nullptr
```

---

## Exercise 3

Insert the following values at the front:

30 20 10

Print the list.

Expected output:

```text
10 <-> 20 <-> 30 -> nullptr
```

---

## Exercise 4

Print the list in reverse order.

Expected output:

```text
30 <-> 20 <-> 10 -> nullptr
```

---

# Intermediate Level

## Exercise 5

Delete the first node.

Print the list after deletion.

---

## Exercise 6

Delete the last node.

Print the list after deletion.

---

## Exercise 7

Search for:

- 20
- 100

Display whether each value exists.

---

## Exercise 8

Return the number of nodes in the list.

---

## Exercise 9

Clear the entire list.

Verify that the list becomes empty.

---

# Advanced Level

## Exercise 10

Implement:

```cpp
void insertAfter(int target, int value);
```

Insert a new node immediately after the target value.

---

## Exercise 11

Implement:

```cpp
void insertBefore(int target, int value);
```

Insert a new node immediately before the target value.

---

## Exercise 12

Implement:

```cpp
void deleteByValue(int value);
```

Delete the first occurrence of a given value.

---

## Exercise 13

Implement:

```cpp
Node* find(int value);
```

Return a pointer to the node if it exists.

---

## Exercise 14

Implement:

```cpp
void reverse();
```

Reverse the linked list without creating another list.

---

## Exercise 15

Modify the implementation to maintain both:

- Head pointer
- Tail pointer

Then compare the time complexity before and after the modification.

---

# Challenge

Build a simple browser history simulator using a Doubly Linked List.

Support the following operations:

- Visit a page
- Back
- Forward
- Display the current page

---

# Learning Checklist

After completing these exercises, you should be able to:

- Create a Doubly Linked List from scratch.
- Insert nodes at the front and back.
- Delete nodes safely.
- Traverse the list in both directions.
- Search efficiently.
- Handle empty and single-node lists.
- Manage dynamic memory correctly.
- Explain the time complexity of each operation.