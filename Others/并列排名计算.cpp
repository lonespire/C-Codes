#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> num(n), ind(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        ind[i] = i;
    }
    sort(ind.begin(), ind.end(), [&num](int a, int b)
         { return num[a] > num[b]; });
    pair<int, int> MAX = {0, 0};
    for (int i = 0; i < n; i++)
    {
        if (num[ind[i]] != MAX.second)
            MAX = {i + 1, num[ind[i]]};
        num[ind[i]] = MAX.first;
    }
    for (int i = 0; i < n; i++)
        cout << num[i] << '\n';

    return 0;
}