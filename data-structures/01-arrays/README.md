# Arrays

## Table of Contents

1. Introduction
2. What Is an Array?
3. Why Use Arrays?
4. Creating an Array
5. Updating Elements
6. Reading Input
7. Accessing Elements
8. Traversing an Array
9. Summary

---

## Introduction

Arrays are one of the most fundamental data structures in computer science.

They provide a simple and efficient way to store multiple values of the same data type in contiguous memory locations.

Understanding arrays is essential because many advanced data structures are built upon the same core principles.

---

## What Is an Array?

An array is a fixed-size collection of elements of the same data type stored in contiguous memory.

Each element is identified by its index.

Example:

```cpp
int numbers[5] = {10, 20, 30, 40, 50};
```

The first element has index `0`.

The last element has index `size - 1`.

---

## Why Use Arrays?

Arrays allow us to:

- Store multiple related values.
- Access elements efficiently.
- Traverse data using loops.
- Organize information in a structured way.

Arrays are one of the building blocks of many other data structures.

---

## Creating an Array

```cpp
int numbers[5];
```

Initialize directly:

```cpp
int numbers[5] = {1, 2, 3, 4, 5};
```

---

## Updating Elements

```cpp
numbers[2] = 100;
```

An element can be modified directly using its index.

---

## Reading Input

```cpp
for (int i = 0; i < 5; i++)
{
    cin >> numbers[i];
}
```

This allows the user to fill the array dynamically.

---

## Accessing Elements

```cpp
cout << numbers[0];
```

Accessing an element by index takes constant time.

**Time Complexity:** `O(1)`

---

## Traversing an Array

```cpp
for (int i = 0; i < 5; i++)
{
    cout << numbers[i] << " ";
}
```

Traversing an array requires visiting every element.

**Time Complexity:** `O(n)`

---

## Summary

Arrays are fixed-size collections of elements stored in contiguous memory locations.

They provide constant-time access through indexing and efficient traversal using loops.

Arrays serve as the foundation for many advanced data structures and algorithms.