#include <iostream>
using namespace std;

class Queue
{
private:

    struct Node
    {
        int data;
        Node* next;

        Node(int value)
        {
            data = value;
            next = nullptr;
        }
    };

    Node* front;
    Node* rear;

public:

    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue()
    {
        clear();
    }

    bool isEmpty() const
    {
        return front == nullptr;
    }

    void enqueue(int value)
    {
        Node* newNode = new Node(value);

        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    bool dequeue(int& value)
    {
        if (isEmpty())
        {
            return false;
        }

        Node* firstNode = front;

        value = firstNode->data;

        front = firstNode->next;

        delete firstNode;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        return true;
    }

    bool peek(int& value) const
    {
        if (isEmpty())
        {
            return false;
        }

        value = front->data;

        return true;
    }

    bool rearValue(int& value) const
    {
        if (isEmpty())
        {
            return false;
        }

        value = rear->data;

        return true;
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* current = front;

        cout << "Front -> ";

        while (current != nullptr)
        {
            cout << current->data;

            if (current->next != nullptr)
            {
                cout << " -> ";
            }

            current = current->next;
        }

        cout << " <- Rear" << endl;
    }

    void clear()
    {
        while (!isEmpty())
        {
            int value;
            dequeue(value);
        }
    }
};


// Example 1: Basic Queue Operations
void basicOperationsExample()
{
    cout << "\n===== Example 1: Basic Operations =====\n";

    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display();

    int value;

    queue.dequeue(value);

    cout << "Dequeued: " << value << endl;

    queue.display();
}


// Example 2: FIFO Behavior
void fifoExample()
{
    cout << "\n===== Example 2: FIFO Behavior =====\n";

    Queue queue;

    queue.enqueue(100);
    queue.enqueue(200);
    queue.enqueue(300);
    queue.enqueue(400);

    cout << "Removal order:\n";

    int value;

    while (!queue.isEmpty())
    {
        queue.dequeue(value);

        cout << value << " ";
    }

    cout << endl;
}


// Example 3: Peek Without Removing
void peekExample()
{
    cout << "\n===== Example 3: Peek =====\n";

    Queue queue;

    queue.enqueue(50);
    queue.enqueue(60);
    queue.enqueue(70);

    int value;

    if (queue.peek(value))
    {
        cout << "Front element: " << value << endl;
    }

    cout << "Queue after peek:\n";

    queue.display();
}


// Example 4: Inspect Front and Rear
void frontAndRearExample()
{
    cout << "\n===== Example 4: Front and Rear =====\n";

    Queue queue;

    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);
    queue.enqueue(20);

    int value;

    if (queue.peek(value))
    {
        cout << "Front: " << value << endl;
    }

    if (queue.rearValue(value))
    {
        cout << "Rear: " << value << endl;
    }

    queue.display();
}


// Example 5: Empty Queue Handling
void emptyQueueExample()
{
    cout << "\n===== Example 5: Empty Queue =====\n";

    Queue queue;

    int value;

    if (!queue.dequeue(value))
    {
        cout << "Cannot dequeue: Queue is empty." << endl;
    }

    if (!queue.peek(value))
    {
        cout << "Cannot peek: Queue is empty." << endl;
    }
}


// Example 6: Single Element
void singleElementExample()
{
    cout << "\n===== Example 6: Single Element =====\n";

    Queue queue;

    queue.enqueue(999);

    queue.display();

    int value;

    queue.dequeue(value);

    cout << "Dequeued: " << value << endl;

    queue.display();

    cout << "Queue is empty: "
         << (queue.isEmpty() ? "Yes" : "No")
         << endl;
}


// Example 7: Reusing the Queue
void reuseQueueExample()
{
    cout << "\n===== Example 7: Reusing Queue =====\n";

    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);

    queue.dequeue(*(new int));

    queue.enqueue(30);
    queue.enqueue(40);

    queue.display();
}


// Example 8: Task Processing Simulation
void taskProcessingExample()
{
    cout << "\n===== Example 8: Task Processing =====\n";

    Queue tasks;

    tasks.enqueue(101);
    tasks.enqueue(102);
    tasks.enqueue(103);
    tasks.enqueue(104);

    cout << "Processing tasks:\n";

    int task;

    while (!tasks.isEmpty())
    {
        tasks.dequeue(task);

        cout << "Processing task #" << task << endl;
    }
}


// Example 9: Customer Service Simulation
void customerServiceExample()
{
    cout << "\n===== Example 9: Customer Service =====\n";

    Queue customers;

    customers.enqueue(1);
    customers.enqueue(2);
    customers.enqueue(3);

    int customer;

    while (!customers.isEmpty())
    {
        customers.dequeue(customer);

        cout << "Serving customer #" << customer << endl;
    }
}


// Example 10: Comparing Insertion and Removal Order
void orderExample()
{
    cout << "\n===== Example 10: Insertion vs Removal Order =====\n";

    Queue queue;

    cout << "Insertion order:\n";

    queue.enqueue(10);
    cout << "10 ";

    queue.enqueue(20);
    cout << "20 ";

    queue.enqueue(30);
    cout << "30 ";

    queue.enqueue(40);
    cout << "40 ";

    cout << "\n\nRemoval order:\n";

    int value;

    while (!queue.isEmpty())
    {
        queue.dequeue(value);

        cout << value << " ";
    }

    cout << endl;
}


int main()
{
    basicOperationsExample();

    fifoExample();

    peekExample();

    frontAndRearExample();

    emptyQueueExample();

    singleElementExample();

    reuseQueueExample();

    taskProcessingExample();

    customerServiceExample();

    orderExample();

    return 0;
}