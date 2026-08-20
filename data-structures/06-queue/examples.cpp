#include <iostream>
using namespace std;

/*
    Array-Based Queue Examples

    This file demonstrates common Queue scenarios using
    the Queue implementation developed in implementation.cpp.

    Main concepts demonstrated:
    - FIFO behavior
    - Enqueue
    - Dequeue
    - Peek
    - Empty Queue
    - Full Queue
    - Queue state changes
*/


class Queue
{
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue(int size)
    {
        if (size <= 0)
        {
            size = 1;
        }

        capacity = size;
        arr = new int[capacity];

        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    bool enqueue(int value)
    {
        if (isFull())
        {
            return false;
        }

        rear++;
        arr[rear] = value;
        count++;

        return true;
    }

    bool dequeue(int& value)
    {
        if (isEmpty())
        {
            return false;
        }

        value = arr[front];
        front++;
        count--;

        if (isEmpty())
        {
            front = 0;
            rear = -1;
        }

        return true;
    }

    bool peek(int& value) const
    {
        if (isEmpty())
        {
            return false;
        }

        value = arr[front];
        return true;
    }

    bool isEmpty() const
    {
        return count == 0;
    }

    bool isFull() const
    {
        return count == capacity;
    }

    int size() const
    {
        return count;
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};


/*
    Example 1: Basic FIFO Behavior

    The first element inserted should be
    the first element removed.
*/
void basicFIFOExample()
{
    cout << "=== Example 1: FIFO Behavior ===" << endl;

    Queue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Queue: ";
    queue.display();

    int value;

    queue.dequeue(value);
    cout << "Dequeued: " << value << endl;

    queue.dequeue(value);
    cout << "Dequeued: " << value << endl;

    cout << "Queue after dequeues: ";
    queue.display();

    cout << endl;
}


/*
    Example 2: Peek

    Peek returns the front element without
    removing it from the Queue.
*/
void peekExample()
{
    cout << "=== Example 2: Peek ===" << endl;

    Queue queue(5);

    queue.enqueue(100);
    queue.enqueue(200);
    queue.enqueue(300);

    int value;

    if (queue.peek(value))
    {
        cout << "Front element: " << value << endl;
    }

    cout << "Queue after peek: ";
    queue.display();

    cout << endl;
}


/*
    Example 3: Empty Queue

    Demonstrates the behavior of dequeue()
    and peek() when the Queue is empty.
*/
void emptyQueueExample()
{
    cout << "=== Example 3: Empty Queue ===" << endl;

    Queue queue(3);

    int value;

    if (!queue.dequeue(value))
    {
        cout << "Cannot dequeue: Queue is empty." << endl;
    }

    if (!queue.peek(value))
    {
        cout << "Cannot peek: Queue is empty." << endl;
    }

    cout << endl;
}


/*
    Example 4: Full Queue

    Demonstrates the capacity limitation
    of a fixed-size array-based Queue.
*/
void fullQueueExample()
{
    cout << "=== Example 4: Full Queue ===" << endl;

    Queue queue(3);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Queue: ";
    queue.display();

    if (!queue.enqueue(40))
    {
        cout << "Cannot enqueue 40: Queue is full." << endl;
    }

    cout << endl;
}


/*
    Example 5: Single Element Queue

    Demonstrates the transition between:
    empty -> one element -> empty
*/
void singleElementExample()
{
    cout << "=== Example 5: Single Element ===" << endl;

    Queue queue(3);

    queue.enqueue(50);

    cout << "Queue: ";
    queue.display();

    int value;

    queue.dequeue(value);

    cout << "Removed: " << value << endl;

    cout << "Queue after removal: ";
    queue.display();

    cout << endl;
}


/*
    Example 6: Multiple Queue Operations

    Demonstrates how front and rear change
    as elements are inserted and removed.
*/
void multipleOperationsExample()
{
    cout << "=== Example 6: Multiple Operations ===" << endl;

    Queue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Initial Queue: ";
    queue.display();

    int value;

    queue.dequeue(value);
    cout << "Removed: " << value << endl;

    queue.enqueue(40);

    cout << "Queue: ";
    queue.display();

    queue.dequeue(value);
    cout << "Removed: " << value << endl;

    queue.enqueue(50);

    cout << "Final Queue: ";
    queue.display();

    cout << endl;
}


int main()
{
    basicFIFOExample();

    peekExample();

    emptyQueueExample();

    fullQueueExample();

    singleElementExample();

    multipleOperationsExample();

    return 0;
}