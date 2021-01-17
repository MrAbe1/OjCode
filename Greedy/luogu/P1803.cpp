#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e6 + 10;
int n;
struct node
{
    int a, b;
} shijian[maxn];
//对bi进行升序排序
// void sort()
// {
//     for (int i = 1; i <= n - 1; i++)
//     {
//         for (int j = 1; j <= n - i; j++)
//         {
//             if (b[j] > b[j + 1])
//             {
//                 swap(a[j], a[j + 1]);
//                 swap(b[j], b[j + 1]);
//             }
//         }
//     }
// }
bool cmp(node a, node b)
{
    //从小到大排序
    return a.b < b.b;
}

int main()
{
    cin >> n;
    rec(i, 1, n)
    {
        cin >> shijian[i].a >> shijian[i].b;
    }
    sort(shijian + 1, shijian + 1 + n, cmp);
    int ans = 1;
    int pre_a = shijian[1].a;
    int pre_b = shijian[1].b;
    rec(i, 2, n)
    {
        if (shijian[i].a >= pre_b && shijian[i].b > pre_b)
        {
            pre_a = shijian[i].a;
            pre_b = shijian[i].b;
            ans++;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
