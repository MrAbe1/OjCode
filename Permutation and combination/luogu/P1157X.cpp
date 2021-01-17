#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int n, r;
int a[22];
int c[22];
int b[22];
int main()
{
    cin >> n >> r;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
        c[i] = i;
    }
    for (int j = 1; j <= r; j++)
        cout << "  " << a[j];
    cout << endl;
    for (int i = 1; i <= r; i++)
    {
        while (next_permutation(a + i, a + i + r + 1))
        {
            for (int j = 1; j <= r; j++)
                cout << "  " << a[j];
            cout << endl;
        }
    }
    return 0;
}