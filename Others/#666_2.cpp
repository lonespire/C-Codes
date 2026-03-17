#include <stdio.h>
#include <string.h>

#define MAXN 600606
char a[3][MAXN];

void swap666(char *a, char *b)
{
    char temp[MAXN];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        scanf("%s", a[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (strcmp(a[i], a[j]) > 0)
            {
                swap666(a[i], a[j]);
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%s ", a[i]);
    }
    printf("\n");
    return 0;
}