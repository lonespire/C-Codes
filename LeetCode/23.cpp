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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<int> ans;
        for(auto &i:lists)
        {
            while (i)
            {
                ans.push_back(i->val);
                i=i->next;
            }
        }
        sort(ans.begin(),ans.end());
        ListNode *root=new ListNode();
        ListNode *cur =root;
        for(auto &i:ans)
        {
            cur->next= new ListNode(i);
            cur=cur->next;
        }
        return root->next;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}