#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution
{
public:
    int totalNQueens(int n)
    {
        int ans=0;
        unordered_map<int, int> mp;
        for (int i = 0; i <= n; i++)
            mp[1 << i] = i;
        function<void(int, int, int, int)> dfs = [&](int ind, int T1, int Tl, int Tr) -> void // Tl,Tr分别表示正斜边和反斜边
        {
            if (ind == n)
            {
                ans++;
                return;
            }
            for (int t = T1; t; t -= (t & -t))
            {
                int x = mp[t & -t];
                if ((Tl & (1 << (ind + x))) && (Tr & (1 << (ind + n - x - 1))))
                {
                    dfs(ind + 1, T1 ^ (1 << x), Tl ^ (1 << (ind + x)), Tr ^ (1 << (ind + n - x - 1)));
                }
            }
        };
        dfs(0, (1 << n) - 1, (1 << (2 * n - 1)) - 1, (1 << (2 * n - 1)) - 1);
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}