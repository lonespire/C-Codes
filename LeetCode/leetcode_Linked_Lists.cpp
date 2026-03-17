#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> cnt;
        ListNode *cur = head;
        while (cur)
        {
            if (cnt.count(cur))
                return 1;
            cnt.insert(cur);
            cur = cur->next;
        }
        return 0;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}