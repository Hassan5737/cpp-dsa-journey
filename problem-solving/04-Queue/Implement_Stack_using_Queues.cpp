/*
==================================================
Problem: Implement Stack using Queues

Platform: LeetCode
Problem Number: 225

Difficulty: Easy

Topics:
- Queue
- Stack
- Design

Approach:
- Use one queue to implement stack behavior.
- When pushing a new element, add it to the back
  of the queue.
- Rotate all previous elements behind the new element
  so the newest element becomes the front.
- This makes pop() and top() behave like a stack.

Time Complexity:
- push(): O(n)
- pop(): O(1)
- top(): O(1)
- empty(): O(1)

Space Complexity:
O(n)

Date:
2026-08-22
==================================================
*/

#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
private:
    queue<int> q;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);

        int size = q.size() - 1;

        for (int i = 0; i < size; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int value = q.front();
        q.pop();

        return value;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};