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
        for (int i = 0; i < n;)
        {
            pair<int, int> MAX = {-1, -1};
            for (int j = i + 1; j < n && j <= i + nums[i]; j++)
            {
                if (MAX.second < j - i + nums[j])
                {
                    MAX = {j, j - i + nums[j]};
                }
            }
            if (MAX.first == i)
                return 0;
            i = MAX.first;
            if (i + nums[i] >= n - 1)
                return 1;
        }
        return 0;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    Solution a;
    vector<int> test = {3, 2, 1, 0, 4};
    cout << a.canJump(test);
    return 0;
}