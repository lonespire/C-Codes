#include<bits/stdc++.h>
int main(){
	srand((unsigned)time(NULL));
	int a;
	int b=rand()%10+1;
	scanf("%d", &a);
	if(a==b){
		printf("OK");
	}
	else{
		printf("ERROR");
	}
	return 0;
}
