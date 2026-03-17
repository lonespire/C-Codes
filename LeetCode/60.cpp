#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        function<int(int)> jc = [&](int n) -> int
        {
            int ans = 1;
            for (int i = n; i; i--)
            {
                ans *= i;
            }
            return ans;
        };
        string temp, ans;
        for (int i = 1; i <= n; i++)
        {
            temp.append(to_string(i));
        }
        int a = jc(n - 1);
        for (int i = 0; i < n; i++)
        {
            ans.push_back(temp[k / a]);
            temp.erase(temp.begin() + (k / a));
            k %= a;
            if (n - i - 1)
                a /= n - i - 1;
        }
        return ans;
    }
};

class Solution1
{
public:
    string getPermutation(int n, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i <= n; i++)
        {
            mp[1 << i] = i;
        }
        int cnt = 0;
        bool flag = 0;
        vector<int> ans, cur;
        function<void(int)> dfs = [&](int T) -> void
        {
            if (flag)
                return;
            if (!T)
            {
                cnt++;
                if (cnt == k)
                {
                    ans = cur;
                    flag = 1;
                }
                return;
            }
            for (int t = T; t; t -= (t & -t))
            {
                int ind = mp[t & -t];
                cur.push_back(ind + 1);
                dfs(T ^ (1 << ind));
                cur.pop_back();
            }
        };
        dfs((1 << n) - 1);
        string temp;
        for (auto &i : ans)
        {
            temp.append(to_string(i));
        }
        return temp;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    s.getPermutation(3, 3);

    return 0;
}