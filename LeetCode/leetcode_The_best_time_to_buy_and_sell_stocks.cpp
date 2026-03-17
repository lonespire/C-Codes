#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int MIN = prices.front(), ans = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            ans = max(ans, prices[i] - MIN);
            MIN = min(MIN, prices[i]);
        }
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    return 0;
}