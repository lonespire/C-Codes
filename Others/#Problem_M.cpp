#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int S(int a)
{
    int ans=0;
    while (a)
    {
        ans+=a%10;
        a/=10;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int s1=S(n);
    }
    
    return 0;
}