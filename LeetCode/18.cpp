#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                // if (nums[j] == 0)
                // {
                //     cout << "yes";
                // }
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                const long long target2 = long(target) - long(nums[i]) - long(nums[j]);
                int k = j + 1, l = n - 1;
                while (k < l)
                {

                    if (nums[k] + nums[l] == target2)
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        l--;
                        k++;
                        while(l<n-1&&nums[l+1]==nums[l]) l--;
                        while(k>j+1&&nums[k-1]==nums[k]) k++;
                    }
                    else if (nums[k] + nums[l] > target2)
                    {
                        l--;
                    }
                    else
                    {
                        k++;
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    s.fourSum(nums, target);
    return 0;
}