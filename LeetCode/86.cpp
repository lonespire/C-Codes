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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode root(INT_MIN, head);
        ListNode *cur = &root;
        ListNode root2(INT_MIN);
        ListNode *cur2 = &root2;
        while (cur->next)
        {
            if (cur->next->val >= x)
                cur = cur->next;
            else
            {
                cur2->next = cur->next;
                cur2 = cur2->next;
                cur->next = cur->next->next;
                cur2->next->next = nullptr;
            }
        }
        cur2->next = root.next;
        return root2.next;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}