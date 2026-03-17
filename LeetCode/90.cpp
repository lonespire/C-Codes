#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> cur;
        cur.reserve(n);
        function<void(int)> dfs = [&](int ind) -> void
        {
            ans.push_back(cur);
            int i = ind + 1;
            while (i < n)
            {
                cur.push_back(nums[i]);
                dfs(i);
                cur.pop_back();
                while (i + 1 < n && (nums[i + 1] == nums[i]))
                    i++;
                i++;
            }
        };
        dfs(-1);
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}