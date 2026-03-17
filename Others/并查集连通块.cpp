#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Union_find
{
public:
    vector<int> fa, son;
    Union_find(int n) : fa(n + 1), son(n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            son[i] = 1;
            fa[i] = i;
        }
    }
    void merge(int a, int b)
    {
        int aa = find(a), bb = find(b);
        if (aa == bb)
            return;
        fa[aa] = bb;
        son[bb] += son[aa];
    }
    int find(int x)
    {
        if (fa[x] == x)
            return x;
        return fa[x] = find(fa[x]);
    }
};

int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    unordered_map<int, int> xixi;
    int n, m;
    cin >> n >> m;
    Union_find u(n);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        u.merge(a, b);
    }
    int MAX = 0;
    // for (int i = 1; i <= m; i++)
    // {
    //     cout << u.son[i] << " ";
    // }
    for (int i = 1; i <= n; i++)
    {
        if (u.fa[i] == i)
            MAX += u.son[i] - 1;
    }
    cout << m - MAX;
    return 0;
}