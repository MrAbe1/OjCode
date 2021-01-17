#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int x;
int ans = 0;
//统计1的个数
int lowbit(int n)
{
    return n & (-n);
}
int main()
{
    cin >> x;
    while (x)
    {
        x = x - lowbit(x); //每次减去末尾的1
        ans++;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}