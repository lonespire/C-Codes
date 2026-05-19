// https://leetcode.cn/problems/find-peak-element/description/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] < nums[mid + 1])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}