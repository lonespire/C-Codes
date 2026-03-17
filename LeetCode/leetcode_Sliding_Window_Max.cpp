#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> d;
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (i >= k)
            {
                ans.push_back(nums[d.front()]);
                if (i - d.front() >= k)
                    d.pop_front();
            }
            while (!d.empty() && nums[i] > nums[d.back()])
                d.pop_back();
            d.push_back(i);
        }
        ans.push_back(nums[d.front()]);
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}