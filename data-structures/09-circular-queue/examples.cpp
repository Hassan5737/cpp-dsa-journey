#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <stdexcept>
#include <utility>
#include <cstddef>

namespace data_structures
{

template <typename T>
class CircularQueue
{
private:
    std::vector<T> data;
    std::size_t frontIndex = 0;
    std::size_t rearIndex = 0;
    std::size_t currentSize = 0;

    std::size_t nextIndex(std::size_t index) const noexcept
    {
        return (index + 1) % data.size();
    }

public:
    explicit CircularQueue(std::size_t capacity)
        : data(capacity)
    {
        if (capacity == 0)
        {
            throw std::invalid_argument("Capacity must be greater than zero.");
        }
    }

    bool isEmpty() const noexcept
    {
        return currentSize == 0;
    }

    bool isFull() const noexcept
    {
        return currentSize == data.size();
    }

    std::size_t size() const noexcept
    {
        return currentSize;
    }

    std::size_t capacity() const noexcept
    {
        return data.size();
    }

    void enqueue(const T& value)
    {
        if (isFull())
        {
            throw std::overflow_error("Queue is full.");
        }

        data[rearIndex] = value;
        rearIndex = nextIndex(rearIndex);
        ++currentSize;
    }

    std::optional<T> dequeue()
    {
        if (isEmpty())
        {
            return std::nullopt;
        }

        T value = std::move(data[frontIndex]);
        frontIndex = nextIndex(frontIndex);
        --currentSize;

        if (isEmpty())
        {
            frontIndex = 0;
            rearIndex = 0;
        }

        return value;
    }

    const T* front() const noexcept
    {
        return isEmpty() ? nullptr : &data[frontIndex];
    }

    const T* back() const noexcept
    {
        if (isEmpty())
        {
            return nullptr;
        }

        const std::size_t lastIndex =
            (rearIndex == 0) ? data.size() - 1 : rearIndex - 1;

        return &data[lastIndex];
    }

    void clear() noexcept
    {
        frontIndex = 0;
        rearIndex = 0;
        currentSize = 0;
    }

    void display() const
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty.\n";
            return;
        }

        std::cout << "Queue: ";

        for (std::size_t i = 0; i < currentSize; ++i)
        {
            std::size_t index = (frontIndex + i) % data.size();
            std::cout << data[index] << ' ';
        }

        std::cout << '\n';
    }
};

} // namespace data_structures

void exampleBasicOperations()
{
    std::cout << "\n=== Example 1: Basic Operations ===\n";

    data_structures::CircularQueue<int> queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display();

    std::cout << "Front: " << *queue.front() << '\n';
    std::cout << "Back: " << *queue.back() << '\n';
    std::cout << "Size: " << queue.size() << '\n';
}

void exampleFullAndEmpty()
{
    std::cout << "\n=== Example 2: Full and Empty States ===\n";

    data_structures::CircularQueue<int> queue(3);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Full: " << std::boolalpha << queue.isFull() << '\n';

    try
    {
        queue.enqueue(40);
    }
    catch (const std::overflow_error& error)
    {
        std::cout << "Error: " << error.what() << '\n';
    }

    while (!queue.isEmpty())
    {
        std::cout << "Removed: " << *queue.dequeue() << '\n';
    }

    std::cout << "Empty: " << queue.isEmpty() << '\n';
}

void exampleCircularBehavior()
{
    std::cout << "\n=== Example 3: Circular Behavior ===\n";

    data_structures::CircularQueue<int> queue(5);

    for (int value = 10; value <= 50; value += 10)
    {
        queue.enqueue(value);
    }

    queue.display();

    queue.dequeue();
    queue.dequeue();

    std::cout << "After removing two elements:\n";
    queue.display();

    queue.enqueue(60);
    queue.enqueue(70);

    std::cout << "After inserting two more elements:\n";
    queue.display();
}

void exampleStringQueue()
{
    std::cout << "\n=== Example 4: Generic Queue with Strings ===\n";

    data_structures::CircularQueue<std::string> queue(4);

    queue.enqueue("Backend");
    queue.enqueue("Blockchain");
    queue.enqueue("Systems Programming");

    queue.display();

    if (const std::string* value = queue.front())
    {
        std::cout << "Next item: " << *value << '\n';
    }
}

void exampleClearOperation()
{
    std::cout << "\n=== Example 5: Clear Operation ===\n";

    data_structures::CircularQueue<int> queue(4);

    queue.enqueue(100);
    queue.enqueue(200);
    queue.enqueue(300);

    std::cout << "Before clear:\n";
    queue.display();

    queue.clear();

    std::cout << "After clear:\n";
    queue.display();

    std::cout << "Size: " << queue.size() << '\n';
    std::cout << "Empty: " << queue.isEmpty() << '\n';
}

int main()
{
    exampleBasicOperations();
    exampleFullAndEmpty();
    exampleCircularBehavior();
    exampleStringQueue();
    exampleClearOperation();

    return 0;
}