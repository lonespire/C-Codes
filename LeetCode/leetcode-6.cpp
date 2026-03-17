#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    string convert(string s, int numRows)
    {
        string ans;
        if (numRows == 1)
            return s;
        int n = s.size();
        for (int i = 0; i < numRows && i < n; i++)
        {
            for (int j = i; j < n; j += numRows * 2 - 2)
            {
                ans += s[j];
                if ( i != numRows - 1 && i != 0 && j + (numRows - i-1) * 2 < n)
                    ans += s[j + (numRows - i-1) * 2];
            }
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}