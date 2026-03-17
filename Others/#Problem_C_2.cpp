#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, H;
        cin >> n >> H;
        vector<int> h(n);
        vector<double> s(n);
        vector<int> ind(n);
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
            s[i] = 2.0 * sqrt(H - h[i]) * sqrt(h[i]);
            ind[i] = i;
        }
        sort(ind.begin(), ind.end(), [&](int i, int j)
             { return s[i] < s[j]; });
        for (int i = 0; i < n; i++)
            cout << ind[i] + 1 << " ";
        cout << endl;
    }

    return 0;
}