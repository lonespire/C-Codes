#include<bits/stdc++.h>
using namespace std;
vector<int> used(10,0);
bool ifused(int a){
	int b=a*2,c=a*3;
	fill(used.begin(),used.end(),0);
	while(a>0){
		used[a%10]++;
		a/=10;
	}
	while(b>0){
		used[b%10]++;
		b/=10;
	}
	while(c>0){
		used[c%10]++;
		c/=10;
	}
	for(int i=0;i<=9;i++){
		if(used[i]>=2){
			return 1;
		}
	}
	return 0;
}
int main(){
	for(int i=123;i<=333;i++){
		if(ifused(i)){
			continue;
		}
		else{
			cout<<i<<" "<<i*2<<" "<<i*3<<endl;
		}
	}
	return 0;
}
