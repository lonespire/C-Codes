#include<bits/stdc++.h>
int main(){
	double a,b,c;
	char d;
	scanf("%lf%c%lf", &a, &d, &b);
	switch(d){
		case '+':
			c=a+b;
			break;
		case '-':
			c=a-b;
			break;
		case '*':
			c=a*b;
			break;
		case '/':
			c=a/b;
			break;
	}
	printf("%.2lf%c%.2lf=%.2lf",a,d,b,c);
	return 0;
}
//#include<stdio.h>
//int main(){
//	double a,b,c;
//	char d;
//	scanf("%fl" "%c" "%fl",&a,&d,&b);
//	switch(d){
//		case '+':
//			c=a+b;
//			break;
//		case '-':
//			c=a-b;
//			break;
//		case '*':
//			c=a*b;
//			break;
//		case '/':
//			c=a/b;
//			break;
//	}
//	printf("%fl%c%fl=%fl",a,d,b,c);
//	return 0;
//}
