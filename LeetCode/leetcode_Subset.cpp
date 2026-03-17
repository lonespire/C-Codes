#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int n;
    vector<int> temp;
    vector<vector<int>> ans;
    void dfs(int ind, vector<int> &nums)
    {
        ans.push_back(temp);
        for (int i = ind + 1; i < n; i++)
        {
            temp.push_back(nums[i]);
            dfs(i, nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        n = nums.size();
        dfs(-1, nums); // todo
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}