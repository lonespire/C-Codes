// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size(), ans = 0;
        // vector<int> dp(n + 1, 0);
        for (int i = 1; i < n; i++)
        {
            if (prices[i] > prices[i - 1])
                ans += prices[i] - prices[i - 1];
        }
        return ans;
    }
};
class Solution1
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i < n; i++)
        {
            dp[i] = dp[i - 1];
            for (int j = 0; j < i; j++)
                dp[i] = max(dp[i], dp[j] + prices[i] - prices[j]);
        }
        return dp[n - 1];
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}