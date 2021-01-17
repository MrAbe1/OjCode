#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
typedef pair<ll, ll> pll;
//坐标转换
pll calc(ll n, ll m)
{
    if (n == 0)
        return {0, 0};
    ll len = 1 << (n - 1), cnt = 1ll << (2 * n - 2);

    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        auto ac = calc(n, a - 1);
        auto bc = calc(n, b - 1);
        double x = ac.first - bc.first;
        double y = ac.second - bc.second;
        printf("%.0lf\n", sqrt(x * x + y * y) * 10);
    }
    system("pause");
    return 0;
}
