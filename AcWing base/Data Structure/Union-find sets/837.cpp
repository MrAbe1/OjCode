#include <iostream>
using namespace std;
const int N = 100010;
int p[N], cnt[N];
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        cnt[i] = 1;
    }
    while (m--)
    {
        string op;
        int a, b;
        cin >> op;
        if (op == "C")
        {
            cin >> a >> b;
            if (find(a) == find(b))
                continue;
            //位置顺序不能反，应该是cnt加完之后
            //再修改父亲，不然，相当于同一个cnt加两遍
            cnt[find(b)] += cnt[find(a)];
            p[find(a)] = find(b);
        }
        else if (op == "Q1")
        {
            cin >> a >> b;
            if (find(a) == find(b))
                puts("Yes");
            else
                puts("No");
        }
        else
        {
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
    }
    return 0;
}