#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        int pre = 0, ans = 0;
        mp[0]++;
        for (int i = 0; i < n; i++)
        {
            pre += nums[i];
            if (mp.count(pre - k))
                ans += mp[pre - k];
            mp[pre]++;
        }
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}