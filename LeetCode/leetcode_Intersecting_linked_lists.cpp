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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode *, int> cnt;
        ListNode *cur = headA;
        while (cur)
        {
            cnt[cur]++;
            cur = cur->next;
        }
        cur = headB;
        while (cur)
        {
            if (cnt[cur])
                return cur;
            cur = cur->next;
        }
        return nullptr;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}