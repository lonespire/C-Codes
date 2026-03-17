#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> b(n);
        b[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
            b[i] = min(a[i], b[i + 1]);
        int ans = 0;
        int Max=INT_MIN,Min=INT_MAX;
        for (int i = 0; i < n; i++)
        {
            b[i] = a[i] - b[i];
            Max=max(Max,b[i]);
            Min=min(Min,b[i]);
        }
        cout<<Max-Min<<endl;
    }
    return 0;
}
/*
3
5
4 2 5 1 3
3
10 8 6
2
7 7
*/