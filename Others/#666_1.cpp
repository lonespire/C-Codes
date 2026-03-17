#include <stdio.h>

void swap666(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
int main()
{
    int a[3];
    for (int i = 0; i < 3; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 3; j++)
            if (a[i] > a[j])
                swap666(&a[i], &a[j]);
    for (int i = 0; i < 3; i++)
        printf("%d ", a[i]);
    return 0;
}