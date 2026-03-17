#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0, MIN = INT_MAX;
        for (int i = 0; i < n - 2; i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            const int target2 = target - nums[i];
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                if (MIN > abs(target2 - nums[l] - nums[r]))
                {
                    ans=nums[i]+nums[l]+nums[r];
                    MIN=abs(target2 - nums[l] - nums[r]);
                }
                if (nums[l] + nums[r] == target2)
                    return target;
                else if (nums[l] + nums[r] > target2)
                    r--;
                else
                    l++;
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
    vector<int> temp={10,20,30,40,50,60,70,80,90};
    cout<<s.threeSumClosest(temp,1);
    return 0;
}