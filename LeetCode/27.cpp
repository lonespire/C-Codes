// https://leetcode.cn/problems/remove-element/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        if (nums.size() == 0)
            return 0;
        int r = nums.size() - 1, l = 0;
        for (int l = 0; l < r;)
        {
            if (nums[r] == val)
            {
                r--;
                continue;
            }
            else if (nums[l] == val)
            {
                swap(nums[r--], nums[l]);
            }
            l++;
        }
        if (nums[r] == val)
            r--;
        return r + 1;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}