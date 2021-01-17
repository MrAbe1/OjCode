#include <iostream>
using namespace std;
//矩阵开的太大100010，生成二维矩阵会超时，矩阵开的太小1001，会报segmention fault
//本题b数组会访问到下标为1001 1001的数组单元，开1001的大小下标是0-1000，肯定会爆
const int N = 1010;
int a[N][N];
int b[N][N];
int n, m, q;

//差分矩阵b[][]
//a[][]为b[][]的前缀和，初始b[][]为0 a[][]为0,
//初始状态 互为差分 和 前缀和
void insert(int x1, int y1, int x2, int y2, int c)
{
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}
int main()
{
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            //cin >> a[i][j];
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            insert(i, j, i, j, a[i][j]);
    while (q--)
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            //cout << b[i][j] << ' ';
            printf("%d ", b[i][j]);
        }
        puts("");
    }
    return 0;
}