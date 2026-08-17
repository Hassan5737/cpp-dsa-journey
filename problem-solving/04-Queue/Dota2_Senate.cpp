/*
==================================================
Problem: Dota2 Senate

Platform: LeetCode
Problem Number: 649

Difficulty: Medium

Topics:
- Queue
- Simulation
- Greedy

Approach:
- Store the indices of Radiant and Dire senators
  in separate queues.
- Compare the front indices of both queues.
- The senator with the smaller index acts first.
- That senator bans the opponent's current senator.
- The acting senator survives and returns to the queue
  for the next round using index + n.
- Continue until one party has no senators left.

Time Complexity:
O(n)

Space Complexity:
O(n)

Date:
2026-08-17
==================================================
*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        queue<int> radiant;
        queue<int> dire;

        int n = senate.size();

       
        for (int i = 0; i < n; i++)
        {
            if (senate[i] == 'R')
            {
                radiant.push(i);
            }
            else
            {
                dire.push(i);
            }
        }

       
        while (!radiant.empty() && !dire.empty())
        {
            int r = radiant.front();
            int d = dire.front();

            radiant.pop();
            dire.pop();

            if (r < d)
            {
               
                radiant.push(r + n);
            }
            else
            {
                
                dire.push(d + n);
            }
        }

        if (!radiant.empty())
        {
            return "Radiant";
        }

        return "Dire";
    }
};