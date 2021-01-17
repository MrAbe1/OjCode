#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int a[10];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "    " << a[i];
    }
    cout << endl;
    //next_permulation 默认的[ )形式
    while (next_permutation(a + 1, a + n + 1))
    {
        for (int i = 1; i <= n; i++)
        {
            cout << "    " << a[i];
        }
        cout << endl;
    }
    return 0;
}