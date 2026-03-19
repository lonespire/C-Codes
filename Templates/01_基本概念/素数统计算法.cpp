#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<bool> is_prime;
vector<int> prime; // 用数组存储素数，遍历更快
void get_prime(int N)
{
    is_prime.assign(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++)
    {
        if (is_prime[i])
            prime.push_back(i); // 素数加入数组（有序）
        for (int j = 0; j < prime.size() && i * prime[j] <= N; j++)
        {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, N = 0;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        N = max(N, num[i]);
    }
    is_prime.resize(N + 1, 1);
    get_prime(N);
    int ans = 0;
    for (auto &i : num)
    {
        if (i < 2 || !is_prime[i])
            continue;
        ans++;
    }
    cout << ans;
    return 0;
}
