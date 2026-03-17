#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
set<int> make_set(int n, int num)
{
    set<int> ans;
    for (int i = 0; i <= n; i++)
    {
        if (i == num)
            continue;
        ans.insert(i);
    }
    return ans;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<vector<int>> out(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        // vector<int> ind(n);
        // for (int i = 0; i < n; i++)
        // {
        //     ind[i] = i;
        // }
        // sort(ind.begin(), ind.end(), [&a](int x, int y)
        //      { return a[x] < a[y]; });
        for (int i = 0; i < n; i++)
        {
            set<int> s = make_set(n, a[i]);
            // int index = ind[i];
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                auto it = s.begin();
                while (*it == a[j])
                    it++;
                out[i][j] = *it;
                s.erase(out[i][j]);
            }
            out[i][i] = *s.begin();
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // if (j != 0)
                //     cout << " ";
                cout << out[i][j]<<" ";
            }
            cout << "\n";
        }
    }
    return 0;
}
/*
5
1 5 5 5 5

0 2 3 4 0
0 4 1 2 3
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0

4
1 2 1 3

3 0 2 4
0 4 3 1
0 3 4 2
0 1 4 2

3
3
1 1 2
5
1 1 3 2 5
4
1 2 1 3
*/