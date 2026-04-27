// https://leetcode.cn/problems/word-break/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        string_view sv(s);
        vector<bool> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) // 以i为起点
        {
            for (auto &word : wordDict)
            {
                if (sv.substr(i, word.size()) == word)
                {
                    dp[i + word.size()] = dp[i + word.size()] || dp[i];
                    if (dp[n])
                        return true;
                }
            }
        }
        return dp[n];
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    vector<string> test = {"aaaa", "aaa"};
    s.wordBreak("aaaaaaa", test);
    return 0;
}