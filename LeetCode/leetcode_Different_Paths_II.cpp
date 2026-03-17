#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (m == 1 && n == 1 && obstacleGrid[0][0] == 1)
            return 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[1][1] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (obstacleGrid[i - 1][j - 1] == 1)
                    continue;
                if (i - 2 >= 0 && obstacleGrid[i - 2][j - 1] != 1)
                    dp[i][j] += dp[i - 1][j];
                if (j - 2 >= 0 && obstacleGrid[i - 1][j - 2] != 1)
                    dp[i][j] += dp[i][j - 1];
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