#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), 1);
        vector<vector<int>> ans;
        vector<int> cur;
        function<void()> dfs = [&]() -> void
        {
            if (cur.size() == nums.size())
            {
                ans.push_back(cur);
                return;
            }
            for (int i = 0; i < nums.size(); i++)
            {
                if (!used[i])
                    continue;
                cur.push_back(nums[i]);
                used[i] = 0;
                dfs();
                used[i] = 1;
                cur.pop_back();
                while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                {
                    i++;
                }
            }
        };
        dfs();
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}