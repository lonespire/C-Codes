#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
    int l, r;
    bool kill;
    Node() : l(0), r(0), kill(0) {}
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, root = 1;
    cin >> n;
    vector<Node> stu(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (b)
        {
            int pre_r = stu[a].r;
            stu[a].r = i;
            stu[pre_r].l = i;
            stu[i].l = a;
            stu[i].r = pre_r;
        }
        else
        {
            int pre_l = stu[a].l;
            if (a == root)
                root = i;
            stu[a].l = i;
            stu[pre_l].r = i;
            stu[i].l = pre_l;
            stu[i].r = a;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        if (stu[x].kill)
            continue;
        stu[x].kill = 1;
        stu[stu[x].r].l = stu[x].l;
        stu[stu[x].l].r = stu[x].r;
    }
    while (root)
    {
        cout << root << " ";
        root = stu[root].r;
    }

    return 0;
}