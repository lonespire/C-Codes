// https://leetcode.cn/problems/find-k-closest-elements/description/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int l = 0, r = arr.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (arr[mid] < x)
                l = mid + 1;
            else
                r = mid;
        }
        int ind = l;
        if (l - 1 >= 0)
        {
            ind = (abs(arr[l] - x) < abs(arr[l - 1] - x)) ? l : (l - 1);
        }
        l = r = ind;
        for (int i = 1; i < k; i++)
            if (l == 0)
                r++;
            else if (r == arr.size() - 1)
                l--;
            else
            {
                if (abs(arr[l - 1] - x) <= abs(arr[r + 1] - x))
                    l--;
                else
                    r++;
            }
        return vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution sol;
    vector<int> arr = {1, 1, 1, 10, 10, 10};
    auto res = sol.findClosestElements(arr, 1, 9);
    for (int v : res)
        cout << v << " ";
    return 0;
}