#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    string intToRoman(int num)
    {
        unordered_map<int, char> int_to_Roman = {{1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}};
        string s = to_string(num), ans;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '4' || s[i] == '9')
            {
                if (s[i] == '4')
                {
                    ans += int_to_Roman[pow(10, s.size() - 1 - i)];
                    ans += int_to_Roman[(5) * pow(10, s.size() - 1 - i)];
                }
                else
                {
                    ans += int_to_Roman[pow(10, s.size() - 1 - i)];
                    ans += int_to_Roman[(10) * pow(10, s.size() - 1 - i)];
                }
                continue;
            }
            if (s[i] > '4')
            {
                ans += int_to_Roman[5 * pow(10, s.size() - 1 - i)];
                s[i] -= 5;
            }
            if (s[i] == '0')
                continue;
            while (s[i] != '0')
            {
                ans += int_to_Roman[pow(10, s.size() - 1 - i)];
                s[i]--;
            }
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int test;
    cin >> test;
    Solution s;
    cout << s.intToRoman(test);
    return 0;
}