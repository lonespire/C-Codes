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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode root;
        root.next=head;
        ListNode *cur=&root;
        while (cur)
        {
            if(!cur->next||!cur->next->next) break;
            ListNode *temp=cur->next;
            cur->next=cur->next->next;
            temp->next=cur->next->next;
            cur->next->next=temp;
            cur=cur->next->next;
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