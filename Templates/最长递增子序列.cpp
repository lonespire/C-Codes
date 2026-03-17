#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        deque<int> d = {INT_MIN};
        for (auto &i : nums)
        {
            if (i > d.back())
                d.push_back(i);
            else
            {
                d[lower_bound(d.begin(), d.end(), i) - d.begin()] = i;
            }
        }
        d.pop_front();
        return d.size();
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}