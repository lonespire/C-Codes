#include<stdio.h>

typedef long long ll;
ll y(ll x)
{
	if (x < 1)return x;
	else if (1 <= x && x < 10) return 2 * x - 1;
	else return 3 * x - 11;
}



int main()
{
	ll x;
	scanf("%lld", &x);
	printf("yֵΪ%lld", y(x));

	return 0;
}