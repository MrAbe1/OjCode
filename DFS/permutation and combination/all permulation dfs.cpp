
/*# 
 求 n 个数的全排列 dfs
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int n, a[maxn];
int choose[maxn], vis[maxn], cnt = 0;
void dfs(int d)
{
    int i;
    if (d == n + 1)
    {
        printf("%4d:", ++cnt);
        for (i = 1; i <= n; ++i)
            printf("%d ", choose[i]);
        printf("\n");
        return;
    }
    for (i = 1; i <= n; ++i)
    {
        if (vis[i])
            continue;
        choose[d] = a[i]; //选
        vis[i] = 1;       // 标记选
        dfs(d + 1);
        vis[i] = 0; //取消标记
    }
}

int main()
{
    scanf("%d", &n);
    int i, j;
    for (i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    dfs(1);
    return 0;
}