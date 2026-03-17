#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int n = s.size(), m = p.size();
        vector<int> p_hash(26, 0);
        for (auto i : p)
            p_hash[i - 'a']++;
        int r = -1;
        vector<int> ans, temp(26, 0);
        int l = 0;
        for (int i = 0; i < n; i++)
        {
            if (!p_hash[s[i] - 'a'])
            {
                l = i + 1;
                temp = vector<int>(26, 0);
                continue;
            }
            temp[s[i] - 'a']++;
            if (i - l + 1 > m)
            {
                temp[s[l] - 'a']--;
                l++;
            }
            if (temp == p_hash)
                ans.push_back(l);
        }
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}
