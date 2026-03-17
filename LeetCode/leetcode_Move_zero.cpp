#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i])
            {
                nums[j] = nums[i];
                j++;
            }
        }
        for (; j < n; j++)
            nums[j] = 0;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}