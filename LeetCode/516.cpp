// https://leetcode.cn/problems/longest-palindromic-subsequence/description/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        const int n = s.size();
        vector<int> dp(n, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = 1; // 初始化长度为1的情况
            for (int j = i + 1, pre = 0; j < n; j++)
            {
                int temp = dp[j]; // 用临时变量存储dp[i+1][j-1]的情况，这个j-1是相对于下个循环也就是j+1的情况讨论的
                if (s[i] == s[j])
                {
                    dp[j] = pre + 2;
                }
                else
                {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                pre = temp;
            }
        }
        return dp[n - 1];
    }
};
class Solution2
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int k = 1; k < n; k++)
        {
            for (int i = 0; i + k < n; i++)
            {
                int j = i + k;
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}