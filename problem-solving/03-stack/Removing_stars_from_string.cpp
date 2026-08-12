/*
==================================================
Problem: Removing Stars From a String

Platform: LeetCode
Problem Number: 2390

Difficulty: Medium

Topics:
- Stack
- Strings
- Simulation

Approach:
1. Traverse the string from left to right.
2. For every normal character, push it onto the stack.
3. When encountering '*', pop the closest non-star character
   from the stack.
4. After processing the entire string, extract the remaining
   characters from the stack.
5. Reverse the result because stack extraction happens from
   top to bottom.

Time Complexity:
O(n)

Space Complexity:
O(n)

Date:
2026-08-12
==================================================
*/

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;


class Solution
{
public:
    string removeStars(string s)
    {
        string result;
        stack<char> st;

        for (char c : s)
        {
            if (c == '*')
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }

        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};