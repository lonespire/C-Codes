// https://leetcode.cn/problems/house-robber/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int prepre = 0, pre = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int MAX = max(pre, prepre + nums[i]);
            prepre = pre;
            pre = MAX;
        }
        return pre;
    }
};
class Solution1
{
public:
    int rob(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[1] = ans = nums[0];
        for (int i = 1; i < n; i++)
        {

            for (int j = 0; j < i; j++)
            {
                dp[i + 1] = max(dp[i + 1], dp[j]);
            }
            dp[i + 1] += nums[i];
            ans = max(dp[i + 1], ans);
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    s.rob(nums);
    return 0;
}