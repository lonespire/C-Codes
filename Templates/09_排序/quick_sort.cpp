#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void quick_sort(vector<int> &num, int l, int r)
{
    if (r - l <= 1)
    {
        if (l == r)
            return;
        if (num[l] > num[r])
            swap(num[l], num[r]);
        return;
    }
    int x = l, y = r, z = num[x];
    while (x < y)
    {
        while (x < y && z < num[y])
            y--;
        if (x < y)
            num[x] = num[y];
        while (x < y && num[x] < z)
            x++;
        if (x < y)
            num[y] = num[x];
    }
    num[x] = z;
    quick_sort(num, l, x);
    quick_sort(num, x + 1, r);
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
    quick_sort(num, 0, 19);
    for (auto &i : num)
        cout << i << ' ';
    return 0;
}