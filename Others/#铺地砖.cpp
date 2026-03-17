#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
using namespace std;

int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, a;
    cin >> n >> m >> a;
    int n1 = (n / a), m1 = (m / a);
    if (n % a != 0)
        n1++;
    if (m % a != 0)
        m1++;
    cout << n1 * m1;
    return 0;
}