// https://leetcode.cn/problems/unique-paths/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
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