#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
#define lowbit(x) (x & -x)
using namespace std;
typedef long long ll;

vector<ll> num, tree1, tree2;
int n, m;
void add(int i, int k)
{
    while (i <= n)
    {
        tree1[i] += k;
        i += lowbit(i);
    }
    return;
}
ll query(int i)
{
    if (i == 0)
        return 0;
    return tree1[i] + query(i - lowbit(i));
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    num.resize(n + 1, 0), tree1.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        add(i, num[i] - num[i - 1]);
    }
    while (m--)
    {
        int o;
        cin >> o;
        if (o == 1)
        {
            int l, r, k, d;
            cin >> l >> r >> k >> d;
            add(l, k);
            if (r > l + 1)
            {
                for (int i = l + 1; i <= r; i++)
                    add(i, d);
                add(r + 1, -(k + d * (r - l)));
            }
        }
        else
        {
            int p;
            cin >> p;
            cout << query(p) << "\n";
        }
    }

    return 0;
}