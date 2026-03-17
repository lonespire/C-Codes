#include <stdio.h>
#include <string.h>
int main()
{
    void sort(char *str[], int n);
    char *string[10] = {(char *)"Jan", (char *)"Feb", (char *)"Mar", (char *)"Apr", (char *)"May",
                        (char *)"Jun", (char *)"Jul", (char *)"Aug", (char *)"Sep", (char *)"Oct"};
    printf("The string list is:\n");
    for (int i = 0; i < 10; i++)
        printf("%s ", string[i]);
    sort(string, 10);
    printf("\n\nThe sorted string list is:\n");
    for (int i = 0; i < 10; i++)
        printf("%s ", string[i]);
    return 0;
}
// 用起泡排序或选择排序实现字符串排序
void sort(char *str[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(str[i], str[j]) > 0)
            {
                char *temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}
