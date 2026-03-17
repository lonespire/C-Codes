#include <bits/stdc++.h>
using namespace std;
#define int long long
int c(int a)
{
    int ans = 1;
    if (a <= 1)
        return 0;
    for (int i = a; i > a - 2; i--)
        ans *= i;
    return ans / 2;
}
int32_t main()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    while (q--)//5
    {
        string t;
        cin >> t;
        int a;
        cin >> a;
        int temp = 0;
        vector<int> ans;
        for (int i = 0; i < t.size(); i++)
        {
            int j = i + a - 1;
            if (t[i] == s[j])
            {
                temp++;
                // cout << t[i] << " " << s[j] << " " << temp << "**** ";
            }
            else
            {
                if (temp > 0)
                {

                    ans.push_back(temp);
                }
                temp = 0;
            }
        }
        if (temp > 0)
        {

            ans.push_back(temp);
        }
        // cout << ans.size() << endl;
        // for (auto i : ans)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        if (ans.size() == 0)
        {
            cout << 0 << endl;
            continue;
        }
        int ansout = 0;
        for (int i = 0; i < ans.size(); i++)
        {

            ansout += c(ans[i]) + ans[i];
            // cout << c(ans[i]) << "*** ";
        }
        // for (int i = 0; i < ans.size(); i++)
        //     ansout += ans[i];
        cout << ansout << endl;
    }

    return 0;
}