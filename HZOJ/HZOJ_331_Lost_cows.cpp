#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> c, nums;
int lowbit(int i)
{
    return (i & -i);
}
void add(int i, int x)
{
    if (i > n)
        return; //?
    c[i] += x;
    add(i + lowbit(i), x);
}
int find(int i)
{
    int sum = 0;
    while (i)
    {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}
int binary_search_01(int target)
{
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (find(mid) < target)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    nums.resize(n);
    c.resize(n + 1, 0);
    nums[0] = 0;
    for (int i = 1; i < n; i++)
        cin >> nums[i];
    for (int i = 1; i <= n; i++)
        add(i, 1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int ind = binary_search_01(nums[i] + 1);
        ans[i] = ind;
        add(ind, -1);
    }
    for (auto i : ans)
        cout << i << endl;
    return 0;
}