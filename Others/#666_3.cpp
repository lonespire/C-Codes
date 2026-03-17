#include <stdio.h>

void swap666(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void input(int *a, int *MIN, int *MAX, int **MINP, int **MAXP)
{
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
        if (*MIN > a[i])
        {
            *MIN = a[i];
            *MINP = &a[i];
        }
        if (*MAX < a[i])
        {
            *MAX = a[i];
            *MAXP = &a[i];
        }
    }
}
void op(int *a, int **MINP, int **MAXP)
{
    swap666(a, *MINP);
    swap666(a + 9, *MAXP);
}
void output(int *a)
{
    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);
}
int main()
{
    int a[10], MIN = 0x3f, MAX = -0x3f;
    int *MINP = NULL, *MAXP = NULL;
    input(a, &MIN, &MAX, &MINP, &MAXP);
    op(a, &MINP, &MAXP);
    output(a);
    return 0;
}
/*1 8554 0 4545454 134 6541154 3113 454 89 45*/