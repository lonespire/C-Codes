#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    double fast_pow(double x, int n)
    {
        double ans = 1;
        while (n)
        {
            if (n % 2)
            {
                ans *= x;
                n--;
            }
            x *= x;
            n >>= 1;
        }
        return ans;
    }
    double myPow(double x, int n)
    {
        if (x == 1)
            return 1;
        if (n < 0)
        {
            n = -n;
            x = 1.0 / x;
        }
        if (n == 0)
            return 1;
        return fast_pow(x, n);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    cout << s.fast_pow(2, 2);
    return 0;
}