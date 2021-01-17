/*# 
 求 n 个数的全排列 STL
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int n, a[maxn], b[maxn];
int choose[maxn], vis[maxn], cnt = 0;
int main()
{
    scanf("%d", &n);
    int i, j;
    for (i = 1; i <= n; ++i)
        scanf("%d", &a[i]), b[i] = i;
    do
    {
        printf("%4d:", ++cnt);
        for (i = 1; i <= n; ++i)
            printf("%d ", a[b[i]]);
        printf("\n");
    } while (next_permutation(b + 1, b + 1 + n));
    return 0;
}