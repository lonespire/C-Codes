// https://leetcode.cn/problems/task-scheduler/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> cnt(26, 0);
        int MAX_cnt = 0, MAX_count = 0;
        for (int i = 0; i < tasks.size(); i++)
        {
            cnt[tasks[i] - 'A']++;
            MAX_cnt = max(MAX_cnt, cnt[tasks[i] - 'A']);
        }
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] == MAX_cnt)
                MAX_count++;
        }
        if (MAX_cnt + (MAX_cnt - 1) * n <= tasks.size() - MAX_count + 1)
            return tasks.size();
        else
        {
            return MAX_cnt + (MAX_cnt - 1) * n + MAX_count - 1;
        }
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}