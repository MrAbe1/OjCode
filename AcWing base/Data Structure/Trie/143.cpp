#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010, M = 31 * N;
int n;
int a[N], son[M][2],idx;
void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (!son[p][u])
            son[p][u]=++idx;
        p = son[p][u];
    }
}
int query(int x)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        //选择与当前位不同的数
        if (son[p][!u])
        {
            p = son[p][!u];
            res = res * 2 + !u;
        }
        else
        {
            p = son[p][u];
            res = res * 2 + u;
        }
    }
    return res;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        //为了避免处理边界问题，先插入Trie树再进行查询
        insert(a[i]);
        //在Trie树中查询与a[i]异或的最大值,返回当前树中选中的值
        int t = query(a[i]);
        res = max(res, a[i]^t);
    }
    cout << res << endl;
}
