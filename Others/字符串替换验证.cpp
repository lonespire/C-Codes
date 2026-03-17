#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<int, int> get_zero_location(string a)
{
    pair<int, int> ans = {0, 0};
    for (int i = 0; a[i]; i++)
    {
        if (a[i] != '0')
            continue;
        if (i & 1)
            ans.first++;
        else
            ans.second++;
    }
    return ans;
}
bool is_crack(string a, pair<int, int> zero)
{
    for (int i = 0; a[i]; i++)
    {
        if (a[i] == '0')
            continue;
        if (!i & 1)
        {
            if (!zero.first)
                return 0;
            else
                zero.first--;
        }
        else
        {
            if (!zero.second)
                return 0;
            else
                zero.second--;
        }
    }
    return 1;
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;
        pair<int, int> zero = get_zero_location(b);
        // cout << zero.first << " " << zero.second << "\n";
        if (is_crack(a, zero))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}