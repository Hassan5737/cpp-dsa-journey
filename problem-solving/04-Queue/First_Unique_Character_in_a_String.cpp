/*
==================================================
Problem: First Unique Character in a String

Platform: LeetCode
Problem Number: 387

Difficulty: Easy

Topics:
- String
- Hash Table
- Counting

Approach:
- Count the frequency of every character.
- Traverse the string again.
- Return the index of the first character whose
  frequency is exactly 1.
- If no unique character exists, return -1.

Time Complexity:
O(n)

Space Complexity:
O(1)

Date:
2026-08-24
==================================================
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> frequency;

        for (char c : s)
        {
            frequency[c]++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (frequency[s[i]] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};