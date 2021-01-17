#include <bits/stdc++.h>
using namespace std;
#define rrec(i, a, b) for (int i = (a); i >= (b); i--)
#define rec(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll maxn = 1e5 + 10;
int n, s;
int a, b;
int x, y;
int ans = 0;
//建立一个小根堆
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
    cin >> n >> s;
    cin >> a >> b;
    rec(i, 1, n)
    {
        cin >> x >> y;
        if (x <= b || x <= (a + b))
        {
            pq.push(y);
        }
    }
    rec(i, 1, n)
    {
        int top = pq.top();
        pq.pop();
        if (top <= s)
        {
            ans++;
            s -= top;
        }
        else
        {
            break;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
