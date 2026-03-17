#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        vector<int> dp(2 * n + 5, 0);
        dp[0] = 1;
        int ans = 0;
        for (int i = 0; i < n;)
        {
            pair<int, int> MAX = {0, 0};
            for (int j = i + 1; j < n && j <= i + nums[i]; j++)
                if (nums[j] + j - i >= MAX.second)
                    MAX = {j, nums[j] + j - i};
            if (nums[i] + i >= n - 1)
            {
                ans++;
                return ans;
            }
            i = MAX.first;
            ans++;
        }
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    Solution a;
    vector<int> temp = {1, 2, 1, 1, 1};
    cout << a.jump(temp);
    return 0;
}