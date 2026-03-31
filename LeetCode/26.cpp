#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (!n)
            return 0;
        int low = 0, fast = 1;
        for (; fast < n && low < n;)
        {
            while (fast < n && nums[fast] == nums[fast - 1])
            {
                fast++;
            }
            if (fast >= n)
                break;
            nums[++low] = nums[fast];
            fast++;
        }
        return low + 1;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}