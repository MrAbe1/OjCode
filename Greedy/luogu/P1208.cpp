#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int n, m;
struct node
{
    int p;
    int a;
} milk[5001];
ll ans = 0;
bool cmp(node a, node b)
{
    return a.p < b.p;
}
int main()
{

    cin >> n >> m;
    rec(i, 1, m)
    {
        cin >> milk[i].p >> milk[i].a;
    }

    //按照从小到大排序
    sort(milk + 1, milk + 1 + m, cmp);

    rec(i, 1, m)
    {
        if (milk[i].a <= n)
        {
            ans += milk[i].p * milk[i].a;
            n -= milk[i].a;
        }
        else
        {
            ans += n * milk[i].p;
            n = 0;
            break;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
