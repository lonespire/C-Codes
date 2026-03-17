#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <climits>
#include <limits>
#define MAX_N 1000
#define MAX_K 10
using namespace std;


struct MyStruct
{
    int Height, Width;
};


int dp[1000][1000] = { 0 };
MyStruct book[105];
bool cmp(MyStruct a, MyStruct b) {
    return a.Height < b.Height;
}



int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> book[i].Height;
        cin >> book[i].Width;
    }
    sort(book + 1, book + n + 1, cmp);
    fill(&dp[0][0], &dp[0][0] + 1000 * 1000, INT_MAX);
    dp[1][1] = 0;
    //dp[0][0]=0;
    for (int i = 1; i <= n; i++)dp[i][1] = 0;
    for (int i = 2; i <= n; i++)
    {
        //dp[i][0] = 0;

        for (int j = 2; j <= i; j++)
        {
            for (int l = j - 1; l < i; l++)
            {
                dp[i][j] = min(dp[i][j], dp[l][j - 1] + abs(book[l].Width - book[i].Width));
            }
        }
    }
    int ans = INT_MAX;
    for (int i = n - k; i <= n; i++)
    {
        ans = min(ans, dp[i][n - k]);
    }
    cout << ans;
    return 0;
}