#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        static constexpr int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        // vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                    // visited[i][j] = true;
                }
                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int xx = x + dir[k][0], yy = y + dir[k][1];
                        if (xx < 0 || xx >= n || yy < 0 || yy >= m || !grid[xx][yy] || grid[xx][yy] == 2) //|| visited[xx][yy]
                            continue;
                        // visited[xx][yy] = true;
                        if (grid[xx][yy] == 1)
                            grid[xx][yy] = grid[x][y] + 1;
                        else
                        {
                            if (grid[xx][yy] <= grid[x][y] + 1)
                                continue;
                            else
                                grid[xx][yy] = grid[x][y] + 1;
                        }
                        q.push({xx, yy});
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!grid[i][j])
                    continue;
                if (grid[i][j] == 1)
                    return -1;
                ans = max(ans, grid[i][j] - 2);
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
        {2, 1, 1},
        {1, 1, 1},
        {0, 1, 2}};
    Solution s;
    cout << s.orangesRotting(grid) << endl;

    return 0;
}