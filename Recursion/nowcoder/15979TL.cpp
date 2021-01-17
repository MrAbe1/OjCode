#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
ll fun(ll n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return fun(n / 2) + fun(n % 2);
}
ll index(ll n)
{
    for (ll i = 0;; i++)
    {
        if (fun(i) == n)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    ll t;
    ll m, n;
    cin >> t;
    while (t--)
    {
        cin >> m;
        cout << fun(m) << " " << index(fun(m)) << endl;
    }
    return 0;
}

//        freopen("test.in","r",stdin);
//        freopen("test.out","w",stdout);
