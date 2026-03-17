#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<int> temp;
    vector<vector<int>> ans;
    int n;
    void dfs(int ind, vector<int> &candidates, int sum, int target)
    {
        if (sum > target)
            return;
        if (sum == target)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = ind; i < n; i++)
        {
            temp.push_back(candidates[i]);
            dfs(i, candidates, sum + candidates[i], target);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        n = candidates.size();
        dfs(0, candidates, 0, target);
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}