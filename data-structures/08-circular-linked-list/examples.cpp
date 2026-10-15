#include <iostream>
#include <stdexcept>

class CircularListExample {
private:
    struct Node {
        int data;
        Node* next;

        explicit Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    CircularListExample() : head(nullptr) {}

    ~CircularListExample() {
        clear();
    }

    CircularListExample(const CircularListExample&) = delete;
    CircularListExample& operator=(const CircularListExample&) = delete;

    bool isEmpty() const {
        return head == nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* current = head;

        while (current->next != head) {
            current = current->next;
        }

        current->next = newNode;
        newNode->next = head;
    }

    bool contains(int value) const {
        if (isEmpty()) {
            return false;
        }

        Node* current = head;

        do {
            if (current->data == value) {
                return true;
            }

            current = current->next;
        } while (current != head);

        return false;
    }

    bool deleteValue(int value) {
        if (isEmpty()) {
            return false;
        }

        Node* current = head;
        Node* previous = nullptr;

        do {
            if (current->data == value) {
                if (current == head && current->next == head) {
                    delete current;
                    head = nullptr;
                    return true;
                }

                if (current == head) {
                    Node* last = head;

                    while (last->next != head) {
                        last = last->next;
                    }

                    head = head->next;
                    last->next = head;
                } else {
                    previous->next = current->next;
                }

                delete current;
                return true;
            }

            previous = current;
            current = current->next;
        } while (current != head);

        return false;
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "List is empty.\n";
            return;
        }

        Node* current = head;

        do {
            std::cout << current->data;
            current = current->next;

            if (current != head) {
                std::cout << " -> ";
            }
        } while (current != head);

        std::cout << " -> (back to head)\n";
    }

    void clear() {
        if (isEmpty()) {
            return;
        }

        Node* current = head->next;

        while (current != head) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }

        delete head;
        head = nullptr;
    }
};

int main() {
    // Example 1: Empty list
    std::cout << "Example 1: Empty list\n";

    CircularListExample firstList;
    firstList.display();

    // Example 2: Inserting elements
    std::cout << "\nExample 2: Inserting elements\n";

    firstList.insertAtEnd(10);
    firstList.insertAtEnd(20);
    firstList.insertAtEnd(30);
    firstList.insertAtEnd(40);

    firstList.display();

    // Example 3: Searching for elements
    std::cout << "\nExample 3: Searching\n";

    std::cout << "Contains 20? "
              << (firstList.contains(20) ? "Yes" : "No") << '\n';

    std::cout << "Contains 99? "
              << (firstList.contains(99) ? "Yes" : "No") << '\n';

    // Example 4: Deleting the head
    std::cout << "\nExample 4: Deleting the head (10)\n";

    firstList.deleteValue(10);
    firstList.display();

    // Example 5: Deleting a middle element
    std::cout << "\nExample 5: Deleting a middle element (30)\n";

    firstList.deleteValue(30);
    firstList.display();

    // Example 6: Deleting the remaining elements
    std::cout << "\nExample 6: Deleting remaining elements\n";

    firstList.deleteValue(20);
    firstList.deleteValue(40);
    firstList.display();

    // Example 7: Deleting from an empty list
    std::cout << "\nExample 7: Deleting from an empty list\n";

    std::cout << "Deletion successful? "
              << (firstList.deleteValue(100) ? "Yes" : "No") << '\n';

    return 0;
}