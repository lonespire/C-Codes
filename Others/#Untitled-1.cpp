#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
using namespace std;

int main() {
    ::ios::sync_with_stdio(false),cin.tie(nullptr);
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    // printf("%.2lf",sqrt(pow(c-a,2)+pow(d-b,2)));
    cout<<fixed<<setprecision(2)<<sqrt(pow(c-a,2)+pow(d-b,2));
    return 0;
}