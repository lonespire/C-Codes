#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
int gcb(int a, int b)
{
    if (!b)
        return a;
    return gcb(b, a % b);
}
int32_t main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "1/0";
        return 0;
    }
    set<int> deq;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        deq.insert(temp);
    }
    n = deq.size();
    vector<int> nums(deq.begin(), deq.end());
    pair<int, int> MAX = {INT_MAX, 0};
    for (int i = 0; i < n - 1; i++)
    {
        if (MAX.first > nums[i + 1] / nums[i])
            MAX = {nums[i + 1] / nums[i], i};
    }
    cout << nums[MAX.second + 1] / gcb(nums[MAX.second + 1], nums[MAX.second]) << '/' << nums[MAX.second] / gcb(nums[MAX.second + 1], nums[MAX.second]);
    return 0;
}