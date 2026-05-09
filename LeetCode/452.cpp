// https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/description/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        long long ans = 1, end = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > end)
            {
                ans++;
                end = points[i][1];
            }
            else
                continue;
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}