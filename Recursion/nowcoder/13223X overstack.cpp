#include <bits/stdc++.h>
using namespace std;
int n;
const long long maxn = 1e6 + 10;
int a[maxn];
int ans = 0;
//判断小美是否在数组中，不在输出
bool judge(int n, int *a)
{
    if (a[1] == n)
    {
        return true;
    }
    return false;
}
void rec(int mei, int n)
{
    int b[maxn];
    int temp = 0;

    for (int i = 1; i <= n / 2; i++)
    {

        b[++temp] = a[i * 2 - 1] > a[i * 2] ? a[i * 2 - 1] : a[i * 2];
        ans++;
    }
    if (!judge(mei, b))
    {
        cout << ans << endl;
        return;
    }
    if (temp == 1)
    {
        cout << ans << endl;
        return;
    }
    rec(mei, temp);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    rec(a[1], n);
    system("pause");
    return 0;
}