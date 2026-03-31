#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        ans.reserve(n / 3);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = n - 1;
            while (l < r)
            {

                if (r <= l)
                    break;
                if (nums[i] + nums[l] + nums[r] <= 0)
                {
                    if (nums[i] + nums[l] + nums[r] == 0)
                        ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (l != i + 1 && l != n - 1 && nums[l] == nums[l - 1])
                        l++;
                }
                else
                {
                    r--;
                    while (r != n - 1 && r != i + 1 && nums[r] == nums[r + 1])
                        r--;
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
    vector<int> test = {0, 0, 0, 0};
    vector<vector<int>> ans = s.threeSum(test);
    for (auto &i : ans)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}