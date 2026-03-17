#include<iostream>
using namespace std;
void printF(int a, int b)
{
	cout << a;
	for (int i = a+1; i <= b; i++)
	{
		cout << " " << i;
	}
	cout << endl;
	return;
}
void f(int a, int b, int n)
{
	if (a > n || b > n)
	return;
	printF(a, b);
	if(b<n)
	f(a, b + 1, n);
	else
	f(a + 1, a + 1, n);
}
int main() 
{
	int n;
	cin >> n;
	f(1, 1, n);
	return 0;
}