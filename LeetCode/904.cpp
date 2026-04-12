#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int mp[100001] = {0};
        int cnt = 0, n = fruits.size();
        int l = 0, r = 0;
        while (r < n)
        {
            if (mp[fruits[r]] == 0)
            {
                cnt++;
            }
            mp[fruits[r]]++;
            if (cnt > 2)
            {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0)
                {
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return r - l;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    vector<int> temp = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    s.totalFruit(temp);
    return 0;
}