#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{

public:
    struct node
    {
        int sum, suml, sumr, maxs;
    };
    vector<node> tree;
    int ans = INT_MIN;
    void update(int ind)
    {
        tree[ind].sum = tree[ind * 2].sum + tree[ind * 2 + 1].sum;
        tree[ind].suml = max(tree[ind * 2].sum + tree[ind * 2 + 1].suml, tree[ind * 2].suml);
        tree[ind].sumr = max(tree[ind * 2 + 1].sum + tree[ind * 2].sumr, tree[ind * 2 + 1].sumr);
        tree[ind].maxs = max({tree[ind * 2].maxs, tree[ind * 2 + 1].maxs, tree[ind * 2].sumr + tree[ind * 2 + 1].suml});
        ans = max({tree[ind].maxs, tree[ind].suml, tree[ind].sumr});
    }
    void build_tree(int ind, int l, int r, vector<int> &nums)
    {

        if (l == r)
        {
            tree[ind].sum = tree[ind].maxs = tree[ind].suml = tree[ind].sumr = nums[l];
            ans = max(ans, tree[ind].sum);
            return;
        }
        int mid = (l + r) / 2;
        build_tree(ind * 2, l, mid, nums);
        build_tree(ind * 2 + 1, mid + 1, r, nums);
        update(ind);
    }
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        tree.resize(n * 4 + 5);
        build_tree(1, 0, n - 1, nums);
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}