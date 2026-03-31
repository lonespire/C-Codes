#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int trap(vector<int> &height) // 采取单调递减队列，我理解为不断更新并储存上一个最大边
    {
        deque<int> q;
        int ans = 0, n = height.size();
        for (int i = 0; i < n; i++)
        {
            int min_height = 0;
            while (!q.empty() && height[q.back()] < height[i])
            {
                min_height = max(min_height, height[q.back()]);
                q.pop_back();
                if (!q.empty())
                    ans += (min(height[q.back()], height[i]) - min_height) * (i - q.back() - 1);
            }
            q.push_back(i);
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution t;
    vector<int> test = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << t.trap(test);
    return 0;
}