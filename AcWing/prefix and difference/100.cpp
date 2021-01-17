#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 100010;
int a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    //技巧，倒叙计算差分数组,a[1]不变
    for (int i = n; i >= 2; i--)
        a[i] -= a[i - 1];
    ll pos = 0, neg = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] < 0)
            neg -= a[i];
        else
            pos += a[i];
    }
    //输出操作数，也就是max(pos,neg)
    cout << min(pos, neg) + abs(pos - neg) << endl;
    //输出a1即b1的所有可能,即最终的可能数列
    cout << abs(pos - neg) + 1 << endl;
    return 0;
}