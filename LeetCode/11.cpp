// https://leetcode.cn/problems/container-with-most-water/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int ans = INT_MIN;
        int l = 0, r = height.size() - 1;
        while (l < r)
        {
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if (height[l] <= height[r])
                l++;
            else
                r--;
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