#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ind(nums.size());
        for (int i = 0; i < nums.size(); i++)
            ind[i] = i;
        sort(ind.begin(), ind.end(), [&nums](int a, int b)
             { return nums[a] < nums[b]; });
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            if (nums[ind[l]] + nums[ind[r]] == target)
                break;
            if (nums[ind[l]] + nums[ind[r]] < target)
                l++;
            else if (nums[ind[l]] + nums[ind[r]] > target)
                r--;
        }
        return {ind[l], ind[r]};
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}