// https://leetcode.cn/problems/permutation-in-string/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> cnt(26, 0);
        int need = 0, other = 0, n = s2.size();
        if (s1.size() > n)
            return 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (cnt[s1[i] - 'a'] == 0)
                need++;
            cnt[s1[i] - 'a']--;
            if (cnt[s1[i] - 'a'] == 0)
                need--;
            if (cnt[s2[i] - 'a'] == 0)
                need++;
            cnt[s2[i] - 'a']++;
            if (cnt[s2[i] - 'a'] == 0)
                need--;
        }
        int r = s1.size() - 1;
        while (r < n)
        {
            if (need == 0)
                return 1;
            int l = r - s1.size() + 1;
            if (cnt[s2[l] - 'a'] == 0)
                need++;
            cnt[s2[l] - 'a']--;
            if (cnt[s2[l] - 'a'] == 0)
                need--;
            l++;
            r++;
            if (r >= n)
                break;
            if (cnt[s2[r] - 'a'] == 0)
                need++;
            cnt[s2[r] - 'a']++;
            if (cnt[s2[r] - 'a'] == 0)
                need--;
        }
        return 0;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution test;
    string s1 = "ab", s2 = "eidbaooo";
    test.checkInclusion(s1, s2);
    return 0;
}