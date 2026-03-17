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
    pair<int,ListNode*> erase(ListNode *root,int n)
    {
        if(!root) return {1,root};
        int num;
        pair<int,ListNode*> temp={0,root->next};
        temp=erase(root->next,n);
        if(temp.first==n+1)
        {
            root->next=temp.second->next;
        }
        return {temp.first+1,root};

    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        pair<int,ListNode*> temp=erase(head,n);
        if(temp.first==n) return head->next;
        else return head;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}