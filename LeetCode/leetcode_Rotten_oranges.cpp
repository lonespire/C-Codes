#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int n, m;
    vector<vector<int>> visited;
    int to[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void bfs(int i, int j, int cnt)
    {
        if (i >= n || j >= m || i < 0 || j < 0)
            return;
        if (visited[i][j] == -1 || visited[i][j] < cnt)
            return;
        visited[i][j] = cnt;
        for (int t = 0; t < 4; t++)
        {
            bfs(i + to[t][0], j + to[t][1], cnt + 1);
        }
    }
    int orangesRotting(vector<vector<int>> &grid)
    {
        n = grid.size(), m = grid[0].size();
        visited.resize(n, vector<int>(m, INT_MAX));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!grid[i][j])
                    visited[i][j] = -1;
                else if (grid[i][j] == 2)
                    visited[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                    bfs(i, j, 0);
            }
        }
        // int max_time = 0;
        // for (int i = 0; i < n; ++i)
        // {
        //     for (int j = 0; j < m; ++j)
        //     {
        //         if (visited[i][j] == -1)
        //             continue; // 跳过空单元格
        //         if (visited[i][j] == INT_MAX)
        //             return -1; // 存在未腐烂的新鲜橘子
        //         max_time = max(max_time, visited[i][j]);
        //     }
        // }
        // return max_time;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == -1)
                    continue;
                ans = max(ans, visited[i][j]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    Solution a;
    vector<vector<int>> temp = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << a.orangesRotting(temp);
    return 0;
}