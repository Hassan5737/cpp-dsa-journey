/*
==================================================
Problem: Next Greater Element I

Platform: LeetCode

Difficulty: Easy

Topics:
- Stack
- Monotonic Stack
- Hash Table
- Array

Approach:
1. Traverse nums2 from left to right.
2. Use a stack to store elements that are still waiting
   for their next greater element.
3. When the current element is greater than the element
   at the top of the stack, the current element is its
   next greater element.
4. Store each result in an unordered_map.
5. Remove the resolved element from the stack.
6. Push the current element into the stack because it may
   still need a greater element later.
7. Elements remaining in the stack have no next greater
   element, so assign -1 to them.
8. Traverse nums1 and retrieve each element's answer
   from the map.

Time Complexity:
O(nums1.length + nums2.length)

Space Complexity:
O(nums2.length)

Date:
2026-08-10
==================================================
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        stack<int> st;
        unordered_map<int, int> nextGreater;

        for (int num : nums2)
        {
            while (!st.empty() && num > st.top())
            {
                nextGreater[st.top()] = num;
                st.pop();
            }

            st.push(num);
        }

        while (!st.empty())
        {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        vector<int> answer;

        for (int num : nums1)
        {
            answer.push_back(nextGreater[num]);
        }

        return answer;
    }
};