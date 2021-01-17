#include <iostream>
using namespace std;
const int N = 100010;
//全局数组若不初始化，编译器将其初始化为零。局部数组若不初始化，内容为随机值。
int a[N];
int sum[N];
int main()
{
    int n, m;
    int s = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
    return 0;
}
