/*
参考例题 HZOJ #72. 练习题2：猜拳
https://oj.haizeix.com/problem/72
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class UnionFind
{
private:
    vector<int> fa, size;

public:
    vector<int> val;
    UnionFind(int n)
    {
        fa.resize(n + 1, 0);
        size.resize(n + 1, 0);
        val.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            fa[i] = i;
            size[i] = 1;
            val[i] = 0;
        }
    }
    int find(int i)
    {
        int root = i;
        vector<int> path;
        while (fa[i] != i)
        {
            path.push_back(i);
            i = fa[i];
        }
        while (fa[root] != root)
        {
            int temp = fa[root];
            fa[root] = i;
            root = temp;
        }
        path.push_back(i);
        for (int i = path.size() - 2; i >= 0; i--)
        {
            val[path[i]] = (val[path[i]] + val[path[i + 1]]) % 3;
        }
        return i;
    }
    // int find(int x)
    // {
    //     if (fa[x] == x)
    //         return x;
    //     int root = find(fa[x]);
    //     val[x] = (val[x] + val[fa[x]]) % 3;
    //     return fa[x] = root;
    // }
    bool merge(int a, int b, int t)
    {
        int aa = find(a), bb = find(b);
        if (aa == bb)
            return false;
        if (size[aa] <= size[bb])
        {
            fa[aa] = bb;
            size[bb] = size[bb] + size[aa];
            val[aa] = (t - val[a] + val[b] + 3) % 3;
        }
        else
        {
            fa[bb] = aa;
            size[aa] = size[bb] + size[aa];
            val[bb] = (-t - val[b] + val[a] + 3) % 3;
        }
        return true;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    UnionFind u(n);
    for (int i = 0, a, b, c; i < m; i++)
    {
        cin >> a >> b >> c;
        if (a == 1)
        {
            u.merge(b, c, 2);
        }
        else
        {
            if (u.find(b) != u.find(c))
                cout << "Unknown" << endl;
            else
            {
                int temp = (u.val[b] - u.val[c] + 3) % 3;
                switch (temp)
                {
                case 0:
                {
                    cout << "Tie" << endl;
                    break;
                }
                case 1:
                {
                    cout << "Loss" << endl;
                    break;
                }
                case 2:
                {
                    cout << "Win" << endl;
                    break;
                }
                default:
                    break;
                }
            }
        }
    }
    return 0;
}