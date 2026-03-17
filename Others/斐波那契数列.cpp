#include<iostream>
#include<set>
using namespace std;
#define MAX_N 100
long long a[MAX_N] = {0};
long long f(int n)
{
	if (n <= 2)
	{
		return n;
	}
	if (a[n])
	{
		return a[n];
	}
	a[n] = f(n - 1) + f(n - 2);
	return f(n - 1) + f(n - 2);
}
int main() 
{
	int n;
	cin >> n;
	cout<<f(n);
	return 0;
}