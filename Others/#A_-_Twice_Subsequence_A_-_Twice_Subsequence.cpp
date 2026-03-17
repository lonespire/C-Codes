#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
using namespace std;
typedef long long ll;

int len[11];
vector<int> s, t;
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    s.resize(n + 1), t.resize(m + 1);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    fill(len, len + 11, m + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> t[i];
        len[t[i]] = m - i;
    }
    int ans = 0;
    for (int i = 0; i + m <= n;)
    {
        int flag = 1;
        for (int j = 0; j < m; j++)
        {
            if (s[i + j] == t[j])
                continue;
            flag = 0;
            break;
        }
        if (flag)
            ans++;
        if (ans == 2)
        {
            cout << "Yes";
            return 0;
        }
        if (flag)
            i++;
        else
            i += len[s[i + m]];
    }
    cout << "No";
    return 0;
}