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
    deque<int> num;
    void getlist(ListNode *i)
    {
        if (!i)
            return;
        num.push_back(i->val);
        getlist(i->next);
    }
    bool isPalindrome(ListNode *head)
    {
        getlist(head);
        int n = num.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            if (num[l] != num[r])
                return 0;
            l++;
            r--;
        }
        return 1;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}