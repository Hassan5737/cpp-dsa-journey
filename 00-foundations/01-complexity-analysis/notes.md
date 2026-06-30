# Complexity Analysis Cheat Sheet

## What Is Complexity Analysis?

Complexity analysis evaluates the efficiency of an algorithm by measuring how its resource consumption grows as the input size increases.

The two primary resources are:

- **Time Complexity**
- **Space Complexity**

---

## Time Complexity

Measures how the number of operations grows as the input size increases.

> Focus on the growth rate, not the execution time.

---

## Space Complexity

Measures the additional memory required by an algorithm during execution.

---

# Asymptotic Notations

| Notation | Meaning |
|----------|---------|
| **O** | Upper Bound (Worst Case) |
| **Ω** | Lower Bound (Best Case) |
| **Θ** | Tight Bound (Exact Growth Rate) |

---

# Common Complexity Classes

| Complexity | Name | Performance |
|------------|------|-------------|
| `O(1)` | Constant | Excellent |
| `O(log n)` | Logarithmic | Excellent |
| `O(n)` | Linear | Good |
| `O(n log n)` | Linearithmic | Very Good |
| `O(n²)` | Quadratic | Expensive |

---

# Growth Order

From fastest to slowest:

```text
O(1)
↓
O(log n)
↓
O(n)
↓
O(n log n)
↓
O(n²)
```

---

# Complexity Analysis Rules

### Ignore Constants

```text
O(2n)  →  O(n)

O(100) → O(1)
```

---

### Ignore Lower-Order Terms

```text
O(n² + n)
↓

O(n²)
```

---

### Consecutive Loops

Add the complexities.

```cpp
for (...)
{
}

for (...)
{
}
```

```text
O(n) + O(n)

↓

O(n)
```

---

### Nested Loops

Multiply the complexities.

```cpp
for (...)
{
    for (...)
    {

    }
}
```

```text
O(n)

×

O(n)

↓

O(n²)
```

---

### Logarithmic Loops

Loops that repeatedly multiply or divide their iterator are typically logarithmic.

```cpp
for (int i = 1; i < n; i *= 2)
{
}
```

```text
O(log n)
```

---

# Best, Average, and Worst Cases

| Case | Description |
|------|-------------|
| Best | Minimum amount of work |
| Average | Expected amount of work |
| Worst | Maximum amount of work |

---

# Practical Examples

| Code Pattern | Complexity |
|--------------|------------|
| Array Indexing | `O(1)` |
| Single Loop | `O(n)` |
| Nested Loops | `O(n²)` |
| Doubling Loop | `O(log n)` |
| Nested Logarithmic + Linear Loop | `O(n log n)` |

---

# Interview Tips

- Think about how the input size grows.
- Ignore hardware performance.
- Ignore compiler optimizations.
- Ignore constant factors.
- Focus on the dominant growth term.
- Analyze loops before writing the final complexity.

---

# Key Takeaways

- Complexity analysis measures scalability.
- Execution time is not the same as time complexity.
- Big O describes the worst-case growth.
- Nested loops multiply.
- Consecutive loops add.
- Logarithmic loops divide the problem size every iteration.
- The dominant term determines the final complexity.