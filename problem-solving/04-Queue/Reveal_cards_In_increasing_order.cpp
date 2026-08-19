/*
==================================================
Problem: Reveal Cards In Increasing Order

Platform: LeetCode
Problem Number: 950

Difficulty: Medium

Topics:
- Queue
- Array
- Sorting
- Simulation

Approach:
1. Sort the deck in ascending order.
2. Store indices [0, 1, 2, ...] in a queue.
3. Place the smallest card in the front index.
4. Move the next index to the back of the queue.
5. Repeat until all cards are placed.

Time Complexity:
O(n log n)

Space Complexity:
O(n)

Date:
2026-08-19
==================================================
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck)
    {
        int n = deck.size();

        sort(deck.begin(), deck.end());

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            q.push(i);
        }

        vector<int> result(n);

        for (int card : deck)
        {
            int index = q.front();
            q.pop();

            result[index] = card;

            if (!q.empty())
            {
                q.push(q.front());
                q.pop();
            }
        }

        return result;
    }
};

