#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    vector<int> bb;
    int temp;
    for (; cin >> temp;)
    {
        bb.push_back(temp);
    }
    deque<int> d = {INT_MAX};
    for (auto &i : bb)
    {
        if (d.back() >= i)
            d.push_back(i);
        else
        {
            d[lower_bound(d.begin(), d.end(), i, greater<int>()) - d.begin()] = i;
        }
    }
    d.pop_front();
    cout << d.size() << '\n';
    d.clear();
    d = {INT_MAX};
    for (auto &i : bb)
    {
        if (d.back() < i)
            d.push_back(i);
        else
        {
            d[lower_bound(d.begin(), d.end(), i) - d.begin()] = i;
        }
    }
    cout << d.size();
    return 0;
}