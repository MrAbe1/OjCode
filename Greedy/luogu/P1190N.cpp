#include <bits/stdc++.h>
#define rec(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
int a[maxn];
int b[maxn];
int main()
{
    int n, m;
    int index;
    cin >> n >> m;
    //输入n个元素到a中
    rec(i, 1, n + 1)
    {
        cin >> a[i];
    }
    //前m个a[i]先把m个水龙头给占用了
    rec(i, 1, m + 1)
    {
        b[i] = a[i];
    }
    //对前面的人 排队
    sort(b + 1, b + m + 1);
    index = 0;
    //后面的人 贴到最小的那一个人后面即b[1]
    rec(i, m + 1, n + 1)
    {
        b[1] += a[i];
        sort(b + 1, b + m + 1);
    }
    //输出b[m]为最大的人
    cout << b[m] << endl;
    return 0;
}

//        freopen("test.in","r",stdin);
//        freopen("test.out","w",stdout);
