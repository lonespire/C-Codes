#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i <= n; i++)
            mp[1 << i] = i;
        vector<vector<int>> ans;
        vector<int> cur;
        function<void(int, int)> dfs = [&](int T, int cnt) -> void
        {
            if (cnt >= k)
            {
                ans.push_back(cur);
                return;
            }
            for (int t = T; t; t -= (t & -t))
            {
                int i = mp[t & -t];
                cur.push_back(i + 1);
                dfs(((T ^ (1 << i)) >> (i + 1)) << (i + 1), cnt + 1);
                cur.pop_back();
            }
        };
        dfs((1 << n) - 1, 0);
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    s.combine(4, 2);
    return 0;
}