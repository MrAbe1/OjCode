#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int n;
int w;
int ans = 0;
int p[30001];
int main()
{
    cin >> w;
    cin >> n;
    rec(i, 1, n)
    {
        cin >> p[i];
    }
    sort(p + 1, p + 1 + n);
    int j = n;
    int i = 1;
    while (i <= j)
    {
        if (p[j] + p[i] > w)
        {
            j--;
            ans++;
        }
        else
        {
            ans++;
            i++;
            j--;
        }
    }
    cout << ans << endl;

    system("pause");
    return 0;
}
