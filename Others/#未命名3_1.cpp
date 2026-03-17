#include<stdio.h>
#include<Windows.h>
int main()
{
    int n,i,j;
    scanf("%d", &n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    if(n%2==1){
    	j=n/2+1;
	}
	else{
		j=n/2;
	}
    for(i=0;i<n/2;i++)
    {
    int x=arr[i];
    arr[i]=arr[j+i];
    arr[j+i]=x;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
system("pause");
return 0;
}
