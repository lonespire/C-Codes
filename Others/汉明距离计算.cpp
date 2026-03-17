#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    string a, b;
    cin >> n;
    cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            ans++;
    cout << ans;
    return 0;
}