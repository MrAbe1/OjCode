#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int t;
int m, n, Q;
int a[8], b[8];
bool flag = false;
bool isDeadAll()
{
    for (int i = 0; i < n; i++)
    {
        if (b[i] > 0)
            return 0;
    }
    return 1;
}
//攻击如果有人死了 再次attack
void attack()
{

    for (int i = 0; i < n; i++)
    {
        b[i] -= 1;
        if (b[i] == 0)
            flag = true;
    }
    for (int i = 0; i < m; i++)
    {
        a[i] -= 1;
        if (a[i] == 0)
            flag = true;
    }
    if (flag)
    {
        flag = false;

        attack();
    }
    return;
}

void dfs(int Q)
{

    if (isDeadAll())
    {
        cout << "Legendary" << endl;
        return;
    }
    if (Q == 0)
    {
        cout << "GG" << endl;
        return;
    }
    attack();
    dfs(Q - 1);
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> m >> n >> Q;
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        dfs(Q);
    }
    system("pause");
    return 0;
}
