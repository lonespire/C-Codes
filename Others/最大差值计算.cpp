#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> num;
        while (n--)
        {
            int temp;
            cin >> temp;
            num.push_back(temp);
        }
        sort(num.begin(), num.end());
        cout << num.back() - num.front() << '\n';
    }

    return 0;
}