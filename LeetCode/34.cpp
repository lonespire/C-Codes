// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int binary_search01(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (target <= nums[mid])
            {
                r = mid;
            }
            else
                l = mid + 1;
        }
        if (nums[l] != target)
            return -1;
        else
            return l;
    }
    int binary_search10(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            if (target < nums[mid])
            {
                r = mid - 1;
            }
            else
                l = mid;
        }
        if (nums[l] != target)
            return -1;
        else
            return l;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (!nums.size())
            return {-1, -1};
        int l = binary_search01(nums, target);
        if (l == -1)
            return {-1, -1};
        int r = binary_search10(nums, target);
        return {l, r};
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    s.searchRange(nums, 8);
    return 0;
}