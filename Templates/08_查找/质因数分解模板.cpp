#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int, int> factorize(int num) {
    unordered_map<int, int> factors;
 
    if (num == 1) {
        factors[1]++;
        return factors;
    }
 
 
    while (num % 2 == 0) {
        factors[2]++;
        num /= 2;
    }
 
    
    for (int i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            factors[i]++;
            num /= i;
        }
    }
 
    if (num > 2) {
        factors[num]++;
    }
 
    return factors;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    return 0;
}
// 6 122
// 12 116
// 24 104
// 48 80
// 96 32
// 64 64
// 0 128
