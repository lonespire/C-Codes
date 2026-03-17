#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int n = s.size();
        vector<int> ans;
        unordered_map<char, pair<int, int>> mp;
        for (int i = 0; i < n; i++)
        {
            if (!mp.count(s[i]))
                mp[s[i]] = {i, i};
            else
                mp[s[i]].second = i;
        }
        int i = 0, j = 0;
        while (i < n && j < n)
        {
            j = mp[s[i]].second;
            for (int t = i; t < j; t++)
            {
                j = max(j, mp[s[t]].second);
            }
            ans.push_back(j - i + 1);
            i = j + 1;
        }
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}