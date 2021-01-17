/*二进制法，全子集生成*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, a[maxn], choose[maxn];
int main()
{
    scanf("%d", &n);
    int i, j;
    for (i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (i = 0; i < (1 << n); i++)
    {
        for (j = 0; j < n; j++)
        { //枚举位置，j既是移动位置，也是数值
            if (i & (1 << j))
                printf("%d ", j + 1);
        }
        printf("\n");
    }
    return 0;
}