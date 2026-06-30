# Complexity Analysis Exercises

This document contains practice exercises designed to strengthen complexity analysis skills.

> **Rule:** Try to solve each exercise before revealing the solution.

---

# Exercise 1

## Analyze the following code.

```cpp
int value = arr[7];
```

### Think First

What is the time complexity of accessing an array element by its index?

---

### Hint

How many operations are required regardless of the array size?

---

<details>
<summary><strong>Solution</strong></summary>

```
O(1)
```

Accessing an array element by index always takes constant time because the memory address is calculated directly.

</details>

---

# Exercise 2

## Analyze the following code.

```cpp
for (int i = 0; i < n; i++)
{
    cout << i;
}
```

### Think First

How many iterations does the loop execute?

---

### Hint

The loop visits every element exactly once.

---

<details>
<summary><strong>Solution</strong></summary>

```
O(n)
```

The loop executes exactly **n** times.

</details>

---

# Exercise 3

## Analyze the following code.

```cpp
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        cout << i << j;
    }
}
```

### Think First

Are the loops sequential or nested?

---

### Hint

Nested loops multiply their complexities.

---

<details>
<summary><strong>Solution</strong></summary>

```
O(n²)
```

The outer loop executes **n** times, and for each iteration the inner loop also executes **n** times.

</details>

---

# Exercise 4

## Analyze the following code.

```cpp
for (int i = 1; i < n; i *= 2)
{
    cout << i;
}
```

### Think First

How does the iterator change after every iteration?

---

### Hint

The iterator doubles every iteration.

---

<details>
<summary><strong>Solution</strong></summary>

```
O(log n)
```

Each iteration doubles the iterator, so the number of iterations grows logarithmically.

</details>

---

# Exercise 5

## Analyze the following code.

```cpp
for (int i = 1; i < n; i *= 2)
{
    for (int j = 0; j < n; j++)
    {
        cout << i << j;
    }
}
```

### Think First

Determine the complexity of each loop separately before combining them.

---

### Hint

The outer loop is logarithmic.

The inner loop is linear.

---

<details>
<summary><strong>Solution</strong></summary>

```
O(n log n)
```

Outer loop:

```
O(log n)
```

Inner loop:

```
O(n)
```

Nested loops multiply.

```
O(log n)

×

O(n)

↓

O(n log n)
```

</details>

---

# Exercise 6

## Analyze the following code.

```cpp
for (int i = 0; i < n; i++)
{
    cout << i;
}

for (int j = 0; j < n; j++)
{
    cout << j;
}
```

### Think First

Are the loops nested?

---

### Hint

Consecutive loops add their complexities.

---

<details>
<summary><strong>Solution</strong></summary>

```
O(n)
```

```
O(n)

+

O(n)

↓

O(2n)

↓

O(n)
```

</details>

---

# Self-Assessment Checklist

Before checking the solution, ask yourself:

- Did I identify every loop?
- Did I determine how many times each loop executes?
- Did I recognize whether the loops are nested or sequential?
- Did I simplify the final complexity correctly?
- Did I remove constants and lower-order terms?