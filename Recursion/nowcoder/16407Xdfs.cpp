#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
const int MOD = 420047;
int visited[81][81];
ll cnt;

void fun(int i, int j)
{
    //没有使用过
    if (visited[i][j] == 0)
    {
        fun(i - 1, j);
        fun(i + 1, j);
        fun(i, j - 1);
        fun(i, j + 1);
    }
    else
    {
        return;
    }
}

int main()
{
    int T, M, N, K;
    cin >> T;
    memset(visited, 0, sizeof(visited));

    while (T--)
    {
        cout << endl;
        cin >> M >> N >> K;
    }
    return 0;
}