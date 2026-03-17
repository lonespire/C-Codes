#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size(), ans = 0;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            int MAX = 0;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    MAX = max(MAX, dp[j]);
            }
            dp[i] += MAX;
            ans = max(dp[i], ans);
        }
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}