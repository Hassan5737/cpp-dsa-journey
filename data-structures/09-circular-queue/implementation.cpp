#include <iostream>
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
    std::size_t frontIndex;
    std::size_t rearIndex;
    std::size_t currentSize;

    std::size_t nextIndex(std::size_t index) const noexcept
    {
        return (index + 1) % data.size();
    }

public:
    explicit CircularQueue(std::size_t capacity)
        : data(capacity),
          frontIndex(0),
          rearIndex(0),
          currentSize(0)
    {
        if (capacity == 0)
        {
            throw std::invalid_argument(
                "CircularQueue capacity must be greater than zero."
            );
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
            throw std::overflow_error("CircularQueue is full.");
        }

        data[rearIndex] = value;
        rearIndex = nextIndex(rearIndex);
        ++currentSize;
    }

    void enqueue(T&& value)
    {
        if (isFull())
        {
            throw std::overflow_error("CircularQueue is full.");
        }

        data[rearIndex] = std::move(value);
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

    T* front() noexcept
    {
        if (isEmpty())
        {
            return nullptr;
        }

        return &data[frontIndex];
    }

    const T* front() const noexcept
    {
        if (isEmpty())
        {
            return nullptr;
        }

        return &data[frontIndex];
    }

    T* back() noexcept
    {
        if (isEmpty())
        {
            return nullptr;
        }

        const std::size_t lastIndex =
            (rearIndex == 0) ? data.size() - 1 : rearIndex - 1;

        return &data[lastIndex];
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
            const std::size_t index =
                (frontIndex + i) % data.size();

            std::cout << data[index] << ' ';
        }

        std::cout << '\n';
    }
};

} // namespace data_structures

int main()
{
    using data_structures::CircularQueue;

    CircularQueue<int> queue(5);

    std::cout << std::boolalpha;

    std::cout << "Initial state:\n";
    std::cout << "Empty: " << queue.isEmpty() << '\n';
    std::cout << "Size: " << queue.size() << '\n';
    std::cout << "Capacity: " << queue.capacity() << "\n\n";

    std::cout << "Enqueue operations:\n";

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    queue.display();

    std::cout << "Full: " << queue.isFull() << '\n';
    std::cout << "Size: " << queue.size() << "\n\n";

    std::cout << "Front: " << *queue.front() << '\n';
    std::cout << "Back: " << *queue.back() << "\n\n";

    std::cout << "Dequeue operation:\n";

    if (auto value = queue.dequeue())
    {
        std::cout << "Removed: " << *value << '\n';
    }

    queue.display();

    std::cout << "\nCircular behavior:\n";

    queue.enqueue(60);
    queue.display();

    queue.enqueue(70);
    queue.dequeue();
    queue.enqueue(80);

    queue.display();

    std::cout << "\nClear operation:\n";

    queue.clear();
    queue.display();

    std::cout << "Empty: " << queue.isEmpty() << '\n';
    std::cout << "Size: " << queue.size() << '\n';

    return 0;
}