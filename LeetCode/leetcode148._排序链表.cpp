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
    ListNode *sortList(ListNode *head)
    {
        int len = 0;
        ListNode *cur = head;
        vector<int> num;
        while (cur)
        {
            num.push_back(cur->val);
            cur = cur->next;
        }
        sort(num.begin(), num.end());
        cur = head;
        while (cur)
        {
            cur->val = num[len++];
            cur = cur->next;
        }
        return head;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}