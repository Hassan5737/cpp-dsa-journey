/*
==================================================
Problem: Backspace String Compare

Platform: LeetCode

Difficulty: Easy

Topics:
- Stack
- Strings
- Simulation

Approach:
1. Create two stacks to process the two strings independently.
2. Traverse string s:
   - Push normal characters into the first stack.
   - When '#' is encountered, remove the previous character if
     the stack is not empty.
3. Traverse string t using the same process with the second stack.
4. Compare the two stacks from the top.
5. If any corresponding characters are different, return false.
6. After the comparison, both stacks must be empty for the strings
   to be equal.
7. Return true if both processed strings are identical.

Time Complexity:
O(n + m)

Space Complexity:
O(n + m)

Date:
2026-08-11
==================================================
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> stS;
        stack<char> stT;

        for (char c : s)
        {
            if (c != '#')
            {
                stS.push(c);
            }
            else
            {
                if (!stS.empty())
                {
                    stS.pop();
                }
            }
        }

        for (char c : t)
        {
            if (c != '#')
            {
                stT.push(c);
            }
            else
            {
                if (!stT.empty())
                {
                    stT.pop();
                }
            }
        }

        while (!stS.empty() && !stT.empty())
        {
            if (stS.top() != stT.top())
            {
                return false;
            }

            stS.pop();
            stT.pop();
        }

        return stS.empty() && stT.empty();
    }
};
