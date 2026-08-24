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
    int count;

    void copyFrom(const Queue& other)
    {
        Node* current = other.front;

        while (current != nullptr)
        {
            enqueue(current->data);
            current = current->next;
        }
    }

public:

    // Constructor
    Queue()
    {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    // Copy Constructor
    Queue(const Queue& other)
    {
        front = nullptr;
        rear = nullptr;
        count = 0;

        copyFrom(other);
    }

    // Copy Assignment Operator
    Queue& operator=(const Queue& other)
    {
        if (this != &other)
        {
            clear();
            copyFrom(other);
        }

        return *this;
    }

    // Destructor
    ~Queue()
    {
        clear();
    }

    // Add an element to the Rear
    bool enqueue(int value)
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

        count++;

        return true;
    }

    // Remove an element from the Front
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

        count--;

        if (count == 0)
        {
            rear = nullptr;
        }

        return true;
    }

    // Return the Front element without removing it
    bool peek(int& value) const
    {
        if (isEmpty())
        {
            return false;
        }

        value = front->data;

        return true;
    }

    // Return the Rear element without removing it
    bool rearValue(int& value) const
    {
        if (isEmpty())
        {
            return false;
        }

        value = rear->data;

        return true;
    }

    // Check whether the Queue is empty
    bool isEmpty() const
    {
        return front == nullptr;
    }

    // Return the number of elements
    int size() const
    {
        return count;
    }

    // Remove all elements
    void clear()
    {
        Node* current = front;

        while (current != nullptr)
        {
            Node* nextNode = current->next;

            delete current;

            current = nextNode;
        }

        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    // Display all elements from Front to Rear
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

    // Display Front element
    void displayFront() const
    {
        int value;

        if (!peek(value))
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Front: " << value << endl;
    }

    // Display Rear element
    void displayRear() const
    {
        int value;

        if (!rearValue(value))
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Rear: " << value << endl;
    }
};


int main()
{
    Queue queue;

    cout << "===== Enqueue =====" << endl;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    queue.display();

    cout << "\n===== Front & Rear =====" << endl;

    queue.displayFront();
    queue.displayRear();

    cout << "\n===== Size =====" << endl;

    cout << "Size: " << queue.size() << endl;

    cout << "\n===== Dequeue =====" << endl;

    int value;

    if (queue.dequeue(value))
    {
        cout << "Dequeued: " << value << endl;
    }

    queue.display();

    cout << "\n===== Peek =====" << endl;

    if (queue.peek(value))
    {
        cout << "Front element: " << value << endl;
    }

    cout << "\n===== Dequeue Until Empty =====" << endl;

    while (!queue.isEmpty())
    {
        queue.dequeue(value);
        cout << "Dequeued: " << value << endl;
    }

    queue.display();

    cout << "\n===== Reuse Queue =====" << endl;

    queue.enqueue(100);
    queue.enqueue(200);

    queue.display();

    cout << "\n===== Copy Constructor =====" << endl;

    Queue copiedQueue(queue);

    copiedQueue.display();

    cout << "\n===== Copy Assignment =====" << endl;

    Queue assignedQueue;

    assignedQueue.enqueue(999);

    assignedQueue = queue;

    assignedQueue.display();

    cout << "\n===== Clear =====" << endl;

    queue.clear();

    queue.display();

    cout << "\n===== Final State =====" << endl;

    cout << "Queue is empty: "
         << (queue.isEmpty() ? "Yes" : "No") << endl;

    cout << "Queue size: " << queue.size() << endl;

    return 0;
}