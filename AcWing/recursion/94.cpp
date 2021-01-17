#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int n;
vector<int> path;
void dfs(int u, int state) //u更像是层数，把dfs的过程想象成一棵树
{
    if (u == n)
    {
        for (auto x : path)
            cout << x << ' ';
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!(state >> i & 1)) //如果第i位置的数没有用过为0
        {
            path.push_back(i + 1);
            dfs(u + 1, state | (1 << i));
            path.pop_back();
            //dfs(u + 1, state);
        }
    }
}
int main()
{
    cin >> n;
    dfs(0, 0);
    system("pause");
    return 0;
}