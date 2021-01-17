#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
ll f[1001];

int main()
{
    // fun[1] = 1;
    // fun[2] = 2;
    // ll ans;
    // for (int i = 3; i <= 1001; i++)
    // {
    //     fun[i] = (2 * fun[i - 1] + 3 * fun[i - 2] + i) % mod;
    // }
    // int n;
    // cin >> n;
    // while (n != 0)
    // {
    //     cout << fun[n] << endl;
    //     cin >> n;
    // }
    int n;
    f[1] = 1, f[2] = 2;

    for (int i = 1; i <= 1001; i++)
    {
        f[i + 2] = (2 * f[i + 1] + 3 * f[i] + i + 2) % mod;
    }
    while (cin >> n && n)
    {

        cout << f[n] << endl;
    }
    system("pause");
    return 0;
}