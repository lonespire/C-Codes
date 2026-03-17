#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        int n = s.size();
        vector<string> ans;
        if (n < 4)
            return ans;
        vector<int> cur;
        function<void(int, int)> dfs = [&](int ind, int cnt) -> void
        {
            if (cnt >= 4)
            {
                if (ind <= n - 1 || cur.size() != 4)
                    return;
                string temp = to_string(cur[0]) + "." + to_string(cur[1]) + "." + to_string(cur[2]) + "." + to_string(cur[3]);
                ans.push_back(temp);
            }
            else if (ind > n - 1)
            {
                return;
            }
            for (int i = ind; i < n && i < ind + 3; i++)
            {
                if (s[ind] == '0' && i > ind)
                    return;
                int x = stoi(s.substr(ind, i - ind + 1));
                if (x > 255 || x < 0)
                    continue;
                cur.push_back(x);
                dfs(i + 1, cnt + 1);
                cur.pop_back();
            }
        };
        dfs(0, 0);
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    s.restoreIpAddresses("25525511135");
    return 0;
}