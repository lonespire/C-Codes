#include <iostream>
using namespace std;
int main(){
    int a=1,m,sum=0,i=0;
    while(true){
        cin>>a;
        i++;
        if(i==1){
            m=a;
        }
        if(a!=0){
            sum+=a;
            if(a<m){
                m=a;
            }
        }
        else{
            i--;
            double x;
            x=sum/i;
            cout<<m<<" "<<x;
        }
    }
    return 0;
}
