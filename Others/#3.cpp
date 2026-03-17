#include <stdio.h>
int main()
{
    void search(float (*p)[4], int n);
    float score[3][4] = {{65, 57, 70, 60}, {58, 87, 90, 81}, {90, 99, 100, 98}};
    search(score, 3);
    return 0;
}
void search(float (*p)[4], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (p[i][j] < 60)
            {
                printf("No.%d fails, his scores are:\n", i + 1);
                for (int k = 0; k < 4; k++)
                    printf("%6.1f", p[i][k]);
                printf("\n");
                break;
            }
        }
    }
}
/*
#include<stdio.h>
int main()
{
    void search(float(*p)[4], int n);
    float score[3][4] = { {65,57,70,60},{58,87,90,81},{90,99,100,98} };
    search(score, 3);
    return 0;
}
void search(float(*p)[4], int n)
{
    int i, j, flag = 0;
    for (i= 0; i < n; i++)
    {
        for (j = 0; j < 4; j++)
            if (*(*(p + i) + j) < 60)
                flag = 1;
        if (flag)
        {
            printf("No.%d fails, his scores are:\n", i + 1);
            for (i = 0; i < 4; i++)
                printf("%6.1f", *(p+i*4 + j));
            printf("\n");
        }
    }
}
*/
