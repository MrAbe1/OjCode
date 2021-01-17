#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
vector<int> v;
int n;
//这里面的u相当于count，统计个数
// void dfs(int u, int state)
// {
//     if (u == n)
//     {
//         for (auto x : v)
//             cout << x << ' ';
//         cout << endl;
//         return;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         //如果第i位没有使用过
//         if (!(state & 1 << i))
//         {
//             v.push_back(i + 1);
//             dfs(u + 1, state | 1 << i);
//             v.pop_back();
//         }
//     }
// }
int main()
{
    cin >> n;
    int a[100];
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    do
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << ' ';
        }
        cout << endl;
    } while (next_permutation(a + 1, a + 1 + n));
    // dfs(0, 0);

    system("pause");
    return 0;
}