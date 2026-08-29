/*
==================================================
Problem: Daily Temperatures

Platform: LeetCode
Problem Number: 739

Difficulty: Medium

Topics:
- Stack
- Monotonic Stack
- Array

Approach:
- Use a monotonic decreasing stack.
- Store indices of temperatures whose warmer
  future day has not been found yet.
- For each temperature:
    1. While the current temperature is warmer
       than the temperature at the stack's top index:
           - Calculate the number of days between them.
           - Store the result.
           - Remove the resolved index.
    2. Push the current index onto the stack.
- Remaining indices have no warmer future day,
  so their answers stay 0.

Time Complexity:
O(n)

Space Complexity:
O(n)

Date:
2026-08-29
==================================================
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> result(temperatures.size(), 0);
        stack<int> st;

        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!st.empty() &&
                   temperatures[i] > temperatures[st.top()])
            {
                int previousDay = st.top();
                st.pop();

                result[previousDay] = i - previousDay;
            }

            st.push(i);
        }

        return result;
    }
};