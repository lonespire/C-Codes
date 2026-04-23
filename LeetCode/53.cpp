#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size(), ans = INT_MIN;
        // int *dp = new int[n];
        ans = max(ans, nums[0]);
        for (int i = 1; i < n; i++)
        {

            nums[i] = max(nums[i], nums[i - 1] + nums[i]);
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};
class Solution2
{
public:
    tuple<int, int, int, int> divide(vector<int> &nums, int l, int r)
    {
        if (l == r)
        {
            return {nums[l], nums[l], nums[l], nums[l]};
        }
        int mid = (l + r) / 2;
        auto [lsum, ll, lmax, lr] = divide(nums, l, mid);
        auto [rsum, rl, rmax, rr] = divide(nums, mid + 1, r);
        return {lsum + rsum, max(lsum + rl, ll), max({lmax, rmax, lr + rl}), max(rsum + lr, rr)};
    }
    int maxSubArray(vector<int> &nums)
    {
        auto [x, y, z, k] = divide(nums, 0, nums.size() - 1);
        return z;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}