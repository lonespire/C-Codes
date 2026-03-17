#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef long long ll;
    string longestPalindrome(string s)
    {
        ll n = s.size();
        if (n <= 1)
            return s;
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        string ans = "";
        for (ll i = 0; i < n; i++)
        {
            ans = max(ans, s.substr(i, 1));
            dp[i][i] = 1;
        }
        for (ll i = 0; i + 1 < n; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
                ans = max(ans, s.substr(i, 2));
            }
        }
        for (ll i = 2; i < n; i++)
        {
            for (ll j = 0; j + i < n; j++)
            {
                if (s[j] == s[j + i] && dp[j + 1][j + i - 1] == 1)
                    dp[j][j + i] = 1;
            }
        }
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j + i < n; j++)
            {
                if (dp[j][j + i] == 1)
                    ans = s.substr(j, i + 1);
            }
        }
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}