#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size(), maxn = 1;
        string ans;
        ans = s.substr(0, 1);
        for (int i = 0; i < n; i++)
        {
            int l = i, r = i;
            while (s[l] == s[r])
            {
                if (maxn < r - l + 1)
                {
                    maxn = r - l + 1;
                    ans = s.substr(l, maxn);
                }
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            int l = i, r = i + 1;
            while (s[l] == s[r])
            {
                if (maxn < r - l + 1)
                {
                    maxn = r - l + 1;
                    ans = s.substr(l, maxn);
                }
            }
        }
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}