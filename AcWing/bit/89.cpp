#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;

/*快速幂 a^b % p*/

int main()
{
    int a, b, p;
    cin >> a >> b >> p;
    //当p等于1时，res = 0 边界情况
    int res = 1 % p;
    while (b)
    {
        //如果b末位是1，进行乘
        if (b & 1)
            res = res * 1ll * a % p;
        //1ll 把int 1 转换成long long 格式
        a = a * 1ll * a % p;
        b >>= 1;
    }
    cout << res << endl;
    system("pause");
    return 0;
}
