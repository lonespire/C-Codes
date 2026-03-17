#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<vector<int>> edg;
    vector<int> indeg;
    int ans = 0;
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        edg.resize(numCourses), indeg.resize(numCourses, 0);
        for (auto &i : prerequisites)
        {
            edg[i[1]].push_back(i[0]);
            indeg[i[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (!indeg[i])
                q.push(i);
        }
        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            ans++;
            for (auto i : edg[top])
            {
                indeg[i]--;
                if (!indeg[i])
                    q.push(i);
            }
        }
        return ans == numCourses;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}