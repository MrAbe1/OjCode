/*求 n 个数选 m 个数的组合的组合，子集生成 DFS
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, a[maxn], choose[maxn];
void dfs(int d, int pre, int m)
{
    int i, j;
    if (d == m + 1)
    { //选完了
        for (i = 1; i <= m; ++i)
            printf("%d ", choose[i]);
        printf("\n");
        return;
    }
    //从pre后面继续选择
    for (i = pre + 1; i <= n; ++i)
    {
        choose[d] = a[i];
        dfs(d + 1, i, m);
    }
}

int main()
{
    scanf("%d", &n);
    int i, j;
    for (i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    dfs(1, 0, 3); //从n个数里选3个
    return 0;
}