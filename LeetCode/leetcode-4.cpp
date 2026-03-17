#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = m, leftmax, rightmin = 0;
        while (l <= r)
        {
            int i = (l + r) / 2;
            int j = (m + n + 1) / 2 - i;
            int nums1_i_1 = i > 0 ? nums1[i - 1] : INT_MIN;
            int nums1_i = i < m ? nums1[i] : INT_MAX;
            int nums2_j_1 = j > 0 ? nums2[j - 1] : INT_MIN;
            int nums2_j = j < n ? nums2[j] : INT_MAX;
            if (nums1_i_1 <= nums2_j && nums2_j_1 <= nums1_i)
            {
                leftmax = max(nums1_i_1, nums2_j_1);
                rightmin = min(nums2_j, nums1_i);
                break;
            }
            else if (nums1_i_1 <= nums2_j)
            {
                l = i + 1;
            }
            else
            {
                r = i - 1;
            }
        }
        return (m + n) % 2 == 0 ? (leftmax + rightmin) / 2.0 : leftmax;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s();

    return 0;
}