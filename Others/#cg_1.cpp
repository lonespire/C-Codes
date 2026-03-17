#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        s.insert({v[i], i});
    }
    for (auto i : s)
    {
        cout << i.first << " " << i.second << endl;
    }
    unordered_map<int, set<pair<int, int>>::iterator> mp;
    for (auto i = s.begin(); i != s.end(); i++)
    {
        mp[(*i).second] = i;
    }
    for (auto i : mp)
    {
        cout << i.first << " " << (*i.second).first << endl;
    }
    return 0;
}
/*
5
6 142 3 89 5
*/