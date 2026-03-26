// https://oj.haizeix.com/problem/322
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
class Union
{
public:
    unordered_map<int, int> fa;
    int find(int i)
    {
        if (!fa.count(i))
        {
            fa[i] = i;
            return i;
        }
        int root = i;
        vector<int> v;
        v.push_back(i);
        while (fa[root] != root)
        {
            root = fa[root];
            v.push_back(root);
        }
        while (fa[i] != i)
        {
            int temp = fa[i];
            fa[i] = root;
            i = temp;
        }
        return root;
    }
    bool merge(int a, int b)
    {
        if (!fa.count(a))
            fa[a] = a;
        if (!fa.count(b))
            fa[b] = b;
        int aa = find(a), bb = find(b);
        if (aa == bb)
            return false;
        fa[aa] = bb;
        return true;
    }
};
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        Union u;
        bool flag = 0;
        vector<pair<int, int>> question;
        question.reserve(x);
        while (x--)
        {
            int a, b, op;
            cin >> a >> b >> op;
            if (!op)
                question.push_back({a, b});
            else
            {
                u.merge(a, b);
            }
        }
        for (auto &i : question)
        {
            if (u.find(i.first) == u.find(i.second))
                flag = 1;
        }
        if (flag)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}