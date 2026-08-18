/*
==================================================
Problem: Number of Students Unable to Eat Lunch

Platform: LeetCode
Problem Number: 1700

Difficulty: Easy

Topics:
- Queue
- Simulation

Approach:
- Store students in a queue.
- Check the student at the front against the
  current sandwich.
- If the student likes the sandwich, remove both.
- Otherwise, move the student to the back of the queue.
- If no student wants the current sandwich, the
  remaining students cannot eat.

Time Complexity:
O(n)

Space Complexity:
O(n)

Date:
2026-08-18
==================================================
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches)
    {
        queue<int> q;

        for (int student : students)
        {
            q.push(student);
        }

        int sandwichIndex = 0;
        int rotations = 0;

        while (!q.empty() && rotations < q.size())
        {
            if (q.front() == sandwiches[sandwichIndex])
            {
                q.pop();

                sandwichIndex++;
                rotations = 0;
            }
            else
            {
                int student = q.front();

                q.pop();
                q.push(student);

                rotations++;
            }
        }

        return q.size();
    }
};

