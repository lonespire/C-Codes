#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> pos(128, -1);
        int n = s.size(), l = 0, r = 0, MAX = 0;
        if (n == 0)
            return MAX;
        for (; r < n; r++)
        {
            char c = s[r];
            if (pos[c] >= l)
                l = pos[c] + 1;
            pos[c] = r;
            MAX = max(r - l + 1, MAX);
        }
        return MAX;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}