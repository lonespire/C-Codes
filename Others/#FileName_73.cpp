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
#define MAX_N 245
#define MAX_K 10
using namespace std;

typedef long long ll;



int main()
{
	string s;
	int n;
	cin>>s;
	cin >> n;
	for (int i = 1; i <= n;i++ )
	{
		for (int j = 0; j < s.size()-i+1; j++)
		{
			if (j==s.size()-i||s[j]>s[j+1])
			{
				for (int k = j; k < s.size() -i; k++)
				{
					s[k] = s[k + 1];
				}
				break;
			}
		}
		
	}
	
	int flag=1, ans = 0;
	for (int i = 0; i < s.size() - n; i++)
	{
		if (s[i] != '0'&&flag==1)flag = 0;
		if (flag)continue;
		cout << s[i];
	}
	return 0;
}