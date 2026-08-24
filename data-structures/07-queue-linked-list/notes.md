# Queue Using a Singly Linked List — Notes

## 1. Queue Definition

A Queue is a linear data structure that follows the FIFO (First In, First Out) principle.

The first element inserted into the Queue is the first element removed.

Example:

Front
  ↓
[10] → [20] → [30] → [40]
                         ↑
                        Rear

Removal order:

10 → 20 → 30 → 40


## 2. Queue Terminology

### Front

The Front points to the first node in the Queue.

The next dequeue operation removes this element.

### Rear

The Rear points to the last node in the Queue.

The next enqueue operation adds a new element after this node.

Example:

Front                         Rear
  ↓                             ↓
[10] → [20] → [30] → [40] → nullptr


## 3. Why Use a Singly Linked List?

A Queue can be implemented using an array or a linked list.

An array-based Queue usually has a fixed capacity.

A linked-list-based Queue uses dynamically allocated nodes, allowing the Queue to grow as new elements are inserted.

Each node contains:

- Data
- Pointer to the next node

Example:

[10 | next] → [20 | next] → [30 | nullptr]

The Queue maintains:

- front
- rear


## 4. Node Structure

A basic Queue node contains:

struct Node
{
    int data;
    Node* next;
};

Each node stores:

- Data
- Address of the next node

The last node always points to nullptr.


## 5. Queue State

### Empty Queue

When the Queue is empty:

front = nullptr
rear  = nullptr

There are no nodes.

### Non-Empty Queue

Example:

front                         rear
  ↓                             ↓
[10] → [20] → [30] → nullptr

### Single Element

When the Queue contains one element:

front
  ↓
[10 | nullptr]
  ↑
 rear

Therefore:

front == rear

This is an important edge case.


## 6. Enqueue

enqueue() adds a new element to the Rear.

### Empty Queue

If the Queue is empty:

front = nullptr
rear  = nullptr

Create a new node.

The new node becomes both the Front and Rear.

### Non-Empty Queue

Before:

front                    rear
  ↓                        ↓
[10] → [20] → nullptr

Insert 30.

The new node is connected after the current Rear.

Then Rear is updated to the new node.

Result:

front                           rear
  ↓                               ↓
[10] → [20] → [30] → nullptr

### Complexity

O(1)

Because the Queue already has direct access to the Rear.


## 7. Dequeue

dequeue() removes the element from the Front.

Before:

front                    rear
  ↓                        ↓
[10] → [20] → [30] → nullptr

Store the current Front node.

Move Front to the next node.

Then delete the old Front node.

Result:

front             rear
  ↓                 ↓
[20] → [30] → nullptr

### Single-Element Case

Before:

front
  ↓
[10 | nullptr]
  ↑
 rear

After dequeue:

front = nullptr
rear  = nullptr

The Queue is now empty.

### Complexity

O(1)


## 8. Peek

peek() returns the Front value without removing it.

Example:

front
  ↓
[10] → [20] → [30] → nullptr

Calling peek() returns:

10

The Queue remains unchanged.

### Complexity

O(1)


## 9. Rear Value

A Queue implementation can also provide access to the last element.

Example:

front                    rear
  ↓                        ↓
[10] → [20] → [30] → nullptr

The Rear value is:

30

Because the Queue maintains a direct rear pointer, this operation runs in O(1).


## 10. Is Empty

The Queue is empty when:

front == nullptr

A consistent empty state should be:

front = nullptr
rear  = nullptr

### Complexity

O(1)


## 11. Display

To display the Queue, start from the Front and traverse until nullptr.

Example:

front
  ↓
[10] → [20] → [30] → nullptr

The traversal produces:

10 → 20 → 30

Every node must be visited.

Therefore:

O(n)


## 12. Time Complexity

| Operation | Complexity |
|-----------|------------|
| Enqueue | O(1) |
| Dequeue | O(1) |
| Peek | O(1) |
| Rear Value | O(1) |
| Is Empty | O(1) |
| Display | O(n) |
| Clear | O(n) |

The key reason enqueue() is O(1) is the existence of the rear pointer.

Without a Rear pointer, inserting at the end of a Singly Linked List would require traversal.

That would make insertion O(n).

Maintaining both Front and Rear pointers allows:

enqueue() → O(1)
dequeue() → O(1)


## 13. Space Complexity

For n elements, the Queue contains n dynamically allocated nodes.

Therefore:

Space Complexity = O(n)

Each node stores:

- The actual data
- A pointer to the next node

The Queue itself also stores:

- front
- rear
- count, if maintained


## 14. Memory Management

Linked-list-based Queues use dynamic memory.

When inserting:

Node* newNode = new Node(value);

memory is allocated.

When removing:

delete firstNode;

the memory occupied by the removed node is released.

Failing to delete removed nodes can cause a Memory Leak.

Every dynamically allocated node should eventually be released.


## 15. Destructor

A class that owns dynamically allocated nodes should release all nodes when the object is destroyed.

A destructor can repeatedly remove nodes until the Queue becomes empty.

Conceptually:

while Queue is not empty:
    delete the Front node

This ensures that dynamically allocated memory is properly released.


## 16. Copying a Linked List Queue

A Queue containing raw pointers cannot safely rely on compiler-generated copy operations.

A shallow copy would copy the pointer values instead of creating new nodes.

This means two Queue objects could point to the same nodes.

This can cause:

- Double deletion
- Dangling pointers
- Unexpected modifications
- Undefined behavior

A proper copy should create completely independent nodes.

This is called a Deep Copy.


## 17. Rule of Three

When a class manages dynamic memory through raw pointers, it commonly needs:

1. Destructor
2. Copy Constructor
3. Copy Assignment Operator

These are known as the Rule of Three.

The purpose is to ensure that copied objects own independent memory.


## 18. Queue Invariants

A good implementation should maintain certain conditions at all times.

### Empty Queue

front == nullptr
rear  == nullptr

### Non-Empty Queue

front != nullptr
rear  != nullptr

### Rear Node

The Rear node must always be the final node.

Therefore:

rear->next == nullptr

### Count

If the implementation maintains a count variable:

count >= 0

and:

count == number of nodes

Maintaining these invariants makes the implementation easier to reason about.


## 19. Array-Based Queue vs Linked List-Based Queue

### Array-Based Queue

Advantages:

- Contiguous memory
- Good cache locality
- Low per-element memory overhead
- Simple memory layout

Disadvantages:

- Fixed capacity in a simple implementation
- Resizing may be required
- Linear Queue can waste positions
- Capacity must be managed

### Linked List-Based Queue

Advantages:

- Dynamic size
- No fixed capacity
- Efficient insertion and removal
- Allocates memory as needed

Disadvantages:

- Extra pointer per node
- Dynamic allocation overhead
- Poorer cache locality
- More complex pointer management


## 20. Why Both Front and Rear Are Important

Suppose the Queue only stores the Front pointer.

To insert at the Rear, we would have to traverse the entire list.

Example:

front
  ↓
[10] → [20] → [30] → [40] → nullptr

Finding the last node requires traversing:

10 → 20 → 30 → 40

This would make enqueue():

O(n)

By maintaining both:

front
rear

we can directly access both ends.

Therefore:

enqueue() → O(1)
dequeue() → O(1)


## 21. Underflow

Queue Underflow occurs when an operation tries to remove or access an element from an empty Queue.

Example:

Queue = empty

dequeue()

The operation should fail safely instead of accessing invalid memory.

Operations that should handle the empty state include:

- dequeue()
- peek()
- rearValue()
- display()


## 22. Overflow

Unlike a fixed-size array-based Queue, a linked-list-based Queue does not have a predefined capacity.

Therefore, there is no traditional Queue Overflow condition based on a fixed array size.

However, dynamic allocation can still fail if the system cannot provide enough memory.

This is one of the major differences between the two implementations.


## 23. Edge Cases

Always test the following cases.

### Case 1 — Empty Queue

front = nullptr
rear  = nullptr

### Case 2 — One Element

front == rear

### Case 3 — Multiple Elements

front → node → node → rear

### Case 4 — Remove Until Empty

After the last dequeue:

front = nullptr
rear  = nullptr

### Case 5 — Reuse After Empty

Example:

enqueue(10)
dequeue()
enqueue(20)

The Queue should continue working correctly.


## 24. Important Pointer Operations

### Enqueue

rear->next = newNode;
rear = newNode;

### Dequeue

Node* firstNode = front;
front = front->next;
delete firstNode;

### Queue Becomes Empty

front = nullptr;
rear = nullptr;

These operations form the core of the linked-list-based Queue.


## 25. Common Mental Model

Think of the Queue as a line of people.

Front                         Rear
  ↓                             ↓
Person A → Person B → Person C

A new person joins at the Rear:

Person A → Person B → Person C → Person D

The person at the Front leaves first:

Person B → Person C → Person D

This is exactly the FIFO behavior.


## 26. Key Takeaways

- A Queue follows FIFO.
- Elements enter through the Rear.
- Elements leave through the Front.
- A Singly Linked List provides dynamic storage.
- front points to the first node.
- rear points to the last node.
- enqueue() is O(1).
- dequeue() is O(1).
- peek() is O(1).
- Traversal-based operations are O(n).
- Linked Lists require careful memory management.
- Removed nodes must be deleted.
- A destructor should release remaining nodes.
- Raw-pointer classes require proper copy semantics.
- A linked-list Queue has no fixed array capacity.
- Maintaining both Front and Rear is essential for efficient operations.


## 27. Mental Checklist

Before considering a Queue implementation complete:

- [ ] FIFO behavior is preserved.
- [ ] Enqueue happens at Rear.
- [ ] Dequeue happens at Front.
- [ ] Empty Queue is represented correctly.
- [ ] Single-element Queue is handled correctly.
- [ ] Rear is updated after insertion.
- [ ] Front is updated after removal.
- [ ] Rear becomes nullptr when the Queue becomes empty.
- [ ] Removed nodes are deleted.
- [ ] No memory leaks occur.
- [ ] peek() does not remove elements.
- [ ] Enqueue is O(1).
- [ ] Dequeue is O(1).
- [ ] Copy operations do not create shared ownership of nodes.