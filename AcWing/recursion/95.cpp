#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int dx[5] = {0, -1, 0, 1, 0};
int dy[5] = {0, 0, 1, 0, -1};
char g[5][5];
int res;
int ans;
bool is_successful;

void turn(int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && yy >= 0 && xx < 5 && yy < 5)
        {
            g[xx][yy] ^= 1;
            //利用^的性质，配偶'0' 变'1' 48变49  49变48
        }
    }
}
int work()
{ //枚举第一行的所有按法，第一行按法确定了，那么第二行的按法也就确定了，依次类推
    //最终只需要判断最后一行的状态是否全1即可。
    //1代表按
    char backup[5][5];
    ans = inf;

    for (int k = 0; k < (1 << 5); k++)
    {
        res = 0;
        memcpy(backup, g, sizeof g);
        //枚举第一行的所有可能的按法，1代表按
        for (int j = 0; j < 5; j++)
        {
            if (k >> j & 1)
            {
                res++;
                turn(0, j);
            }
        }
        //第一行按完之后，看看1到第4行的状态，是0的话，只能把行下面对应的元素turn掉

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (g[i][j] == '0')
                {
                    res++;
                    turn(i + 1, j);
                }
            }
        }
        bool is_successful = true;
        //枚举最后一行的状态
        for (int i = 0; i < 5; i++)
        {
            if (g[4][i] == '0')
            {
                is_successful = false;
                break;
            }
        }
        memcpy(g, backup, sizeof backup);
        if (is_successful)
            ans = min(ans, res);
    }
    if (ans <= 6)
        return ans;
    else
        return -1;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 5; i++)
        {
            cin >> g[i];
        }
        cout << work() << endl;
    }
    system("pause");
    return 0;
}