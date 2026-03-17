#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	double pi=2;
	cin>>n;
	for(int i=1;i<=n;i++){
		pi*=4*i*i;
		pi=pi/((2*i-1)*(2*i+1));
	}
	cout<<pi<<" ";
	return 0;
}
