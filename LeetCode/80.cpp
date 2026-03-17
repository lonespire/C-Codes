#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int cnt = 0, i = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (j != 0 && nums[j - 1] != nums[j])
                cnt = 0;
            if (cnt < 2)
                nums[i++] = nums[j];
            cnt++;
        }
        return i;
    }
};
class Solution1
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int last = INT_MIN, cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != last)
            {
                last = nums[i];
                cnt = 1;
            }
            else if (cnt >= 2)
            {
                nums.erase(nums.begin() + i);
                i--;
                continue;
            }
            else
                cnt++;
        }
        return nums.size();
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}