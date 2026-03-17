#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, a;
        string s;
        cin >> n >> a >> s;
        multiset<int> v;
        int pre = 1;
        int cnt_1 = 0;
        int temp = 0;
        int temp_1 = 0;
        bool near_0 = 0;
        bool flag = 0;
        for (auto &i : s)
        {
            if (i == '0')
            {
                if (pre == '0')
                {
                    near_0 = 0;
                }
                if (pre == '1')
                {
                    if (near_0&&temp_1 >= a)
                        flag = 1;
                    temp_1 = 0;
                }
                temp++;
            }
            else
            {
                if (pre == '0')
                {
                    if (temp >= a + 1)
                        v.insert(temp);
                    temp = 0;
                    near_0 = 1;
                }
                else
                {
                    temp_1++;
                }
                cnt_1++;
            }
            pre = i;
        }
        if (pre == 0)
            v.insert(temp);
        vector<int> v1(v.begin(), v.end());
        if (!v1.empty())
        {
            cout << cnt_1 + a + 1 << endl;
            continue;
        }
        else if (flag)
        {
            cout << cnt_1 + 1 << endl;
            continue;
        }
        cout << cnt_1 << endl;
    }
    return 0;
}