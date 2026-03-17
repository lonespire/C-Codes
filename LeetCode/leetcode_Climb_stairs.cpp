#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int climbStairs(int n)
    {
        int dp[50] = {0};
        dp[1] = dp[0] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}