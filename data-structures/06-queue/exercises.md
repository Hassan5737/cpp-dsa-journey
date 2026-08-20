# Queue — Practice Exercises

These exercises are designed to reinforce the concepts covered in the
Array-Based Queue module.

The exercises progress from basic Queue operations to implementation,
analysis, debugging, and design challenges.

---

## Exercise 1 — Basic Enqueue

Create a Queue with a capacity of 5 and insert the following values:

10, 20, 30

Then display the Queue.

Expected order:

10 20 30

### Goal

Practice the basic `enqueue()` operation and understand how elements are
added at the Rear.

---

## Exercise 2 — Basic Dequeue

Create a Queue with the following elements:

10, 20, 30

Perform one `dequeue()` operation.

Display the Queue afterward.

Expected remaining elements:

20 30

### Goal

Understand that Queue elements are removed from the Front.

---

## Exercise 3 — FIFO Verification

Insert:

10, 20, 30, 40

Then repeatedly dequeue all elements.

Record the order in which they are removed.

### Question

Does the removal order match the insertion order?

### Expected Result

10 → 20 → 30 → 40

### Goal

Verify the FIFO principle.

---

## Exercise 4 — Peek Without Removal

Create a Queue containing:

100, 200, 300

Call `peek()`.

Then display the Queue.

### Questions

1. What value does `peek()` return?
2. Was the element removed?
3. What is the Queue state afterward?

### Goal

Understand the difference between `peek()` and `dequeue()`.

---

## Exercise 5 — Empty Queue

Create an empty Queue.

Try to perform:

- `dequeue()`
- `peek()`

### Questions

1. What should happen?
2. Why should the operations fail?
3. Which Queue condition is being handled?

### Expected Concept

Queue Underflow.

---

## Exercise 6 — Full Queue

Create a Queue with capacity 3.

Insert:

10, 20, 30

Then try:

40

### Questions

1. What should happen?
2. Why can the fourth element not be inserted?
3. Which condition is being handled?

### Expected Concept

Queue Overflow.

---

## Exercise 7 — Single Element

Create an empty Queue.

Perform:

enqueue(50)

Then:

dequeue()

### Questions

1. What should `front` represent before the dequeue?
2. What should `rear` represent before the dequeue?
3. What should the Queue state be after the dequeue?
4. What should happen to `front` and `rear` when the Queue becomes empty?

### Goal

Practice the important single-element edge case.

---

## Exercise 8 — Multiple Operations

Start with an empty Queue with capacity 5.

Perform the following operations:

enqueue(10)
enqueue(20)
enqueue(30)
dequeue()
enqueue(40)
dequeue()
enqueue(50)

### Questions

1. What is the final Queue?
2. What is the Front element?
3. What is the Rear element?
4. How many elements are currently stored?

### Goal

Track Queue state across multiple operations.

---

## Exercise 9 — State Tracking

Consider a Queue with capacity 5.

Starting state:

front = 0
rear = -1
count = 0

Perform:

enqueue(10)
enqueue(20)
enqueue(30)
dequeue()
enqueue(40)

After every operation, write down:

- `front`
- `rear`
- `count`

### Goal

Develop the ability to reason about Queue state without executing the program.

---

## Exercise 10 — Time Complexity

Determine the time complexity of the following operations in the implemented
array-based Queue:

- `enqueue()`
- `dequeue()`
- `peek()`
- `isEmpty()`
- `isFull()`
- `display()`

### Expected Answer

enqueue()  → O(1)
dequeue()  → O(1)
peek()     → O(1)
isEmpty()  → O(1)
isFull()   → O(1)
display()  → O(n)

### Question

Why is `display()` O(n) while `peek()` is O(1)?

---

## Exercise 11 — Why Not Shift?

Suppose a Queue contains:

[    ][ 20 ][ 30 ][ 40 ][ 50 ]

After removing the first element, someone suggests shifting the remaining
elements toward the beginning.

### Questions

1. What would the resulting array look like?
2. What would be the time complexity of shifting?
3. Why would this make `dequeue()` less efficient?
4. Why is simply moving `front` preferable?

### Goal

Understand why the Queue does not need to physically remove array elements.

---

## Exercise 12 — Linear Queue Limitation

Consider a Queue with capacity 5:

[    ][    ][ 30 ][ 40 ][ 50 ]

Assume `rear` is already at the last array position.

### Questions

1. Is there free memory in the array?
2. Is the Queue still considered full by the linear implementation?
3. Why can't the Queue reuse the first two positions?
4. What data structure solves this problem?

### Expected Concept

Circular Queue.

---

## Exercise 13 — Implement Size

Add a member function:

size()

that returns the current number of elements in the Queue.

### Requirements

- It should run in O(1).
- It should not traverse the array.
- It should remain correct after every enqueue and dequeue.

### Goal

Practice maintaining additional internal state.

---

## Exercise 14 — Implement Clear

Add a member function:

clear()

that removes all elements from the Queue.

### Requirements

After calling `clear()`:

- Queue must be empty.
- `count` must be zero.
- `front` and `rear` must represent an empty Queue.
- The allocated memory should remain available for reuse.

### Goal

Understand the difference between clearing data and destroying the
underlying data structure.

---

## Exercise 15 — Implement Rear Peek

Add a function:

rearValue()

that returns the last active element without removing it.

### Requirements

- Return failure if the Queue is empty.
- Operation must run in O(1).
- Do not traverse the Queue.

### Goal

Practice accessing the Rear while preserving Queue state.

---

## Exercise 16 — Debugging Challenge

Consider the following logic:

enqueue():

rear++;
arr[rear] = value;

dequeue():

value = arr[front];
front++;

### Question

What problems could occur if there are no checks for:

- Full Queue
- Empty Queue
- Array boundaries

Explain the possible consequences.

### Goal

Understand why defensive checks are essential.

---

## Exercise 17 — Memory Management

Suppose the Queue contains:

int* arr;

and memory is allocated using:

arr = new int[capacity];

### Questions

1. What happens if `delete[] arr` is never called?
2. What type of problem can this cause?
3. Where should the cleanup normally happen in a class-based design?
4. Why must `delete[]` be used instead of `delete`?

### Expected Concepts

- Memory leak
- Destructor
- Dynamic memory management
- Array deletion

---

## Exercise 18 — Encapsulation

Consider this design:

public:
    int* arr;
    int front;
    int rear;

### Questions

1. Why is exposing these members publicly dangerous?
2. How could external code corrupt the Queue state?
3. How does making them private improve the design?

### Goal

Understand why Data Structures should protect their internal state.

---

## Exercise 19 — Improve the Interface

Design a cleaner Queue interface containing operations such as:

enqueue()
dequeue()
peek()
isEmpty()
isFull()
size()
clear()
display()

### Questions

1. Which functions should return `bool`?
2. Which functions should be `const`?
3. Which internal members should remain private?
4. Which operations modify the Queue?
5. Which operations only inspect the Queue?

### Goal

Practice designing a clean object-oriented interface.

---

## Exercise 20 — Array Queue vs Linked List Queue

Compare an array-based Queue with a linked-list-based Queue.

Complete the following table:

| Feature | Array-Based Queue | Linked-List-Based Queue |
|---------|-------------------|-------------------------|
| Capacity | ? | ? |
| Memory allocation | ? | ? |
| Dynamic growth | ? | ? |
| Memory overhead | ? | ? |
| Cache locality | ? | ? |
| Implementation complexity | ? | ? |

### Goal

Understand the trade-offs between different Queue implementations.

---

## Exercise 21 — Design Challenge

Design a Queue class that satisfies the following requirements:

- Dynamic capacity
- Encapsulation
- FIFO behavior
- O(1) enqueue
- O(1) dequeue
- O(1) peek
- Safe overflow handling
- Safe underflow handling
- Proper memory management

### Question

Would a simple linear array-based Queue still be the best design?

Explain your answer.

---

## Exercise 22 — Circular Queue Challenge

The linear Queue has a space-utilization problem.

Design a Circular Queue that allows:

- Rear to wrap around
- Reuse of freed positions
- O(1) enqueue
- O(1) dequeue

### Questions

1. How should `rear` move when it reaches the last index?
2. How should `front` move when it reaches the last index?
3. How can you determine whether the Queue is empty?
4. How can you determine whether it is full?

### Goal

Prepare for the next Queue implementation.

---

## Exercise 23 — Algorithmic Thinking

Given a Queue containing:

10, 20, 30, 40, 50

You need to remove only the element `30`.

### Constraint

You are only allowed to use Queue operations.

### Questions

1. How can you temporarily move elements?
2. How can you preserve the original order of the remaining elements?
3. What is the resulting Queue?

### Goal

Practice solving problems using the abstraction provided by a data structure
instead of directly manipulating its internal representation.

---

## Exercise 24 — Real-World Design

Design a Queue-based system for a printer.

Each print job contains:

- Job ID
- Document name
- Number of pages

### Requirements

- New jobs are added to the Rear.
- Jobs are processed from the Front.
- Users can view the next job.
- The system should report when the Queue is empty.
- The system should report when the Queue is full.

### Goal

Connect the Queue abstraction to a practical software system.

---

## Exercise 25 — Challenge

Build a complete reusable Queue class from scratch.

Your implementation should include:

- Dynamic memory allocation
- Constructor
- Destructor
- `enqueue()`
- `dequeue()`
- `peek()`
- `isEmpty()`
- `isFull()`
- `size()`
- `clear()`
- `display()`
- Overflow handling
- Underflow handling
- Edge-case handling
- Encapsulation
- Const correctness

### Additional Requirements

Document the time complexity of every operation.

Test the Queue with:

- Empty state
- Single element
- Multiple elements
- Full state
- Overflow
- Underflow
- Repeated enqueue/dequeue operations

### Goal

Create a clean, reusable, and well-tested Queue implementation that
demonstrates your understanding of the complete module.

---

## Reflection Questions

After completing the exercises, answer the following questions:

1. Why does a Queue use FIFO?
2. Why are enqueue and dequeue performed at opposite ends?
3. Why is `dequeue()` O(1) in the current implementation?
4. Why would shifting elements make dequeue O(n)?
5. What is Queue Overflow?
6. What is Queue Underflow?
7. What happens when a Queue contains exactly one element?
8. What is the main limitation of a linear array-based Queue?
9. Why does a Circular Queue solve the space-utilization problem?
10. When would you choose an array-based Queue over a linked-list-based Queue?

---

## Completion Checklist

Before considering this module complete, make sure you can:

- [ ] Explain the FIFO principle.
- [ ] Explain Front and Rear.
- [ ] Implement `enqueue()`.
- [ ] Implement `dequeue()`.
- [ ] Implement `peek()`.
- [ ] Implement `isEmpty()`.
- [ ] Implement `isFull()`.
- [ ] Handle Overflow.
- [ ] Handle Underflow.
- [ ] Handle the single-element case.
- [ ] Explain the time complexity of Queue operations.
- [ ] Explain the limitations of a linear Queue.
- [ ] Explain why Circular Queues are useful.
- [ ] Manage dynamic memory correctly.
- [ ] Apply encapsulation.
- [ ] Design a reusable Queue class.
- [ ] Solve Queue problems using only Queue operations.