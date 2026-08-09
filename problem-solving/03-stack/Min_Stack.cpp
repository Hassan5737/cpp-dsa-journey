/*
==================================================
Problem: Min Stack

Platform: LeetCode

Difficulty: Medium

Topics:
- Stack
- Design

Approach:
1. Use a stack of pairs.
2. The first value stores the actual element.
3. The second value stores the minimum value from
   the bottom of the stack up to the current element.
4. When pushing a new value, compare it with the
   current minimum and store the smaller value.
5. pop() removes the top pair.
6. top() returns the actual value stored in the pair.
7. getMin() returns the minimum stored in the top pair.

This allows all operations to be performed in O(1).

Time Complexity:
O(1) for push, pop, top, and getMin.

Space Complexity:
O(n)

Date:
2026-08-09
==================================================
*/

#include <iostream>
#include <stack>
#include <utility>

using namespace std;

class MinStack
{
private:
    stack<pair<int, int>> st;

public:

    MinStack()
    {
    }

    void push(int value)
    {
        if (st.empty())
        {
            st.push({value, value});
        }
        else
        {
            int currentMin = min(value, st.top().second);
            st.push({value, currentMin});
        }
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

