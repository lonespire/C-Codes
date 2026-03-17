#include<bits/stdc++.h>
#define CRT_SECURE_NO_WARNINGS
#define MAX_N 1000
#define MAX_K 10
using namespace std;

int n;


int main()
{
	cin >> n;
	if (n % 2 == 1)
	{
		for (int i = 1; i <= n / 2; i++)
		{
			cout << '-';
		}
		cout << '=';
		for (int i = 1; i <= n / 2; i++)
		{
			cout << '-';
		}
	}
	else
	{
		for (int i = 1; i <= n / 2 - 1; i++)
		{
			cout << '-';
		}
		for (int i = 1; i <= 2; i++)
		{
			cout << '=';
		}
		for (int i = 1; i <= n / 2 - 1; i++)
		{
			cout << '-';
		}
	}


	return 0;
}
