//矩阵快速幂
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
ll pre, now;
ll gpre, gnow;
int n;
int main()
{
    int n;
    ll ans;
    ll gans;
    while (cin >> n && n)
    {
        pre = 1;
        now = 2;
        gpre = 8;

        if (n == 1)
        {
            cout << 2 << endl;
        }
        else if (n == 2)
        {
            cout << 8 << endl;
        }
        else
        {
            for (int i = 3; i <= n; i++)
            {

                ans = (2 * now + 3 * pre + i) % mod;
                pre = now % mod;
                now = ans % mod;
                gans = (gpre + ans + i * i) % mod;
                gpre = gans % mod;
            }
            cout << gans << endl;
        }
    }
    system("pause");
    return 0;
}