#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int l = 0, r = 0, MAX = 0;
        vector<int> cnt(26, 0);
        while (r < n)
        {
            MAX = max(MAX, ++cnt[s[r] - 'A']);
            if (r - l + 1 - MAX > k)
            {
                cnt[s[l] - 'A']--;
                l++;
            }
            r++;
        }
        return r - l; // 此时r刚好多加了一个1
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution test;
    string s = "ABBB";
    test.characterReplacement(s, 4);
    return 0;
}