#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (auto &i : nums)
        {
            if (i <= 0)
                i = n + 1;
        }
        for (auto &i : nums)
        {
            if (abs(i) <= n)
                nums[abs(i) - 1] = -abs(nums[abs(i) - 1]);
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                return i + 1;
        }
        return n + 1;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    Solution a;
    vector<int> temp = {1, 2, 0};
    cout << a.firstMissingPositive(temp);
    return 0;
}