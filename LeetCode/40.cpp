#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        set<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        function<void(int, int)> dfs = [&](int ind, int sum) -> void
        {
            if (sum == target)
            {
                ans.insert(temp);
                return;
            }
            for (int i = ind; i < candidates.size(); i++)
            {
                while (i != ind && candidates[i] == candidates[i - 1])
                {
                    i++;
                    if (i >= candidates.size())
                        return;
                }

                if (candidates[i] + sum > target)
                    break;
                temp.push_back(candidates[i]);
                dfs(i + 1, sum + candidates[i]);
                temp.pop_back();
            }
            return;
        };
        dfs(0, 0);
        vector<vector<int>> a(ans.begin(), ans.end());
        return a;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    vector<int> a = {2, 5, 2, 1, 2};
    s.combinationSum2(a, 5);
    return 0;
}