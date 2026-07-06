# Arrays Practice Exercises

This document contains practice exercises covering the fundamentals of arrays.

> **Rule:** Try solving each exercise before revealing the solution.

---

# Exercise 1

## Create an Array

Create an integer array named `numbers` that stores five values:

```
10 20 30 40 50
```

### Hint

Use array initialization.

<details>
<summary><strong>Solution</strong></summary>

```cpp
int numbers[5] = {10, 20, 30, 40, 50};
```

</details>

---

# Exercise 2

## Access an Element

Print the third element of the following array.

```cpp
int numbers[5] = {10, 20, 30, 40, 50};
```

### Hint

Remember that array indexing starts from zero.

<details>
<summary><strong>Solution</strong></summary>

```cpp
cout << numbers[2];
```

</details>

---

# Exercise 3

## Update an Element

Replace the value `30` with `100`.

### Hint

Modify the element using its index.

<details>
<summary><strong>Solution</strong></summary>

```cpp
numbers[2] = 100;
```

</details>

---

# Exercise 4

## Read User Input

Write a program that reads five integers into an array.

### Hint

Use a `for` loop.

<details>
<summary><strong>Solution</strong></summary>

```cpp
int numbers[5];

for (int i = 0; i < 5; i++)
{
    cin >> numbers[i];
}
```

</details>

---

# Exercise 5

## Traverse an Array

Print every element of the array.

### Hint

Visit each index exactly once.

<details>
<summary><strong>Solution</strong></summary>

```cpp
for (int i = 0; i < 5; i++)
{
    cout << numbers[i] << " ";
}
```

</details>

---

# Exercise 6

## Find the Largest Element

Write a program that finds the largest value in an integer array.

### Hint

Keep track of the current maximum while traversing the array.

<details>
<summary><strong>Solution</strong></summary>

```cpp
int maximum = numbers[0];

for (int i = 1; i < 5; i++)
{
    if (numbers[i] > maximum)
    {
        maximum = numbers[i];
    }
}

cout << maximum;
```

</details>

---

# Exercise 7

## Calculate the Sum

Calculate the sum of all elements in the array.

### Hint

Initialize a variable to zero and accumulate the values.

<details>
<summary><strong>Solution</strong></summary>

```cpp
int sum = 0;

for (int i = 0; i < 5; i++)
{
    sum += numbers[i];
}

cout << sum;
```

</details>

---

# Exercise 8

## Reverse Printing

Print the array elements in reverse order without modifying the array.

### Hint

Start from the last index.

<details>
<summary><strong>Solution</strong></summary>

```cpp
for (int i = 4; i >= 0; i--)
{
    cout << numbers[i] << " ";
}
```

</details>

---

# Self-Assessment Checklist

Before moving to the next topic, make sure you can:

- Declare an array.
- Initialize an array.
- Access elements by index.
- Update elements.
- Read input into an array.
- Traverse an array.
- Find the maximum element.
- Calculate the sum of all elements.
- Print the array in reverse order.