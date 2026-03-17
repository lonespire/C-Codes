#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    unordered_map<char, int> ori;
    // bool if_cont()
    // {
    //     for (auto i : ori)
    //     {
    //         if (!cnt.count(i.first) || cnt[i.first] < i.second)
    //             return 0;
    //     }
    //     return 1;
    // }
    string minWindow(string s, string t)
    {
        int n = s.size(), m = t.size(), ans = INT_MAX, ansi = 0, diff = 0;
        // cout << t << " " << m;
        for (int i = 0; i < m; i++)
        {
            if (!ori.count(t[i]))
                diff++;
            ori[t[i]]++;
        }
        bool flag = 0;
        for (int i = 0, j = 0; i < n && j < n;)
        {
            if (!ori.count(s[i]) && !flag)
            {
                i++;
                continue;
            }
            else if (ori.count(s[i]) && !flag)
            {
                flag = 1;
                j = i;
            }
            if (ori.count(s[j]))
            {
                ori[s[j]]--;
                if (ori[s[j]] == 0)
                    diff--;
            }
            while (!diff)
            {
                if (ans > j - i + 1)
                {
                    ans = j - i + 1;
                    ansi = i;
                }
                i++;
                if (ori.count(s[i - 1]))
                {
                    ori[s[i - 1]]++;
                    if (ori[s[i - 1]] > 0)
                        diff++;
                }
            }
            j++;
        }
        return ans == INT_MAX ? "" : s.substr(ansi, ans);
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    Solution a;
    a.minWindow("ADOBECODEBANC", "ABC");
    // cout << a.minWindow("ADOBECODEBANC", "ABC");
    return 0;
}