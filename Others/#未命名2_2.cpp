#include<stdio.h>
#include<Windows.h>
int main() 
    {
        char c;
    int zimu=0,kongge=0,shuzi=0,el=0;
 while((c=getchar())!='\n'){
     if(c>='a'&&c<='z'||c>='A'&&c<='Z')
        zimu++;
     else if(c==' ')
         kongge++;
     else if(c>='0'&&c<='9')
         shuzi++;
     else
         el++;
		}
     printf("%d %d %d %d",zimu,kongge,shuzi,el);
     system    ("pause");
     return 0;
 }
