// https://leetcode.cn/problems/search-in-rotated-sorted-array/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[l] <= nums[mid])
            {
                if (nums[l] <= target && target <= nums[mid])
                    r = mid;
                else
                    l = mid + 1;
                continue;
            }
            else
            {
                if (nums[mid + 1] <= target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid;
                continue;
            }
        }
        if (nums[l] == target)
            return l;
        else
            return -1;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    vector<int> nums = {5, 1, 3};
    s.search(nums, 5);
    return 0;
}