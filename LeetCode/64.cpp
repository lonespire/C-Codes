// https://leetcode.cn/problems/minimum-path-sum/description/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!i && !j)
                    continue;
                int ii = i - 1, jj = j - 1;
                if (jj < 0)
                    dp[i][j] = dp[ii][j];
                else if (ii < 0)
                    dp[i][j] = dp[i][jj];
                else
                    dp[i][j] = min(dp[ii][j], dp[i][jj]);
                dp[i][j] += grid[i][j];
            }
        }
        return dp[n - 1][m - 1];
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}