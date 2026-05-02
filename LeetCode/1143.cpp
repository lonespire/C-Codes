// https://leetcode.cn/problems/longest-common-subsequence/description/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int longestCommonSubsequence(string &text1, string &text2)
    {
        if (text1.size() > text2.size())
            swap(text1, text2);
        int n = text1.size(), m = text2.size();
        int *dp = new int[m + 1]();
        for (int i = 1; i <= n; i++)
        {
            char c = text1[i - 1];
            for (int j = 1, pre = 0; j <= m; j++)
            {
                int temp = dp[j];
                if (c == text2[j - 1])
                    dp[j] = pre + 1;
                else
                    dp[j] = max(dp[j], dp[j - 1]);
                pre = temp;
            }
        }
        return dp[m];
        delete[] dp;
    }
};
class Solution2
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
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