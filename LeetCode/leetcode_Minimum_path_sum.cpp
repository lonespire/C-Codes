#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = grid[i - 1][j - 1];
            }
        }
        for (int j = 1; j <= n; j++)
        {
            dp[1][j] += dp[1][j - 1];
        }
        for (int j = 1; j <= m; j++)
        {
            dp[j][1] += dp[j - 1][1];
        }
        for (int i = 2; i <= m; i++)
        {
            for (int j = 2; j <= n; j++)
            {
                dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}