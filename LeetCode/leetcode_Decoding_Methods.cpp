#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        unordered_map<char, int> reflect;
        vector<int> dp(n, 0);
        for (int i = 1; i <= 26; i++)
            reflect[i] = 1;
        if (s[0] == '0')
            return 0;
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i] != '0')
                dp[i] += dp[i - 1];
            if (s[i - 1] != '0' && reflect.count((s[i - 1] - '0') * 10 + s[i] - '0'))
                if (i >= 2)
                    dp[i] += dp[i - 2];
                else
                    dp[i]++;
        }
        return dp[n - 1];
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    Solution a;
    cout << a.numDecodings("2101");
    return 0;
}