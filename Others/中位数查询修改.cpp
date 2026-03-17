#include <bits/stdc++.h>
using namespace std;
#define int long long
int get_mamu(const multiset<int> &nums)
{
    auto mid = next(nums.begin(), (nums.size() + 1) / 2);
    return distance(nums.begin(), nums.lower_bound(*mid));
}
int32_t main()
{
    ::ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        multiset<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }
        while (q--)
        {
            int p, v;
            cin >> p >> v;
            s.erase(s.find(a[p - 1]));
            a[p - 1] += v;
            s.insert(a[p - 1]);
            cout << get_mamu(s) << '\n';
        }
        // break; ///////////////////////////
    }
    return 0;
}
/*
1
4 2
4 5 2 3
4 1
4 3
*/