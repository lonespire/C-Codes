// https://leetcode.cn/problems/non-overlapping-intervals/description/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             {if(a[1]==b[1])return a[0]<b[0];else return a[1]<b[1]; });
        int end = INT_MIN, ans = 0;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][0] < end)
            {
                ans++;
            }
            else
                end = intervals[i][1];
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    Solution sol;
    cout << sol.eraseOverlapIntervals(intervals) << endl;
    return 0;
}