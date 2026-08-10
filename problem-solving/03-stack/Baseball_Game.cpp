/*
==================================================
Problem: Baseball Game

Platform: LeetCode

Difficulty: Easy

Topics:
- Stack
- Simulation
- Strings

Approach:
1. Use a stack to store all valid scores currently in the record.
2. If the operation is an integer, convert it from string to int and push it.
3. If the operation is "C", remove the last score using pop().
4. If the operation is "D", double the last score and push the new score.
5. If the operation is "+", take the last two scores, add them,
   and push the resulting score.
6. Traverse the stack at the end and calculate the total sum.

Time Complexity:
O(n)

Space Complexity:
O(n)

Date:
2026-08-10
==================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    int calPoints(vector<string>& operations)
    {
        stack<int> record;

        for (string operation : operations)
        {
            if (operation != "C" && operation != "D" && operation != "+")
            {
                record.push(stoi(operation));
            }
            else if (operation == "C")
            {
                record.pop();
            }
            else if (operation == "D")
            {
                record.push(record.top() * 2);
            }
            else if (operation == "+")
            {
                int temp = record.top();
                record.pop();

                int temp_2 = record.top() + temp;

                record.push(temp);
                record.push(temp_2);
            }
        }

        int result = 0;

        while (!record.empty())
        {
            result += record.top();
            record.pop();
        }

        return result;
    }
};

