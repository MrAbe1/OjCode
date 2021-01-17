
/*二进制法，选数为 m 的子集生成*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, a[maxn], choose[maxn];

int numberOf1(int x)
{
    int cnt = 0;
    while (x)
    {
        cnt++;
        x = x & (x - 1); //去掉末尾的1
    }
    return cnt;
}
int main()
{
    scanf("%d", &n);
    int m = 3; //选3个数
    int i, j;
    for (i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (i = 0; i < (1 << n); i++)
    {
        if (numberOf1(i) == m)
        {
            for (j = 0; j < n; j++)
            { //枚举位置，判断j位置是否有1（1右移动j位）
                if (i & (1 << j))
                    printf("%d ", j + 1);
            }
            printf("\n");
        }
    }

    return 0;
}