#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string num;
        cin >> num;
        if (num[0] == '-')
        {
            bool flag = false;
            // num.insert(1, "1");
            for(int i = 1; i < num.size(); i++)
            {
                if(num[i] > '1')
                {
                    num.insert(i, "1");
                    flag = true;
                    break;
                }
            }
            if(!flag)
            {
                num+="1";
            }
            cout<<num<<endl;
        }
        else if (num[0] == '0')
        {
            cout << "10" << endl;
        }
        else
        {
            bool flag = false;
            // num.insert(1, "1");
            for(int i = 0; i < num.size(); i++)
            {
                if(num[i] == '0')
                {
                    num.insert(i, "1");
                    flag = true;
                    break;
                }
            }
            if(!flag)
            {
                num+="1";
            }
            cout<<num<<endl;
        }
    }
    return 0;
}
/*
1000000000000000000
1000000000000000000
*/