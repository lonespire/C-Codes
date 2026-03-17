#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// https://leetcode.cn/problems/group-anagrams/?envType=study-plan-v2&envId=top-100-liked
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> final_ans;
        final_ans.reserve(strs.size());
        auto array_hash = [fn = hash<int>{}](const array<int, 26> &arr) -> size_t
        {
            size_t hash = 0;
            for (int c : arr)
                hash = (hash << 1) ^ c;
            return hash;
        };
        unordered_map<array<int, 26>, vector<string>, decltype(array_hash)> ans(0, array_hash);
        for (auto &str : strs)
        {
            array<int, 26> counts{};
            for (auto c : str)
            {
                counts[c - 'a']++;
            }
            ans[counts].emplace_back(move(str));
        }
        for (auto &i : ans)
            final_ans.emplace_back(move(i.second));
        return final_ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}