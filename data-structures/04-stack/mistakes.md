# Common Stack Mistakes

This document highlights common mistakes developers make when implementing a stack using an array and explains how to avoid them.

---

# Mistake 1

## Forgetting to Check for Overflow

Attempting to push an element into a full stack results in writing beyond the array bounds.

### Incorrect

```cpp
data[++topIndex] = value;
```

### Correct

```cpp
if (isFull())
{
    return;
}

data[++topIndex] = value;
```

Always verify that the stack has available space before inserting a new element.

---

# Mistake 2

## Forgetting to Check for Underflow

Calling `pop()` or `peek()` on an empty stack leads to invalid access.

### Incorrect

```cpp
return data[topIndex--];
```

### Correct

```cpp
if (isEmpty())
{
    return -1;
}

return data[topIndex--];
```

Always check whether the stack is empty before accessing the top element.

---

# Mistake 3

## Using an Incorrect Initial Value for the Top Index

The stack should start empty.

### Incorrect

```cpp
int topIndex = 0;
```

### Correct

```cpp
int topIndex = -1;
```

Using `-1` clearly indicates that no elements are stored.

---

# Mistake 4

## Off-by-One Errors

The last valid index in the array is:

```cpp
CAPACITY - 1
```

Checking against `CAPACITY` is incorrect and may cause out-of-bounds access.

### Incorrect

```cpp
if (topIndex == CAPACITY)
```

### Correct

```cpp
if (topIndex == CAPACITY - 1)
```

---

# Mistake 5

## Confusing Pre-Increment and Post-Increment

The order of updating `topIndex` matters.

### Correct Push

```cpp
data[++topIndex] = value;
```

### Correct Pop

```cpp
return data[topIndex--];
```

Changing the increment or decrement order may access the wrong index.

---

# Mistake 6

## Clearing the Entire Array Unnecessarily

Some beginners reset every element in the array.

```cpp
for (int i = 0; i < CAPACITY; i++)
{
    data[i] = 0;
}
```

This is unnecessary.

Simply resetting the top index is sufficient.

```cpp
topIndex = -1;
```

---

# Mistake 7

## Accessing the Top Element Directly

Avoid accessing the array directly from outside the class.

### Incorrect

```cpp
cout << data[topIndex];
```

### Correct

```cpp
cout << peek();
```

Encapsulation protects the internal state of the stack.

---

# Mistake 8

## Ignoring the Return Value of Pop

The `pop()` operation returns the removed element.

Ignoring the returned value may waste useful information.

### Example

```cpp
int removedValue = pop();
```

---

# Best Practices

- Always check for overflow before pushing.
- Always check for underflow before popping or peeking.
- Keep the top index private.
- Use helper functions such as `isEmpty()` and `isFull()`.
- Give variables descriptive names.
- Keep the implementation simple and readable.
- Test empty, partially filled, and full stacks.

---

# Quick Checklist

Before considering your implementation complete, verify that:

- Overflow is handled correctly.
- Underflow is handled correctly.
- `topIndex` is initialized properly.
- Push updates the top correctly.
- Pop updates the top correctly.
- Peek does not remove elements.
- Display prints from top to bottom.
- The stack can be cleared successfully.