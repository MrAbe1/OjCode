#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
const int N = 20, M = 1 << 20;
int n;
//20*2^20的数组，M代表状态
int f[M][N], weight[N][N];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> weight[i][j];
        }
    }
    //把f数组设为极大数组
    memset(f, 0x3f, sizeof f);
    //第0个位置被选中，停留在第0个位置
    //前一个代表状态，后一个代表当前停留的位置
    //f代表长度
    f[1][0] = 0;

    //列举所有的状态
    for (int i = 0; i < (1 << n); i++)
    {
        //列举当前停留的位置
        for (int j = 0; j < n; j++)
        {
            if (i >> j & 1) //判断i的第j位置是否为1
            {
                for (int k = 0; k < n; k++)
                {
                    //i - (1 << j) i的第j未没选，但是选中了k位
                    if (i - (1 << j) >> k & 1)
                    {
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + weight[k][j]);
                    }
                }
            }
        }
    }
    //-的优先级高于<<
    cout << f[(1 << n) - 1][n - 1] << endl;
    system("pause");
    return 0;
}