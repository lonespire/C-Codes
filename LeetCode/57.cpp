#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    // 利用两个二分查找解决
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int n = intervals.size();
        if (!n)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<vector<int>> ans;
        int start = newInterval[0], end = newInterval[1];
        int ind = 0;
        while (ind < n && intervals[ind][1] < start)
        {
            ans.push_back(intervals[ind]);
        }
        bool once = 1;
        while (ind < n && intervals[ind][0] <= end)
        {
            if (once)
            {
                start = min(start, intervals[ind][0]);
                once = 0;
            }
            end = max(intervals[ind][1], end);
            ind++;
        }
        ans.push_back({start, end});
        while (ind < n)
        {
            ans.push_back(intervals[ind]);
        }
        return ans;
    }
};
class Solution1
{
public:
    // 利用两个二分查找解决
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int n = intervals.size();
        if (!n)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        if (n == 1)
        {
            if (intervals[0][0] > newInterval[1])
            {
                intervals.insert(intervals.begin(), newInterval);
                return intervals;
            }
            else if (intervals[0][1] < newInterval[0])
            {
                intervals.push_back(newInterval);
                return intervals;
            }
            else
            {
                intervals[0][0] = min(intervals[0][0], newInterval[0]);
                intervals[0][1] = max(intervals[0][1], newInterval[1]);
                return intervals;
            }
        }
        int l = 0, r = n - 1;
        while (l < r) // 找到最后一个start小于目标start的ind
        {
            int mid = (l + r + 1) / 2;
            if (intervals[mid][0] <= newInterval[0])
                l = mid;
            else
                r = mid - 1;
        }
        int ans1 = l;
        l = 0, r = n - 1;
        while (l < r) // 找到第一个end大于目标end的ind
        {
            int mid = (l + r) / 2;
            if (intervals[mid][1] < newInterval[1])
                l = mid + 1;
            else
                r = mid;
        }
        int ans2 = l;
        if (ans2 == 0)
        {
            if (intervals[0][0] > newInterval[1])
            {
                intervals.insert(intervals.begin(), newInterval);
                // return intervals;
            }
            else
            {
                intervals[0][0] = newInterval[0];
                return intervals;
            }
        }
        else if (ans1 == n - 1)
        {
            if (intervals[n - 1][1] >= newInterval[0])
            {
                intervals[n - 1][1] = newInterval[1];
                return intervals;
            }
            else
            {
                intervals.push_back(newInterval);
                return intervals;
            }
        }
        else
        {
            if (intervals[ans1][1] < newInterval[0])
            {
                intervals[ans1 + 1][0] = min(newInterval[0], intervals[ans1 + 1][0]);
            }
            else
            {
                intervals[ans1][0] = min(newInterval[0], intervals[ans1][0]);
            }
            if (intervals[ans1][0] > newInterval[1])
            {
                intervals[ans1 - 1][1] = max(newInterval[1], intervals[ans1 - 1][1]);
            }
            else
            {
                intervals[ans1][1] = max(newInterval[1], intervals[ans1][1]);
            }
        }
        return intervals;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    std::vector<std::vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> t = {4, 8};
    s.insert(intervals, t);
    return 0;
}