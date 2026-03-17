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
#define MAX_N 5005

//#define MAX_K 10
using namespace std;

typedef long long ll;
ll dp[MAX_N];
ll Number[MAX_N];


int main()
{
    int n;
    ll cnt[MAX_N];
    cin >> n;
    fill(dp, dp + MAX_N, 1);
    fill(cnt, cnt + MAX_N, 1);
    dp[1] = 1;
    for (int i = 1; i <= n; i++)cin >> Number[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (Number[j] > Number[i])
            {
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                }
                else if (dp[i] == dp[j] + 1)cnt[i]+=cnt[j];
            }
            if (Number[j] == Number[i] && dp[j] == dp[i]) {
                cnt[i] -= cnt[j];
            }
        }
    }
    ll ans = 0, total = 0;

    for (int i = 1; i <= n; i++)
    {
        if (ans < dp[i]) {
            ans = dp[i];
            total = cnt[i];
        }
        else if (ans == dp[i])
        {
            total += cnt[i];
        }
    }
    cout << ans << " " << total;
    return 0;
}