#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int n, h;
ll ans = 0;
int a[301];
int b[301];
int main()
{
    cin >> n;
    a[0] = 0;

    rec(i, 1, n)
    {
        cin >> a[i];
    }
    sort(a, a + 1 + n);
    int j = 0;
    int i = n;
    int c = 0;
    while (j <= n)
    {
        if (j % 2 == 0)
        {
            b[j++] = a[c++];
        }
        else
        {
            b[j++] = a[i--];
        }
    }
    rec(i, 1, n)
    {
        ans += (b[i] - b[i - 1]) * (b[i] - b[i - 1]);
    }
    cout << ans << endl;

    /* 比较骚的一种题解
    int q=0,p=n;//p,q分别记录接下来要跳的石头是那块
    while(q<p){
        ans+=pow((A[p]-A[q]),2);//计算跳一次后增加消耗的体力值
        q++;
        ans+=pow((A[q]-A[p]),2);//同上
        p--;
    }
*/

    system("pause");
    return 0;
}