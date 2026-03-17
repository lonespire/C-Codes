#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *cur1 = list1, *cur2 = list2;
        ListNode *ans;
        if (!cur1)
        {
            return cur2;
        }
        else if (!cur2)
            return cur1;
        if (cur1->val > cur2->val)
        {
            ans = new ListNode(cur2->val);
            cur2 = cur2->next;
        }
        else
        {
            ans = new ListNode(cur1->val);
            cur1 = cur1->next;
        }
        ListNode *anshead = ans;
        while (cur1 && cur2)
        {
            if (cur1->val > cur2->val)
            {
                ans->next = new ListNode(cur2->val);
                cur2 = cur2->next;
                ans = ans->next;
            }
            else
            {
                ans->next = new ListNode(cur1->val);
                cur1 = cur1->next;
                ans = ans->next;
            }
        }
        if (!cur1 && cur2)
        {
            ans->next = cur2;
        }
        else if (!cur2 && cur1)
            ans->next = cur1;
        return anshead;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}