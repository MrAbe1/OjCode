#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
ll n, x;
ll ans = 0;
ll a[maxn];
int main()
{
    cin >> n >> x;
    rec(i, 1, n)
    {
        cin >> a[i];
    }
    int pre = a[1];
    ans = 0;
    rec(i, 2, n)
    {
        if (a[i] + pre <= x)
        {
            pre = a[i];
            continue;
        }
        else
        {
            ans += (a[i] + pre) - x;
            a[i] = x - pre;
            pre = a[i];
        }
    }
    cout << ans << endl;

    system("pause");
    return 0;
}
