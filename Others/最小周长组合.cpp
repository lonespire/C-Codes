#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    ll a;
    cin >> a;
    ll l = (a + 1) / 2, w = a + !(a % 2);
    // cout << l * w << endl;
    cout << 2 * (l + w) << endl;
    return 0;
}