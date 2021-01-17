#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int main()
{
    int x;
    cin >> x;
    for (int i = 31; i >= 0; i--)
        cout << ((x >> i) & 1); //从高位开始输出
    system("pause");
    return 0;
}