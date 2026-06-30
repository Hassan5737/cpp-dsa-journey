# Common Mistakes

This document records common misconceptions encountered while learning complexity analysis.

The goal is not to collect mistakes, but to understand why they happen and how to avoid them in the future.

---

## Mistake #1

### Incorrect Assumption

Two consecutive loops always result in `O(n²)`.

### Correct Analysis

Consecutive loops **add** their complexities.

```cpp
for (int i = 0; i < n; i++)
{
    // ...
}

for (int i = 0; i < n; i++)
{
    // ...
}
```

```
O(n) + O(n)

↓

O(2n)

↓

O(n)
```

### Key Lesson

Sequential loops are added, not multiplied.

---

## Mistake #2

### Incorrect Assumption

Nested loops should always be added.

### Correct Analysis

Nested loops multiply their complexities.

```cpp
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {

    }
}
```

```
O(n)

×

O(n)

↓

O(n²)
```

### Key Lesson

Whenever a loop executes completely inside another loop, multiply their complexities.

---

## Mistake #3

### Incorrect Assumption

Accessing an array element requires linear time.

### Correct Analysis

```cpp
int value = arr[7];
```

```
O(1)
```

The memory address is calculated directly, so the operation takes constant time.

### Key Lesson

Array indexing is always constant time.

---

## Mistake #4

### Incorrect Assumption

A loop that doubles its iterator has linear complexity.

### Correct Analysis

```cpp
for (int i = 1; i < n; i *= 2)
{

}
```

```
O(log n)
```

Each iteration reduces the remaining work exponentially.

### Key Lesson

Repeated multiplication or division usually indicates logarithmic complexity.

---

## Mistake #5

### Incorrect Assumption

Constants affect Big O notation.

### Correct Analysis

```
O(5n)

↓

O(n)
```

```
O(100)

↓

O(1)
```

Constant factors are ignored because they do not affect the growth rate.

### Key Lesson

Focus on scalability, not exact operation counts.

---

## Mistake #6

### Incorrect Assumption

Lower-order terms should always be included.

### Correct Analysis

```
O(n² + n)

↓

O(n²)
```

The dominant term determines the overall complexity.

### Key Lesson

Ignore lower-order terms when expressing Big O.

---

## Final Reminder

When analyzing an algorithm, always follow this order:

1. Count the loops.
2. Determine how many times each loop executes.
3. Decide whether the loops are sequential or nested.
4. Apply the correct rule (add or multiply).
5. Remove constants and lower-order terms.
6. Keep only the dominant growth rate.