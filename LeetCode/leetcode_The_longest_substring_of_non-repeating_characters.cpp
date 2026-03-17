#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (!n)
            return 0;
        unordered_set<char> if_rep;
        int r = -1, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i)
                if_rep.erase(s[i - 1]);
            while (r < n - 1 && !if_rep.count(s[r + 1]))
            {
                r++;
                if_rep.insert(s[r]);
            }
            ans = max(ans, r - i + 1);
        }
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    Solution a;
    cout << a.lengthOfLongestSubstring("pwwkew");
    return 0;
}