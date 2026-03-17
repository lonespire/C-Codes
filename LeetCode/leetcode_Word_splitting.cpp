#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> words;
        for (auto i : wordDict)
            words.insert(i);
        int n = s.size();
        vector<bool> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && words.count(s.substr(j, i - j)))
                    dp[i] = 1;
            }
        }
        return dp[n];
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}