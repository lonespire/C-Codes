#include <stdio.h>
#include <math.h>
#include <string.h>
int max(int a, int b)
{
    return a > b ? a : b;
}
int min(int a, int b)
{
    return a < b ? a : b;
}
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void sort(char a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
        }
    }
}
int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    char str[999];
    for (int i = 0; i < n; i++)
    {
        char temp[999];
        scanf("%s", temp);
        int j = 0;
        while (temp[j])
        {
            str[cnt++] = temp[j];
            j++;
        }
    }
    sort(str, cnt);
    str[cnt] = '\0';
    printf("%s", str);
    return 0;
}
/*
3
aac
zyz
whd
*/