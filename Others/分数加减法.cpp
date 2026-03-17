#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
using namespace std;

int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    long double n;
    cin >> n;
    cout << fixed << setprecision(2) << (long double)(1 - (long double)1 / (n + 1));
    return 0;
}