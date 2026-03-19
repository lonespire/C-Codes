#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> getnext(string &t)
{
    int m = t.size();
    vector<int> next(m);
    next[0] = -1;
    int j = -1;
    for (int i = 0; i < m; i++)
    {
        while (j != -1 && t[j + 1] != t[i])
            j = next[j];
        if (t[j + 1] == t[i])
            j++;
        next[i] = j;
    }
    return next;
}
int kmp(string &s, string &t)
{
    int n = s.size(), m = t.size();
    vector<int> next = getnext(t);
    int j = -1;
    for (int i = 0; s[i]; i++)
    {
        while (j != -1 && s[i] != t[j + 1])
            j = next[j];
        if (s[i] == t[j + 1])
            j++;
        if (j == m - 1)
            return i - m + 1;
    }
    return -1;
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    cout << kmp(a, b);
    return 0;
}