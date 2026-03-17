#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        // sort(nums.begin(), nums.end());
        int sum = 0, n = nums.size();
        for (auto i : nums)
            sum += i;
        if (sum & 1)
            return 0;
        vector<bool> dp(sum / 2 + 1, 0);
        dp[0] = 1;
        for (auto i : nums)
        {
            if (i > sum / 2)
                continue;
            for (int j = sum / 2; j >= i; j--)
            {
                if (dp[j - i])
                    dp[j] = 1;
            }
        }
        return dp[sum / 2];
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}