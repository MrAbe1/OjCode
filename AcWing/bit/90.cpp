#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
/*快速乘  a*b%p*/
int main()
{
    ull a, b, p;
    cin >> a >> b >> p;
    ull res = 0;
    while (b)
    {
        if (b & 1)
            res = (res + a) % p;
        b >>= 1;
        a = a * 2 % p;
    }
    cout << res << endl;
    system("pause");
    return 0;
}