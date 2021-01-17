#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll N = 1e4 + 1;
int w[N];
int main()
{
    int n, m, L, R;
    int max = 0;
    int temp;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    cin >> m;
    cin >> L >> R;
    for (int k = L; k <= R; k++)
        max += w[k];
    for (int j = 2; j <= m; j++)
    {
        temp = 0;
        cin >> L >> R;
        for (int k = L; k <= R; k++)
        {
            temp += w[k];
        }
        if (temp > max)
        {
            max = temp;
        }
    }
    cout << max << endl;
    return 0;
}