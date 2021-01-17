#include <iostream>
using namespace std;
const int N = 5010;
int g[N][N];
int main()
{
    int N, R;
    cin >> N >> R;
    //设置长，宽，这题设置n,m 是为了之后不去计算后面无意义的矩阵
    int n = R, m = R;
    for (int i = 0, x, y, w; i < N; i++)
    {
        cin >> x >> y >> w;
        //把g下标设为从1开始，避免处理边界
        x++, y++;
        //正方形超出范围
        n = max(n, x), m = max(m, y);
        g[x][y] += w;
    }
    //动态规划的思想求前缀和
    //下标变成从1开始可以避免边界处理问题
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
        }
    int res = 0;

    for (int i = R; i <= n; i++)
        for (int j = R; j <= m; j++)
            res = max(res, g[i][j] - g[i - R][j] - g[i][j - R] + g[i - R][j - R]);

    cout << res << endl;
    return 0;
}