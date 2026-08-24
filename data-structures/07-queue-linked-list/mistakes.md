# Queue Using a Singly Linked List — Common Mistakes

## 1. Forgetting to Update Rear

One of the most common mistakes is inserting a new node without updating the Rear pointer.

Incorrect logic:

rear->next = newNode;

Correct logic:

rear->next = newNode;
rear = newNode;

The Rear must always point to the last node in the Queue.

Invariant:

rear->next == nullptr


## 2. Updating Rear Before Connecting the New Node

The new node must first be connected to the existing Rear.

Correct order:

rear->next = newNode;
rear = newNode;

Changing Rear without connecting the nodes can break the linked list.


## 3. Not Handling the First Element

When the Queue is empty, both Front and Rear must point to the new node.

Initial state:

front = nullptr
rear  = nullptr

After enqueue:

front
  ↓
[10 | nullptr]
  ↑
 rear

A common mistake is updating only Rear and forgetting Front.


## 4. Forgetting to Reset Rear After the Last Dequeue

Consider a Queue containing one node:

front
  ↓
[10 | nullptr]
  ↑
 rear

After dequeue, the Queue becomes empty.

Both pointers must be reset:

front = nullptr
rear  = nullptr

If Rear is not reset, it may point to deleted memory.

This creates a dangling pointer.


## 5. Accessing Front When the Queue Is Empty

Calling peek() on an empty Queue without checking the state can result in invalid memory access.

Always check:

if (isEmpty())

before accessing Front.


## 6. Accessing Rear When the Queue Is Empty

The same rule applies to Rear.

Do not access:

rear->data

when:

rear == nullptr

Always verify that the Queue contains an element first.


## 7. Forgetting to Delete Removed Nodes

A common memory-management mistake is moving Front without deleting the old node.

Incorrect idea:

front = front->next;

This removes the node from the Queue structure but does not release its memory.

Correct approach:

Node* firstNode = front;
front = front->next;
delete firstNode;


## 8. Deleting the Node Before Moving Front

Another dangerous mistake is deleting the current Front first.

Incorrect order:

delete front;
front = front->next;

After deletion, accessing front->next is invalid.

Correct order:

Node* firstNode = front;
front = front->next;
delete firstNode;


## 9. Losing the Address of the Node

Consider:

delete front;

If Front is deleted without saving the necessary information first, the linked list can no longer be traversed safely.

A temporary pointer should be used:

Node* firstNode = front;

This preserves access to the node that will be deleted.


## 10. Traversing to the Rear During Every Enqueue

A Singly Linked List can insert at the end in O(n) if it only stores Front.

For example:

front
  ↓
[10] → [20] → [30] → nullptr

Finding the last node requires traversal.

This would make:

enqueue() → O(n)

Maintaining a Rear pointer allows:

enqueue() → O(1)


## 11. Confusing FIFO With LIFO

A Queue follows:

FIFO — First In, First Out

A Stack follows:

LIFO — Last In, First Out

Queue:

enqueue(10)
enqueue(20)
enqueue(30)

Removal order:

10 → 20 → 30

Stack:

push(10)
push(20)
push(30)

Removal order:

30 → 20 → 10


## 12. Removing From the Wrong End

Queue insertion must happen at the Rear.

Queue removal must happen at the Front.

Correct:

enqueue → Rear
dequeue → Front

Removing from the Rear changes the structure into behavior closer to a Stack.


## 13. Incorrect Empty Condition

For a linked-list-based Queue, the simplest empty condition is:

front == nullptr

A valid empty state should also have:

rear == nullptr

The implementation should maintain both pointers consistently.


## 14. Forgetting the Single-Element Case

The single-element Queue requires special attention.

Before dequeue:

front == rear

After dequeue:

front = nullptr
rear  = nullptr

Failing to handle this case can leave Rear pointing to deleted memory.


## 15. Incorrectly Checking Queue Full

A linked-list-based Queue does not have a fixed capacity like a simple array-based Queue.

Therefore, checking:

rear == Size - 1

does not make sense for a linked list.

The Queue grows dynamically until memory allocation can no longer be satisfied.


## 16. Memory Leak During clear()

A clear() function must delete every dynamically allocated node.

Conceptually:

while Queue is not empty:
    remove the Front node

Every node must eventually be deleted.


## 17. Destructor Forgetting to Release Nodes

If the Queue object is destroyed while nodes still exist, the destructor must release them.

Otherwise, dynamically allocated memory can remain allocated after the object is gone.

A proper destructor should call clear() or perform equivalent cleanup.


## 18. Shallow Copy

Copying a Queue containing raw pointers can create two objects that point to the same nodes.

Example:

Queue A:

front
  ↓
[10] → [20] → nullptr

After a shallow copy:

Queue A front ──┐
                ↓
              [10] → [20]

Queue B front ──┘

Both objects now share the same nodes.

This can lead to double deletion and undefined behavior.


## 19. Missing Copy Constructor

When a class owns dynamic memory, a proper Copy Constructor should create a deep copy.

Each Queue should own its own nodes.

Example:

Queue A:

[10] → [20]

Queue B:

[10] → [20]

The values are equal, but the nodes are different objects in memory.


## 20. Missing Copy Assignment Operator

The same ownership problem can occur during assignment.

For example:

queue2 = queue1;

The assignment operator should:

1. Protect against self-assignment.
2. Release the old nodes owned by queue2.
3. Create independent nodes copied from queue1.
4. Preserve the correct Front and Rear pointers.


## 21. Self-Assignment Problem

An assignment such as:

queue = queue;

should not destroy the object before copying from it.

A self-assignment check prevents this:

this != &other


## 22. Incorrect Count Management

If the Queue maintains a count variable, it must stay synchronized with the actual number of nodes.

After enqueue:

count++

After dequeue:

count--

After clear:

count = 0

The invariant should always be:

count == number of nodes


## 23. Negative Count

The count should never become negative.

Before decrementing count during dequeue, the Queue should already contain an element.

Correct condition:

if (!isEmpty())
    count--;


## 24. Incorrect Rear After Multiple Dequeues

Consider:

front                    rear
  ↓                        ↓
[10] → [20] → [30] → nullptr

After removing 10:

front             rear
  ↓                 ↓
[20] → [30] → nullptr

After removing 20:

front       rear
  ↓           ↓
[30] → nullptr

After removing 30:

front = nullptr
rear  = nullptr

Rear must always follow the last remaining node.


## 25. Using the Wrong Complexity

For a Queue with both Front and Rear pointers:

enqueue() → O(1)
dequeue() → O(1)
peek()    → O(1)
isEmpty() → O(1)
display() → O(n)

Do not claim enqueue() is O(n) when a Rear pointer is maintained.


## 26. Modifying the Queue During Display

The display operation should only traverse the Queue.

It should not:

- Delete nodes
- Move Front
- Move Rear
- Change the Queue size

Display should leave the Queue unchanged.


## 27. Accidentally Changing Front During Traversal

A dangerous implementation is:

current = front;

and then modifying Front itself while traversing.

Instead, use a temporary pointer:

Node* current = front;

Then move:

current = current->next;

This preserves the Queue's Front pointer.


## 28. Using Front Instead of a Temporary Pointer

Incorrect traversal:

front = front->next;

This changes the actual Queue state.

Correct traversal:

Node* current = front;

while (current != nullptr)
{
    current = current->next;
}

The Queue remains unchanged.


## 29. Forgetting nullptr at the End of the List

The last node must always satisfy:

rear->next == nullptr

When inserting a new node, its next pointer should initially be:

nullptr

Otherwise, traversal may continue into invalid memory.


## 30. Returning Invalid Values Without a Clear Contract

If peek() or dequeue() returns a value directly, using a special value such as -1 to indicate failure can be ambiguous if -1 is also valid data.

For example:

enqueue(-1)

Then:

peek()

Returning -1 could mean:

- The Queue contains -1
- The Queue is empty

A safer design is to return a boolean success/failure result and provide the value through a reference parameter.


## 31. Mixing Interface and Implementation Logic

A clean Queue class should keep internal pointer management private.

External code should interact through public operations such as:

enqueue()
dequeue()
peek()
isEmpty()
size()
clear()

The internal Node structure and pointer manipulation should remain encapsulated.


## 32. Ignoring Memory Allocation Failure

Dynamic allocation can fail when the system cannot provide enough memory.

For production-quality code, allocation failure should be considered when designing the error-handling strategy.

For learning implementations, the important concept is understanding that new allocates memory dynamically and that the allocated memory must eventually be released.


## 33. General Debugging Checklist

When a Queue implementation behaves incorrectly, check the following:

- Is Front initialized to nullptr?
- Is Rear initialized to nullptr?
- Does enqueue() handle the first element?
- Does enqueue() update Rear?
- Does dequeue() update Front?
- Does dequeue() delete the removed node?
- Does Rear become nullptr when the Queue becomes empty?
- Does peek() handle an empty Queue?
- Does display() preserve Front?
- Does the last node point to nullptr?
- Does clear() delete every node?
- Does the destructor release all nodes?
- Are copied Queues independent?
- Is count synchronized with the number of nodes?
- Are FIFO rules preserved?


## Key Lesson

Most Queue bugs are not caused by the FIFO concept itself.

They usually come from incorrect pointer management and incorrect handling of
edge cases.

The most important states to understand are:

1. Empty Queue
2. One-element Queue
3. Multiple-element Queue
4. Removing the last element
5. Reusing the Queue after it becomes empty

If these states are handled correctly, the core Queue implementation becomes
much easier to reason about.