#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        int l;
        if(s[0]==s[2])
        {
            cout<<"No"<<endl;
            continue;
        }
        if(s[1]=='+'||s[1]=='*')
        {
            cout<<"Yes"<<endl;
            continue;
        }
        cout<<"No"<<endl;
    }
    
    return 0;
}