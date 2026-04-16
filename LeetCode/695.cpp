#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        static constexpr int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans = 0;
        int cur_s = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] && !visited[i][j])
                {
                    q.push({i, j});
                    visited[i][j] = true;
                }
                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    cur_s++;
                    for (int k = 0; k < 4; k++)
                    {
                        int xx = x + dir[k][0], yy = y + dir[k][1];
                        if (xx < 0 || xx >= n || yy < 0 || yy >= m || !grid[xx][yy] || visited[xx][yy])
                            continue;
                        visited[xx][yy] = true;
                        q.push({xx, yy});
                    }
                }
                ans = max(ans, cur_s);
                cur_s = 0;
            }
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    Solution s;
    cout << s.maxAreaOfIsland(grid) << endl;

    return 0;
}