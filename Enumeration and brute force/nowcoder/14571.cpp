#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int n;

int main()
{
    while (cin >> n)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int i = 1; i <= n - j; i++)
            {
                cout << " ";
            }
            for (int i = 1; i <= 2 * j - 1; i++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
    return 0;
}