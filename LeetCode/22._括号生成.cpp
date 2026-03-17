#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    void solve(int l, int r, int n, vector<string> &s, string temp)
    {
        if (r == n && l == n)
        {
            s.push_back(temp);
            return;
        }
        if (l < n)
            solve(l + 1, r, n, s, temp + '(');
        if (r < n && l > r)
            solve(l, r + 1, n, s, temp + ')');
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> s;
        solve(0, 0, n, s, "");
        return s;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    Solution a;
    vector<string> ans = a.generateParenthesis(4);
    for (auto i : ans)
        cout << i << endl;
    return 0;
}