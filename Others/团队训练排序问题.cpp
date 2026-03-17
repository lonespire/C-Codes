#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
using namespace std;
typedef long long ll;

int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int m;
    cin >> m;
    while (m--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> num(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> num[i];
        sort(num.begin() + 1, num.end());
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (num[i] * (n - i + 1) >= x)
            {
                ans = (n - i + 1);
                // cout << num[i] << " ";
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}