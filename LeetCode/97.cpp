#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.size(), m = s2.size();
        if (n + m != s3.size())
            return false;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++)
            dp[i + 1][0] = dp[i][0] && s1[i] == s3[i];
        for (int i = 0; i < m; i++)
            dp[0][i + 1] = dp[0][i] && s2[i] == s3[i];
        for (int k = 1; k <= n + m; k++)
        {
            for (int i = 1; i - 1 < n && i < k; i++)
            {
                int j = k - i;
                if (j - 1 >= m || j <= 0)
                    continue;
                dp[i][j] = dp[i - 1][j] && s3[k - 1] == s1[i - 1] || dp[i][j - 1] && s3[k - 1] == s2[j - 1];
            }
        }
        return dp[n][m];
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    s.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    return 0;
}