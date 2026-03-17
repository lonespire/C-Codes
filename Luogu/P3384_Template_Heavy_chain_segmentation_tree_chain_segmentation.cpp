#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class segment_tree
{
public:
    struct node
    {
        ll tag, sum;
        node() : tag(0), sum(0) {}
    };
    vector<int> nums;
    vector<node> tree;
    segment_tree(int n) : n(n), tree(4 * n + 5) {}
    int n;
    void update(int ind)
    {
        tree[ind].sum = tree[ind * 2].sum + tree[ind * 2 + 1].sum;
    }
    void down(int ind, int l, int r)
    {
        if (!tree[ind].tag)
            return;
        int mid = (r - l) / 2;
        tree[ind * 2].tag += tree[ind].tag;
        tree[ind * 2 + 1].tag += tree[ind].tag;
        tree[ind * 2].sum += tree[ind].tag * (mid - l + 1);
        tree[ind * 2 + 1].sum += tree[ind].tag * (r - mid);
        tree[ind].tag = 0;
    }
    void build_tree(int ind, int l, int r, vector<int> nums)
    {
        if (l == r)
        {
            tree[ind].sum = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build_tree(ind * 2, l, mid, nums);
        build_tree(ind * 2 + 1, mid + 1, r, nums);
        update(ind);
    }
    void modify(int ind, int l, int r, int x, int y, int c)
    {
        if (x <= l && r <= y)
        {
            tree[ind].tag += c;
            tree[ind].sum += c * (r - l + 1);
            return;
        }
        int mid = (r + l) / 2;
        down(ind, l, r);
        if (mid >= x)
            modify(ind * 2, l, mid, x, y, c);
        if (mid < y)
            modify(ind * 2 + 1, mid + 1, r, x, y, c);
        update(ind);
    }
    ll query(int ind, int l, int r, int x, int y)
    {
        if (x <= l && r <= y)
        {
            return tree[ind].sum;
        }
        int mid = (l + r) / 2;
        down(ind, l, r);
        ll sum = 0;
        if (x <= mid)
            sum += query(ind * 2, l, mid, x, y);
        if (mid < y)
            sum += query(ind * 2 + 1, mid + 1, r, x, y);
        return sum;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    return 0;
}