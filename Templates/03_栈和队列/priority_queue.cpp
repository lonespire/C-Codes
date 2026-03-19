#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct PriorityQueue
{
    vector<int> data;
    int size, n;
    PriorityQueue(int size) : data(size + 1), size(size), n(0) {}
    PriorityQueue(vector<int> a) : data(a.size()), size(a.size() + 1), n(a.size() - 1) { data = a; }
};
void clearPQ(PriorityQueue &p)
{
    if (p.data.empty())
        return;
    p.data.clear();
    return;
}
void up_update(PriorityQueue &p, int i)
{
    if (i == 1)
        return;
    if (p.data[i] > p.data[i / 2])
    {
        swap(p.data[i], p.data[i / 2]);
        up_update(p, i / 2);
    }
}
void down_update(PriorityQueue &p, int i)
{
    if (2 * i > p.data.size() - 1)
        return;
    int ind = i;
    if (p.data[ind * 2] > p.data[ind])
        ind *= 2;
    if (ind + 1 <= p.data.size() - 1 && p.data[ind + 1] > p.data[ind])
        ind++;
    if (i == ind)
        return;
    swap(p.data[i], p.data[ind]);
    down_update(p, ind);
}
bool push(PriorityQueue &p, int x)
{
    if (p.n + 1 == p.size)
        return 0;
    p.n++;
    p.data[p.n] = x;
    up_update(p, p.n);
    return 1;
}
bool pop(PriorityQueue &p)
{
    if (p.data.empty())
        return 0;
    p.data[1] = p.data[p.n];
    p.n--;
    down_update(p, 1);
    return 1;
}
void output(PriorityQueue p)
{
    for (int i = 1; i <= p.n; i++)
        cout << p.data[i] << " ";
    cout << '\n';
}
// PriorityQueue prioQbuild_pq(vector<int> a)
// {
//     PriorityQueue ans(a);
//     for (int i = (a.size() - 1) / 2; i >= 1; i--)
//         down_update(ans, i);
//     return ans;
// }
int main()
{
    // ::ios::sync_with_stdio(false), cin.tie(nullptr);
    // int op, x;
    PriorityQueue p(100);
    int n;
    cin >> n;
    vector<int> test(n);
    for (auto &i : test)
        i = rand() % 100000;
    PriorityQueue ans(test);
    for (auto i : ans.data)
        cout << i << " ";
    cout << endl;
    for (int i = (test.size() - 1) / 2; i >= 1; i--)
        down_update(ans, i);
    // while (cin >> op)
    // {
    //     if (op == 1)
    //     {
    //         cin >> x;
    //         printf("insert%din\n", x);
    //         push(p, x);
    //         output(p);
    //     }
    //     else
    //     {
    //         printf("pop%din top\n", p.data[1]);
    //         pop(p);
    //         output(p);
    //     }
    // }
    output(ans);
    for (auto i : test)
        cout << i << " ";
    return 0;
}