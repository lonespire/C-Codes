// https://leetcode.cn/problems/longest-increasing-subsequence/description/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> tails;
        tails.reserve(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            if (!tails.size())
            {
                tails.push_back(nums[i]);
                continue;
            }
            auto it = lower_bound(tails.begin(), tails.end(), nums[i]);
            if (it == tails.end())
            {
                tails.push_back(nums[i]);
            }
            else
            {
                *it = nums[i];
            }
        }
        return tails.size();
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}