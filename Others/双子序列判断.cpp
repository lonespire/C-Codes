#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
bool flag = 0;
vector<int> a, b;
unordered_map<int, vector<int>> num;
void dfs(int inda, int indb, int cnt)
{
    if (cnt == 2)
    {
        flag = 1;
        return;
    }
    for (auto &i : num[b[indb]])
    {
        if (inda >= i)
            continue;
        if (indb == m - 1)
        {
            dfs(i, 0, cnt + 1);
        }
        else
            dfs(i, indb + 1, cnt);
    }
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    a.resize(n), b.resize(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        num[a[i]].push_back(i);
    }
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (auto i : num[b[0]])
    {
        dfs(i, 1, 0);
    }
    if (flag)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}