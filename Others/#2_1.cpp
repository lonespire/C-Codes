#include<stdio.h>
#include<math.h>



void symg(int n)
{
	int a=(n / 1000)%10, b=(n/100)%10, c=(n/10)%10, d=n%10;
	if (n == pow(a, 4) + pow(b, 4) + pow(c, 4) + pow(d, 4)) printf("%d ", n);
}
int main()
{
	for (int i = 1000; i <= 9999; i++) symg(i);

	return 0;
}
