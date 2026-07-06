# Common Mistakes

This document records common mistakes and misconceptions related to arrays.

The purpose is to understand *why* these mistakes happen and how to avoid them.

---

## Mistake #1

### Incorrect Assumption

Array indexing starts from **1**.

### Correct Explanation

Array indexing starts from **0**.

```cpp
int numbers[5] = {10, 20, 30, 40, 50};

cout << numbers[0]; // 10
cout << numbers[4]; // 50
```

### Key Lesson

The first element is always at index **0**.

---

## Mistake #2

### Incorrect Assumption

The last valid index is equal to the array size.

### Correct Explanation

For an array of size **n**, the last valid index is:

```text
n - 1
```

Example:

```cpp
int numbers[5];
```

Valid indices:

```text
0 1 2 3 4
```

Invalid:

```cpp
numbers[5];
```

### Key Lesson

The highest valid index is always **size - 1**.

---

## Mistake #3

### Incorrect Assumption

Arrays can grow automatically after creation.

### Correct Explanation

Built-in C++ arrays have a fixed size.

```cpp
int numbers[5];
```

The size cannot be changed after declaration.

### Key Lesson

If dynamic resizing is required, use `std::vector`.

---

## Mistake #4

### Incorrect Assumption

Accessing an invalid index simply returns an empty value.

### Correct Explanation

Accessing an index outside the array bounds results in **undefined behavior**.

```cpp
int numbers[5];

cout << numbers[100];
```

The program may:

- Print garbage values
- Crash
- Behave unpredictably

### Key Lesson

Always ensure the index is within the valid range.

---

## Mistake #5

### Incorrect Assumption

Traversing an array has constant time complexity.

### Correct Explanation

Accessing a single element is **O(1)**.

Traversing the entire array is **O(n)**.

```cpp
for (int i = 0; i < size; i++)
{
    cout << numbers[i];
}
```

### Key Lesson

Reading one element is different from visiting every element.

---

## Final Reminder

Before working with arrays, always verify:

- The array size.
- The index range.
- Whether the array has been initialized.
- Whether the operation affects one element or the entire array.