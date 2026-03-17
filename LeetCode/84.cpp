#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int ans = INT_MIN, n = heights.size();
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            while (v.size() && heights[v.back()] >= heights[i])
            {
                int top = v.back();
                v.pop_back();
                ans = max(ans, heights[top] * (i - (v.empty() ? -1 : v.back()) - 1));
            }
            v.push_back(i);
            // if (ans == 12)
            // {
            //     cout << 1;
            // }
        }
        while (v.size())
        {
            int top = v.back();
            v.pop_back();
            ans = max(ans, heights[top] * (n - (v.empty() ? -1 : v.back()) - 1));
        }

        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    vector<int> test = {5, 4, 1, 2};
    s.largestRectangleArea(test);
    return 0;
}