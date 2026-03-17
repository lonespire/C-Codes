#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        pair<int, int> temp = {intervals[0][0], intervals[0][1]};
        for (auto i : intervals)
        {
            if (i[0] <= temp.second)
            {
                temp = {temp.first, max(temp.second, i[1])};
                continue;
            }
            else
            {
                ans.push_back({temp.first, temp.second});
                temp = {i[0], i[1]};
            }
        }
        ans.push_back({temp.first, temp.second});
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}