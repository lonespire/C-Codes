// https://leetcode.cn/problems/house-robber-ii/description/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int _rob(vector<int> &nums, int l, int r)
    {
        int prepre = 0, pre = 0;
        for (int i = l; i < r; i++)
        {
            int MAX = max(pre, prepre + nums[i]);
            prepre = pre;
            pre = MAX;
        }
        return pre;
    }
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        return max(_rob(nums, 0, nums.size() - 1), _rob(nums, 1, nums.size()));
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}