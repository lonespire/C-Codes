#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> num(n + 1);
    num[0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        if (num[i] > num[i - 1])
            ans += num[i] - num[i - 1];
    }
    cout << ans;
    return 0;
}