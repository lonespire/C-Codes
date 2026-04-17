#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    static constexpr int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[n - 1][n - 1] == 1)
            return -1;
        queue<pair<int, int>> q;

        if (!grid[0][0])
        {
            q.push({0, 0});
            grid[0][0] = 2;
        }
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int xx, yy, k = 0; k < 8; k++)
            {
                xx = x + dir[k][0], yy = y + dir[k][1];
                if (xx < 0 || xx >= n || yy < 0 || yy >= n || grid[xx][yy])
                    continue;
                int minTime = grid[x][y] + 1;
                grid[xx][yy] = minTime;
                if (xx == n - 1 && yy == n - 1)
                    return grid[xx][yy] - 1;
                q.push({xx, yy});
            }
        }
        if (!grid[n - 1][n - 1])
            return -1;
        else
            return grid[n - 1][n - 1] - 1;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    vector<vector<int>> grid = {{0, 1}, {1, 0}};
    // cout << s.shortestPathBinaryMatrix(grid) << endl;
    grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 1}};
    cout << s.shortestPathBinaryMatrix(grid) << endl;

    return 0;
}