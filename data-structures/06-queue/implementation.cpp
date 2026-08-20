#include <iostream>
using namespace std;

class Queue
{
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    // Constructor
    Queue(int size)
    {
        if (size <= 0)
        {
            cout << "Invalid queue size." << endl;
            size = 1;
        }

        capacity = size;
        arr = new int[capacity];

        front = 0;
        rear = -1;
        count = 0;
    }

    // Destructor
    ~Queue()
    {
        delete[] arr;
    }

    // Add an element to the rear
    bool enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue Overflow: cannot enqueue " << value << "." << endl;
            return false;
        }

        rear++;
        arr[rear] = value;
        count++;

        return true;
    }

    // Remove and return the front element
    bool dequeue(int& value)
    {
        if (isEmpty())
        {
            cout << "Queue Underflow: queue is empty." << endl;
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

    // Return the front element without removing it
    bool peek(int& value) const
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return false;
        }

        value = arr[front];
        return true;
    }

    // Check whether the queue is empty
    bool isEmpty() const
    {
        return count == 0;
    }

    // Check whether the queue is full
    bool isFull() const
    {
        return count == capacity;
    }

    // Return the number of elements
    int size() const
    {
        return count;
    }

    // Return the maximum capacity
    int getCapacity() const
    {
        return capacity;
    }

    // Display all active elements
    void display() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue: ";

        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // Display queue information
    void displayInfo() const
    {
        cout << "Capacity: " << capacity << endl;
        cout << "Current Size: " << count << endl;
        cout << "Front Index: " << front << endl;
        cout << "Rear Index: " << rear << endl;
        cout << "Status: ";

        if (isEmpty())
            cout << "Empty";
        else if (isFull())
            cout << "Full";
        else
            cout << "Partially Filled";

        cout << endl;
    }

    // Clear the queue
    void clear()
    {
        front = 0;
        rear = -1;
        count = 0;
    }
};


int main()
{
    Queue queue(5);

    cout << "=== Enqueue Operations ===" << endl;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display();

    cout << "\n=== Peek Operation ===" << endl;

    int frontValue;

    if (queue.peek(frontValue))
    {
        cout << "Front element: " << frontValue << endl;
    }

    cout << "\n=== Dequeue Operation ===" << endl;

    int removedValue;

    if (queue.dequeue(removedValue))
    {
        cout << "Removed: " << removedValue << endl;
    }

    queue.display();

    cout << "\n=== Queue Information ===" << endl;

    queue.displayInfo();

    cout << "\n=== Filling the Queue ===" << endl;

    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60);
    queue.enqueue(70);

    queue.display();

    cout << "\n=== Overflow Test ===" << endl;

    queue.enqueue(80);

    cout << "\n=== Clear Queue ===" << endl;

    queue.clear();

    queue.display();

    cout << "\n=== Underflow Test ===" << endl;

    if (!queue.dequeue(removedValue))
    {
        cout << "Dequeue operation failed as expected." << endl;
    }

    return 0;
}