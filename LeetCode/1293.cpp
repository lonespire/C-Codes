// https://leetcode.cn/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    static constexpr int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int shortestPath(vector<vector<int>> &grid, int k)
    {
        int n = grid.size(), m = grid[0].size();
        if (n == 1 && m == 1)
            return 0;
        vector<vector<int>> visited(n, vector<int>(m, INT_MAX));
        visited[0][0] = 0;
        queue<array<int, 3>> q;
        q.push({0, 0, 0});
        int step = 0;
        while (!q.empty())
        {
            step++;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto [x, y, z] = q.front();
                q.pop();
                for (int j = 0, xx, yy; j < 4; j++)
                {
                    xx = x + dir[j][0], yy = y + dir[j][1];
                    if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                        continue;
                    if ((visited[xx][yy] <= z + grid[xx][yy]) || (z + grid[xx][yy] > k))
                        continue;
                    visited[xx][yy] = z + grid[xx][yy];
                    if (xx == n - 1 && yy == m - 1)
                        return step;
                    q.push({xx, yy, z + grid[xx][yy]});
                }
            }
        }
        return -1;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution sol;
    vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {0, 0, 0}, {0, 1, 1}, {0, 0, 0}};
    cout << sol.shortestPath(grid, 1) << endl;
    return 0;
}