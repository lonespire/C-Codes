#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
vector<int> num;
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    num.resize(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    deque<int> d;
    for (int i = 0; i < n; i++)
    {
        if (i - d.front() > m)
            d.pop_front();
        if (d.empty())
            cout << 0 << '\n';
        else
            cout << num[d.front()] << '\n';
        while (!d.empty() && num[d.back()] > num[i])
            d.pop_back();
        d.push_back(i);
    }
    return 0;
}