#include<iostream>
using namespace std;
int max1(int a,int b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}
bool ou(int a){
	if(a%2==0){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	int a[5][5],MAX=-9999;
	long double b=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=4;i++){
		MAX=max1(MAX,a[1][i]);
	}
	for(int i=1;i<=4;i++){
		MAX=max1(MAX,a[4][i]);
	}
	for(int i=1;i<=4;i++){
		MAX=max1(MAX,a[i][1]);
	}
	for(int i=1;i<=4;i++){
		MAX=max1(MAX,a[i][1]);
	}
	for(int i=1;i<=4;i++){
		if(ou(a[i][i])){
			b+=a[i][i];
		}
	}
	for(int i=4;i>=1;i--){
		if(ou(a[i][5-i])){
			b+=a[i][5-i];
			}
	}
	cout<<MAX<<" "<<b/8;
	return 0;
}
//1 1 2 2
//1 1 1 1
//1 1 1 1
//1 1 1 1
