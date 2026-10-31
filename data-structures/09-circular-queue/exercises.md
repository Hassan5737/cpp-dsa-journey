# Circular Queue Exercises

A collection of exercises designed to strengthen your understanding of Circular Queues, array-based implementations, and object-oriented design.

Try to solve each exercise independently before checking its solution.

---

## Table of Contents

- [Exercise 1: Basic Operations](#exercise-1-basic-operations)
- [Exercise 2: Circular Index Calculation](#exercise-2-circular-index-calculation)
- [Exercise 3: Trace the Queue](#exercise-3-trace-the-queue)
- [Exercise 4: Handle Full Queue](#exercise-4-handle-full-queue)
- [Exercise 5: Implement a Queue Using Templates](#exercise-5-implement-a-queue-using-templates)
- [Exercise 6: Reverse a Circular Queue](#exercise-6-reverse-a-circular-queue)
- [Exercise 7: Queue Rotation](#exercise-7-queue-rotation)
- [Exercise 8: Complexity Analysis](#exercise-8-complexity-analysis)

---

## Exercise 1: Basic Operations

Create a Circular Queue with a capacity of 5.

Perform the following operations:

1. Insert `10`, `20`, and `30`.
2. Display the queue.
3. Remove one element.
4. Insert `40` and `50`.
5. Display the front and rear elements.
6. Check whether the queue is empty or full.

**Goal:** Understand the basic behavior of Circular Queue operations.

<details>
<summary>Solution</summary>

```cpp
CircularQueue<int> queue(5);

queue.enqueue(10);
queue.enqueue(20);
queue.enqueue(30);

queue.display();

queue.dequeue();

queue.enqueue(40);
queue.enqueue(50);

queue.display();

if (queue.front())
    std::cout << "Front: " << *queue.front() << '\n';

if (queue.back())
    std::cout << "Rear: " << *queue.back() << '\n';

std::cout << "Empty: " << queue.isEmpty() << '\n';
std::cout << "Full: " << queue.isFull() << '\n';
```

</details>

---

## Exercise 2: Circular Index Calculation

Assume a Circular Queue has a capacity of 6.

The current rear index is `5`.

1. Calculate the next rear index.
2. Explain why the index returns to `0`.
3. Write a C++ expression that calculates the next circular index.

**Goal:** Understand circular indexing and the modulo operator.

<details>
<summary>Solution</summary>

```cpp
std::size_t nextIndex = (5 + 1) % 6;
```

Result:

```text
0
```

The modulo operator ensures that the index stays within the valid array range.

</details>

---

## Exercise 3: Trace the Queue

Consider a Circular Queue with a capacity of 5.

Execute these operations in order:

```text
enqueue(10)
enqueue(20)
enqueue(30)
dequeue()
enqueue(40)
enqueue(50)
dequeue()
enqueue(60)
```

Determine:

1. The final queue contents.
2. The final front element.
3. The final rear element.
4. The current size.
5. Whether the queue is full.

**Goal:** Practice tracing front and rear positions.

<details>
<summary>Solution</summary>

Final logical queue:

```text
Queue: 30 40 50 60
Front: 30
Rear: 60
Size: 4
Full: No
```

The queue reuses positions that became available after dequeue operations.

</details>

---

## Exercise 4: Handle Full Queue

Modify the `enqueue()` operation so that it handles a full queue safely.

Requirements:

1. Detect when the queue is full.
2. Prevent insertion when no space is available.
3. Report the error using an appropriate exception.
4. Ensure that the queue state remains unchanged after a failed insertion.

**Goal:** Practice boundary validation and exception handling.

<details>
<summary>Solution</summary>

```cpp
void enqueue(const T& value)
{
    if (isFull())
    {
        throw std::overflow_error("Queue is full.");
    }

    data[rearIndex] = value;
    rearIndex = nextIndex(rearIndex);
    ++currentSize;
}
```

The full condition is checked before modifying the queue.

</details>

---

## Exercise 5: Implement a Queue Using Templates

Create a generic Circular Queue class that supports different data types.

Requirements:

- Use `template <typename T>`.
- Store elements using `std::vector<T>`.
- Keep internal state private.
- Implement `enqueue()`, `dequeue()`, `front()`, and `isEmpty()`.
- Support both integer and string values.

**Goal:** Apply OOP principles and generic programming.

<details>
<summary>Solution</summary>

```cpp
CircularQueue<int> numbers(5);
numbers.enqueue(100);
numbers.enqueue(200);

CircularQueue<std::string> words(5);
words.enqueue("Backend");
words.enqueue("Systems");
```

The same class can manage different data types without duplicating its implementation.

</details>

---

## Exercise 6: Reverse a Circular Queue

Implement a function that reverses the logical order of elements in a Circular Queue.

Example:

```text
Before:
10 20 30 40

After:
40 30 20 10
```

**Goal:** Practice queue traversal and element manipulation.

<details>
<summary>Solution</summary>

One possible approach is to remove all elements into a temporary stack, then insert them back into the queue.

```cpp
#include <stack>

template <typename T>
void reverseQueue(CircularQueue<T>& queue)
{
    std::stack<T> temporary;

    while (!queue.isEmpty())
    {
        temporary.push(*queue.dequeue());
    }

    while (!temporary.empty())
    {
        queue.enqueue(temporary.top());
        temporary.pop();
    }
}
```

This approach uses O(n) additional space and O(n) time.

</details>

---

## Exercise 7: Queue Rotation

Implement a function that rotates the queue to the left by `k` positions.

Example:

```text
Original:
10 20 30 40 50

Rotate left by 2:

Result:
30 40 50 10 20
```

**Goal:** Understand how circular movement can be used to implement rotation.

<details>
<summary>Solution</summary>

```cpp
template <typename T>
void rotateLeft(CircularQueue<T>& queue, std::size_t k)
{
    if (queue.isEmpty())
    {
        return;
    }

    k %= queue.size();

    for (std::size_t i = 0; i < k; ++i)
    {
        auto value = queue.dequeue();

        if (value)
        {
            queue.enqueue(*value);
        }
    }
}
```

Each rotation removes the front element and inserts it at the rear.

Time Complexity: O(k).

</details>

---

## Exercise 8: Complexity Analysis

Complete the following table for an array-based Circular Queue.

| Operation | Time Complexity |
|---|---|
| Enqueue | ? |
| Dequeue | ? |
| Front | ? |
| Back | ? |
| Is Empty | ? |
| Is Full | ? |
| Display | ? |

**Goal:** Understand the performance characteristics of Circular Queue operations.

<details>
<summary>Solution</summary>

| Operation | Time Complexity |
|---|---|
| Enqueue | O(1) |
| Dequeue | O(1) |
| Front | O(1) |
| Back | O(1) |
| Is Empty | O(1) |
| Is Full | O(1) |
| Display | O(n) |

</details>

---

## Learning Objectives

After completing these exercises, you should be able to:

- Understand circular indexing.
- Trace front and rear positions.
- Handle full and empty queue conditions.
- Implement a generic Circular Queue.
- Apply object-oriented programming principles.
- Use Circular Queue operations to solve practical problems.
- Analyze time and space complexity.