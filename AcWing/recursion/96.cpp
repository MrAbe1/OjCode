#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
//
int main()
{

    //三根棍的汉诺塔，四根棍的而汉诺塔
    //三根棍的hanoi tower把前i-1个碟移动到第2根棍子
    //最后一个移动到第三根棍子，再把前i - 1个碟移动到第三根棍子上去
    int d[15], f[15];

    d[1] = 1;
    for (int i = 2; i <= 12; i++)
    {
        d[i] = 1 + d[i - 1] * 2;
    }

    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    //四根棍子的hanoi tower
    //先移动j个碟子到第2个棍子上面，再把i-j个棍子移动到最后的棍子上面，d[i-j],三个汉诺塔问题
    //再把j个碟子放到最后的棍子上去。  每次移动的碟子数目不同可能会导致最后的结果不同，这里面用
    //用a= min(a,b)的方式，保证取最小值更新f[i];
    for (int i = 1; i <= 12; i++)
    {
        for (int j = 0; j < i; j++)
        {
            f[i] = min(f[i], f[j] * 2 + d[i - j]);
        }
    }
    for (int i = 1; i <= 12; i++)
        cout << f[i] << endl;

    system("pause");
    return 0;
}
