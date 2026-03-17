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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode root(INT_MIN,head);
        ListNode *cur=&root;
        for(int i=0;i<left-1;i++) cur=cur->next;
        head=cur;
        cur=cur->next;
        for(int i=0;i<(right-left);i++)
            {
                ListNode *temp=head->next;
                head->next=cur->next;
                cur->next=cur->next->next;
                head->next->next=temp;
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