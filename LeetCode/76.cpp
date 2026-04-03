// https://leetcode.cn/problems/minimum-window-substring/description/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        string ans;
        int MAX = INT_MAX, n = s.size(), need = 0, ansl = -1, ansr = -1; // need用于判断是否已经初始化窗口满足足够字母
        if (n < t.size())
            return ans;
        vector<int> mp(128, INT_MIN);
        for (auto c : t)
        {
            if (mp[c] == INT_MIN)
            {
                mp[c] = 0;
                need++;
            }
            mp[c]--;
        }
        int l = 0, r = 0;
        while (l <= r && r < n)
        {
            while (need && r < n)
            {
                if (mp[s[r]] != INT_MIN)
                {
                    mp[s[r]]++;
                    if (mp[s[r]] == 0)
                        need--;
                }
                if (need)
                    r++;
            }
            if (!need && r - l + 1 < MAX)
            {
                ansl = l, ansr = r;
                MAX = r - l + 1;
            }
            if (mp[s[l]] == INT_MIN)
            {
                l++;
                continue;
            }
            else
            {
                if (mp[s[l]])
                {
                    mp[s[l]]--;
                    l++;
                }
                else
                {
                    r++;
                    if (mp[s[r]] != INT_MIN)
                        mp[s[r]]++;
                }
                continue;
            }
        }
        if (ansl == -1)
            return ans;
        else
            return s.substr(ansl, ansr - ansl + 1);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution test;
    string s = "ADOBECODEBANC", t = "ABC";
    cout << test.minWindow(s, t);
    return 0;
}