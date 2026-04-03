// https://leetcode.cn/problems/minimum-size-subarray-sum/description/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int MIN = INT_MAX, sum = 0;
        int l = 0, r = 0;
        for (; r < n; r++)
        {
            sum += nums[r];
            if (sum >= target)
                break;
        }

        while (r < n && l <= r)
        {
            while (sum - nums[l] >= target && l <= r)
            {
                sum -= nums[l];
                l++;
            }
            MIN = min(MIN, r - l + 1);
            r++;
            if (r < n)
                sum += nums[r];
        }
        if (MIN == INT_MAX)
            return 0;
        else
            return MIN;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution test;
    vector<int> num = {2, 3, 1, 2, 4, 3};
    test.minSubArrayLen(7, num);
    return 0;
}