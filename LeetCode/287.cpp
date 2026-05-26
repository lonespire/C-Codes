// https://leetcode.cn/problems/find-the-duplicate-number/description/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int fast = 0, low = 0;
        do
        {
            fast = nums[nums[fast]];
            low = nums[low];
        } while (fast != low);
        low = 0;
        while (low != fast)
        {
            low = nums[low];
            fast = nums[fast];
        }
        return fast;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    Solution sol;
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << sol.findDuplicate(nums) << endl;

    return 0;
}