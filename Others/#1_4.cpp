#include <stdio.h>
#include <locale.h>
#define N 3000
void joseph(int *arr, int n, int m);
int main()
{
    setlocale(LC_ALL, "");
    int array[N] = {0};
    int n, m;
    printf("请输入参加人数n和淘汰条件m：");
    scanf("%d %d", &n, &m);
    printf("淘汰顺序： ");
    joseph(array, n, m);
    return 0;
}
// 请完成以下函数
void joseph(int *arr, int n, int m)
{
    int cnt = 0, x = 1;
    for (int i = 1; cnt < n; i = i % n + 1)
    {
        if (arr[i])
            continue;
        if (x % m == 0)
        {
            printf("%d ", i);
            x = 0;
            arr[i] = 1;
            cnt++;
        }
        x++;
    }
}
