#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return 0;
        int n = s1.size();
        check_char(s1, 0, n - 1, s2, 0, n - 1);
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, 0)));
        for (int len = 1; len <= n; len++)
        {
            for (int i = 0; i < n - len + 1; i++)
            {
                for (int j = 0; j < n - len + 1; j++)
                {
                    if (len == 1)
                        dp[i][j][1] = (s1[i] == s2[j]);
                    else
                    {
                        if (!check_char(s1, i, i + len - 1, s2, j, j + len - 1))
                        {
                            continue;
                        }
                        for (int k = 1; k < len; k++)
                        {
                            dp[i][j][len] = dp[i][j][len] || ((dp[i][j][k] && dp[i + k][j + k][len - k]) || (dp[i][j + len - k][k] && dp[i + k][j][len - k]));
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }

private:
    bool check_char(const string &s1, int a, int b, const string &s2, int c, int d)
    {
        vector<int> cnt(26, 0);
        for (int i = a; i <= b; i++)
            cnt[s1[i] - 'a']++;
        for (int i = c; i <= d; i++)
            cnt[s2[i] - 'a']--;
        for (int &i : cnt)
            if (i)
                return false;
        return true;
    }
};
class Solution1
{
public:
    bool isScramble(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return 0;

        function<bool(int, int, string)>
            dfs = [&](int l, int r, string s) -> bool
        {
            if (s2.substr(l, r - l + 1) == s)
                return 1;
            if (l == r)
                return 0;
            bool ans = 0;
            for (int i = 0; i < s.size() - 1; i++)
            {
                ans = ans || (dfs(l, i + l, s.substr(0, i + 1)) && dfs(i + l + 1, r, s.substr(i + 1, s.size() - i - 1)));
                ans = ans || (dfs(l, r - i - 1, s.substr(i + 1, s.size() - i - 1)) && dfs(r - i, r, s.substr(0, i + 1)));
            }
            return ans;
        };
        return dfs(0, s1.size() - 1, s1);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    s.isScramble("abcdbdacbdac", "bdacabcdbdac");
    return 0;
}