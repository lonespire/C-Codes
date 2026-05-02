// https://leetcode.cn/problems/jump-game/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return true;
        int far = 0;
        for (int i = 0; i <= far && i < n; i++)
        {
            if (i + nums[i] > far)
            {
                if (i + nums[i] >= n - 1)
                    return true;
                far = i + nums[i];
            }
        }
        return false;
    }
};
class Solution1
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return true;
        for (int i = 0; i < n;)
        {
            int far = i;
            int ii = i;
            for (int j = i + 1; j <= i + nums[i]; j++)
            {
                if (j + nums[j] > far)
                {
                    if (j + nums[j] >= n - 1)
                        return true;
                    far = j + nums[j];
                    ii = j;
                }
            }
            if (i == ii)
                return false;
            i = ii;
        }
        return false;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    vector<int> test = {2, 3, 1, 1, 4};
    s.canJump(test);
    return 0;
}