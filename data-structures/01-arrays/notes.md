# Arrays Cheat Sheet

## Definition

An array is a fixed-size collection of elements of the same data type stored in contiguous memory locations.

---

# Key Properties

- Fixed size
- Same data type
- Contiguous memory allocation
- Zero-based indexing
- Constant-time element access

---

# Array Declaration

```cpp
int numbers[5];
```

---

# Array Initialization

```cpp
int numbers[5] = {10, 20, 30, 40, 50};
```

---

# Access an Element

```cpp
cout << numbers[2];
```

Time Complexity:

```
O(1)
```

---

# Update an Element

```cpp
numbers[2] = 100;
```

Time Complexity:

```
O(1)
```

---

# Read Input

```cpp
for (int i = 0; i < 5; i++)
{
    cin >> numbers[i];
}
```

Time Complexity:

```
O(n)
```

---

# Traverse an Array

```cpp
for (int i = 0; i < 5; i++)
{
    cout << numbers[i] << " ";
}
```

Time Complexity:

```
O(n)
```

---

# Complexity Summary

| Operation | Complexity |
|-----------|------------|
| Access | O(1) |
| Update | O(1) |
| Traversal | O(n) |
| Linear Search | O(n) |

---

# Advantages

- Fast random access
- Simple to use
- Cache-friendly memory layout
- Efficient traversal

---

# Limitations

- Fixed size
- Insertion is expensive
- Deletion is expensive
- Stores elements of the same data type

---

# Remember

- First index = `0`
- Last index = `size - 1`
- Accessing an invalid index results in undefined behavior.
- Arrays cannot grow dynamically after creation.