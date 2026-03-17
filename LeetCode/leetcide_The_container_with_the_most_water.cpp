#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1, ans = 0;
        while (l < r)
        {
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if (height[r] >= height[l])
                l++;
            else
                r--;
        }
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    Solution a;
    vector<int> b = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << a.maxArea(b);
    return 0;
}