#include <bits/stdc++.h>
#define MOD 9973
#define BASE 131
using namespace std;
typedef long long ll;
int Fast_pow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b % 2 == 1)
            ans *= a;
        ans %= MOD;
        b = (b >> 1);
        a *= a;
        a %= MOD;
    }
    return ans;
}
int hash_func(string &s)
{
    int h = 0, kbase = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        h = (h + s[i] * kbase) % MOD;
        kbase = kbase * BASE % MOD;
    }
    return h;
}
bool match(string &s, string &t, int i)
{
    for (int j = 0; j < t.size(); j++)
    {
        if (s[j + i] != t[j])
            return 0;
    }
    return 1;
}
int RabinKarp(string &s, string &t)
{
    int thash = hash_func(t), nbase = Fast_pow(BASE, t.size()), h = 0;
    for (int i = 0; i < s.size(); i++)
    {
        h = h * BASE + s[i];
        h %= MOD;
        if (i >= t.size())
            h = (h - s[i - t.size()] * nbase % MOD + MOD) % MOD;
        if (i + 1 < t.size())
            continue;
        if (h != thash)
            continue;
        if (match(s, t, i - t.size() + 1))
            return i - t.size() + 1;
    }
    return -1;
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    cout << RabinKarp(a, b);
    return 0;
}