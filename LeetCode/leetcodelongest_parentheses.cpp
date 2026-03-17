#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size(), ans = 0;
        vector<int> dp(n + 1, 0);
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '(')
                continue;
            if (s[i - 1] == '(')
            {
                if (i >= 2)
                    dp[i] = dp[i - 2] + 2;
                else
                    dp[i] += 2;
                ans = max(ans, dp[i]);
            }
            else
            {
                if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                {
                    if (i - dp[i - 1] - 2 >= 0)
                        dp[i] = dp[i - dp[i - 1] - 2] + dp[i - 1] + 2;
                    else
                        dp[i] = dp[i - 1] + 2;
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    Solution a;
    cout << a.longestValidParentheses("(()())");
    return 0;
}