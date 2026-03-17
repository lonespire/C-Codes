#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution1
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string a = countAndSay(n - 1);
        string ans;
        int cnt = 1;
        for (int i = 0; i < a.size() - 1; i++)
        {
            if (a[i + 1] != a[i])
            {
                ans += to_string(cnt) + a[i];
                cnt = 1;
            }
            else
                cnt++;
        }
        ans += to_string(cnt) + a[a.size() - 1];
        return ans;
    }
};
class Solution
{
public:
    string countAndSay(int n)
    {
        string a = "1";
        for (int j = 1; j < n; j++)
        {
            string ans;
            int cnt = 1;
            for (int i = 0; i < a.size(); i++)
            {
                if (a[i + 1] != a[i] || i + 1 == a.size())
                {
                    ans += to_string(cnt) + a[i];
                    cnt = 1;
                }
                else
                    cnt++;
            }
            a = ans;
        }
        return a;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    s.countAndSay(4);
    return 0;
}