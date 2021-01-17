#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e6 + 10;
int n;
int a[maxn], b[maxn];
//对bi进行升序排序
void sort()
{
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            if (b[j] > b[j + 1])
            {
                swap(a[j], a[j + 1]);
                swap(b[j], b[j + 1]);
            }
        }
    }
}

int main()
{
    cin >> n;
    rec(i, 1, n)
    {
        cin >> a[i] >> b[i];
    }
    sort();
    int ans = 1;
    int pre_a = a[1];
    int pre_b = b[1];
    rec(i, 2, n)
    {
        if (a[i] >= pre_b && b[i] > pre_b)
        {
            pre_a = a[i];
            pre_b = b[i];
            ans++;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
