# Queue Using a Singly Linked List — Exercises

## 1. Basic Queue Operations

Create a Queue class using a Singly Linked List.

The class should support:

- enqueue()
- dequeue()
- peek()
- isEmpty()
- display()

### Requirements

The Queue must follow FIFO behavior.

Test it using:

10
20
30
40

Expected display:

10 20 30 40

After one dequeue:

20 30 40


## 2. Test FIFO Behavior

Insert the following values:

10
20
30
40
50

Then repeatedly call dequeue().

Expected removal order:

10
20
30
40
50

### Goal

Verify that the Queue always removes the oldest element first.


## 3. Test the Empty Queue

Create an empty Queue and test:

- dequeue()
- peek()
- display()
- isEmpty()

### Questions

1. Does the Queue crash?
2. Does dequeue() handle the empty state?
3. Does peek() handle the empty state?
4. Does display() handle the empty state?
5. Does isEmpty() return true?


## 4. Test a Single Element

Perform:

enqueue(100)

Then check:

- peek()
- display()
- dequeue()
- isEmpty()

Expected behavior:

Before dequeue:

front == rear

After dequeue:

front == nullptr
rear  == nullptr

### Goal

Verify that the single-element edge case is handled correctly.


## 5. Remove Until Empty

Perform:

enqueue(10)
enqueue(20)
enqueue(30)

Then:

dequeue()
dequeue()
dequeue()

At the end, verify:

front == nullptr
rear  == nullptr

Then try:

dequeue()
peek()
display()

### Goal

Verify that the Queue remains stable after becoming empty.


## 6. Reuse an Empty Queue

Perform:

enqueue(10)
dequeue()

Then:

enqueue(20)
enqueue(30)

Display the Queue.

Expected:

20 30

### Goal

Make sure the Queue can be reused after becoming empty.


## 7. Test Peek

Perform:

enqueue(10)
enqueue(20)
enqueue(30)

Call:

peek()

Expected:

10

Then display the Queue.

Expected:

10 20 30

### Goal

Verify that peek() does not remove the Front element.


## 8. Test Rear

Add a function that returns the value at the Rear.

Perform:

enqueue(10)
enqueue(20)
enqueue(30)

Expected Rear:

30

Then dequeue once.

Expected Rear:

30

Then enqueue:

40

Expected Rear:

40

### Goal

Verify that the Rear pointer always references the last node.


## 9. Queue Size

Add a size() function.

Example:

enqueue(10)
enqueue(20)
enqueue(30)

Expected:

size() → 3

After:

dequeue()

Expected:

size() → 2

After:

dequeue()
dequeue()

Expected:

size() → 0

### Goal

Keep the size synchronized with the actual number of nodes.


## 10. Clear Operation

Implement:

clear()

The function should remove every node from the Queue.

Example:

enqueue(10)
enqueue(20)
enqueue(30)

Then:

clear()

Expected state:

front = nullptr
rear  = nullptr
size  = 0

### Goal

Practice deleting every dynamically allocated node safely.


## 11. Destructor Test

Create a Queue object inside a local scope.

Example:

{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
}

When the scope ends, the destructor should automatically release all nodes.

### Goal

Verify that the Queue owns and properly cleans up its dynamic memory.


## 12. Copy Constructor

Implement a Copy Constructor.

Example:

Queue q1;

q1.enqueue(10);
q1.enqueue(20);
q1.enqueue(30);

Queue q2 = q1;

Then modify q2.

Example:

q2.dequeue();

Expected:

q1:

10 20 30

q2:

20 30

### Goal

Verify that q1 and q2 own different nodes.

Changing one Queue must not modify the other.


## 13. Copy Assignment Operator

Implement the Copy Assignment Operator.

Example:

Queue q1;
Queue q2;

q1.enqueue(10);
q1.enqueue(20);
q1.enqueue(30);

q2.enqueue(100);
q2.enqueue(200);

q2 = q1;

Expected:

q1:

10 20 30

q2:

10 20 30

Then modify q2.

Expected:

q1 remains unchanged.


## 14. Self Assignment

Test:

q = q;

The Queue should remain unchanged.

### Goal

Make sure the Copy Assignment Operator handles self-assignment safely.


## 15. Memory Leak Check

Create a Queue and perform many operations:

- enqueue
- dequeue
- enqueue
- dequeue
- clear
- enqueue
- dequeue

Make sure every dynamically allocated node is eventually deleted.

### Goal

Practice identifying ownership and lifetime of dynamically allocated memory.


## 16. Display Without Modifying the Queue

Implement display() using a temporary pointer.

The Queue should remain exactly the same after display().

Example:

Before:

10 20 30

Call:

display()

After:

10 20 30

### Important

Do not move the actual Front pointer during traversal.

Use a temporary pointer such as:

Node* current = front;


## 17. Reverse Display

Implement a function that displays the Queue in reverse order without changing the Queue.

Example:

Queue:

10 20 30 40

Reverse display:

40 30 20 10

### Challenge

Try solving it without modifying the Queue.

Think about whether recursion or another data structure can help.


## 18. Search

Implement:

contains(value)

Example:

Queue:

10 20 30 40

contains(30)

Expected:

true

contains(100)

Expected:

false

### Complexity

What is the time complexity of searching a linked-list-based Queue?

Answer:

O(n)


## 19. Count Occurrences

Implement:

count(value)

Example:

Queue:

10 20 10 30 10

count(10)

Expected:

3

### Goal

Practice traversing the linked list and counting matching values.


## 20. Get Maximum Value

Implement a function that returns the maximum value in the Queue.

Example:

Queue:

10 50 20 40 30

Expected:

50

### Complexity

O(n)


## 21. Get Minimum Value

Implement a function that returns the minimum value in the Queue.

Example:

Queue:

10 50 20 40 30

Expected:

10

### Complexity

O(n)


## 22. Compare Two Queues

Implement a function that checks whether two Queues contain the same values in the same order.

Example:

Queue A:

10 20 30

Queue B:

10 20 30

Expected:

true

Example:

Queue A:

10 20 30

Queue B:

10 30 20

Expected:

false


## 23. Merge Two Queues

Create a function that combines two Queues into a new Queue.

Example:

Queue A:

10 20 30

Queue B:

40 50 60

Result:

10 20 30 40 50 60

### Challenge

Decide whether the function should:

- Copy the elements
- Move the nodes
- Modify the original Queues

Document your design decision.


## 24. Rotate the Queue

Implement:

rotate(k)

Example:

Queue:

10 20 30 40 50

rotate(2)

Expected:

30 40 50 10 20

### Goal

Practice manipulating the Front and Rear pointers.


## 25. Reverse the Queue

Implement:

reverse()

Example:

Before:

10 20 30 40

After:

40 30 20 10

### Important

The Queue should remain a valid Queue after reversal.

The Front and Rear pointers must be updated correctly.


## 26. Complexity Analysis

For every operation in your Queue implementation, write its time complexity.

Analyze:

- enqueue()
- dequeue()
- peek()
- rear()
- isEmpty()
- size()
- display()
- clear()
- contains()
- getMax()
- getMin()

Then explain why each operation has that complexity.


## 27. Memory Analysis

Assume the Queue contains n nodes.

Answer:

1. What is the space complexity?
2. How much extra memory does each node require because of the next pointer?
3. What is the difference between Queue storage and temporary traversal storage?


## 28. Array vs Linked List Challenge

Compare the following two implementations:

Queue Using Array

Queue Using Singly Linked List

Create a table containing:

- Storage model
- Fixed or dynamic size
- Enqueue complexity
- Dequeue complexity
- Memory overhead
- Cache locality
- Overflow behavior
- Memory allocation behavior

Then explain which implementation you would choose in different situations.


## 29. Debugging Challenge

The following Queue has a bug:

enqueue(10)
enqueue(20)
enqueue(30)

dequeue()
dequeue()
dequeue()

After the third dequeue, Rear still points to the old node.

### Task

Identify:

1. Why this is dangerous.
2. What pointer should be changed.
3. What the correct empty state should be.

Expected:

front = nullptr
rear  = nullptr


## 30. Pointer Visualization Exercise

Draw the Queue after every operation.

Start with:

Queue = empty

Then execute:

enqueue(10)
enqueue(20)
enqueue(30)
dequeue()
enqueue(40)
dequeue()
dequeue()

For every step, draw:

- Front
- Rear
- Every node
- Every next pointer

### Goal

Build a strong mental model of how the pointers change.


## 31. Implementation Challenge

Build a complete production-style Queue class using a Singly Linked List.

The class should include:

- Private Node structure
- Front pointer
- Rear pointer
- Size counter
- Constructor
- Destructor
- Copy Constructor
- Copy Assignment Operator
- enqueue()
- dequeue()
- peek()
- rear()
- isEmpty()
- size()
- clear()
- display()
- contains()
- getMax()
- getMin()
- reverse()
- comparison support

### Requirements

The implementation should:

- Follow FIFO
- Manage dynamic memory safely
- Handle all edge cases
- Avoid memory leaks
- Maintain Queue invariants
- Have clear naming
- Use encapsulation
- Document time complexity
- Follow clean C++ practices


## 32. Final Review Questions

Before moving to the next data structure, make sure you can answer these questions without looking at your implementation:

1. Why does a Queue follow FIFO?

2. Why do we need both Front and Rear pointers?

3. Why is enqueue() O(1)?

4. Why is dequeue() O(1)?

5. What happens when the Queue contains exactly one node?

6. What happens to Rear after removing the last node?

7. Why must removed nodes be deleted?

8. What is a dangling pointer?

9. What is a memory leak?

10. Why is display() O(n)?

11. Why does a linked-list Queue not have a fixed capacity?

12. What is the difference between shallow copy and deep copy?

13. Why might a Queue class need the Rule of Three?

14. Why should traversal use a temporary pointer?

15. What invariant should always be true about rear->next?

16. What is the space complexity of a linked-list-based Queue?

17. What are the main trade-offs between an array-based Queue and a linked-list-based Queue?


## Final Goal

The goal of these exercises is not only to make the Queue work.

The goal is to understand:

- FIFO behavior
- Pointer manipulation
- Dynamic memory management
- Front and Rear management
- Edge cases
- Complexity analysis
- Object ownership
- Deep copying
- Encapsulation
- Clean C++ implementation

Understand → Implement → Analyze → Test → Document → Improve.