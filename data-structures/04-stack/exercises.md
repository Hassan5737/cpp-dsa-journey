# Stack Exercises

These exercises are designed to reinforce the concepts covered in this module.

Try solving each problem before looking at any reference implementation.

---

# Beginner Level

## Exercise 1

Create an empty stack.

Verify that the stack is initially empty.

---

## Exercise 2

Push the following values onto the stack:

10 20 30 40 50

Display the stack.

Expected output:

```text
50
40
30
20
10
```

---

## Exercise 3

Pop one element.

Display the stack again.

Expected output:

```text
40
30
20
10
```

---

## Exercise 4

Return the current top element without removing it.

Use the `peek()` function.

---

## Exercise 5

Return the current number of elements stored in the stack.

---

# Intermediate Level

## Exercise 6

Continue pushing values until the stack becomes full.

Attempt to push one additional value.

Verify that overflow is handled correctly.

---

## Exercise 7

Remove every element using repeated calls to `pop()`.

Verify that the stack becomes empty.

---

## Exercise 8

Attempt to pop from an empty stack.

Verify that underflow is handled correctly.

---

## Exercise 9

Insert several values.

Call `clear()`.

Verify that the stack becomes empty.

---

# Advanced Level

## Exercise 10

Implement:

```cpp
bool contains(int value);
```

Return whether the given value exists in the stack.

---

## Exercise 11

Implement:

```cpp
int search(int value);
```

Return the position of a value relative to the top of the stack.

Return `-1` if the value does not exist.

---

## Exercise 12

Implement:

```cpp
void displayReverse();
```

Print the stack from the bottom element to the top.

---

## Exercise 13

Modify the implementation so that the stack size is provided by the user during construction.

---

## Exercise 14

Implement a stack using a linked list instead of an array.

Compare both implementations.

---

# Challenge

Use a stack to determine whether a string has balanced parentheses.

Examples:

```text
()

(())

((()))

()()()

(()(()))
```

should return:

```text
Balanced
```

while

```text
(

(()

))(

(()))
```

should return:

```text
Not Balanced
```

---

# Learning Checklist

After completing these exercises, you should be able to:

- Implement a stack from scratch.
- Perform push, pop, and peek operations.
- Detect overflow and underflow conditions.
- Explain why stack operations run in constant time.
- Compare array-based and linked list-based implementations.
- Apply stacks to solve practical programming problems.