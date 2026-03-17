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
#define MAX_N 10005
#define MAX_K 10
using namespace std;


int dp[MAX_N][MAX_N][2];
int main()
{
    int n, m;
    int ans = 0;
    cin >> n >> m;
    fill(&dp[0][0][0], &dp[0][0][0] + MAX_N * MAX_N, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1,a; j <= m; j++)
        {
            cin >> a;
            dp[i][j][1 - a] = 0;
            dp[i][j][a] = min(dp[i - 1][j][1 - a], min(dp[i][j - 1][1 - a], dp[i - 1][j - 1][a]))+1;
            ans = max(ans, dp[i][j][a]);
        }
    }
    
    cout << ans;
    return 0;
}