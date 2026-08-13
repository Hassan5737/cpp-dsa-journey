# Stack Using a Singly Linked List — Exercises

These exercises are designed to reinforce the concepts covered in this module.

The goal is not only to practice Stack operations, but also to strengthen
understanding of:

- Singly Linked Lists
- Pointer manipulation
- Dynamic memory allocation
- Memory management
- LIFO behavior
- Object-oriented design

Try solving each exercise independently before looking for a reference
implementation.

---

# Beginner Level

## Exercise 1 — Basic Push

Create an empty Stack and push the following values:

```text
10
20
30
40
```

Display the Stack.

Expected order:

```text
40 30 20 10
```

Explain why the values appear in reverse insertion order.

---

## Exercise 2 — Peek

Push:

```text
10
20
30
```

Call:

```cpp
peek();
```

Verify that the returned value is:

```text
30
```

Then call `display()` and verify that the Stack has not changed.

---

## Exercise 3 — Pop

Push:

```text
10
20
30
```

Perform one `pop()` operation.

Display the Stack.

Expected result:

```text
20 10
```

---

## Exercise 4 — Multiple Pop Operations

Push:

```text
10
20
30
40
50
```

Remove all elements one by one.

Record the order in which the values are removed.

Expected order:

```text
50
40
30
20
10
```

Explain how this demonstrates the LIFO principle.

---

# Intermediate Level

## Exercise 5 — Empty Stack

Create an empty Stack.

Test:

```cpp
pop();
peek();
display();
```

Verify that the implementation handles the empty Stack safely.

---

## Exercise 6 — Single Element

Create a Stack containing only:

```text
100
```

Perform:

```cpp
peek();
pop();
```

Then verify that the Stack is empty.

Expected state:

```text
top → nullptr
```

---

## Exercise 7 — Search

Add the following function:

```cpp
bool contains(int value) const;
```

The function should return:

```text
true
```

if the value exists in the Stack and:

```text
false
```

otherwise.

Example:

```cpp
Stack stack;

stack.push(10);
stack.push(20);
stack.push(30);

stack.contains(20); // true
stack.contains(50); // false
```

Analyze the time complexity of your implementation.

---

## Exercise 8 — Stack Size

Add:

```cpp
int size() const;
```

The function should return the number of elements currently stored in the
Stack.

Example:

```text
Stack:

30
20
10

size() → 3
```

Consider whether your implementation should calculate the size by traversing
the linked list or maintain a dedicated size counter.

Compare the complexity of both approaches.

---

## Exercise 9 — Clear the Stack

Implement:

```cpp
void clear();
```

The function should remove every node and leave the Stack empty.

After calling:

```cpp
clear();
```

the Stack should satisfy:

```cpp
isEmpty() == true
```

Make sure every dynamically allocated node is properly deleted.

---

# Advanced Level

## Exercise 10 — Reverse the Stack

Implement:

```cpp
void reverse();
```

Given:

```text
top → 30 → 20 → 10 → nullptr
```

the result should be:

```text
top → 10 → 20 → 30 → nullptr
```

Try solving this using pointer manipulation without creating another Stack.

---

## Exercise 11 — Get Minimum Element

Implement:

```cpp
int getMin() const;
```

Return the smallest value currently stored in the Stack.

Example:

```text
top → 40 → 10 → 30 → 20 → nullptr
```

Expected:

```text
getMin() → 10
```

Handle the empty Stack case appropriately.

---

## Exercise 12 — Get Maximum Element

Implement:

```cpp
int getMax() const;
```

Return the largest value currently stored in the Stack.

Example:

```text
top → 40 → 10 → 30 → 20 → nullptr
```

Expected:

```text
getMax() → 40
```

---

## Exercise 13 — Destructor Verification

Create a Stack containing several dynamically allocated nodes.

Allow the Stack object to go out of scope.

Verify conceptually that the destructor releases every node.

Think carefully about:

```cpp
Stack::~Stack()
```

and explain why simply deleting `top` once would not be sufficient.

---

# Challenge 1 — Balanced Parentheses

Use a Stack to determine whether a string contains balanced parentheses.

Examples:

```text
()
(())
((()))
()()()
(()(()))
```

Expected:

```text
Balanced
```

Examples of unbalanced expressions:

```text
(
(()
))( 
(()))
```

Expected:

```text
Not Balanced
```

---

# Challenge 2 — Reverse a String

Use the Stack to reverse a string.

Input:

```text
hello
```

Expected output:

```text
olleh
```

Do not use a built-in reverse function.

---

# Challenge 3 — Decimal to Binary

Use a Stack to convert a decimal number into its binary representation.

Example:

```text
Input:
10

Output:
1010
```

Hint:

Repeatedly divide the number by `2` and push the remainders onto the Stack.

Then pop the values to construct the binary representation.

---

# Challenge 4 — Palindrome Checker

Use a Stack to determine whether a string is a palindrome.

Examples:

```text
level
madam
racecar
```

should return:

```text
Palindrome
```

while:

```text
hello
world
```

should return:

```text
Not a Palindrome
```

---

# Challenge 5 — Stack Using Only Stack Operations

Create a function that reverses the elements of a Stack using another Stack.

Given:

```text
Top
 ↓
40
30
20
10
```

produce:

```text
Top
 ↓
10
20
30
40
```

Think about how the LIFO behavior can be used to achieve the reversal.

---

# Complexity Challenge

For each implemented operation, determine its time complexity.

Complete the following table:

| Operation | Time Complexity | Reason |
|-----------|-----------------|--------|
| `push()` | ? | ? |
| `pop()` | ? | ? |
| `peek()` | ? | ? |
| `display()` | ? | ? |
| `contains()` | ? | ? |
| `size()` | ? | ? |
| `clear()` | ? | ? |
| `reverse()` | ? | ? |

---

# Reflection Questions

After completing the exercises, answer the following questions:

1. Why is the beginning of the linked list a better choice for the Stack's top
   than the end?

2. Why are `push()` and `pop()` O(1)?

3. What would happen if `pop()` did not delete the removed node?

4. Why should `display()` use a temporary pointer instead of modifying `top`?

5. What is the main difference between an array-based Stack and a
   linked-list-based Stack?

6. What are the memory trade-offs of using a linked list?

7. Why does the linked-list implementation not require a fixed capacity?

---

# Learning Checklist

After completing this module, you should be able to:

- [ ] Explain the LIFO principle.
- [ ] Implement a Stack using a Singly Linked List.
- [ ] Perform `push`, `pop`, and `peek`.
- [ ] Traverse the Stack safely.
- [ ] Handle Stack Underflow.
- [ ] Allocate and release nodes dynamically.
- [ ] Explain the role of the destructor.
- [ ] Analyze time and space complexity.
- [ ] Compare array-based and linked-list-based implementations.
- [ ] Apply a Stack to solve practical problems.

