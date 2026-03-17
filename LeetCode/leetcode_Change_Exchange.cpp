#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (auto j : coins)
            {
                if (i < j)
                    continue;
                dp[i] = min(dp[i], dp[i - j]);
            }
            if (dp[i] != INT_MAX)
                dp[i]++;
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}