#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
using namespace std;

vector<int> shop;
int n, m;

int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    shop.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> shop[i];
    }
    while (m--)
    {
        int u, v, p;
        cin >> u >> v >> p;
        int MAXN = 0;
        for (int i = u; i <= v; i++)
        {
            MAXN = max(MAXN, shop[i] % p);
        }
        cout << MAXN << '\n';
    }

    return 0;
}