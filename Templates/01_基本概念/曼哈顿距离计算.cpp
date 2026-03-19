#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
using namespace std;

int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << abs(a - c) + abs(b - d);
    return 0;
}