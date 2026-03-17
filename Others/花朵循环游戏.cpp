#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a, b;
        cin >> a >> b;
        if (n <= a)
        {
            cout << "Sayonara" << endl;
            continue;
        }
        if (n % (a + b) <= a)
            cout << n % (a + b) << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}