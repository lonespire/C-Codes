#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;
    long long minimumCost(string s)
    {
        ll ans = 0;
        for (int i = 0; i < s.size() - 1; i++)
            if (s[i] != s[i + 1])
                ans += min((ll)i + 1, (ll)s.size() - i - 1);
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}