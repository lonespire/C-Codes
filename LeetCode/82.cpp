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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode root(INT_MIN, head);
        root.next = head;
        ListNode *cur = head;
        ListNode *last = &root;
        while (cur)
        {
            if (cur->next == nullptr)
                break;
            if (cur->next->val == cur->val)
            {
                while (cur->next && cur->next->val == cur->val)
                {
                    cur->next = cur->next->next;
                }
                last->next = cur->next;
            }
            else
                last = cur;
            cur = last->next;
        }
        return root.next;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}