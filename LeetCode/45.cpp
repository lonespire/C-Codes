
// https://leetcode.cn/problems/jump-game-ii/description/
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
        int cnt = 0, bord = 0, far = 0;
        for (int i = 0; i <= far && i < n; i++)
        {
            if (i > bord)
            {
                cnt++;
                bord = far;
            }
            if (far < nums[i] + i)
            {
                if (i + nums[i] >= n - 1)
                    return cnt + 1;
                far = nums[i] + i;
            }
        }
        return 0;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    vector<int> test = {2, 3, 1, 1, 4};
    s.jump(test);
    return 0;
}