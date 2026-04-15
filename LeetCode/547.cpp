// https://leetcode.cn/problems/number-of-provinces/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected) // 这里采用bfs写法，实际上并查集结果更快
    {
        int n = isConnected.size();
        bool *visited = new bool[n]{};

        queue<int> q;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                q.push(i);
                ans++;
            }
            while (!q.empty())
            {
                int top = q.front();
                q.pop();
                visited[top] = 1;
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && isConnected[top][j])
                        q.push(j);
                }
            }
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}