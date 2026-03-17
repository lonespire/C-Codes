#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1;
        for (int k = 0; k <= j; k++)
        {
            if (nums[k] == 0)
            {
                swap(nums[i++], nums[k]);
            }
            else if (nums[k] == 2)
            {
                swap(nums[k--], nums[j--]);
            }
        }
    }
};
class Solution1
{
public:
    void sortColors(vector<int> &nums)
    {
        function<void(int, int)> f = [&](int l, int r) -> void
        {
            if (l == r)
                return;
            else if (r - l == 1)
            {
                if (nums[l] > nums[r])
                    swap(nums[l], nums[r]);
                return;
            }
            f(l, (l + r) / 2);
            f((l + r) / 2 + 1, r);
            vector<int> temp;
            int i = l, j = (l + r) / 2 + 1;
            while (i <= (l + r) / 2 || j <= r)
            {
                if (j > r || i <= (l + r) / 2 && nums[i] < nums[j])
                {
                    temp.push_back(nums[i]);
                    i++;
                }
                else
                {
                    temp.push_back(nums[j]);
                    j++;
                }
            }
            for (int k = l; k <= r; k++)
            {
                nums[k] = temp[k - l];
            }
        };
        f(0, nums.size() - 1);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}