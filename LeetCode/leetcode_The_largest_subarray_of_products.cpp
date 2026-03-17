#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int ans = nums[0], MAXN = nums[0], minus = nums[0];
        for (int i = 1; i < n; i++)
        {
            int temp_MAXN = max({MAXN * nums[i], nums[i], minus * nums[i]});
            int temp_minus = min({MAXN * nums[i], nums[i], minus * nums[i]});
            ans = max(temp_MAXN, ans);
            MAXN = temp_MAXN;
            minus = temp_minus;
        }
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}