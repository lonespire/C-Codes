// https://leetcode.cn/problems/unique-paths-ii/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = !obstacleGrid[0][0];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j])
                    continue;
                int ii = i - 1, jj = j - 1;
                if (ii >= 0)
                    dp[i][j] += dp[ii][j];
                if (jj >= 0)
                    dp[i][j] += dp[i][jj];
            }
        }
        return dp[m - 1][n - 1];
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}