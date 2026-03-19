#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void merge_sort(vector<int> &num, int l, int r)
{
    if (l >= r)
        return;
    // if (!r - l)
    //     return;
    // if (r - l == 1)
    // {
    //     if (num[l] > num[r])
    //         swap(num[l], num[r]);
    //     return;
    // }
    // if (r - l == 2)
    // {
    //     if (num[l] > num[l + 1])
    //         swap(num[l], num[l + 1]);
    //     if (num[l] > num[l + 2])
    //         swap(num[l], num[l + 2]);
    //     if (num[l + 1] > num[l + 2])
    //         swap(num[l + 1], num[l + 2]);
    //     return;
    // }
    int mid = (r + l) / 2;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    vector<int> temp;
    int p1 = l, p2 = mid + 1;
    while (p1 <= mid || p2 <= r)
    {
        if (p1 > mid)
        {
            temp.push_back(num[p2]);
            p2++;
            continue;
        }
        if (p2 > r)
        {
            temp.push_back(num[p1]);
            p1++;
            continue;
        }
        if (num[p1] <= num[p2])
        {
            temp.push_back(num[p1]);
            p1++;
            continue;
        }
        else
        {
            temp.push_back(num[p2]);
            p2++;
            continue;
        }
    }
    for (int i = l; i <= r; i++)
        num[i] = temp[i - l];
}
vector<int> get_nums(int n)
{
    vector<int> num(n);
    srand(time(nullptr));
    for (int i = 0; i < n; i++)
        num[i] = rand() % 1000;
    return num;
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    vector<int> num = get_nums(20);
    merge_sort(num, 0, 19);
    for (auto &i : num)
        cout << i << ' ';
    return 0;
}