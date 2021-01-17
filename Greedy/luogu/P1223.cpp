/**
 * 这题输出行末尾可以空格
*/

#include <bits/stdc++.h>
using namespace std;
#define rec(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e6 + 100;
int T[maxn];
int temp[maxn];
int index1[maxn];
int visted[maxn]; //
double sum = 0;
// int main()
// {
//     int n;
//     cin >> n;
//     memset(visted, 0, sizeof(visted));
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> T[i];
//         temp[i] = T[i];
//     }
//     sort(T + 1, T + n + 1);
//     int i = 0;
//     for (int j = 1; j <= n; j++)
//     {
//         for (int k = 1; k <= n; k++)
//             if (T[j] == temp[k] && visted[k] == 0)
//             {
//                 visted[k] = 1;
//                 index1[j] = k;
//                 break;
//             }
//     }
//     cout << index1[1];
//     for (int j = 2; j <= n; j++)
//         cout << " " << index1[j];
//     cout << endl;
//     for (int l = 1; l <= n; l++)
//     {
//         sum += T[l] * (n - l);
//     }
//     printf("%.2lf\n", sum / n);
//     return 0;
// }

//        freopen("test.in","r",stdin);
//        freopen("test.out","w",stdout);

//pair的使用 无敌

pair<int, int> a[maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        //a[i] = make_pair(t, i);
        a[i].first = t;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    ll sum = 0;
    ll sum1 = 0;
    rec(i, 1, n + 1)
    {
        cout << a[i].second << " ";
        if (i == n)
            break;
        sum += a[i].first;
        sum1 += sum;
    }
    cout << endl;
    printf("%.2f\n", sum1 * 1.0 / n);
    return 0;
}