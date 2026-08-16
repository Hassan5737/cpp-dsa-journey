/*
==================================================
Problem: Number of Recent Calls

Platform: LeetCode
Problem Number: 933

Difficulty: Easy

Topics:
- Queue
- Design

Approach:
1. Store every request timestamp in a queue.
2. For each new request at time t, add t to the queue.
3. Calculate the beginning of the valid time range:
   t - 3000
4. Remove all requests that occurred before this
   time range.
5. Return the number of remaining requests.

Time Complexity:
O(n) amortized

Space Complexity:
O(n)

Date:
2026-08-16
==================================================
*/

#include <iostream>
#include <queue>

using namespace std;

class RecentCounter
{
private:
    queue<int> requests;

public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        int start = t - 3000;

        requests.push(t);

        while (requests.front() < start)
        {
            requests.pop();
        }

        return requests.size();
    }
};
