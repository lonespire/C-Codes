#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size(), ans = 0;
        deque<int> d;
        for (int i = 0; i < n; i++)
        {
            while (!d.empty() && height[d.back()] < height[i])
            {
                int temp = height[d.back()];
                d.pop_back();
                if (d.empty())
                    break;
                ans += (min(height[d.back()], height[i]) - temp) * (i - d.back() - 1); // todo
            }
            d.push_back(i);
        }
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}