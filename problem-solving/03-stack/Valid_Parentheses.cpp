/*
==================================================
Problem: Valid Parentheses

Platform: LeetCode

Difficulty: Easy

Topics:
- Stack
- Strings

Approach:
1. Create a stack to store opening brackets.
2. Traverse the string character by character.
3. If the current character is an opening bracket,
   push it onto the stack.
4. If it is a closing bracket:
   - Check if the stack is empty.
   - Check whether the top opening bracket matches it.
   - If not, return false.
   - Otherwise, pop the matching opening bracket.
5. After processing the entire string, make sure the
   stack is empty.
6. Return the result.

Time Complexity:
O(n)

Space Complexity:
O(n)

Date:
2026-08-08
==================================================
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                    return false;

                if (c == ')' && st.top() != '(')
                    return false;

                if (c == '}' && st.top() != '{')
                    return false;

                if (c == ']' && st.top() != '[')
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
};

