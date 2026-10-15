
#include <iostream>
#include <stdexcept>

class CircularLinkedList
{
private:
    struct Node
    {
        int data;
        Node* next;

        explicit Node(int value)
            : data(value), next(nullptr)
        {
        }
    };

    Node* head;
    Node* tail;
    int listSize;

    void copyFrom(const CircularLinkedList& other)
    {
        Node* current = other.head;

        for (int i = 0; i < other.listSize; ++i)
        {
            insertAtEnd(current->data);
            current = current->next;
        }
    }

public:
    CircularLinkedList()
        : head(nullptr), tail(nullptr), listSize(0)
    {
    }

    // Copy constructor
    CircularLinkedList(const CircularLinkedList& other)
        : head(nullptr), tail(nullptr), listSize(0)
    {
        try
        {
            copyFrom(other);
        }
        catch (...)
        {
            clear();
            throw;
        }
    }

    // Copy assignment operator
    CircularLinkedList& operator=(const CircularLinkedList& other)
    {
        if (this != &other)
        {
            CircularLinkedList temp(other);
            swap(temp);
        }

        return *this;
    }

    // Destructor
    ~CircularLinkedList()
    {
        clear();
    }

    void swap(CircularLinkedList& other) noexcept
    {
        Node* tempHead = head;
        head = other.head;
        other.head = tempHead;

        Node* tempTail = tail;
        tail = other.tail;
        other.tail = tempTail;

        int tempSize = listSize;
        listSize = other.listSize;
        other.listSize = tempSize;
    }

    bool isEmpty() const
    {
        return head == nullptr;
    }

    int size() const
    {
        return listSize;
    }

    void insertAtBeginning(int value)
    {
        Node* newNode = new Node(value);

        if (isEmpty())
        {
            head = tail = newNode;
            newNode->next = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }

        ++listSize;
    }

    void insertAtEnd(int value)
    {
        Node* newNode = new Node(value);

        if (isEmpty())
        {
            head = tail = newNode;
            newNode->next = newNode;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }

        ++listSize;
    }

    bool deleteFromBeginning()
    {
        if (isEmpty())
        {
            return false;
        }

        Node* nodeToDelete = head;

        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            tail->next = head;
        }

        delete nodeToDelete;
        --listSize;

        return true;
    }

    bool deleteFromEnd()
    {
        if (isEmpty())
        {
            return false;
        }

        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            listSize = 0;
            return true;
        }

        Node* previous = head;

        while (previous->next != tail)
        {
            previous = previous->next;
        }

        delete tail;
        tail = previous;
        tail->next = head;

        --listSize;

        return true;
    }

    bool contains(int value) const
    {
        Node* current = head;

        for (int i = 0; i < listSize; ++i)
        {
            if (current->data == value)
            {
                return true;
            }

            current = current->next;
        }

        return false;
    }

    void display() const
    {
        if (isEmpty())
        {
            std::cout << "List is empty.\n";
            return;
        }

        Node* current = head;

        for (int i = 0; i < listSize; ++i)
        {
            std::cout << current->data;

            if (i < listSize - 1)
            {
                std::cout << " -> ";
            }

            current = current->next;
        }

        std::cout << " -> (back to head)\n";
    }

    void clear() noexcept
    {
        if (isEmpty())
        {
            return;
        }

        tail->next = nullptr;

        Node* current = head;

        while (current != nullptr)
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = tail = nullptr;
        listSize = 0;
    }
};

int main()
{
    CircularLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    std::cout << "Initial list: ";
    list.display();

    list.insertAtBeginning(5);

    std::cout << "After inserting 5 at beginning: ";
    list.display();

    list.insertAtEnd(40);

    std::cout << "After inserting 40 at end: ";
    list.display();

    list.deleteFromBeginning();

    std::cout << "After deleting from beginning: ";
    list.display();

    list.deleteFromEnd();

    std::cout << "After deleting from end: ";
    list.display();

    std::cout << "Contains 20? "
              << (list.contains(20) ? "Yes" : "No") << '\n';

    std::cout << "Size: " << list.size() << '\n';

    CircularLinkedList copiedList = list;

    std::cout << "Copied list: ";
    copiedList.display();

    return 0;
}
