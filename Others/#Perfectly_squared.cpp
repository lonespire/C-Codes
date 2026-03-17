#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            int MIN = INT_MAX;
            for (int j = 1; j * j <= i; j++)
            {
                MIN = min(MIN, dp[i - j * j]);
            }
            MIN++;
            dp[i] = MIN;
        }
        return dp[n];
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}