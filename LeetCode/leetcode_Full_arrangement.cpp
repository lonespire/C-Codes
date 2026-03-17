#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<vector<int>> ans;
    unordered_map<int, int> bitmask;
    void dfs(int t1, vector<int> temp, vector<int> &nums)
    {
        if (!t1)
        {
            ans.push_back(temp);
        }
        for (int t = t1; t; t -= (t & -t))
        {
            int i = bitmask[(t & -t)];
            temp.push_back(nums[i]);
            dfs(t1 ^ (1 << i), temp, nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i <= n + 1; i++)
            bitmask[(1 << i)] = i;
        dfs((1 << n) - 1, {}, nums);
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    Solution a;
    vector<int> temp = {1, 2, 3};
    vector<vector<int>> ans = a.permute(temp);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}