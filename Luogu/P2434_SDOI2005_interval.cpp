#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> section(n);
    for (auto &i : section)
    {
        int a, b;
        cin >> a >> b;
        i = {a, b};
    }
    sort(section.begin(), section.end(), [&section](pair<int, int> a, pair<int, int> b)
         { return a.first < b.first; });
    vector<pair<int, int>> ans;
    pair<int, int> temp = {section[0].first, section[0].second};
    for (auto &i : section)
    {
        if (i.first > temp.second)
        {
            ans.push_back(temp);
            temp = {i.first, i.second};
        }
        else
        {
            temp = {temp.first, max(i.second, temp.second)};
        }
    }
    ans.push_back(temp);
    for (auto &i : ans)
        cout << i.first << ' ' << i.second << '\n';
    return 0;
}