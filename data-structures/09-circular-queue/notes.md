# Circular Queue: Notes

## 1. Overview

A Circular Queue is a linear data structure that follows the **FIFO (First In, First Out)** principle.

Unlike a traditional array-based queue, a Circular Queue connects the last position back to the first position, creating a circular structure.

This allows the queue to reuse previously occupied positions after elements are removed.

---

## 2. Why Circular Queue?

In a traditional array-based queue, removing elements from the front does not automatically make those positions reusable if the rear pointer only moves forward.

A Circular Queue solves this limitation by using circular indexing.

**Main advantages:**

- Efficient memory utilization.
- Reuses available positions.
- Avoids shifting elements after dequeue.
- Provides constant-time insertion and removal.

---

## 3. Internal Structure

A typical array-based Circular Queue maintains:

| Member | Purpose |
|---|---|
| `data` | Stores queue elements |
| `frontIndex` | Points to the first element |
| `rearIndex` | Points to the next insertion position |
| `currentSize` | Tracks the number of stored elements |

The queue also has a fixed capacity.

### Important distinction

`rearIndex` represents the next available insertion position, not necessarily the index of the last stored element.

The last stored element is located at:

```cpp
(rearIndex + capacity - 1) % capacity
```

---

## 4. Circular Indexing

Circular indexing is the core mechanism of a Circular Queue.

The next position is calculated using the modulo operator:

\[
nextIndex = (currentIndex + 1) \bmod capacity
\]

Example with a capacity of 5:

| Current Index | Next Index |
|---:|---:|
| 0 | 1 |
| 1 | 2 |
| 2 | 3 |
| 3 | 4 |
| 4 | 0 |

When the last index is reached, the next position becomes zero.

---

## 5. Queue States

The implementation uses a separate size counter to distinguish between empty and full states.

### Empty Condition

```cpp
currentSize == 0
```

### Full Condition

```cpp
currentSize == data.size()
```

This approach allows the queue to use every available position.

For example, a queue with a capacity of 5 can store exactly 5 elements.

---

## 6. Core Operations

### Enqueue

Adds an element at the rear of the queue.

General steps:

1. Check whether the queue is full.
2. Insert the element at `rearIndex`.
3. Advance `rearIndex` circularly.
4. Increase `currentSize`.

### Dequeue

Removes the front element.

General steps:

1. Check whether the queue is empty.
2. Retrieve the front element.
3. Advance `frontIndex` circularly.
4. Decrease `currentSize`.
5. Reset the indices when the queue becomes empty, if that is the chosen implementation strategy.

### Front

Returns the first element without removing it.

### Back

Returns the last element without removing it.

### Clear

Resets the queue to its initial empty state.

### Display

Traverses the logical queue elements using circular indexing.

---

## 7. Object-Oriented Design

A Circular Queue can be implemented as a class to encapsulate its internal state and operations.

Important OOP principles:

- **Encapsulation:** Keep internal data members private.
- **Abstraction:** Expose a clear public interface.
- **Generic Programming:** Use templates to support different data types.

Example:

```cpp
template <typename T>
class CircularQueue
{
private:
    // Internal state

public:
    // Public operations
};
```

---

## 8. Generic Programming

Using:

```cpp
template <typename T>
```

allows the same Circular Queue implementation to work with multiple data types.

Examples:

```cpp
CircularQueue<int> numbers(5);

CircularQueue<double> measurements(10);

CircularQueue<std::string> messages(8);
```

This avoids writing separate implementations for each data type.

---

## 9. Handling Empty Results

Operations such as `dequeue()` may not always produce a value.

One approach is using `std::optional<T>`:

```cpp
std::optional<T> dequeue();
```

An empty result can be represented using:

```cpp
std::nullopt
```

This avoids returning an arbitrary value when the queue is empty.

---

## 10. Time Complexity

| Operation | Time Complexity |
|---|---|
| Enqueue | O(1) |
| Dequeue | O(1) |
| Front | O(1) |
| Back | O(1) |
| Is Empty | O(1) |
| Is Full | O(1) |
| Size | O(1) |
| Clear | O(1) |
| Display | O(n) |

Where `n` represents the number of elements currently stored.

### Space Complexity

\[
O(C)
\]

Where `C` represents the queue capacity.

---

## 11. Common Applications

Circular Queues are useful in systems that repeatedly reuse a fixed-size buffer.

Examples include:

- CPU scheduling.
- Round-robin scheduling.
- Network packet buffering.
- Keyboard input buffering.
- Audio and video streaming buffers.
- Producer-consumer systems.

---

## 12. Important Implementation Considerations

- Never perform modulo by zero.
- Check queue boundaries before accessing or modifying elements.
- Keep the size counter synchronized with insertion and removal operations.
- Use circular indexing to prevent out-of-range positions.
- Keep internal state private.
- Define clear behavior for empty and full queues.
- Avoid assuming that logical elements occupy consecutive array positions.

---

## 13. Key Takeaways

- A Circular Queue follows FIFO ordering.
- Circular indexing allows positions to be reused.
- The modulo operator handles wrap-around.
- A separate size counter allows all array positions to be utilized.
- Enqueue and dequeue operations take O(1) time.
- Object-oriented design provides encapsulation and a clean interface.
- Templates make the implementation reusable across different data types.

---

## 14. Further Learning

After understanding Circular Queues, explore:

- Deque (Double-Ended Queue).
- Circular Buffer.
- Queue Implementation Using Linked Lists.
- Priority Queue.
- Producer-Consumer Problem.