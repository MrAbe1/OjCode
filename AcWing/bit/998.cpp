#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int n, m;
pair<string, int> a[maxn];
//对bit位进行n次运算，now是当前位置的值，0，1；
int calc(int bit, int now)
{
    for (int i = 1; i <= n; i++)
    {
        int x = a[i].second >> bit & 1;
        if (a[i].first == "AND")
            now &= x;
        else if (a[i].first == "OR")
            now |= x;
        else
            now ^= x;
    }
    return now;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        char str[5];
        int x;
        scanf("%s%d", str, &x);
        a[i] = make_pair(str, x);
    }
    //val是初始攻击力，ans是最后造成的伤害
    int val, ans = 0;
    for (int bit = 29; bit >= 0; bit--)
    {
        int res0 = calc(bit, 0);
        int res1 = calc(bit, 1);
        //ps val + (1 << bit) <= m应该是天然成立的
        if (val + (1 << bit) <= m && res0 < res1)
            val += (1 << bit), ans += res1 << bit;
        else
            //当前位置置0，所以value不变
            ans += res0 << bit;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
