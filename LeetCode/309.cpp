#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0)); // 0为持有 1为没有
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], (i - 2 < 0 ? 0 : dp[i - 2][1]) - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> test = {1, 2, 3, 0, 2};
    Solution s;
    s.maxProfit(test);
    return 0;
}