# Circular Queue: Common Mistakes

This document covers common mistakes encountered when implementing and working with Circular Queues using arrays and object-oriented programming.

Understanding these mistakes helps prevent logical errors, invalid memory access, and incorrect queue behavior.

---

## Table of Contents

- [1. Incorrect Full Condition](#1-incorrect-full-condition)
- [2. Incorrect Circular Index Calculation](#2-incorrect-circular-index-calculation)
- [3. Confusing Empty and Full States](#3-confusing-empty-and-full-states)
- [4. Incorrect Dequeue Logic](#4-incorrect-dequeue-logic)
- [5. Forgetting to Update the Queue Size](#5-forgetting-to-update-the-queue-size)
- [6. Accessing Elements in an Empty Queue](#6-accessing-elements-in-an-empty-queue)
- [7. Incorrect Display Traversal](#7-incorrect-display-traversal)
- [8. Not Handling Zero Capacity](#8-not-handling-zero-capacity)
- [9. Modifying State Before Validation](#9-modifying-state-before-validation)
- [10. Violating Encapsulation](#10-violating-encapsulation)

---

## 1. Incorrect Full Condition

**Problem:**

Using an incorrect condition to determine whether the queue is full.

```cpp
return rearIndex == capacity - 1;
```

**Why is it wrong?**

A Circular Queue allows the rear index to wrap around to the beginning of the array. Checking only whether the rear index has reached the last position does not correctly identify a full queue.

**Correct approach:**

When tracking the number of stored elements:

```cpp
return currentSize == data.size();
```

---

## 2. Incorrect Circular Index Calculation

**Problem:**

Incrementing an index without wrapping it around.

```cpp
rearIndex++;
```

**Why is it wrong?**

The index may move outside the valid array boundaries, resulting in invalid memory access.

**Correct approach:**

```cpp
rearIndex = (rearIndex + 1) % data.size();
```

This ensures that the next index always remains within the valid range.

---

## 3. Confusing Empty and Full States

**Problem:**

Using the same condition to identify both empty and full states.

**Why is it wrong?**

The implementation may incorrectly reject valid insertions or allow invalid removals.

**Correct approach:**

When using a separate size counter:

```cpp
bool isEmpty() const
{
    return currentSize == 0;
}

bool isFull() const
{
    return currentSize == data.size();
}
```

The size counter distinguishes the two states clearly.

---

## 4. Incorrect Dequeue Logic

**Problem:**

Removing an element without updating the front index or current size.

```cpp
void dequeue()
{
    // Remove the element only.
}
```

**Why is it wrong?**

The queue's logical state becomes inconsistent. The removed element may still appear to be part of the queue.

**Correct approach:**

```cpp
frontIndex = (frontIndex + 1) % data.size();
--currentSize;
```

The front index and element count must both be updated after a successful removal.

---

## 5. Forgetting to Update the Queue Size

**Problem:**

Updating the front or rear index without maintaining the size counter.

**Why is it wrong?**

The queue may report incorrect empty and full states.

**Correct approach:**

After a successful insertion:

```cpp
++currentSize;
```

After a successful removal:

```cpp
--currentSize;
```

The size must always represent the number of stored elements.

---

## 6. Accessing Elements in an Empty Queue

**Problem:**

Accessing the front element without checking whether the queue contains any elements.

```cpp
return data[frontIndex];
```

**Why is it wrong?**

The operation may return an invalid or stale value when the queue is empty.

**Correct approach:**

```cpp
const T* front() const noexcept
{
    if (isEmpty())
    {
        return nullptr;
    }

    return &data[frontIndex];
}
```

Alternatively, an interface using `std::optional` can explicitly represent the absence of a value.

---

## 7. Incorrect Display Traversal

**Problem:**

Displaying elements using a normal loop from the front index to the rear index.

```cpp
for (std::size_t i = frontIndex; i <= rearIndex; ++i)
{
    std::cout << data[i] << ' ';
}
```

**Why is it wrong?**

The logical queue may wrap around the end of the underlying array. A normal increasing loop does not correctly handle this situation.

**Correct approach:**

Traverse exactly `currentSize` elements using circular indexing:

```cpp
for (std::size_t i = 0; i < currentSize; ++i)
{
    std::size_t index =
        (frontIndex + i) % data.size();

    std::cout << data[index] << ' ';
}
```

---

## 8. Not Handling Zero Capacity

**Problem:**

Creating a Circular Queue with zero capacity.

```cpp
CircularQueue<int> queue(0);
```

**Why is it wrong?**

Circular index calculations use the modulo operator. Modulo by zero is invalid.

**Correct approach:**

Reject zero capacity during construction:

```cpp
if (capacity == 0)
{
    throw std::invalid_argument(
        "Capacity must be greater than zero."
    );
}
```

---

## 9. Modifying State Before Validation

**Problem:**

Updating the rear index before checking whether the queue is full.

**Why is it wrong?**

A failed insertion may leave the internal state inconsistent.

**Correct approach:**

Always validate the operation before modifying the queue:

```cpp
void enqueue(const T& value)
{
    if (isFull())
    {
        throw std::overflow_error("Queue is full.");
    }

    data[rearIndex] = value;
    rearIndex = (rearIndex + 1) % data.size();
    ++currentSize;
}
```

---

## 10. Violating Encapsulation

**Problem:**

Making internal queue members publicly accessible.

```cpp
public:
    std::vector<T> data;
    std::size_t frontIndex;
    std::size_t rearIndex;
```

**Why is it wrong?**

External code can modify the internal state directly, potentially breaking the queue's invariants.

**Correct approach:**

Keep implementation details private and expose controlled public operations:

```cpp
private:
    std::vector<T> data;
    std::size_t frontIndex;
    std::size_t rearIndex;
    std::size_t currentSize;
```

This protects the internal state and makes the class easier to maintain.

---

## Key Takeaways

- Always use circular indexing to keep positions within array boundaries.
- Track the number of stored elements to distinguish full and empty states.
- Validate operations before modifying internal state.
- Never access elements without checking the queue state.
- Traverse logical elements rather than assuming they occupy consecutive array positions.
- Handle zero capacity explicitly.
- Keep internal implementation details private.
- Maintain consistent front, rear, and size values after every operation.

A reliable Circular Queue implementation depends on maintaining its internal invariants throughout every operation.