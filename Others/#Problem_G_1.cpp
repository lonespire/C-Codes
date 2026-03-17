#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
vector<int> get_primes(int n)
{
    vector<bool> is_prime(n + 1, 1);
    vector<int> primes;
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
            primes.push_back(i);
        for (auto p : primes)
        {
            if (i * p > n)
                break;
            is_prime[i * p] = 0;
            if (i % p == 0)
                break;
        }
    }
    return primes;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> primes = get_primes(1000000);
    vector<bool> if_useful(1000001, 1);
    for (int i = 0; i < primes.size(); i++)
    {
        for (int j = i; j < primes.size(); j++)
        {
            if (primes[i] * primes[j] > 1000000)
                break;
            int cur = primes[i] * primes[j];
            while (cur <= 1000000)
            {
                if_useful[cur] = 0;
                if (cur > 1000000)
                    break;
                cur *= primes[i] * primes[j];
            }
        }
    }
    for (int i = 2; i * i <= 1000000; i++)
    {
        if_useful[i * i] = 0;
    }
    vector<int> ans;
    for (int i = 2; i <= 1000000; i++)
        if (if_useful[i])
            ans.push_back(i);
    // for (auto i : ans)
    // {
    //     cout << i << " ";
    //     if (i > 300)
    //         break;
    // }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n / 2; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}