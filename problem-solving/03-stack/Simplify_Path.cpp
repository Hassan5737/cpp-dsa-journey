#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;

        string part;
        stringstream ss(path);

        while (getline(ss, part, '/'))
        {
            if (part.empty() || part == ".")
            {
                continue;
            }
            else if (part == "..")
            {
                if (!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(part);
            }
        }

        vector<string> dirs;

        while (!st.empty())
        {
            dirs.push_back(st.top());
            st.pop();
        }

        string result;

        for (int i = dirs.size() - 1; i >= 0; i--)
        {
            result += "/" + dirs[i];
        }

        return result.empty() ? "/" : result;
    }
};