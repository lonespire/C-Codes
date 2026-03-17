#include<bits/stdc++.h>
int main(){
	double a,b;
	scanf("%lf", &a);
	if(a<80){
		b=0;
		printf("%.2lf",b);
	}
	else if(80<=a&&a<=90){
		b=100+a;
		printf("%.2lf",b);
	}
	else{
		b=200+a/2*3;
		printf("%.2lf",b);
	}
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
