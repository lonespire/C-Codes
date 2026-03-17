#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
void get_cnt(vector<int> &cnt, int n, vector<int> &head, int i)
{
    int j = 0;
    while (n)
    {
        if (n % 2 == 1)
            cnt[j]++;
        if (n / 2 == 0)
            head[i] = j;
        n /= 2;
        j++;
    }
    return;
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        bool flag = 0;
        vector<int> cnt(65, 0); // 记录位数上1的数量
        cin >> n;
        vector<int> v(n), head(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            get_cnt(cnt, v[i], head, i);
        }
        for (int i = 0; i < n; i++)
        {
            if (cnt[head[i]] > 1)
            {
                cout << "NO" << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << "YES" << endl;
        // for (auto i : cnt)
        //     cout << i << " ";
        // cout << endl;
        // for (auto i : head)
        //     cout << i << " ";
        // cout << endl;
    }

    return 0;
}
/*
3
2
3 5
4
1 2 4 8
3
1 2 3
*/