// https://leetcode.cn/problems/edit-distance/description/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int dp[501][501];
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
            dp[i][0] = i;
        for (int j = 1; j <= m; j++)
            dp[0][j] = j;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = word1[i - 1] == word2[j - 1] ? dp[i][j] = dp[i - 1][j - 1] : min(min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1), dp[i][j - 1] + 1);
            }
        }
        return dp[n][m];
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}