#include<bits/stdc++.h>
using namespace std;
string a;
int s_to_i(string x){
	int sb=0,boolt=0;
	int i=0;
	if(x[0]=='-'){
		i++;
		boolt=1;
	}
	for(i;i<=x.length()-1;i++){
		sb*=10;
		sb+=x[i]-'0';
	}
	if(boolt){
		sb*=-1;
	} 
	return sb;
	
}
int main(){
	cin>>a;
	cout<<s_to_i(a);
	return 0;
}
